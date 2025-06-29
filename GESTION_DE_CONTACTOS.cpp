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
            /*case 'B':
            case 'C': 
            case 'D':*/ 
            case 'E': cout << "Saliendo del programa..."; break;
            default: cout << "Opción no válida.\n";
        }
		
	}while (opcion != 'E');
	
	return 0;
	
}
