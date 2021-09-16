#include <stdio.h>
#define MAX_SIZE 6

int main()
{
	int array[MAX_SIZE] = {10, 20, 30, 40, 50, 60};	//CRIA ARRAY
	int temp1[MAX_SIZE/2];				//CRIA PRIMEIRO ARRAY SECUNDARIO
	int temp2[MAX_SIZE/2];				//CRIA SEGUNDO ARRAY SECUNDARIO
	int i, j, k;

	/*
	Aqui seria uma parte de paralelizar a primeira metade do array em um processador
	e a segunda metade no outro, assim seria executada a tarefa de multiplicação na
	metade do tempo.
	*/

	for(i=0; i< MAX_SIZE/2; i++){	//PRIMEIRO PROCESSADOR MULTIPLICA A PRIMEIRA METADE E SALVA NO ARRAY
		array[i] = temp1[i] * 4;
	}

	for(j=0; j< MAX_SIZE/2; j++){	//SEGUNDO PROCESSADOR MULTIPLICA A SEGUNDA METADE E SALVA NO ARRAY
		array[j+3] = temp2[j] * 4;
	}

	/*
	Depois que cada processador sobrescrever a resposta em cada espaço do array ele 
	será impresso na tela.
	*/

	for(k=0; k < MAX_SIZE; k++){	//IMPRIME O ARRAY
		printf("array[%i] = %i\n", k, array[k]);
	}

    return 0;
}
