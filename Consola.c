#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
#include<time.h>

//PROTOTIPOS DE FUNCIONES MENÚ
void inicio(void);
void titulo(void);

//PROTOTIPOS DE FUNCIONES TIC TAC TOE
void tttcpu (char c [3][3]);
void tttmulti (char c [3][3]);
void Intro_Primera (char c [3][3]);
void Tablero (char c [3][3]);
void Intro_Valores (char c [3][3]);
void Intro_IA (char c [3][3]);
void Intro_User1 (char c [3][3]);
void Intro_User2 (char c [3][3]);
int Ganador1 (char c [3][3]);
int Ganador2 (char c[3][3]);

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
					tttmulti(c);
					break;
				case 2:
					titulo();
					system("color 3F");
					printf("TIC TAC TOE Vs.CPU\n\n");
					printf("Jugador 1--->X\n\n");
					printf("CPU--->O\n\n\n\n");
					tttcpu(c);
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

//FUNCIONES TIC TAC TOE
void tttcpu (char c [3][3]){
	int i,j;
	i=0;
	Intro_Primera(c);
	do{
		system("cls");
		Tablero(c);
		if(i % 2==0){
			Intro_Valores(c);
		}
		else{
			Intro_IA(c);
		}
		j=Ganador1(c);
		i++;
	}while(i<=9&&j==2);
	system("cls");
	Tablero(c);
	if(j==0){
		printf("VICTORIA, HAS GANADO\n\n");
	}
	else if(j==1){
		printf("DERROTA, HAS PERDIDO\n\n");
	}
	else{
		printf("EMPATE\n\n");
	}
}
void tttmulti (char c [3][3]){
	int i,j;
	i=0;
	Intro_Primera(c);
	do{
		system("cls");
		Tablero(c);
		if(i % 2==0){
			Intro_User1(c);
		}
		else{
			Intro_User2(c);
		}
		j=Ganador1(c);
		i++;
	}while(i<=9&&j==2);
	system("cls");
	Tablero(c);
	if(j==0){
		printf("VICTORIA, HAS GANADO\n\n");
	}
	else if(j==1){
		printf("DERROTA, HAS PERDIDO\n\n");
	}
	else{
		printf("EMPATE\n\n");
	}
}
void Intro_Primera (char c [3][3]){
	int i, j;
	char aux;
	aux='1';
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
		c [i][j]=aux++;	
		}
	}
}
void Intro_Valores (char c [3][3]){
	char aux;
	int i,j,k;
	do{
		do{
			printf("Coloque una ficha: ");
			fflush(stdin);
			scanf("%c",&aux);
		}while(aux<'1'||aux>'9');
		k=0;
		switch(aux){
			case '1':{
				i=0;
				j=0;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			case '2':{
				i=0;
				j=1;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			case '3':{
				i=0;
				j=2;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			case '4':{
				i=1;
				j=0;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			case '5':{
				i=1;
				j=1;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			case '6':{
				i=1;
				j=2;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			case '7':{
				i=2;
				j=0;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			case '8':{
				i=2;
				j=1;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			case '9':{
				i=2;
				j=2;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			
		}
	}while(k==1);
	c [i][j]='X';
}
void Intro_IA (char c [3][3]){
	int i,j,k;
	srand(time(NULL));
	do{
		i=rand() % 3;
		j=rand() % 3;
		k=0;
		if (c[i][j]=='X'||c[i][j]=='O'){
			k=1;
		}
	}while(k==1);
	c[i][j]='O';
}
void Tablero (char c [3][3]){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(j<2){
				printf(" %c |",c [i][j]);
			}
			else{
				printf(" %c |",c [i][j]);
			}	
		}
		if(i<2){
			printf("\n-----------\n");
		}
	}
	printf("\n\n");
}
int Ganador1 (char c[3][3]){
	if(c[0][0]=='X'||c[0][0]=='O'){
		if(c[0][0]==c[0][1]&&c[0][0]==c[0][2]){
			if(c[0][0]='X'){
				return 0; //He ganado
			}
			else{
				return 1; //He perdido
			}
		}
		if(c[0][0]==c[1][0]&&c[0][0]==c[2][0]){
				if(c[0][0]='X'){
				return 0; //He ganado
			}
			else{
				return 1; //He perdido
			}
		}
	}
	if(c[1][1]=='X'||c[1][1]=='O'){
		if(c[1][1]==c[0][0]&&c[1][1]==c[2][2]){
			if(c[1][1]='X'){
				return 0; //He ganado
			}
			else{
				return 1; //He perdido
			}
		}
		if(c[1][1]==c[1][0]&&c[1][1]==c[1][2]){
			if(c[1][1]='X'){
				return 0; //He ganado
			}
			else{
				return 1; //He perdido
			}
		}
		if(c[1][1]==c[0][1]&&c[1][1]==c[2][1]){
			if(c[1][1]='X'){
				return 0; //He ganado
			}
			else{
				return 1; //He perdido
			}
		}
		if(c[1][1]==c[0][1]&&c[1][1]==c[2][0]){
			if(c[1][1]='X'){
				return 0; //He ganado
			}
			else{
				return 1; //He perdido
			}
		}
	}
	if(c[2][2]=='X'||c[2][2]=='O'){
		if(c[2][2]==c[1][2]&&c[2][2]==c[0][2]){
			if(c[2][2]='X'){
				return 0; //He ganado
			}
			else{
				return 1; //He perdido
			}
		}
		if(c[2][2]==c[2][1]&&c[2][2]==c[2][0]){
				if(c[2][2]='X'){
				return 0; //He ganado
			}
			else{
				return 1; //He perdido
			}
		}
	}
	return 2;
}
int Ganador2 (char c[3][3]){
	if(c[0][0]=='X'||c[0][0]=='O'){
		if(c[0][0]==c[0][1]&&c[0][0]==c[0][2]){
			if(c[0][0]='X'){
				return 0; //He ganado
			}
			else{
				return 1; //He perdido
			}
		}
		if(c[0][0]==c[1][0]&&c[0][0]==c[2][0]){
				if(c[0][0]='O'){
				return 0; //He ganado
			}
			else{
				return 1; //He perdido
			}
		}
	}
	if(c[1][1]=='X'||c[1][1]=='O'){
		if(c[1][1]==c[0][0]&&c[1][1]==c[2][2]){
			if(c[1][1]='O'){
				return 0; //He ganado
			}
			else{
				return 1; //He perdido
			}
		}
		if(c[1][1]==c[1][0]&&c[1][1]==c[1][2]){
			if(c[1][1]='O'){
				return 0; //He ganado
			}
			else{
				return 1; //He perdido
			}
		}
		if(c[1][1]==c[0][1]&&c[1][1]==c[2][1]){
			if(c[1][1]='O'){
				return 0; //He ganado
			}
			else{
				return 1; //He perdido
			}
		}
		if(c[1][1]==c[0][1]&&c[1][1]==c[2][0]){
			if(c[1][1]='O'){
				return 0; //He ganado
			}
			else{
				return 1; //He perdido
			}
		}
	}
	if(c[2][2]=='X'||c[2][2]=='O'){
		if(c[2][2]==c[1][2]&&c[2][2]==c[0][2]){
			if(c[2][2]='O'){
				return 0; //He ganado
			}
			else{
				return 1; //He perdido
			}
		}
		if(c[2][2]==c[2][1]&&c[2][2]==c[2][0]){
				if(c[2][2]='O'){
				return 0; //He ganado
			}
			else{
				return 1; //He perdido
			}
		}
	}
	return 2;
}
void Intro_User1 (char c [3][3]){
	char aux;
	int i,j,k;
	do{
		do{
			printf("Coloque una ficha: ");
			fflush(stdin);
			scanf("%c",&aux);
		}while(aux<'1'||aux>'9');
		k=0;
		switch(aux){
			case '1':{
				i=0;
				j=0;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			case '2':{
				i=0;
				j=1;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			case '3':{
				i=0;
				j=2;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			case '4':{
				i=1;
				j=0;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			case '5':{
				i=1;
				j=1;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			case '6':{
				i=1;
				j=2;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			case '7':{
				i=2;
				j=0;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			case '8':{
				i=2;
				j=1;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			case '9':{
				i=2;
				j=2;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			
		}
	}while(k==1);
	c [i][j]='X';
}
void Intro_User2 (char c [3][3]){
	char aux;
	int i,j,k;
	do{
		do{
			printf("Coloque una ficha: ");
			fflush(stdin);
			scanf("%c",&aux);
		}while(aux<'1'||aux>'9');
		k=0;
		switch(aux){
			case '1':{
				i=0;
				j=0;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			case '2':{
				i=0;
				j=1;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			case '3':{
				i=0;
				j=2;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			case '4':{
				i=1;
				j=0;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			case '5':{
				i=1;
				j=1;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			case '6':{
				i=1;
				j=2;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			case '7':{
				i=2;
				j=0;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			case '8':{
				i=2;
				j=1;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			case '9':{
				i=2;
				j=2;
				if(c [i][j]=='X'||c [i][j]=='O'){
					k=1;
					printf("Casilla ocupada. Por favor, escoja otra: \n\n");
				}
				break;
			}
			
		}
	}while(k==1);
	c [i][j]='O';
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
