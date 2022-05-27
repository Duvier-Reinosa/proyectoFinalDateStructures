#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define aactual 2022
//señores, no dejen de estudiar .. reflexionen sobre lo que les estan pidiendo
typedef struct nodo{
	int indice;
	char titulo[20];
	char autor[20];
	char generoLiterario[20];
	int nPaginas;
	char editorial[20];
	char idioma[20];
	int dia,mes,anio;
	int precio;
	int cantidadDeEjemplares;
	char estado[7];
	struct nodo *siguiente;
}nodoL;

typedef nodoL *lista;

int venderLibro(){
	
}


//funcion para validar si ya hay datos iguales
//retorna 1 si: Todos los campos son iguales pero el estado es diferente o si todos los campos son diferentes y el estado es igual o diferente
//retorna 0 si: Todos los campos son iguales incluido el estado
//retorna 2 si: la lista esta vacia y no hay datos guardados para comparar
int comprobarEstado(lista milista,char titulo[], char autor[], char generoLiterario[], int nPaginas, char editorial[], char idioma[], int dia, int mes, int anio,int precio,int cantidadDeEjemplares,char estado[]){
	int bandera=0;
	if(milista==NULL){
		bandera=2;	
		return bandera;
	}else{
		while(milista!=NULL){
		if(strcasecmp(milista->titulo,titulo)==0 && strcasecmp(milista->autor,autor)==0 && strcasecmp(milista->generoLiterario,generoLiterario)==0
		 && milista->nPaginas==nPaginas && strcasecmp(milista->editorial,editorial)==0 && strcasecmp(milista->idioma,idioma)==0
		  && milista->dia==dia && milista->mes==mes && milista->anio==anio && milista->precio==precio && milista->cantidadDeEjemplares==cantidadDeEjemplares
		  	&& strcasecmp(milista->estado,estado)==0
		  ){
			  bandera=0;
			  return bandera;
		}
		else if(strcasecmp(milista->titulo,titulo)!=0 || strcasecmp(milista->autor,autor)!=0 || strcasecmp(milista->generoLiterario,generoLiterario)!=0
		 		||milista->nPaginas!=nPaginas || strcasecmp(milista->editorial,editorial)!=0 ||  strcasecmp(milista->idioma,idioma)!=0
				   || milista->dia!=dia ||milista->mes!=mes || milista->anio!=anio || milista->precio!=precio || milista->cantidadDeEjemplares!=cantidadDeEjemplares
		 			 || (strcasecmp(milista->estado,estado)==0 || strcasecmp(milista->estado,estado)!=0 )){
						  bandera=1;
						  return bandera;
					  }
		else if(strcasecmp(milista->titulo,titulo)==0 && strcasecmp(milista->autor,autor)==0 && strcasecmp(milista->generoLiterario,generoLiterario)==0
				 && milista->nPaginas==nPaginas && strcasecmp(milista->editorial,editorial)==0 && strcasecmp(milista->idioma,idioma)==0
		  			&& milista->dia==dia && milista->mes==mes && milista->anio==anio && milista->precio==precio && milista->cantidadDeEjemplares==cantidadDeEjemplares
		  				&& strcasecmp(milista->estado,estado)!=0){
							bandera=1;
							return bandera;
		}
		milista=milista->siguiente;
		}
	}
}

int validarFecha(int dia, int mes, int anio){//vallida fecha 
	int fecha_correcta=0;
	if(mes>=1 && mes<=12 && dia>=1 && dia <=31 && anio<=aactual){//si el mes esta entre 1 y 12, y ademas, año no supera al actual
		switch (mes)
		{
		case 1: fecha_correcta=1;
		break;
		case 2: if(anio % 4 ==0 && anio % 100 !=0 || anio%400 ==0){//caso de año bisiesto
					if(dia>=1 && dia <=29)//si es bisiesto, febrero tendra 29 dias
						fecha_correcta=1;
				}else if(dia>=1 && dia<=28)//si no es bisiesto, febrero tendra 28 dias
					fecha_correcta=1;
		break;
		case 3: fecha_correcta=1;
		break;
		case 4: fecha_correcta=1;
		break;
		break;
		case 5: fecha_correcta=1;
		break;
		case 6: fecha_correcta=1;
		break;
		case 7: fecha_correcta=1;
		break;
		case 8: fecha_correcta=1;
		break;
		case 9: fecha_correcta=1;
		break;
		case 10: fecha_correcta=1;
		break;
		case 11: if(dia>=1 && dia <=30)//noviembre tiene 30 dias
					fecha_correcta=1;
		break;
		case 12: if(dia>=1 && dia <=31)//diciembre tiene 31 dias
					fecha_correcta=1;
		break;
		}
	}
	return fecha_correcta;
}

void insertarLibro(lista *list,int indice,char *titulo,char *autor, char *generoLiterario, int nPaginas, char *editorial, char *idioma,int dia,int mes,int anio, char *estado, int precio, int cantidadDeEjemplares){
//	Nota 1: No puede haber libros repetidos con el mismo estado(nuevo o usado).
//	Nota 2: Las fechas deben estar validadas en el formato d�a/mes/a�o
		lista nodo; //crea nodo para enlazar
		nodo=(lista)malloc(sizeof(nodoL));// reserve memoria para ese nodo
		nodo->indice=indice;
		strcpy(nodo->titulo,titulo);
		strcpy(nodo->autor,autor);
		strcpy(nodo->generoLiterario,generoLiterario);
		nodo->nPaginas = nPaginas;
		strcpy(nodo->editorial,editorial);
		strcpy(nodo->idioma,idioma);
		strcpy(nodo->estado,estado);
		nodo->dia = dia;
		nodo->mes = mes;
		nodo->anio = anio;
		nodo->precio = precio;
		nodo->cantidadDeEjemplares = cantidadDeEjemplares;
		nodo->siguiente=*list; //apunta a la cabeza de la lista	
		*list=nodo; // milista recupera la cabeza		
}



int validarnum(char numero[]){//Valida si una cadena esta esta entre 0 y 9
    int i=0,tamanyo,bandera=0;
    tamanyo=strlen(numero);
    while(i<tamanyo && bandera==0){
        if(isdigit(numero[i])!=0){
            i++;
        }else{
            bandera=1;
        }
    }
    return bandera;
}

int validarcadena(char nombre[]){//Valida si una cadena esta entre la a-z o A-Z
    int i = 0, tamanyio, bandera = 0;
    tamanyio = strlen(nombre);
    while(i < tamanyio && bandera == 0) {
        if(isalpha(nombre[i]) != 0 || nombre[i]==32){
            i++;	
        }else{
            bandera = 1;
        }
    }
    return bandera;
}


void mostrarLibroCompleto(lista milista){//muestra libro completo
	if(milista==NULL){
		printf("lista vacia");
	}else{
		while (milista!=NULL){
			printf("\n\n");
			printf("\t\tIndice: ");
			printf("%d",milista->indice);
			printf("\n");
			printf("************************************************");
			printf("\n");
			printf("Titulo: ");
			printf("%s",milista->titulo);
			printf("\n");
			printf("************************************************");
			printf("\n");
			printf("Autor: ");
			printf("%s",milista->autor);
			printf("\n");
			printf("************************************************");
			printf("\n");
			printf("Genero literario: ");
			printf("%s",milista->generoLiterario);
			printf("\n");
			printf("************************************************");
			printf("\n");
			printf("numero de paginas: ");
			printf("%d", milista->nPaginas);
			printf("\n");
			printf("************************************************");
			printf("\n");
			printf("Editorial: ");
			printf("%s",milista->editorial);
			printf("\n");
			printf("************************************************");
			printf("\n");
			printf("Idioma: ");
			printf("%s",milista->idioma);
			printf("\n");
			printf("************************************************");
			printf("\n");
			printf("Dia: ");
			printf("%d",milista->dia);
			printf("\n");
			printf("************************************************");
			printf("\n");
			printf("Mes: ");
			printf("%d",milista->mes);
			printf("\n");
			printf("************************************************");
			printf("\n");
			printf("Año: ");
			printf("%d",milista->anio);
			printf("\n");
			printf("************************************************");
			printf("\n");
			printf("Precio: ");
			printf("%d", milista->precio);
			printf("\n");
			printf("************************************************");
			printf("\n");
			printf("Cantidad: ");
			printf("%d",milista->cantidadDeEjemplares);
			printf("\n");
			printf("************************************************");
			printf("\n");
			printf("Estado: ");
			printf("%s", milista->estado);
			printf("\n");
			milista=milista->siguiente;
		}
	}

}
void mostrarParteDeLibro(lista milista){//mostrar indice y titulo del libro para modificar libro
	while(milista != NULL){
		printf("************************************************");
		printf("\n\n");
		printf("\t\tIndice: ");
		printf("%d",milista->indice);
		printf("\n");
		printf("************************************************");
		printf("\n");
		printf("Titulo: ");
		printf("%s",milista->titulo);
		printf("\n");
		printf("************************************************");
		milista=milista->siguiente;
	}
}
void mostrarParaEliminar(lista milista){//mostrar indice y cantidad del libro para eliminar libro
		while(milista != NULL){
			if(milista->cantidadDeEjemplares==0){
				printf("************************************************");
				printf("\n\n");
				printf("\t\tIndice: ");
				printf("%d",milista->indice);
				printf("\n");
				printf("************************************************");
				printf("\n");
				printf("Titulo ");
				printf("%s",milista->titulo);
				printf("\n");
				printf("************************************************");
				printf("\n");
				printf("Cantidad ");
				printf("%d",milista->cantidadDeEjemplares);
				printf("\n");
				printf("************************************************");
			}else{
				printf("no hay ese libro");
			}
			milista=milista->siguiente;
		}	
}

void buscarTitulo(lista milista,char buscarTitulo[]){//muestra libro por titulo
	if(milista==NULL){
		printf("lista vacia");
	}else{
		while (milista!=NULL){	
			if(strcasecmp(milista->titulo,buscarTitulo)==0){
				printf("Libro encontrado");
				printf("\n\n");
				printf("\t\tIndice: ");
				printf("%d",milista->indice);
				printf("\n");
				printf("************************************************");
				printf("\n");
				printf("Titulo: ");
				printf("%s",milista->titulo);
				printf("\n");
				printf("************************************************");
				printf("\n");
				printf("Autor: ");
				printf("%s",milista->autor);
				printf("\n");
				printf("************************************************");
				printf("\n");
				printf("Genero literario: ");
				printf("%s",milista->generoLiterario);
				printf("\n");
				printf("************************************************");
				printf("\n");
				printf("numero de paginas: ");
				printf("%d", milista->nPaginas);
				printf("\n");
				printf("************************************************");
				printf("\n");
				printf("Editorial: ");
				printf("%s",milista->editorial);
				printf("\n");
				printf("************************************************");
				printf("\n");
				printf("Idioma: ");
				printf("%s",milista->idioma);
				printf("\n");
				printf("************************************************");
				printf("\n");
				printf("Dia: ");
				printf("%d",milista->dia);
				printf("\n");
				printf("************************************************");
				printf("\n");
				printf("Mes: ");
				printf("%d",milista->mes);
				printf("\n");
				printf("************************************************");
				printf("\n");
				printf("Año: ");
				printf("%d",milista->anio);
				printf("\n");
				printf("************************************************");
				printf("\n");
				printf("Precio: ");
				printf("%d", milista->precio);
				printf("\n");
				printf("************************************************");
				printf("\n");
				printf("Cantidad: ");
				printf("%d",milista->cantidadDeEjemplares);
				printf("\n");
				printf("************************************************");
				printf("\n");
				printf("Estado: ");
				printf("%s", milista->estado);
				printf("\n");
				printf("************************************************");
			}
		milista=milista->siguiente;
		}
	}
}

int comprobarIndice(lista milista, int indice){//si el indice coincide con el que el usuario ingresa 
	while(milista!=NULL){
		if(milista->indice==indice){
			return 1;
			break;
		}
		
	milista=milista->siguiente;
	}
	return 0;
}

void editarLibroCantidad(lista milista,int cantidad,int indicelibro){//modifica el campo cantidad de la estructura
	while(milista!=NULL){
		if(comprobarIndice(milista,indicelibro)==1){
			milista->cantidadDeEjemplares=cantidad;
			break;
		}
	milista=milista->siguiente;
	}
		
}
void editarLibroPrecio(lista milista,int cambiarprecio,int indicelibro){//modifique el campo precio de la estructura
	
	while(milista!=NULL){
		if(comprobarIndice(milista,indicelibro)==1){
			milista->precio=cambiarprecio;
			break;
		}
	milista=milista->siguiente;
	}
}

int comprobarEliminar(lista milista){
	while(milista!=NULL){
		if(milista->cantidadDeEjemplares==0){
			return milista->cantidadDeEjemplares;
		}
		milista=milista->siguiente;
	}
	return 0;
}

void eliminarLibro(lista *milista){//funcion para eliminar libro con existencia en 0
	lista anterior=NULL;
	lista primero=*milista;
	lista actual=primero;
	lista ultimo;
	int encontrado=0;

	if(primero!=NULL){
		while(actual!=NULL && encontrado!=1){
			if(actual->cantidadDeEjemplares==comprobarEliminar(*milista)){
				if(actual==primero){
					primero=primero->siguiente;
				}else if(actual==ultimo){
					anterior->siguiente=NULL;
					ultimo=anterior;
				}else{
					anterior->siguiente=actual->siguiente;
					}
				printf("libro eliminado:");
				encontrado=1;
			}
			anterior=actual;
			actual=actual->siguiente;
		}
		if(encontrado==0){
			printf("el libro no existe");
		}else{
			free(anterior);
		}
	}else{
		printf("inventario vacio");
	}
	
}
void imprimirMenu() {
	
	printf("****************SISTEMA DE VENTA DE LIBROS**************\n\n");
	printf("Seleccione una opcion con el indice[1, 2, 3...]\n\n");
	printf("1. Agregar Libro\n");
	printf("2. Editar libro\n");
	printf("3. Eliminar libro\n");
	printf("4. Buscar/imprimir libro\n");
	printf("5. vender libro\n");
	printf("6. Editar venta\n");
	printf("7. Eliminar Venta\n");
	printf("8. Imprimir factura\n");
	printf("9. Salir\n");
}

int main() {
	int indice=0,indiceAModificar,cambiarprecio,indicelibro,indiceAEliminar,opcionBuscar;
	int m = 0,guardarnum=0,npaginas=0,Dia,Mes,Anio,Precio=0,Cantidad=0,dia,mes,anio, cantidadEnInventario;
	char titulo[20],autor[20],generoLiterario[20],editorial[20],idioma[20],estado[7],nPaginas[20], precio[20], cantidad[20],buscartitulo[20];
	
	lista inventario;//esta lista es importante ya que ser� la cabeza global, para enviarse como parametro a las funciones
	inventario = NULL;//setea la cabeza
	while(m != 9){
		system("cls");
		imprimirMenu();
		scanf("%d", &m);
		switch(m){
			case 1: system("cls");
					printf("Ingrese libros a la lista, presione -1 para terminar: \n");
    				printf("ingrese titulo del libro:");
    				fflush(stdin);
					scanf("%[^\n]",&titulo);
					fflush(stdin);
					printf ("\n");
					guardarnum=atoi(titulo);
					while(validarcadena(titulo)!=0 && guardarnum!=-1){
						printf("ingrese titulo valido\n");
						fflush(stdin);
						scanf("%[^\n]",&titulo);
						fflush(stdin);
						guardarnum=atoi(titulo);
						printf("\n");
					}
					if(validarcadena(titulo)==0){
						printf("titulo valido...\n");
					}
					
					while(guardarnum!=-1){
						printf("ingrese autor: ");
						printf("\n");
						fflush(stdin);
						scanf("%[^\n]",&autor);
						fflush(stdin);
						printf("\n");
						while(validarcadena(autor)!=0){
							printf("ingrese un nombre de autor valido: ");
							fflush(stdin);
							scanf("%[^\n]",&autor);
							fflush(stdin);
							printf("\n");
						}
						if(validarcadena(autor)==0){
							printf("nombre valido...");
							printf("\n");
						}

						printf("ingrese genero literario:");
						fflush(stdin);
						scanf("%[^\n]",&generoLiterario);
						fflush(stdin);
						while(validarcadena(generoLiterario)!=0){
							printf("ingrese un genero literario valido: ");
							fflush(stdin);
							scanf("%[^\n]",&generoLiterario);
							fflush(stdin);
							printf("\n");
						}
						if(validarcadena(generoLiterario)==0){
							printf("genero literario valido...");
							printf("\n");
						}
						
						printf("ingrese el numero de paginas:");
						scanf("%s", &nPaginas);
						fflush(stdin);
						npaginas=atoi(nPaginas);
						while(validarnum(nPaginas)!=0){
							printf("ingrese un numero valido: ");
							scanf("%s",&nPaginas);
							npaginas=atoi(nPaginas);
							printf("\n");
						}
						if(validarnum(nPaginas)==0){
							printf("numero valido...");
							printf("\n");
						}
						
						printf("ingrese editorial:");
						fflush(stdin);
						scanf("%[^\n]",&editorial);
						fflush(stdin);
						while(validarcadena(editorial)!=0){
							printf("ingrese la editorial valida: ");
							fflush(stdin);
							scanf("%[^\n]",&editorial);
							fflush(stdin);
							printf("\n");
						}
						if(validarcadena(editorial)==0){
							printf("editorial valida...");
							printf("\n");
						}

						printf("ingrese idioma del libro:");
						fflush(stdin);
						scanf("%[^\n]",&idioma);
						fflush(stdin);
						while(validarcadena(idioma)!=0){
							printf("ingrese idioma valido: ");
							fflush(stdin);
							scanf("%[^\n]",&idioma);
							fflush(stdin);
							printf("\n");
						}
						if(validarcadena(idioma)==0){
							printf("idioma valido...");
							printf("\n");
						}
						printf("ingrese dia de publicacion: ");
						scanf("%d",&dia);
						printf("\n");
						printf("ingrese mes de publicacion: ");
						scanf("%d",&mes);
						fflush(stdin);
						printf("\n");
						printf("ingrese año de publicacion: ");
						scanf("%d",&anio);
						fflush(stdin);
						printf("\n");
						while(validarFecha(dia,mes,anio)==0){
							printf("ingrese fecha valida: ");
							printf("\n");
							printf("ingrese dia de publicacion: ");
							scanf("%d",&dia);
							printf("\n");
							printf("ingrese mes de publicacion: ");
							scanf("%d",&mes);
							printf("\n");
							printf("ingrese año de publicacion: ");
							scanf("%d",&anio);
							printf("\n");
						}
						if(validarFecha(dia,mes,anio)==1){
							printf("fecha correcta\n");
						}
						
						fflush(stdin);
						printf("ingrese el precio del libro:");
						scanf("%s", &precio);
						fflush(stdin);
						Precio=atoi(precio);
						while(validarnum(precio)!=0){
							printf("ingrese un numero valido: ");
							scanf("%s",&precio);
							Precio=atoi(precio);
							printf("\n");
						}
						if(validarnum(precio)==0){
							printf("numero valido...");
							printf("\n");
						}

						fflush(stdin);
						printf("ingrese la cantidad de libros:");
						scanf("%s", &cantidad);
						Cantidad=atoi(cantidad);
						while(validarnum(cantidad)!=0){
							printf("ingrese un numero valido: ");
							scanf("%s",&cantidad);
							Cantidad=atoi(cantidad);
							printf("\n");
						}
						if(validarnum(cantidad)==0){
							printf("numero valido...");
							printf("\n");
						}
							
					printf("ingrese estado del libro: 'nuevo' o 'usado' : ");
						fflush(stdin);
						scanf("%[^\n]",&estado);
						fflush(stdin);
						while(validarcadena(estado)!=0){
							printf("escriba solo 'nuevo' o 'usado' ");
							printf("\n");
							fflush(stdin);
							scanf("%[^\n]",&estado);
							fflush(stdin);
							printf("\n");
						}
						if(validarcadena(estado)==0){
							printf("estado valido...");
							printf("\n");
						}
						
						system("cls");

						if(comprobarEstado(inventario,titulo,autor,generoLiterario,npaginas,editorial,idioma,dia,mes,anio,Precio,Cantidad,estado)==2){
							indice++;
							insertarLibro(&inventario,indice,titulo,autor,generoLiterario,npaginas,editorial,idioma,dia,mes,anio,estado,Precio,Cantidad);
						}else if(comprobarEstado(inventario,titulo,autor,generoLiterario,npaginas,editorial,idioma,dia,mes,anio,Precio,Cantidad,estado)==1){
							indice++;
							insertarLibro(&inventario,indice,titulo,autor,generoLiterario,npaginas,editorial,idioma,dia,mes,anio,estado,Precio,Cantidad);
						}else{
							printf("no se puede ingresar los datos\n");
						}

							printf("Ingrese libros a la lista, presione -1 para terminar: \n");
		    				printf("ingrese titulo del libro:");
		    				fflush(stdin);
							scanf("%[^\n]",&titulo);
							fflush(stdin);
							printf ("\n");
							guardarnum=atoi(titulo);
							while(validarcadena(titulo)!=0 && guardarnum!=-1){
								printf("ingrese titulo valido\n");
								fflush(stdin);
								scanf("%[^\n]",&titulo);
								fflush(stdin);
								guardarnum=atoi(titulo);
								printf("\n");
							}
							if(validarcadena(titulo)==0){
								printf("titulo valido...\n");
							}
					}
			break;
		case 2: system("cls");
				mostrarLibroCompleto(inventario);
				printf("\n");
				printf("seleccione el indice del libro que desea modificar ");
				scanf("%d",&indicelibro);
				if(comprobarIndice(inventario,indicelibro)==1){
					printf("Que desea modificar: (1) cantidad de existencia (2)precio unitario");
					printf("\n");
					scanf("%d",&indiceAModificar);
					if(indiceAModificar==1){	
						printf("ingrese nueva cantidad en inventario");
						printf("\n");
						scanf("%d",&cantidadEnInventario);
						editarLibroCantidad(inventario,cantidadEnInventario,indicelibro);
						printf("cantidad actualizado.");
					}else if(indiceAModificar==2){
							printf("ingrese nuevo precio unitario");
							printf("\n");
							scanf("%d",&cambiarprecio);
							editarLibroPrecio(inventario,cambiarprecio,indicelibro); 	
							printf("precio actualizado.");
					}
				}else if (comprobarIndice(inventario,indicelibro)==0) {
					printf("no existe el libro indicado");
				}
		break;
		
		case 3: system("cls");
				mostrarParaEliminar(inventario);
				if(inventario!=NULL){
					printf("\n");
					printf("(Solo se muestran los libros que se pueden eliminar)\n");
					printf("Que libro desea eliminar? Ingrese el indice: ");
					printf("\n");
					scanf("%d",&indiceAEliminar);
					if(comprobarIndice(inventario,indiceAEliminar)==1){
						eliminarLibro(&inventario);				
					}else{
						printf("no existe el libro");
					}
				}else{
					printf("lista vacia");
				}
		break;
		
		case 4: system("cls");
				printf("Como desea  buscar?");
				printf("\n");
				printf("1. Buscar por titulo\n");
				printf("2. Buscar por autor\n");
				printf("3. Buscar por estado (nuevo o usado)\n");
				printf("4. Buscar por rango de precios\n");	
				printf("escriba 1,2,3 o 4");
				printf("\n");
				scanf("%d",&opcionBuscar);
				switch(opcionBuscar){
					case 1: system ("cls");
							printf("ingrese el titulo que desea buscar: ");
							scanf("%s",&buscartitulo);
							fflush(stdin);
							buscarTitulo(inventario,buscartitulo);		
					break;
				}
				
		break;
		case 5: break;
		case 6: break;
		case 7: break;
		case 8: break;
		case 9: system("cls");
				return 0;
				break;
	}
			printf("\n");
		  	printf("ingrese el numero 10 para volver al menu principal: ");
  			scanf("%d",&m); 
	}
}
