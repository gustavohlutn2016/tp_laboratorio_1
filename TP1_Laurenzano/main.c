#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
/*
TP 1  de GustavoLaurenzano. DNI 22650576
*/
/**
*\brief Declaro los prototipos de las funciones que estan en la bibliotecaque voy a usar
*\param para la suma
*\param para la resta
*\param para la division
*\param para multiplicacion
*\param para factorial
*\return devuelve el resultado delas operaciones respectivas calcula
*/


float sumar(float operando1, float operando2);
float restar(float operando1, float operando2);
float dividir(float operando1, float operando2);
float multiplicar(float operando1, float operando2);
int factorial(int);

/**
*\brief Comienzo de la funcion principal
*\param declaro variables
*/
float main(void)
{


    int seguir=1;
    int opcion=0;
    float num1=0;
    float num2=0;
    float resultado=0;
    int x;
/**
*\brief Funcion de bucle para pedir opciones por printf hasta que el usuario elija opcion 9
*\param opcion
*\return devuelve un 1 o un cero
*/
        while(seguir==1)
        {
            printf("\n 1- Ingresar 1er operando A= %f \n", num1);
            printf(" 2- Ingresar 2do operando B= %f\n" , num2);
            printf(" 3- Calcular la suma (A+B)\n");
            printf(" 4- Calcular la resta (A-B)\n");
            printf(" 5- Calcular la division (A/B)\n");
            printf(" 6- Calcular la multiplicacion (A*B)\n");
            printf(" 7- Calcular el factorial (A!)\n");
            printf(" 8- Calcular todas las operaciones\n");
            printf(" 9- Salir\n");

/**
*\brief lee el numero ingresado por el  usuario
*\param luego lo comparo con if para ver si sigue pidiendo o si entra al switch
*\return devuelve un numero del 1 al 9
*/
            scanf("%d",&opcion);

                if((opcion<=0)||(opcion>10))
                {
                printf("valor no valido como opcion  Elija de 1 a 9 \n ");
                }
                if ((opcion>0)&&(opcion<10)){
/**
*\brief Funcion switch que segun el numero elegido entra a la opcion case correspondiente para hacer la operacion
*\param scanf de num1
*\param scanf de num2
*\param suma de num1 y num2
*\param resta de num1 y num2
*\param division de num1 y num2
*\param multiplicacion de num1 y num2
*\param factorial de num1
*\param realiza todas las operaciones matematicas anteriores  juntas y las informa
*\return devuelve el resultado pedido en cada operacion y lo imprime por pantalla
*/
                switch(opcion) {
            case 1:
                printf("ingrese 1er operando: ");
                scanf("%f",&num1);
                seguir=1;
                break;

            case 2:
                printf("ingrese 2 operando: ");
                scanf("%f",&num2);
                seguir=1;
                break;
            case 3:
                system("cls");
                resultado=sumar(num1, num2);
                printf("\n La suma es %.2f \n ", resultado);
                seguir=1;

                break;
            case 4:
                system("cls");
                resultado=restar(num1, num2);
                printf("\n La resta es %.2f \n ", resultado);
                seguir=1;
                break;
            case 5:
                system("cls");
                if(num2==0)
                    {
                printf("No se puede dividir por cero \n");
                }
                if(!(num2==0)){
                resultado=dividir(num1, num2);
                printf("\n La division es %.2f \n ", resultado);
                seguir=1;
                }
                break;
            case 6:
                system("cls");
                resultado=multiplicar(num1, num2);
                printf("\n La multiplicacion es %.2f \n ", resultado);
                seguir=1;
                break;
            case 7:
                system("cls");
                int x ;
                fflush(stdin);
                x = factorial((int)num1);
                printf("\nEl factorial es: %d \n", x);
                seguir=1;
                break;

            case 8:
                system("cls");
                resultado=sumar(num1, num2);
                printf("\n La suma es %.2f \n   ", resultado);
                resultado=restar(num1, num2);
                printf("\n La resta es %.2f \n   ", resultado);




                if(num2==0)
                    {
                printf("\n No se puede dividir por cero \n");
                }
                if(!(num2==0)){
                resultado=dividir(num1, num2);
                printf("\n La division es %.2f \n ", resultado);

                }
                {
                resultado=multiplicar(num1, num2);
                printf("\n La multiplicacion es %.2f \n     ", resultado);

                }


                fflush(stdin);
                x = factorial((int)num1);

                printf(" \n El factorial es: %d \n" , x);

                seguir=1;

                break;
            case 9:
                printf("\n Esta opcion es para salir del menu \n");
                seguir=0;
                system("pause");
                system("cls");
                break;

                }

            }

}
    return 0;

}









