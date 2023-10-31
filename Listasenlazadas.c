#include <stdio.h>
#include <stdlib.h>

// Declaracion de la estructura del nodo.
typedef struct Node {
    int data;
    struct Node *next;
} Node;


// Función encargada de agregar un nodo al final de la lista.
void addNode(Node **head, int value) {

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
void deleteNode(Node **head, int value) {

    Node *current = *head;
    Node *prev = NULL;

    while (current != NULL && current->data != value) {  // Mientras Current no sea Null y el valor de data sea igual a Value
        prev = current;    
        current = current->next; // Manda a current al siguiente nodo en la lista
    }

    if (current == NULL) {
        printf("El valor %d no se encontró en la lista.\n", value);
        return;
    }

// Estas estructuras de control son las encargadas de eliminar un nodo específico de la lista en función de la posicion
    if (prev == NULL) {
        *head = current->next;  
    } else {
        prev->next = current->next;
    }

    free(current);   // Libera la memoria empleada para el nodo
}


// Función encargada de  agregar un nodo al inicio de la lista
void addToFront(Node **head, int value) {

    Node *newNode = (Node *)malloc(sizeof(Node));  // Se reserva la memoria para el nuevo nodo
    newNode->data = value; // Se establece un valor para el nuevo nodo
    newNode->next = *head;
    *head = newNode;  // Actualiza el puntero para que apunte a otro nodo
}


// Función encargada de imprimir la lista
void printList(Node *head) {

    Node *current = head;
    while (current != NULL) {   // Recorre la lista mientras Current no sea Null
        printf("%d -> ", current->data);  // Imprime  el valor del  nodo actual
        current = current->next;
    }
    printf("NULL\n");
}

// Función esta encargada de  buscar un nodos dependiendo del valor
void searchNode(Node *head, int value) {

    Node *current = head;
// En esta parte busca un valor de la lista  mientras se recorre la lista nodo por nodo
    while (current != NULL) { 
        if (current->data == value) {  // Si se encuentra el valor se imprime un mensaje indicando que se ha encontrado
            printf("El valor %d se encuentra en la lista.\n", value);
            return; 
        }
        current = current->next;
    }
    printf("El valor %d no se encuentra en la lista.\n", value);
}


// Función encargada de obtener el elemento enesimo 
void getElementAt(Node *head, int index) {

    Node *current = head;
    int currentIndex = 0;
    while (current != NULL && currentIndex) {   // Este bucle se ejecuta hasta que se alcanza el índice deseado o hasta llegar al final de la lista 
        current = current->next;
        currentIndex++;
    }

    if (current == NULL) {
        printf("El elemento en el índice %d no existe en la lista.\n", index);
    } else {
        printf("Elemento en el índice %d: %d\n", index, current->data);
    }
}


// Función encargada de liberar la memoria de la lista.
void freeList(Node *head) {

    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}


// Función main. Encargada de llamar la demas funciones.
int main() {

    Node *head = NULL;

// En esta parte se llama la funcion addNode y se establecen los numeros de la lista inicial. (1, 2, 3).

    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);

    printf("Lista inicial:\n");
    printList(head);

// Se llama a la funcion addToFront y se establece un nuevo nodo al inicio de la lista.

    addToFront(&head, 0);
    printf("Lista después de agregar un nodo al inicio:\n");
    printList(head);

// En esta parte se llama a la funcion addNNode y se establece un nuevo nodo al final de la lista. 

    addNode(&head, 4);
    printf("Lista después de agregar un nodo al final:\n");
    printList(head);

// En esta seccion

    searchNode(head, 3);
    searchNode(head, 5);

// En esta seccion se declaran los elementos enesimos mediante la funcion getElementAt.

    getElementAt(head, 2);
    getElementAt(head, 5);

// En esta parte se llama a la funcion deleteNode para eliminar nodos. 

    deleteNode(&head, 2);
    printf("Lista después de eliminar un nodo por valor:\n");
    printList(head);

    freeList(head); // Liberar la memoria al final del programa

    return 0;
}
