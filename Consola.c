#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
#include<time.h>

//PROTOTIPOS DE FUNCIONES MENÚ
void inicio(void);
void titulo(void);

//PROTOTIPOS DE FUNCIONES ADIVINAR EL NÚMERO
void adivinar(void);

//MENÚ
int main()
{
	inicio();
	titulo();
	int opcion,opcion2;	
	char c [3] [3];
	system("color 1F");
	printf("Escoja un juego:\n\n");
	printf("1)	TIC TAC TOE\n");	
	printf("2)	PIEDRA PAPEL TIJERA\n");
	printf("3)	ADIVINA EL NUMERO\n");	
	printf("4)	SALIR\n\n");
	printf("Marque aqui la opcion:\t");
	scanf("%i",&opcion);
	switch(opcion)
	{
		case 1: //TIC TAC TOE
			system("cls");
			system("color 1F");
			titulo();
			printf("TIC TAC TOE\n\n\n");
			printf("Seleccione el modo de juego:\n\n");
			printf("1)	MODO MULTIJUGADOR 1 Vs.1\n");
			printf("2)	MODO INDIVIDUAL Vs. CPU\n");
			printf("Marque aqui su opcion:\t");
			scanf("%i",&opcion2);
			switch(opcion2)
			{
				case 1:
					system("cls");
					titulo();
					system("color 4F");
					printf("TIC TAC TOE 1 Vs.1\n\n");
					printf("Jugador 1--->X\n\n");
					printf("Jugador 2--->O\n\n\n\n");
					break;
				case 2:
					titulo();
					system("color 3F");
					printf("TIC TAC TOE Vs.CPU\n\n");
					printf("Jugador 1--->X\n\n");
					printf("CPU--->O\n\n\n\n");
					break;
			}break;
		case 2: //PIEDRA PAPEL TIJERA
			system("cls");
			system("color 1F");
			titulo();
			printf("PIEDRA PAPEL TIJERA\n\n\n");
			printf("Seleccione el modo de juego:\n\n");
			printf("1)	MODO MULTIJUGADOR 1 Vs.1\n");
			printf("2)	MODO INDIVIDUAL Vs. CPU\n");
			printf("Marque aqui su opcion:\t");
			scanf("%i",&opcion2);
			switch(opcion2)
			{
				case 1:
					system("cls");
					titulo();
					system("color 4F");
					printf("PIEDRA PAPEL TIJERA\n");
					printf("MODO MULTIJUGADOR 1 Vs.1\n\n");
					break;
				case 2:
					system("cls");
					titulo();
					system("color 3F");
					printf("PIEDRA PAPEL TIJERA\n");
					printf("MODO INDIVIDUAL Vs. CPU\n\n");
					break;
			}break;	
		case 3: //ADIVINAR UN NÚMERO 
			system("cls");
			fflush(stdin);
			system("color 1F");
			titulo();
			printf("ADIVINA EL NUMERO\n\n\n");
			adivinar();
			break;
		case 4: //SALIR
			system("cls");
			system("color 1F");
			titulo();
			printf("HA ESCOGIDO LA OPCION: SALIR\n\n\n");
			printf("ADIOS Y HASTA PRONTO!");
			return 0;
			break;
		default:
			return 1;
			system("cls");
			break;				
	}
	system("pause");
	return 0;
}

//FUNCIONES MENÚ
void inicio(void)
{
	system("color 1F");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tHola! Soy CHINTENDO ZII. Bienvenido!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	system("pause");
	system("cls");
}
void titulo(void)
{
	system("color 1F");
	printf("\t\t\t\t\t******CHINTENDO ZII LTD.******\t\t\t\n");
	printf("\t\t\t\t\t      All rights reserved\t\t\t\n");
	printf("\t\t\t\t\t    By SamuSung Electronics\t\t\t\n\n\n\n");
}

//FUNCIONES ADIVINAR EL NÚMERO
void adivinar(void){
	int i;
	int salto = 0;
	int p;
	int misterio = 0;
	int esta = 0;
	printf("\nPiensa un numero del 1 al 100\n");
	printf("Responde a las preguntas con si(s) o no(n)\n\n");
	for (p = 1; p< 128; p *= 2){
		salto = 0;
		for (i=1; i<=100; i++){
			if (i & p){
			 	printf("%3d%c", i, salto % 10 ? ' ' : '\n');
			 	salto++;
			}
		}
		printf("\n\nEsta tu numero en esta lista?: ");
		esta = getchar();
		getchar();
		if (esta == 's' || esta == 'S')
		misterio += p;
		system("cls");
	}
	printf("\n\nEl numero que has pensado es %d\n", misterio);
}
