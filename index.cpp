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


//funcion para validar si ya hay datos iguales
//retorna 1 si: Todos los campos son iguales pero el estado es diferente o si todos los campos son diferentes y el estado es igual o diferente
//retorna 0 si: Todos los campos son iguales incluido el estado
int comprobarEstado(lista milista,char titulo[], char autor[], char generoLiterario[], int nPaginas, char editorial[], char idioma[], int dia, int mes, int anio,int precio,int cantidadDeEjemplares,char estado[]){
	int bandera=0;
	while(milista!=NULL){
		if(strcmp(milista->titulo,titulo)==0 && strcmp(milista->autor,autor)==0 && strcmp(milista->generoLiterario,generoLiterario)==0
		 && milista->nPaginas==nPaginas && strcmp(milista->editorial,editorial)==0 && strcmp(milista->idioma,idioma)==0
		  && milista->dia==dia && milista->mes==mes && milista->anio==anio && milista->precio==precio && milista->cantidadDeEjemplares==cantidadDeEjemplares
		  	&& strcmp(milista->estado,estado)==0
		  ){
			  bandera=0;
			  return bandera;
		}else if(strcmp(milista->titulo,titulo)!=0 && strcmp(milista->autor,autor)!=0 && strcmp(milista->generoLiterario,generoLiterario)!=0
		 		&& milista->nPaginas!=nPaginas && strcmp(milista->editorial,editorial)!=0 && strcmp(milista->idioma,idioma)!=0
				  && milista->dia!=dia && milista->mes!=mes && milista->anio!=anio && milista->precio!=precio && milista->cantidadDeEjemplares!=cantidadDeEjemplares
		 			 && strcmp(milista->estado,estado)==0 || strcmp(milista->estado,estado)!=0 ){
						  bandera=1;
						  return bandera;
					  }
		else if(strcmp(milista->titulo,titulo)==0 && strcmp(milista->autor,autor)==0 && strcmp(milista->generoLiterario,generoLiterario)==0
				 && milista->nPaginas==nPaginas && strcmp(milista->editorial,editorial)==0 && strcmp(milista->idioma,idioma)==0
		  			&& milista->dia==dia && milista->mes==mes && milista->anio==anio && milista->precio==precio && milista->cantidadDeEjemplares==cantidadDeEjemplares
		  				&& strcmp(milista->estado,estado)!=0){
							bandera=1;
							return bandera;
		}
		milista=milista->siguiente;
	}
	return bandera;
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
int validarnum(char numero[]){//Valida si una cadena es numeroisdigit !=0 es numero, si es 0 es cadena
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

int validarcadena(char nombre[]){//Valida si una cadena es cadena isalpha !=0 es cadena, si no, es numero
    int i = 0, tamanyio, bandera = 0;
    tamanyio = strlen(nombre);
    while(i < tamanyio && bandera == 0) {
        if(isalpha(nombre[i]) != 0){
            i++;
        }else{
            bandera = 1;
        }
    }
    return bandera;
}


void mostrarLibroCompleto(lista milista){//muestra libro completo
	while (milista!=NULL)
	{
		printf("************************************************");
		printf("\n");
		printf("Indice: ");
		printf("%d",milista->indice);
		printf("\n");
		printf("************************************************");
		printf("\n");
		printf("Titulo: ");
		printf("%s",&milista->titulo);
		printf("\n");
		printf("************************************************");
		printf("************************************************");
		printf("\n");
		printf("Autor: ");
		printf("%s",&milista->autor);
		printf("\n");
		printf("************************************************");
		printf("\n");
		printf("Genero literario: ");
		printf("%s",&milista->generoLiterario);
		printf("\n");
		printf("************************************************");
		printf("\n");
		printf("numero de paginas: ");
		printf("%d", milista->nPaginas);
		printf("\n");
		printf("************************************************");
		printf("\n");
		printf("Editorial: ");
		printf("%s",&milista->editorial);
		printf("\n");
		printf("************************************************");
		printf("\n");
		printf("Idioma: ");
		printf("%s",&milista->idioma);
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
		printf("%s", &milista->estado);
		printf("\n");
		milista=milista->siguiente;
	}

}
void mostrarParteDeLibro(lista milista){//mostrar indice y titulo del libro para modificar libro
	while (milista!=NULL)
	{
		printf("************************************************");
		printf("\n");
		printf("Indice: ");
		printf("%d",milista->indice);
		printf("\n");
		printf("************************************************");
		printf("\n");
		printf("Titulo: ");
		printf("%s",&milista->titulo);
		printf("\n");
		printf("************************************************");
		milista=milista->siguiente;
	}	
}

int comprobarIndice(lista milista, int indice){//si el indice coincide con el que el usuario ingresa 
	while(milista!=NULL){
		if(milista->indice==indice){
			return 1;
		}
	milista=milista->siguiente;
	}
	return 0;
}

int opcionDeEditar(lista milista, int mod){//opcion para editar precio o cantidad
	if(mod==1){
		return 1;
	}else if(mod==2){
		return 2;
	}
    return 0; 
}
int editarLibroCantidad(lista milista,int cantidad){//modifica el campo cantidad de la estructura
	while(milista!=NULL){
			milista->cantidadDeEjemplares=cantidad;
			return 1;
		milista=milista->siguiente;
	}
	return 0;
}
int editarLibroPrecio(lista milista,int cambiarprecio){//modifique el campo precio de la estructura
	while(milista!=NULL){
			milista->precio=cambiarprecio;
			return 1;
		milista=milista->siguiente;
	}
	return 0;
}
void imprimirMenu() {
	printf("****************SISTEMA DE VENTA DE LIBROS**************\n\n");
	printf("Seleccione una opci�n con el indice[1, 2, 3...]\n\n");
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
	int indice=0,opcionglobal=0,mod,cantidad,cambiarprecio,indicelibro;
	int m = 0,nPaginas,precio,cantidadDeEjemplares,guardarnum=0,dia,mes,anio;
	char titulo[20],autor[20],generoLiterario[20],editorial[20],idioma[20],estado[7];
	
	lista inventario;//esta lista es importante ya que ser� la cabeza global, para enviarse como parametro a las funciones
	while(m != 9){
		system("cls");
		imprimirMenu();
		scanf("%d", &m);
		switch(m){
			case 1: system("cls");
					printf("Ingrese libros a la lista, presione -1 para terminar: \n");
    				printf("ingrese titulo del libro:");
					scanf("%s",&titulo);
					printf ("\n");
					guardarnum=atoi(titulo);
					while(validarcadena(titulo)!=0 && guardarnum!=-1){
						printf("ingrese titulo valido\n");
						scanf("%s",&titulo);
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
						scanf("%s",&autor);
						fflush(stdin);
						printf("\n");
						while(validarcadena(autor)!=0){
							printf("ingrese un nombre de autor valido: ");
							scanf("%s",&autor);
							printf("\n");
						}
						if(validarcadena(autor)==0){
							printf("nombre valido...");
							printf("\n");
						}

						printf("ingrese genero literario:");
						scanf("%s",&generoLiterario);
						fflush(stdin);
						while(validarcadena(generoLiterario)!=0){
							printf("ingrese un genero literario valido: ");
							scanf("%s",&generoLiterario);
							printf("\n");
						}
						if(validarcadena(generoLiterario)==0){
							printf("genero literario valido...");
							printf("\n");
						}
							printf("ingrese el numero de paginas:");
							scanf("%i", &nPaginas);

						printf("ingrese editorial:");
						scanf("%s",&editorial);
						fflush(stdin);
						while(validarcadena(editorial)!=0){
							printf("ingrese la editorial valida: ");
							scanf("%s",&editorial);
							printf("\n");
						}
						if(validarcadena(editorial)==0){
							printf("editorial valida...");
							printf("\n");
						}

						printf("ingrese idioma del libro:");
						scanf("%s",&idioma);
						fflush(stdin);
						while(validarcadena(idioma)!=0){
							printf("ingrese idioma valido: ");
							scanf("%s",&idioma);
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

						printf("\n");
						printf("ingrese el precio del libro: ");
						scanf("%d",&precio);
						printf("\n");

						printf("\n");
						printf("ingrese cantidad de libros: ");
						scanf("%d",&cantidadDeEjemplares);
						printf("\n");
						
						printf("ingrese estado del libro: 'nuevo' o 'usado' : ");
						scanf("%s",&estado);
							
							//while(strcmp(estado,nuevo)!=0)
						

						if(comprobarEstado(inventario,titulo,autor,generoLiterario,nPaginas,editorial,idioma,dia,mes,anio,precio,cantidadDeEjemplares,estado)==1){
							indice++;
							insertarLibro(&inventario,indice,titulo,autor,generoLiterario,nPaginas,editorial,idioma,dia,mes,anio,estado,precio,cantidadDeEjemplares);
						}else{
							printf("no se puede ingresar los datos");
						}
						system("cls");
						printf("\n");
						printf("ingrese mas libros, con -1 termina...");
						printf("\n");
						printf("ingrese titulo del libro:");
						scanf("%s",&titulo);
						guardarnum=atoi(titulo);
							while(validarcadena(titulo)!=0 && guardarnum!=-1){
								printf("ingrese titulo valido\n");
								scanf("%s",&titulo);
								guardarnum=atoi(titulo);
								printf("\n");
							}
								if(validarcadena(titulo)==0){
									printf("titulo valido...\n");
								}
					}
			break;
		case 2: system("cls");
				mostrarParteDeLibro(inventario);
				printf("\n");
				printf("seleccione el indice del libro que desea modificar ");
				printf("\n");
				scanf("%d",&indicelibro);
				if(comprobarIndice(inventario,indicelibro)==1){
					printf("Qué desea modificar: (1) cantidad de existencia (2)precio unitario");
					printf("\n");
					scanf("%d",&mod);
					if(opcionDeEditar(inventario,mod)==1){
							printf("ingrese nueva cantidad en inventario");
							printf("\n");
							scanf("%d",&cantidad);
							if(editarLibroCantidad(inventario,cantidad)==1){
								printf("cantidad actualizada");
							}
							
					}else if(opcionDeEditar(inventario,mod)==2){
							printf("ingrese nuevo precio unitario");
							printf("\n");
							scanf("%d",&cambiarprecio);
							if(editarLibroPrecio(inventario,cambiarprecio)==1){
								printf("precio actualizado");
							}
					} 							
				}else{
					printf("no existe el libro indicado");
				}
		break;
		
	}
	}
}
