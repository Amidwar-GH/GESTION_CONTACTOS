#include<iostream>
#include<string>
using namespace std;

struct contactoEmail{
	string nombres;
	char sexo;
	int edad;
	string telefono;
	string email;
	string nacionalidad;
};

const int ContactosLimite = 100;
contactoEmail contactos[ContactosLimite];
int TotalContactos=0;


void AgregarContacto(){
	
	char RPTA;
	
	do{
		if(TotalContactos >= ContactosLimite){
			cout<<"Limite de contactos excedido."<<endl;
			break;
		}
		
		cin.ignore();
		cout<<"--------------------------------------"<<endl;
		cout<<"PROTOCOLO DE INCORPORACION DE CONTACTO"<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"Digite su nombre: ";
		getline(cin, contactos[TotalContactos].nombres);
		
		cout<<"Sexo (M - F) ";
		cin>>contactos[TotalContactos].sexo;
		
		cout << "Edad: ";
    	cin >> contactos[TotalContactos].edad;
    	
		cin.ignore();
    	
    	cout << "Telefono: ";
    	getline(cin, contactos[TotalContactos].telefono);
    	
    	
		cout << "Email: ";
    	getline(cin, contactos[TotalContactos].email);
    	
		
		cout << "Nacionalidad: ";
    	getline(cin, contactos[TotalContactos].nacionalidad);
		
		
		TotalContactos += 1;
		cout<<"Contacto guardado exitosamente."<<endl;
		cout<<"Desea guardar otro contacto? (S/N)"<<endl;
		cin>>RPTA;
		RPTA=toupper(RPTA);
		
	}while(RPTA == 'S');
	
	cout<<"Regresando al MENU principal..."<<endl;
	
} 

void eliminarContacto(){
	
	char RESP;
	bool validador = false;
	do{
		if(TotalContactos == 0){
			cout<<"Aun no hay contactos registrados."<<endl;
			return;
		}
		
		cin.ignore();
		string nombre;
		cout<<"--------------------------------------"<<endl;
		cout<<"PROTOCOLO DE INCORPORACION DE CONTACTO"<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"Nombre del contacto que desea eliminar: "<<endl;
		getline(cin,nombre);
		
		for(int i=0; i<TotalContactos; i++){
			if(nombre == contactos[i].nombres){
				for(int j=i; j<TotalContactos-1; j++){
					contactos[j] = contactos[j+1];
				}
				TotalContactos -= 1;
				cout<<"El contacto fue eliminado exitosamente"<<endl;
				validador = true;
				return;
			}
		}
		
		if(!validador){
			cout<<"El contacto no fue encontrado"<<endl;
			break;
		}
		cout<<"Desea ELIMINAR otro contacto? (S/N)"<<endl;
		cin>>RESP;
		RESP = toupper(RESP);
		
	}while(RESP == 'S' );
	
	cout<<"Regresando al MENU principal..."<<endl;
	
	
}


void mostrarContactos(){
	cout<<"---------------------------------"<<endl;
	cout<<"PROTOCOLO DE MUESTRA DE CONTACTOS"<<endl;
	cout<<"---------------------------------"<<endl;
	if(TotalContactos == 0){
		cout<<"Aun no hay contactos registrados"<<endl;
		return;
	}
	
	for(int i=0; i<TotalContactos; i++){
		cout<<"Nombre: "<< contactos[i].nombres<<"| Sexo "<<contactos[i].sexo<<" | Edad "<<contactos[i].edad<<" | Telefono "<<contactos[i].telefono<<" | Email "<<contactos[i].email<<" | Nacionalidad "<<contactos[i].nacionalidad<<endl;
		cout<<"------------------------------------------------------------------------------------------------------"<<endl;
			
	}
}




int main(){
	char opcion;
	
	do{
		cout<<endl;
		cout<<"---------------------------------------"<<endl;
		cout<<"-MENU PRINCIPAL DE GESTOR DE CONTACTOS-"<<endl;
		cout<<"---------------------------------------"<<endl;
		cout<<endl;
		cout<<"***Seleccione una opcion***"<<endl;
		cout<<"A. Agregar contacto."<<endl;
		cout<<"B. Eliminar contacto."<<endl;
		cout<<"C. Mostrar listado general,"<<endl;
		cout<<"D. Mostrar contactos por servidor de correo."<<endl;
		cout<<"E. Salir del programa."<<endl;
		cin>>opcion;
		opcion = toupper(opcion);
		
		switch (opcion) {
            case 'A': AgregarContacto(); break;
            case 'B': eliminarContacto(); break;
            case 'C': mostrarContactos(); break;
            //case 'D':*/ 
            case 'E': cout << "Saliendo del programa..."; break;
            default: cout << "Opción no válida.\n";
        }
		
	}while (opcion != 'E');
	
	return 0;
	
}
