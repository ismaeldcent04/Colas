// Hecho por:
//      Alex        Bujosa          1098913
//      Jerry       Rivas           1089317
//      Sebastian   Henriquez       1101507
//      Ismael      Dicent          1100368
//      Steven      Martinez        1101817
//Realizar un programa en c++ plus que inserte y elimine elementos a una cola

#include <iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;
//Creando la estructura nodo 
struct Nodo {
	int dat;
	Nodo *next;
};

void add_queue(Nodo*&, Nodo*&, int);//Creando prototipo de la funcion 
void del_queue(Nodo*&, Nodo*&, int&);//Creando prototipo de la funcion 
void display_queue(Nodo*&);//Creando prototipo de la funcion 
bool empty_queue(Nodo*);//Creando prototipo de la funcion 
void menu();//Creando prototipo de la funcion 

int main()
{
	menu();
}

//Funcion que me permite crear un menu
void menu() {
	Nodo* front = NULL;//Declarando el nodo del frente
	Nodo* back = NULL;//Declarando el nodo de atras
	int op;
	int dat;

	do
	{
		cout << "\t.:MENU:.\n";
		cout << "1.Insertar un elemento en la cola" << endl;
		cout << "2.Eliminar los elementos de la cola" << endl;
		cout << "3.Mostrarlos elementos de la cola" << endl;
		cout << "4.Salir"<<endl;
		
		cout << "\nIngrese la opcion de su preferencia:";
		cin >> op; 

		switch (op)
		{
		 case 1://Agregar elemento a la cola
			 cout << "Digite un numero:";
			 cin >> dat;
			 add_queue(front, back, dat);//llamando a la funcion que me permite agregar un elemento a la cola, tomando tres parametros el nodo del frente, el de atras y el dato a insertar.
			 system("pause");//Pausa el programa hasta que presiones una tecla
			break;
		 case 2://Eliminar elemento de la cola
			 cout << "\nEliminando datos de la cola:\n";
			 while (front != NULL)//Mientras la cola no este vacia
			 {
				del_queue(front,back, dat);//Llama a la funcion que me permite eliminar todos los elementos de la cola

				 if (front != NULL)// En caso de que haya mas de un elemento
				 {
					 cout << dat << ",";//Muestra los elementos eliminados separados en coma
				 }
				 else// si no 
				 {
					 cout << dat << ".";//Muestra el elemento eliminado seguido de un punto
				 }
			 }
			 system("pause");//Pausa el programa hasta que presiones una tecla
			break;
		 case 3://Mostrar los elementos que contiene la cola
			 if (empty_queue(front))//si la cola esta vacia
			 {
				 cout << "La cola esta vacia\n";
			 }
			 else//si no
			 {
				 cout << "Los numeros que estan en la pila son: \n";
				 display_queue(front);//Llama a la funcion que me permite mostrar los elementos que tiene la cola.
				 
			 }
			 system("pause");//Pausa el programa hasta que presiones una tecla
			break;
		 case 4:
			 break;
		 default:
			 cout << "Ingreso una opcion erronea, por favor intente nuevamente...\n";
			 system("pause");//Pausa el programa hasta que presiones una tecla
				break;
		}
		system("cls");//Limpia la pantalla

	} while (op != 4);//Mientras el usuario eliga una opcion diferente de 4 ejecuta todo  el codigo anterior

}

//Funcion que me permite agregar elementos a la cola
void add_queue(Nodo*& front, Nodo*& back, int n) {
	Nodo* nuevo_nodo = new Nodo();//Crea el espacio en memoria para almacenar un nodo
	nuevo_nodo->dat = n;//Asignamos nuevo nodo al dato que queremos insertar dentro de la cola
	nuevo_nodo->next = NULL;//Asignamos Null al nodo siguiente

	if (empty_queue(front))// Si la cola solo tiene un nodo
	{
		front = nuevo_nodo; //asigna el frente al ultimo nodo que en este caso seria el unico
	}
	else//si no
	{
		back->next = nuevo_nodo;// asignamos el nodo back a nuevo nodo asegurandonos de que el nodo back siempre señale al ultimo elemento de la cola
	}
	back = nuevo_nodo;//Asignamos el nodo back al ultimo nodo de la cola

	cout << "\nInsertando elemento a la cola...\n";
}

//Funcion que me permite saber si la cola esta vacia
bool empty_queue(Nodo* front) {
	return(front == NULL) ? true : false;//si la cola esta vacia retorna true y si no esta vacia retorna false
}

//Funcion que me permite eliminar todos los elementos de la cola
void del_queue(Nodo*& front, Nodo*& back, int& n) {
	n = front->dat;//Seleccionamos el dato que queremos eliminar
	Nodo* aux = front;// creamos un nodo auxiliar y le asignamos el frente de la cola

	if (front == back)//si el nodo de atras y nodo de frente de la cola son iguales significa que solo hay un elemento en la cola
	{
		front = NULL;//Asignamos el frente de la cola a NULL
		back = NULL;// Asignamos la parte de atras de la cola a NULL
	}
	else//si no 
	{
		front = front->next;//Asignamos el frente de la cola al nodo siguiente
	}
	delete aux;//Eliminamos el elemento de la cola 
}

//Funcion que me permite mostrar todos los elementos de la cola
void display_queue(Nodo*&front) {
	Nodo* aux = front;// Asignamos el nodo aux al frente de la cola
	while (aux!= NULL)//Mientras hayan elementos dentro de la cola
	{
		cout << aux->dat << " ";//Mostramos el elemento de la cola
		aux= aux->next;//Asignamos el nodo aux al siguiente elemento de la cola
	}
	cout << endl;
}



