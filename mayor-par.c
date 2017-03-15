	/*Programa para seleccionar el numero mayor del arreglo, que sea par, donde el numero siguiente sea impar,
	el siguiente-siguiente debe ser la mitad del par
	y la suma del anterior y el siguiente debe dar el numero par*/

#include<stdio.h> //libreria para entrada y salida de datos
#include<stdlib.h> //libreria para poder utilizar la funcion rand y srand
#include<time.h> //para poder utilizar la funcion time(NULL)

int main()
{
	int n=0, mayor=0, divisible=0, tam_arreglo=1000, bandera=0;
	int anterior=0,sig=0,sig_sig=0;
	int arreglo[tam_arreglo];

	srand(time(NULL));	//srand le da una semilla a la funcion rand para no repetir numeros, time(NULL) devuelve la cantidad de seg. desde 1 de enero del 1970 hasta la fecha del sistema
	while(n<tam_arreglo)	//Ciclo para llenar el arreglo con nùmeros random
	{
		arreglo[n]=rand()%100;	//Llena el arreglo con nùmeros de 0 a 99
		n++;	//Aumenta n para avanzar en el arreglo
	}

	n=1; //n=1, porque el primer numero no cumplira las caracteristicas, ya que no tendra un numero anterior
	while(n<(tam_arreglo-2)) //Ciclo para revisar todos los numeros del arreglo, cant_num-2 porque los ultimos 2 numeros no cumpliran las caracteristicas ya que no tendran, siguiente ni siguiente-siguiente
	{
		if(arreglo[n]>mayor && arreglo[n]%2==0 && arreglo[n+1]%2!=0 && arreglo[n+2]==arreglo[n]/2 && arreglo[n]==arreglo[n-1]+arreglo[n+1]) //Condicion para las caracteristicas deseadas
		{
			mayor=arreglo[n]; //el numero mayor del arreglo que cumple las caracteristicas, se agrega a l variable "mayor"
			divisible=mayor/2; //Calcula cuantas veces es divisible el numero mayor
			bandera=1; //Bandera para imprimir si se encontro un numero con las caracteristicas o no
			anterior=arreglo[n-1]; //Guarda el numero anterior al mayor
			sig=arreglo[n+1]; //Guarda el numero siguiente al mayor
			sig_sig=arreglo[n+2]; //Guarda el numero siguiente-siguiente al mayor
		}	//Estos ultimos 3 numeros se guardan para imprimirlos y comprobar si es correcto el resultado
		n++; //aumenta n para avanzar en el arreglo
	}

	if(bandera!=0) //Condicion para revisar si hubo cambio en la bandera
	{
		printf("el mayor es %d y es divisible %d veces \n anterior: %d, siguiente: %d, Sig_sig: %d \n",mayor,divisible,anterior,sig,sig_sig);	
		return 0; //Return aqui, para terminar el programa si se encontro el numero con las caracteristicas y que no imprima el siguiente print
	}
	
	printf("No se encontro un numero que cumpla las caracteristicas...\n"); 
	//print por si no se encuentra un numero que cumpla con las caracteristicas
}