// Input output stream.
#include<iostream> 
// This library allows to execute system.("CLS") wich clears the console.
#include <stdlib.h>
// This library allows to execute Sleep()
#include<windows.h>

// So we can use cout<< format.
using namespace std;

//----------------------------------------Global variables----------------------------------------
int windowWidth=80;
int windowHeigth=20;
char wallsMaterial='#';
char airMaterial=' ';
int points = 0;

char ret[]="asd";



//----------------------------------------Predefinition of functions----------------------------------------

int game(); // Map generation, depends on some variables wich determine width, heigth, wall & air material...
int menu();// Interactive menu, first thing to appear when you execute the geame.
int colors(); // Just a sample function to know what colors and things available we can do.
char colorRandomizer(string); // Receives a string and makes it gay.


//----------------------------------------Main Function----------------------------------------
int main(){
	
	menu();
	
	//colors();
	
	//game();
	
	return 0;
}

//----------------------------------------Other Functions----------------------------------------

int menu(){
	
	int exit = 0;
	int option = 0;
	
	while (!exit){
		system("CLS");
		cout<<"  _____________________________________________________________________"<<endl;
		cout<<" | Bienvenido al SNAKE mas cheto de la historia de la humanidad!       |"<<endl;
		cout<<" |  - Proyecto creado por ";	cout<<colorRandomizer("Tiago Altstadt"); cout<<".                             |	"<<endl;
		cout<<" |_____________________________________________________________________|"<<endl<<endl;
		
		cout<<"  ___________________________________________________"<<endl;
		cout<<" | Alto: "<<windowHeigth<<"                                          |"<<endl;
		cout<<" | Largo: "<<windowWidth<<"                                         |"<<endl;
		cout<<" | Material Paredes: "<<wallsMaterial<<"                               |"<<endl;
		cout<<" | Material Aire: "<<airMaterial<<"                                  |"<<endl;
		cout<<" |___________________________________________________|"<<endl;
		cout<<endl<<" Elija una opcion:"<<endl;
		cout<<"  1- Jugar."<<endl<<"  2- Configurar variables."<<endl<<"  0- Salir."<<endl;
		
		cout<<endl<<" Opcion: "; cin>>option;
		
		switch(option){
			case 0:
				system("CLS");
				cout<<" Gracias por jugar!!"<<endl;
				exit = 1;
			break;
			case 1: 
				system("CLS");
				cout<<" Cargando snake..."<<endl;
				game();
			break;
			case 2: 
				system("CLS");
				int exit_configuration = 0;
				cout<<" Configuracion de variables: "<<endl<<"  1- Alto."<<endl<<"  2- Ancho."<<endl<<"  3- Material para paredes."<<endl<<"  4- Material para aire."<<endl<<"  0- Volver"<<endl;
				cout<<endl<<"  Opcion: "; cin>>option;
				switch(option){
					case 1:
						cout<<"Ingrese la altura deseada: "; cin>>windowHeigth;
					break;
					case 2:
						cout<<"Ingrese el largo deseado: "; cin>>windowWidth;
					break;
					case 3:
						cout<<"Ingrese el material para los ladrillos: "; cin>>wallsMaterial;
					break;
					case 4:
						cout<<"Ingrese el material para el aire: "; cin>>airMaterial;
					break;
					case 0:
						exit_configuration = 1;
					break;
					default: 
						cout<<"Cualquiera mandaste, proba denuevo"<<endl;
					break;
				}
			break;
			
			
			
		}
		
		
		
		
	}
	
	return 0;
}

int colors(){
	
	printf("\n");
    printf("\x1B[31mTexting\033[0m\t\t");
    printf("\x1B[32mTexting\033[0m\t\t");
    printf("\x1B[33mTexting\033[0m\t\t");
    printf("\x1B[34mTexting\033[0m\t\t");
    printf("\x1B[35mTexting\033[0m\n");
    
    printf("\x1B[36mTexting\033[0m\t\t");
    printf("\x1B[36mTexting\033[0m\t\t");
    printf("\x1B[36mTexting\033[0m\t\t");
    printf("\x1B[37mTexting\033[0m\t\t");
    printf("\x1B[93mTexting\033[0m\n");
    
    printf("\033[3;42;30mTexting\033[0m\t\t");
    printf("\033[3;43;30mTexting\033[0m\t\t");
    printf("\033[3;44;30mTexting\033[0m\t\t");
    printf("\033[3;104;30mTexting\033[0m\t\t");
    printf("\033[3;100;30mTexting\033[0m\n");

    printf("\033[3;47;35mTexting\033[0m\t\t");
    printf("\033[2;47;35mTexting\033[0m\t\t");
    printf("\033[1;47;35mTexting\033[0m\t\t");
    printf("\t\t");
    printf("\n");
    
    return 0;
}

char colorRandomizer(string text){
	
	int color = 1;
	
	char ret[] = " ";
	
	for(int i=0; i<text.length(); i++){
		cout<<"\x1B[3"<< color <<"m"<<text[i]<<"\033[0m";	
		if(color < 4){
			color++;
		}else
		color = 1;
	}
	return ret[0];
}

int game(){
	// Creating vector map (file, column)
	char map[windowHeigth][windowWidth];
	
	while(1){
		system("CLS");
		
		// Filling all spaces with something
		for(int i=0; i<windowHeigth; i++){
			for(int j=0; j<windowWidth; j++){
				map[i][j] = airMaterial;
			}
			// Adding first and last line brick
			map[i][1] = wallsMaterial;
			map[i][windowWidth-1] = wallsMaterial;
		}
		
		// Adding top & bottom wall bricks
		for(int i=1; i<windowWidth-1; i++){
			map[0][i] = wallsMaterial;
			map[windowHeigth-1][i] = wallsMaterial;
		}
	
		
		// Drawing the map
		for(int i=0; i<windowHeigth; i++){
			for(int j=0; j<windowWidth; j++){
				cout<<map[i][j];
			}
		cout<<endl;
		}
		
		cout<<"  Puntaje: "<<points<<"."<<endl;;
		
		Sleep(1);
	}
	
	return 0;
}


