#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct nodo{
	char titulo[20];
	char autor[20];
	char fechaDeFabricacion[20];
	char generoLiterario[20];
	int nPaginas[20];
	char editorial[20];
	char idioma[20];
	char fechaDePublicacion[20];
	int estado;
	int precio;
	int cantidadDeEjemplares;
	struct nodo *sig;
}nodoL;

typedef nodoL *lista;

char ingresaTexto() {
	char texto[20];
	int flag = 0;
	
	while(flag != 1){
		scanf("%s", texto);
		if(strlen(texto) > 0){
			flag = 1;
		} else {
			flag = 0;
			printf("******Texto Invalido******");
		}
	}
	
	return *texto;
}

void insertarLibro(lista *list,char *titulo){
//	Nota 1: No puede haber libros repetidos con el mismo estado(nuevo o usado).
//	Nota 2: Las fechas deben estar validadas en el formato d�a/mes/a�o
	lista nodo; //crea nodo para enlazar
	nodo=(lista)malloc(sizeof(nodoL));// reserve memoria para ese nodo
	strcpy(nodo->titulo,titulo);
	
	
	nodo->sig=*list; //apunta a la cabeza de la lista
	*list=nodo; // milista recupera la cabeza
}


void menu() {
	printf("1. Agregar Libro");
	printf("2. Editar libro");
	printf("3. Eliminar libro");
	printf("4. Buscar/imprimir libro");
	printf("5. vender libro");
	printf("6. Editar venta");
	printf("7. Eliminar Venta");
	printf("8. Imprimir factura");
	printf("9. Salir");
}

int main() {
	ingresaTexto();
}
