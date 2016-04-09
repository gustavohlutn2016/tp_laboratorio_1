#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



#endif // FUNCIONES_H_INCLUDED

/**
*\brief Funcion que calcula la suma de dos valores
*\param operandos de la suma
*\return devuelve el resultado de la suma
*/
float sumar(float operando1,float operando2)
{
    float resultado;
    resultado = operando1+ operando2;
    return resultado;
}

/**
*\brief Funcion que calcula la resta de dos valores
*\param operandos de la resta
*\return devuelve el resultado de la resta
*/
float restar(float operando1,float operando2)
{
    float resultado;
    resultado = operando1- operando2;
    return resultado;
}

/**
*\brief Funcion que calcula la division de dos  valores
*\param operandos de la division
*\return devuelve el resultado de la division
*/

float dividir(float operando1,float operando2)
{
    float resultado;
    resultado = operando1 / operando2;
    return resultado;
}
/**
*\brief Funcion que calcula la multiplicacion de dos  valores
*\param operandos de la multipicacion
*\return devuelve el resultado de la multiplicacion
*/


float multiplicar(float operando1,float operando2)
{
    float resultado;
    resultado = operando1 * operando2;
    return resultado;
}

/**
*\brief Funcion que calcula el factorial del un valor
*\param operando del factorial
*\return devuelve el resultado del factoreo
*/

int factorial(int n)
{
    int x;

    if(n != 1)
    {
        x = factorial(n - 1);
        return (n * x);
    }
    else
    {
        return 1;
    }
}


