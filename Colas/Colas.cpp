// Colas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct Nodo {
	int dat;
	Nodo *next;
};

void add_queue(Nodo*&, Nodo*&, int);
void del_queue(Nodo*&, Nodo*&, int&);
void display_queue(Nodo*&);
bool empty_queue(Nodo*);

void menu();

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
			 system("pause");
			break;
		 case 2://Eliminar elemento de la cola
			 cout << "\nEliminando datos de la cola:\n";
			 while (front != NULL)//Mientras la cola no este vacia
			 {
				del_queue(front,back, dat);//Llama a la funcion que me permite eliminar todos los elementos de la cola

				 if (front != NULL) 
				 {
					 cout << dat << ",";
				 }
				 else
				 {
					 cout << dat << ".";
				 }
			 }
			 system("pause");
			break;
		 case 3://Mostrar los elementos que contiene la cola
			 if (empty_queue(front))//si la cola esta vacia
			 {
				 cout << "La cola esta vacia\n";
			 }
			 else
			 {
				 cout << "Los numeros que estan en la pila son: \n";
				 display_queue(front);//Llama a la funcion que me permite mostrar los elementos que tiene la cola.
				 
			 }
			 system("pause");
			break;
		 case 4:
			 break;
		 default:
			 cout << "Ingreso una opcion erronea, por favor intente nuevamente...\n";
			 system("pause");
				break;
		}
		system("cls");

	} while (op != 4);

}

//Funcion que me permite agregar elementos a la cola
void add_queue(Nodo*& front, Nodo*& back, int n) {
	Nodo* nuevo_nodo = new Nodo();//Crea el espacio en memoria para almacenar un nodo
	nuevo_nodo->dat = n;//Carga el valor dentro del nodo(dat)
	nuevo_nodo->next = NULL;

	if (empty_queue(front))
	{
		front = nuevo_nodo;
	}
	else
	{
		back->next = nuevo_nodo;
	}
	back = nuevo_nodo;

	cout << "\nInsertando elemento a la cola...\n";
}

//Funcion que me permite saber si la cola esta vacia
bool empty_queue(Nodo* front) {
	return(front == NULL) ? true : false;//
}

//Funcion que me permite eliminar todos los elementos de la cola
void del_queue(Nodo*& front, Nodo*& back, int& n) {
	n = front->dat;
	Nodo* aux = front;

	if (front == back)
	{
		front = NULL;
		back = NULL;
	}
	else
	{
		front = front->next;
	}
	delete aux;
}

//Funcion que me permite mostrar todos los elementos de la cola
void display_queue(Nodo*&front) {
	Nodo* aux = front;
	while (aux!= NULL)
	{
		cout << aux->dat << " ";
		aux= aux->next;
	}
	cout << endl;
}



