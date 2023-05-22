#include <iostream>

#include <fstream>

#include<windows.h>

#include <string>

using namespace std;

string ValidacionTXT(string x) { // validacion de caracteres 

	int z;	bool espa;

	while (x.empty()) {

		cout << "Error, Por favor introduzca informacion: " << endl;

		cin.ignore();

		getline(cin, x);

	}

	for (z = 0; z < x.length(); z++) {

		if (!isalpha(x.at(z)) && !isspace(x.at(z))) {

			espa = true;

			z = 100;

		}

		else {

			espa = false;

		}

	}

	while (espa == true) {

		cout << "Error, Por favor introduzca informacion sin simbolos: " << endl;

		cin.ignore();

		getline(cin, x);

		while (x.empty()) {

			cout << "Error, Por favor introduzca informacion: " << endl;

			cin.ignore();

			getline(cin, x);

		}

		for (z = 0; z < x.length(); z++) {

			if (!isalpha(x.at(z)) && !isspace(x.at(z))) {

				espa = true;

				z = 100;

			}

			else {

				espa = false;

			}

		}

	}

	return x;

};

int ValidacionAno(int x) {

	while (x <= 1900 || x > 2023 || x == NULL || x == 0)

	{

		cout << "Por favor, introduzca un ano de entre 1900 al ano actual." << endl;

		cin >> x;

	}

	return x;

};

struct {

	int NumeroC, anos, CantidadT, CT, preciouni;

	string NombreJuego, NombreT, genero, descrip, DT;

	float precioF, PrecioUn;

}Citas[20];

bool S1{ true };  //Variable para salir del programa principal

int N1; //variable para el switch en la linea  78

int N;    //Variable para el selector del menu

int NoC = 0;  //Variable para el numero de articulos

string NombreJ; //Variable para el nombre

int anos;

string NT; //Nombre del tratamiento

string DT; //Descripcion del tratamiento

float PrecioUT; //Precio unitario

int CT;

float PU; //Precio unitario

float Precio; //Precio final

bool InfoC{ false }; //Variable

int i, aborrar, z, w = 0, amod;

bool datava;

bool espa;

int preciouni;

int CantidadT;

string genero;

string descrip;

int main() {

	ifstream ifile;

	ifstream citas;

	NoC = 1;

	while (S1 == true) {

		cout << "Bienvenido a la tienda de videojuegos Tevyat por favor seleccione una opcion:" << endl;
		cout << "\t-------------------------------------------" << endl;

		cout << "1: Agendar articulo. \n2: Modificar articulo. \n3: Eliminar articulo. \n4: Lista de articulos vigentes. \n5: Limpiar pantalla. \n6: Salir y guardar la informacion ." << endl;

		cin >> N;

		system("cls");

		switch (N) {

		case 1: //Dar de alta una orden

			i = NoC - 1;


			cout << "El numero del articulo es: \n" << NoC << endl;

			Citas[i].NumeroC = NoC;

			cout << "Por favor introduzca el nombre del juego: " << endl;

			cin.ignore();

			getline(cin, NombreJ);

			NombreJ = ValidacionTXT(NombreJ);

			Citas[i].NombreJuego = NombreJ;

			cout << endl << "Por favor, ingrese el año de lanzamiento del juego." << endl;

			cout << endl << "Ano:" << endl;

			cin >> anos;

			while (cin.fail()) {

				cout << "Por favor solo ingrese numeros." << endl;

				cin.clear();

				cin.ignore(); // limpia todo el bucle hasta que se le ingrese un dato correcto

				cin >> anos;

			}

			anos = ValidacionAno(anos);

			Citas[i].anos = anos;

			cout << endl << "Por favor, introduzca la clasificacion del juego: " << endl;

			cin.ignore();

			getline(cin, NT);

			NT = ValidacionTXT(NT);

			Citas[i].NombreT = NT;

			cout << endl << "Por favor, introduzca las caracteristicas del juego: " << endl;

			cin.ignore();

			getline(cin, DT);

			DT = ValidacionTXT(DT);

			Citas[i].DT = DT;

			cout << endl << "Por favor, introduzca el genero del juego:" << endl;

			cin.ignore();

			getline(cin, genero);

			genero = ValidacionTXT(genero);

			Citas[i].genero = genero;

			cout << endl << "Por favor, de una corta descripcion del juego: " << endl;

			cin.ignore();

			getline(cin, descrip);

			descrip = ValidacionTXT(descrip);

			Citas[i].descrip = descrip;

			cout << endl << "Por favor, introduzca un precio: " << endl;

			cin >> CT;

			while (cin.fail()) {

				cout << "Por favor ingrese solo numeros." << endl;

				cin.clear();

				cin.ignore();

				cin >> CT;

			}

			cout << endl << "Por favor, introduzca el precio unitario (por pieza):" << endl;

			cin >> preciouni;

			while (cin.fail()) {

				cout << "Por favor ingrese solo numeros: " << endl;

				cin.clear();

				cin.ignore();

				cin >> preciouni;

			}

			Precio = CT + (CT * .16);

			Citas[i].precioF = Precio;

			system("cls");

			InfoC = false;

			while (InfoC == false) {


				cout << endl << "A continuacion, se mostrara la informacion del articulo: " << endl << "Numero del articulo: " << NoC << endl << "Nombre del juego: " << NombreJ << endl;

				cout << "Año del lanzamiento: " << anos << endl << "clasificacion del juego: " << NT << endl << "caracteristicas del juego: " << DT << endl << "descripcion del videojuego: " << descrip << endl << "genero del videojuego: " << genero << endl;

				cout << "Precio unitario: " << preciouni << endl << "Precio por juego: " << CT << endl;

				cout << endl << "Precio final del articulo mas iva: " << Precio << "$ pesos." << endl << endl;

				cout << "Por favor, verifique que toda la informacion esta correcta, si desea modificar algo de esto por favor pulse \nalguno de estos botones: \n1: Nombre. \n2: Ano. \n3: Clasificacion. \n4: Caracteristicas. \n5: Genero. \n6: Descripcion. \n7: Precio. \n8: Precio Unitario. \n9: La informacion es correcta." << endl;

				cin >> N1;

				switch (N1) {

				case 1: cout << "Por favor introduzca el nombre del juego:" << endl;

					cin.ignore();

					getline(cin, NombreJ);

					NombreJ = ValidacionTXT(NombreJ);

					Citas[i].NombreJuego = NombreJ;

					system("cls");

					break;

				case 2:	cout << endl << "Por favor, ingrese el año de lanzamiento del juego." << endl;

					cout << endl << "Ano:" << endl;

					cin >> anos;

					while (cin.fail()) {

						cout << "Por favor ingrese solo numeros." << endl;

						cin.clear();

						cin.ignore();

						cin >> anos;

					}

					anos = ValidacionAno(anos);

					Citas[i].anos = anos;

					system("cls");

					break;

				case 3:cout << endl << "Por favor, introduzca la clasificacion del juego." << endl;

					cin.ignore();

					getline(cin, NT);

					NT = ValidacionTXT(NT);

					Citas[i].NombreT = NT;

					system("cls");

					break;

				case 4:cout << endl << "Por favor, introduzca las caracteristicas del juego: " << endl;

					cin.ignore();

					getline(cin, DT);

					DT = ValidacionTXT(DT);

					Citas[i].DT = DT;

					system("cls");

					break;

				case 5:cout << endl << "Por favor, introduzca el genero del juego: " << endl;

					cin.ignore();

					getline(cin, genero);

					genero = ValidacionTXT(genero);

					Citas[i].genero = genero;

					system("cls");

					break;

				case 6:cout << endl << "Por favor, de una corta descripcion del juego: " << endl;

					cin.ignore();

					getline(cin, descrip);

					descrip = ValidacionTXT(descrip);

					Citas[i].descrip = descrip;

					system("cls");

					break;

				case 7: cout << endl << "Por favor, introduzca el precio: " << endl;

					cin >> CT;

					if (cin.fail()) {

						cout << "Por favor ingrese solo numeros: " << endl;

						cin.clear();

						cin.ignore();

						cin >> CT;

						Citas[i].CT;

					} system("cls");

					break;

				case 8:cout << endl << "Por favor, introduzca el precio unitario (por pieza)" << endl;

					cin >> preciouni;

					while (cin.fail()) {

						cout << "Por favor solo ingrese numeros." << endl;

						cin.clear();

						cin.ignore();

						cin >> preciouni;

						Citas[i].preciouni;

					}

					Citas[i].CT;;

					Precio = CT + (CT * .16);

					Citas[i].precioF = Precio;

					system("cls");

					break;

				case 9: InfoC = true;

					cout << "La informacion ha sido guardada localmente, recuerde cerrar el programa aporpiadamente o la informacion no sera guardada.";

					Sleep(2000);

					system("cls");

					NoC = NoC + 1;

					break;

				default: cout << "Por favor introduzca una opcion correcta";

					break;

				}

			}

			break;

		case 2: //Modificar una cita

			cout << "Por favor, introduzca el numero de la cita a modificar, si no hay articulos y desea salir pulse 1." << endl;

			cin.clear();

			cin.ignore();

			for (i = w; i < NoC - 1; i++) {

				if (Citas[i].NumeroC == 0) {

					i = i + 1;

				}

				cout << "Numero de Articulo: " << Citas[i].NumeroC << endl << "Nombre del Juego:" << Citas[i].NombreJuego << endl << "Ano:" << Citas[i].anos << endl << "Clasificacion:" << Citas[i].NombreT << endl << "Caracteristicas:" << Citas[i].DT << endl << "Genero:" << Citas[i].genero << endl << "Descripcion:" << Citas[i].descrip << "Precio:" << Citas[i].precioF << "Precio unitario:" << Citas[i].preciouni << endl;

			}

			cin >> amod;

			if (amod > NoC - 1) {

				cout << "Por favor, introduzca una articulo valido: ";

				Sleep(1000);

				system("cls");

				return main();

			}

			i = amod - 1;

			InfoC = false;


			cout << endl << "A continuacion, se mostrara la informacion del articulo:" << endl << "Numero del articulo:" << NoC << endl << "Nombre del juego:" << NombreJ << endl;

			cout << "Año del lanzamiento:" << anos << endl << "clasificacion del juego:" << NT << endl << "caracteristicas del juego:" << DT << endl << "descripcion del videojuego:" << descrip << endl << "genero del videojuego:" << genero << endl;

			cout << "Precio unitario:" << preciouni << endl << "Precio por juego:" << CT << endl;

			cout << endl << "Precio final del articulo mas iva:" << Precio << "$ pesos." << endl << endl;

			cout << "Por favor, verifique que toda la informacion esta correcta, si desea modificar algo de esto por favor pulse \nalguno de estos botones: \n1: Nombre. \n2: Ano. \n3: Clasificacion. \n4: Caracteristicas. \n5: Genero. \n6: Descripcion. \n7: Precio. \n8: Precio Unitario. \n9: La informacion es correcta." << endl;

			cin >> N1;

			switch (N1) {

			case 1: cout << "Por favor introduzca el nombre del juego: " << endl;

				cin.ignore();

				getline(cin, NombreJ);

				NombreJ = ValidacionTXT(NombreJ);

				Citas[i].NombreJuego = NombreJ;

				system("cls");

				break;

			case 2:	cout << endl << "Por favor, ingrese el año de lanzamiento del juego: " << endl;

				cout << endl << "Ano:" << endl;

				cin >> anos;

				while (cin.fail()) {

					cout << "Por favor solo ingrese numeros." << endl;

					cin.clear();

					cin.ignore();

					cin >> anos;

				}

				anos = ValidacionAno(anos);

				Citas[i].anos = anos;

				system("cls");

				break;

			case 3:cout << endl << "Por favor, introduzca la clasificacion del juego: " << endl;

				cin.ignore();

				getline(cin, NT);

				NT = ValidacionTXT(NT);

				Citas[i].NombreT = NT;

				system("cls");

				break;

			case 4:cout << endl << "Por favor, introduzca las caracteristicas del juego: " << endl;

				cin.ignore();

				getline(cin, DT);

				DT = ValidacionTXT(DT);

				Citas[i].DT = DT;

				system("cls");

				break;

			case 5:cout << endl << "Por favor, introduzca el genero del juego: " << endl;

				cin.ignore();

				getline(cin, genero);

				genero = ValidacionTXT(genero);

				Citas[i].genero = genero;

				system("cls");

				break;

			case 6:cout << endl << "Por favor, de una corta descripcion del juego: " << endl;

				cin.ignore();

				getline(cin, descrip);

				descrip = ValidacionTXT(descrip);

				Citas[i].descrip = descrip;

				system("cls");

				break;

			case 7: cout << endl << "Por favor, introduzca el precio" << endl;

				cin >> CT;

				if (cin.fail()) {

					cout << "Por favor solo ingrese numeros." << endl;

					cin.clear();

					cin.ignore();

					cin >> CT;

					Citas[i].CT;

				} system("cls");

				break;

			case 8:cout << endl << "Por favor, introduzca el precio unitario (por pieza)" << endl;

				cin >> preciouni;

				while (cin.fail()) {

					cout << "Por favor solo ingrese numeros." << endl;

					cin.clear();

					cin.ignore();

					cin >> preciouni;

					Citas[i].preciouni;

				}

				Citas[i].CT;;

				Precio = CT + (CT * .16);

				Citas[i].precioF = Precio;

				system("cls");

				break;

			case 9: InfoC = true;

				cout << "La informacion ha sido guardada localmente, recuerde cerrar el programa aporpiadamente o la informacion no sera guardada.";

				Sleep(2000);

				system("cls");

				NoC = NoC + 1;

				break;

			case 10: InfoC = true;

				cout << "La informacion ha sido guardada localmente, recuerde cerrar el programa aporpiadamente o la informacion no sera guardada.";

				Sleep(2000);

				system("cls");

				break;

			default: cout << "Por favor introduzca una opcion correcta";

				break;

			}

			break;

		case 3: cin.clear();

			cin.ignore();

			cout << "Por favor, introduzca el numero de articulo a borrar, si desea salir pulse cualquier tecla ." << endl << endl;

			// para salir pulse cualquier tecla

			for (i = w; i < NoC - 1; i++) {

				if (Citas[i].NumeroC == 0) {

					i = i + 1;

				}

				cout << "Numero de Articulo: " << Citas[i].NumeroC << endl << "Nombre del Juego: " << Citas[i].NombreJuego << endl << "Ano: " << Citas[i].anos << endl << "Clasificacion:" << Citas[i].NombreT << endl << "Caracteristicas:" << Citas[i].DT << endl << "Genero: " << Citas[i].genero << endl << "Descripcion : " << Citas[i].descrip << "Precio:" << Citas[i].precioF << "Precio unitario:" << Citas[i].preciouni << endl;

				cin >> aborrar;

				system("cls");

				while (aborrar > NoC - 1) {

					cout << "Por favor, introduzca un articulo valido.";

					Sleep(1000);

					system("cls");

					return main();

				}for (i = aborrar - 1; i < NoC; i++) {

					Citas[i].NombreJuego = Citas[i + 1].NombreJuego;

					Citas[i].anos = Citas[i + 1].anos;

					Citas[i].NombreT = Citas[i + 1].NombreT;

					Citas[i].DT = Citas[i + 1].DT;

					Citas[i].genero = Citas[i + 1].genero;

					Citas[i].descrip = Citas[i + 1].descrip;

					Citas[i].NumeroC = Citas[i + 1].NumeroC - 1;

					if (Citas[i].NumeroC < 0) {

						Citas[i].NumeroC = 0;   // le agrega el valor de la cita anterior borrada

					}

					Citas[i].precioF = Citas[i + 1].precioF;

					Citas[i].preciouni = Citas[i + 1].preciouni;

					Citas[i + 1].NombreJuego = "0";

					Citas[i + 1].anos = 0;

					Citas[i + 1].NombreT = "0";

					Citas[i + 1].DT = "0";

					Citas[i + 1].genero = "0";

					Citas[i + 1].descrip = "0";

					Citas[i + 1].precioF = 0;

					Citas[i + 1].preciouni = 0;

				}cout << "La informacion ha sido borrada, volviendo al menu.";

				Sleep(2000);

				system("cls");

				NoC = NoC - 1;

				break;

		case 4://Opcion para mostrar las listas de articulos activas

			for (i = w; i < NoC - 1; i++) {

				if (Citas[i].NumeroC == 0) {

					i = i + 1;

				}

				cout << "Numero de Articulo: " << Citas[i].NumeroC << endl << "Nombre del Juego: " << Citas[i].NombreJuego << endl << "Ano: " << Citas[i].anos << endl << "Clasificacion:" << Citas[i].NombreT << endl << "Caracteristicas:" << Citas[i].DT << endl << "Genero: " << Citas[i].genero << endl << "Descripcion : " << Citas[i].descrip << "Precio:" << Citas[i].precioF << "Precio unitario:" << Citas[i].preciouni << endl;

			}

			system("pause");

			system("cls");

			break;

		case 5:system("cls"); //Opcion para limpiar la pantalla

			break;

		case 6: system("cls"); //Opcion para salir y guardar las articulos en el archivo de texto.

			cout << "Gracias por ordenar con la tienda Tevyat, guardando la informacion, por favor, no cierre el programa.";

			for (i = w; i < NoC - 1; i++) {

				{

					{

						ofstream citas("Tevyat.txt", ios::app); //ofstream abrir archivos en modo de lectura

						if (!citas) //modo, archivo de texto, binario, seleccioar el modo en que se va abrir el archivo

						{

							cout << "Error opening file" << endl;

						}

						citas << "Numero de Articulo: " << Citas[i].NumeroC << endl << "Nombre del Juego: " << Citas[i].NombreJuego << endl << "Ano: " << Citas[i].anos << endl << "Clasificacion:" << Citas[i].NombreT << endl << "Caracteristicas:" << Citas[i].DT << endl << "Genero: " << Citas[i].genero << endl << "Descripcion : " << Citas[i].descrip << endl << "Precio:" << Citas[i].precioF << endl << "Precio unitario:" << Citas[i].preciouni << endl << "NO MODIFICALBLE" << endl << endl;

					}

					{

						ofstream reader("Contador_articulos.txt");

						if (!reader)

						{

							cout << "Error opening file" << endl;

						}

						reader << NoC;

					}

				}

				Sleep(1500); //para que el programa se espere milisegundos

				S1 = false;

			}

			S1 = false; // el ciclo while termina aqui

			break;

		default: cout << "La opcion introducida es incorrecta, por favor introduzca una opcion valida." << endl;

			cin.clear();

			cin.ignore();

			Sleep(1200);

			system("cls");

			break;

			}

		}

	}

}