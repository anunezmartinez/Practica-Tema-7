/*
	nombre_programa: Main.c
	descripción: Práctica 7 de Programación, uso de bucles y cálculos matemáticos.
	@autor: Adrián Núñez Martínez
	fecha: 31/3/2022
	@versión: 1.0
*/

//Solo usamos la libreria stdio.h ya que vamos a trabajar solo con bucles.
#include <stdio.h>

//Protopitos de las funciones.

int solicitarOpcionMenu();
void selecionarOpcion(int);
void calcularFactorial();
void calculaDivisores();
void perfectNumber();

int main()
{
    solicitarOpcionMenu();

    return 0;
}

int solicitarOpcionMenu()
{
    int myInt = 0;
    char loop = 'y'; //Creamos un loop para que vuelva a preguntarnos si quieremos volver a elegir una opcion o cerrarlo.
    do //Presentamos un menú de opciones al usuario.
    {
        printf("1 - Calcular el factorial de un número\n");
        printf("2 - Calcular los divisores de un número\n");
        printf("3 - Comprobar si un número es perfecto\n");
        printf("0 - Cerrar el programa.\n");

        printf("Introduce tu opción : \n");
        scanf("%d", &myInt);
        if (myInt < 4 && myInt > -1) //Validamos los datos de entrada.
        {
            selecionarOpcion(myInt);
        }
        printf("\n Quieres continuar?(y/n)\n"); //Una vez elegida la opcion, preguntamos al usuario y quiere cerrar el programa o volver a empezar.
        scanf("\n %c", &loop);

    } while (loop == 'y');

    return myInt;
}

void selecionarOpcion(int seleccion) //Esta funcion se basa en un switch case para llamar a las funciones en base al input de la funcion anterior.
{

    switch (seleccion) //Cada switch case irá en base a la eleccion del usuario.
    {
    case 0: //Añadimos un caso cero para poder cerrar el programa a peticion del usuario.
        break;
    case 1:
        calcularFactorial();
        break;
    case 2:
        calculaDivisores();
        break;
    case 3:
        perfectNumber();
        break;
    }
}

void calcularFactorial()
{

    int i, f = 1, num;

    printf("Introduce un número : "); //Solicitamos un número al usuario.
    scanf("%d", &num);

    for (i = 1; i <= num; i++) //Calculamos el factorial usando un bucle for.
        f = f * i;

    printf("El factorial de  %d es: %d\n", num, f); //Y lo mostramos por pantalla.
}

void calculaDivisores()
{

    int num1, i; // Declaramos las variables de tipo entero

    printf("Introduce un numero: ");
    scanf("%d", &num1); // Guardamos el número introducido por el usuario en la variable num1

    for (i = 1; i <= num1; i++)
    {
        if (num1 % i == 0) // La condición es que el numero dividido entre num1 de como resto 0
        {
            printf("%d, es divisor de %d \n", i, num1);
        }
    }
}

void perfectNumber()
{

    int i, Number, Sum = 0; //Decalaramos las variables locales que vamos a necesitar.

    printf("\n Introduce un número \n"); //Solicitamos un numero al usuario.
    scanf("%d", &Number);

    for (i = 1; i < Number; i++)
    {
        if (Number % i == 0) //Dentro del bucle for, vemos si el numero introducido modulo del contdor es igual a cero, si es así, sumamos.
        {
            Sum = Sum + i;
        }
    }

    if (Sum == Number) //Una vez la suma sea igual al numero, ya tenemos nuestro resultado, por la contra, no sería un numero perfecto.
        printf("\n %d es un número perfecto", Number);
    else
        printf("\n%d no es un número perfecto", Number);
}