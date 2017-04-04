	/*
		GARCIA LOMELI ABRAHAM AMOS
		ANALISIS DE ALGORITMOS 3CM2

		ESTE CODIGO FUE DESARROLLADO EL DIA 30 DE MARZO DEL 2017
		
		PROBLEMA DEL VIAJERO  V1.0
	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	//variable para almacenar la tabla se memoizacion
int memo[1005][1005];
int adyacencia[22][22];


int Minimo(int a, int b){
	return (a<=b)?a:b;
}


void showBits(int n) {
	unsigned int mask = 1 << ((8 * sizeof(int))-1);
	printf("\t%d\t = ", n);
	while(mask>0) {
		printf("%d", (n&mask)?1:0);
		mask >>= 1;
	}
	printf("\n");
}





int Viaje(int mascara, int nodoActual, int ciudades){
	printf("mascara %d, nodoActual %d\n", mascara,nodoActual);
	
	if(mascara==(1<<nodoActual)-1){
		return 0;
	}

	if(memo[mascara][nodoActual]!=-1){
		return memo[mascara][nodoActual];
	}

	int respuesta=999999;
	int i=0;
	for(i=0; i<ciudades; i++){
		printf("============= Para la ciudad %d quiero ver si ya visite %d\n",nodoActual,i );
		if(!(mascara&(1<<i))){
			if((1<<i)<ciudades){
				printf("Viaje(%d,%d); matriz= %d\n", mascara|(1<<i),i,adyacencia[nodoActual][i]);
				showBits((1<<i));
				respuesta=Minimo(respuesta,Viaje(mascara|(1<<i),i,ciudades)+adyacencia[nodoActual][i]);
			}
			
		}
	}

	memo[mascara][nodoActual]=respuesta;
	return respuesta;

}






void main(int argc, char *argv[])
{
	int ciudades=0;
	do{
		scanf("%d",&ciudades);
	}while(ciudades>21);

	printf("llenar matriz\n");
	int Auxciudades=ciudades;
	ciudades=(1<<ciudades-1);

	int potencia=0;
	int posicion=0;
	int j,i;
	for(i=0; i<ciudades; i++){
		for (j = 0; j< ciudades; j++)
		{
			memo[i][j]=-1;
		}
	}

	for(i=0; i<Auxciudades; i++){
		for (j = 0; j< Auxciudades; j++)
		{
			adyacencia[i][j]=atoi(argv[posicion+1]);
			posicion++;
		}
	}
	printf("la matriz de adyacencia es: \n");

	for(i=0; i<Auxciudades; i++){
		for (j = 0; j<Auxciudades; j++)
		{
			printf("%d ",adyacencia[i][j] );
		}
		printf("\n");
	}

	int mascara=0;

	printf("El costo de viaje mas corto que pasa por todos los nodos es de:%d\n",Viaje(mascara,1, ciudades));
}



