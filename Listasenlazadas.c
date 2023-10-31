#include <stdio.h>
#include <stdlib.h>

// Declaracion de la estructura del nodo.

typedef struct Node {
    int data;
    struct Node *next;
} Node;


// Función encargada de agregar un nodo al final de la lista.

void addNode() {

    Node *newNode = (Node *)malloc(sizeof(Node));  // Se reserva espacio en memoria y asigna la dirección al puntero newNode
    newNode->data = value; // Se asigna un valor a la variable data del Nodo
    newNode->next = NULL;

// Estas estructuras de control se encargan de insertar el nodo al final de la lista enlazada
    if (*head == NULL) {  // Si la lista está vacía el nuevo nodo se convierte en el primer nodo
        *head = newNode;
    } else {   // Sino se enlaza el nuevo nodo al último nodo
        Node *current = *head; 
        while (current->next != NULL) {  // Recorre la lista hasta que Current apunte al ultimo nodo
            current = current->next;
        }
        current->next = newNode;
    }    
}

// Función encargarda de eliminar nodos.

void deleteNode() {




}


// Función encargada de  agregar un nodo al inicio de la lista

void addToFront(){


}


// Función encargada de imprimir la lista
void printList() {


}


// Función encargada de obtener el elemento enésimo
void getElementAt() {


}


// Función encargada de liberar la memoria de la lista.
void freeList() {



}


// Función main. Encargada de llamar la demas funciones.
int main() {


}
