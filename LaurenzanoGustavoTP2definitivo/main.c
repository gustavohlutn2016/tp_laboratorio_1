#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utn.h"

#define QTY_PERSONAS 20
/*TP2 GUSTAVO LAURENZANO 1°F*/


typedef struct{
    char nombre[50];
    char apellido[50];
    int legajo;
    int dni;
    int edad;
}Persona;

void inicializarArrayPersonas(Persona arrayPersonas[],int cantidadDeElementos,int valor);
int buscarPrimerOcurrencia(Persona arrayPersonas[],int cantidadDeElementos,int valor);



int main()
{
    // arrays de clientes
    Persona arrayPersonas[QTY_PERSONAS];


    Persona auxiliarCliente;


    char auxiliarNombreStr[50];
    char auxiliarApellidoStr[50];
    char auxiliarLegajoStr[50];
    int auxiliarLegajo;
    char auxiliarDniStr[50];
    int auxiliarDni;
    char auxiliarEdadStr[50];
    int auxiliarEdad;


    int indiceLugarLibre;
    int indiceResultadoBusqueda;
    int opcion = 0;
    int i,j;

    inicializarArrayPersonas(arrayPersonas,QTY_PERSONAS,-1); /**< Se indica con -1 que esa posicion esta vacia */
    while(opcion != 7)

    {//se pide la opcion y se entra a cada case segun elija laopcion
         opcion = getInt("\n\n\n\n\n1 - AGREGAR A UNA PERSONA \n2 - DAR DE BAJA A UNA PERSONA\n3 - MODIFICACION DE DATOS\n4 - LISTAR PERSONAS\n5 - ORDENAR POR NOMBRE\n6 - GRAFICAR POR ASTERISCOS\n7 -SALIR \n\n\n");
         switch(opcion)
         {
            case 1://para dar de alta una persona

                indiceLugarLibre = buscarPrimerOcurrencia(arrayPersonas,QTY_PERSONAS,-1);
                if(indiceLugarLibre == -1)
                {
                    printf("\n\nNO HAY LUGARES LIBRES!\n");
                    break;
                }

                printf("\nAGREGAR A UNA PERSONA\n");
                if (!getStringLetras("Ingrese el nombre: ",auxiliarNombreStr))
                {
                    printf ("El nombre debe estar compuesto solo por letras\n");
                    break;
                }

                if (!getStringLetras("Ingresar el apellido: ",auxiliarApellidoStr))
                {
                    printf ("El apellido debe estar compuesto solo por letras\n");
                    break;
                }

                if (!getStringNumeros("Ingresar el legajo: ",auxiliarLegajoStr))
                {
                    printf ("El legajo debe ser numerico\n");
                    break;
                }
                auxiliarLegajo = atoi(auxiliarLegajoStr);



                if(buscarPrimerOcurrencia(arrayPersonas,QTY_PERSONAS,auxiliarLegajo) != -1)
                {
                    printf("\n\nEL LEGAJO YA EXISTE!!!\n");
                    break;
                }

                 if (!getStringNumeros("Ingresar el dni: ",auxiliarDniStr))
                {
                    printf ("El dni debe ser numerico\n");
                    break;
                }
                auxiliarDni = atoi(auxiliarDniStr);

                if (!getStringNumeros("Ingresar el edad: ",auxiliarEdadStr))
                {
                    printf ("El edad debe ser numerico\n");
                    break;
                }
                auxiliarEdad = atoi(auxiliarEdadStr);






                strcpy(arrayPersonas[indiceLugarLibre].nombre,auxiliarNombreStr);
                strcpy(arrayPersonas[indiceLugarLibre].apellido,auxiliarApellidoStr);
                arrayPersonas[indiceLugarLibre].dni = auxiliarDni;
                arrayPersonas[indiceLugarLibre].legajo = auxiliarLegajo;
                arrayPersonas[indiceLugarLibre].edad = auxiliarEdad;

                break;

            case 2:
                if (!getStringNumeros("Ingresar el legajo a dar de baja: ",auxiliarLegajoStr))
                {
                    printf ("El legajo debe ser numerico\n");
                    break;
                }
                indiceResultadoBusqueda = buscarPrimerOcurrencia(arrayPersonas,QTY_PERSONAS,atoi(auxiliarLegajoStr));

                if(indiceResultadoBusqueda == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE LEGAJO\n");
                    break;
                }
                arrayPersonas[indiceResultadoBusqueda].legajo=-1;
                break;

            case 3://para modificar los de una personaya cargada
                if (!getStringNumeros("Ingresar el legajo a modificar: ",auxiliarLegajoStr))
                {
                    printf ("El legajo debe ser numerico\n");
                    break;
                }

                indiceResultadoBusqueda = buscarPrimerOcurrencia(arrayPersonas,QTY_PERSONAS,atoi(auxiliarLegajoStr));

                if(indiceResultadoBusqueda == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE LEGAJO\n");
                    break;
                }

                if (!getStringLetras("Ingrese el nombre: ",auxiliarNombreStr))
                {
                    printf ("El nombre debe estar compuesto solo por letras\n");
                    break;
                }

                if (!getStringLetras("Ingrese el apellido: ",auxiliarApellidoStr))
                {
                    printf ("El apellido debe estar compuesto solo por letras\n");
                    break;
                }
                if (!getStringNumeros("Ingrese el dni: ",auxiliarDniStr))
                {
                    printf ("El dni debe ser numerico\n");
                    break;
                }
                auxiliarDni = atoi(auxiliarDniStr);
                if (!getStringNumeros("Ingrese el edad: ",auxiliarDniStr))
                {
                    printf ("El edad debe ser numerico\n");
                    break;
                }
                auxiliarEdad = atoi(auxiliarEdadStr);




                strcpy(arrayPersonas[indiceResultadoBusqueda].nombre,auxiliarNombreStr);
                strcpy(arrayPersonas[indiceResultadoBusqueda].apellido,auxiliarApellidoStr);
                arrayPersonas[indiceLugarLibre].dni = auxiliarDni;
                arrayPersonas[indiceLugarLibre].edad = auxiliarEdad;

                break;

            case 4:// se usa para imprimir listado de las personas que  estan cargadas
                printf("\nLISTAR\n");
                for(i=0;i < QTY_PERSONAS; i++)
                {
                    if(arrayPersonas[i].legajo != -1)//verifico que laposicion no este vacia
                    {
                        printf("\n%s - %s - %d - %d - %d ",arrayPersonas[i].nombre,arrayPersonas[i].apellido,arrayPersonas[i].legajo,arrayPersonas[i].dni,arrayPersonas[i].edad);
                    }
                }
                break;









            case 5: //ordena alfabeticamente por nombre a todas laspersonascargadas
                printf("\nORDENADO\n");

                for(i=0; i < QTY_PERSONAS - 1; i++)
                {
                    if(arrayPersonas[i].legajo == -1)//verifico que laposicion no este vacia
                    {
                        continue;
                    }
                    for(j=i+1; j < QTY_PERSONAS; j++)
                    {
                        if(arrayPersonas[j].legajo == -1)
                        {
                            continue;
                        }
                        if(strcmp(arrayPersonas[i].nombre,arrayPersonas[j].nombre) > 0)
                        {
                            auxiliarCliente = arrayPersonas[j];
                            arrayPersonas[j] = arrayPersonas[i];
                            arrayPersonas[i] = auxiliarCliente;
                        }
                    }
                }
                break;
                case 6:
               printf("\nGRAFICO POR ASTERISCOS\n");
                //declaro variables paraarmar los contadores segun edad
                int i;
                int j;
                int contGeneral=0;
                int contMenor18=0;
                int contEntre19y35=0;
                int contMayor35=0;

                for(i=0; i < QTY_PERSONAS - 1; i++)//armo un for para iterar
                {
                    if(arrayPersonas[i].legajo != -1)//verifico que la posicion no este vacia
                    {
                       contGeneral++;//si esta cargada incremento el contador general
                        if (arrayPersonas[i].edad >35)
                            {
                              contMayor35++;
                            }
                            //dependiendo elrango de edades voy subiendo los contadores de cada rango
                        if (arrayPersonas[i].edad >1 && arrayPersonas[i].edad  <=18)
                            {
                              contMenor18++;
                            }
                         if (arrayPersonas[i].edad >18 && arrayPersonas[i].edad  <35)
                            {
                              contEntre19y35++;
                            }


                    }
                }


//Declro el char para las matrices de los asteriscos


                char grafico[3][contGeneral];
 //Hago un for para obtener los valores d las 3 columnas
                for(i=0 ; i<3 ; i++)
                 {
                   for(j=0; j<contGeneral; j++ )
                    {
                        grafico[i][j] ='?xF-';

                    }

                 }
                  for(j=0; j<contGeneral; j++ )//ubico los asteriscos segun valor obtenido
                {
                    if(contMenor18 > j)
                    {
                      grafico[0][j] ='*';
                    }
                    if(contEntre19y35 > j)
                    {
                      grafico[1][j] ='*';
                    }
                    if(contMayor35 > j)
                    {
                      grafico[2][j] ='*';
                    }


                }
                system("cls");
                if (contGeneral  >0)
                {
                 printf("menor de 18\tentre 19 y 35\tmayorde35\n");//Imprimo encabezado de asteriscos
                 for(j=0 ; j<contGeneral ; j++)
                    {
                             for( i=0 ; i<3 ;i++)
                            {
                                printf("%c\t\t",grafico[i][j]);//imprimo los asteriscos
                            }
                            printf("\n");
                    }
                 printf("\n\n");

                }
                else
                {
                    printf("No hay ninguna persona cargada \n\n\n");
                }

                break;



         }
    }


    return 0;
}

/**
 * \brief Inicializa un array de Personas con el valor recibido
 * \param array Es el array a ser inicializado
 * \param cantidadDeElementos Indica la logitud del array
 * \param valor Es el valor que sera cargado en cada posición
 * \return void
 *
 */
void inicializarArrayPersonas(Persona arrayPersonas[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        arrayPersonas[i].legajo = valor;
    }
}

/**
 * \brief Busca la primer ocurrencia de un valor en un array de Personas
 * \param array Es el array en el cual buscar
 * \param cantidadDeElementos Indica la logitud del array
 * \param valor Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay, la posición de la misma
 *
 */
int buscarPrimerOcurrencia(Persona arrayPersonas[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        if(arrayPersonas[i].legajo == valor)
        {
            return i;
        }
    }
    return -1;
}




