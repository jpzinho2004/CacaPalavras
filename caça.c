#include<stdio.h>  
#include<stdlib.h>  //Inserção das bibliotecas padrão
#include<locale.h>	//Utilizada para que os acentos funcionem corretamente no código


//Declaração de todas as funções utilizadas no programa
void menu(char pal[10], char matteste[10][10]);
void criamat(char matteste[10][10]);
void matTeste(char matteste[10][10]);
void imprimemat(char matteste[10][10]);
void palavra(char pal[10]);
void EsqDir(char pal[10], char matteste[10][10]);
void DirEsq(char pal[10], char matteste[10][10]);
void AltoBaixo(char pal[10], char matteste[10][10]);
void BaixoAlto(char pal[10], char matteste[10][10]);

int main(){  //O int main contem apenas os arrays correspondentes à palavra que vai ser inserida e à matriz trabalhada

	char matteste[10][10];  //O nome está matteste por que acabei mudando a lógica do projeto, porém já havia escrito muitas vezes
	char pal[10];	//Só percebi o nome meio dúbio depois que me falaram, e eu já o tinha utilizado bastante

	menu(pal, matteste);
}

void menu(char pal[10], char matteste[10][10]){	//Função menu que chama todas as outras
	int escolha, op;  //Variáveis locais para o funcionamento dos switch case
	escolha=10;

	setlocale(LC_ALL, "Portuguese");  //Função utilizada para que os acentos funcionem corretamente

	while(escolha!=0){  //O while foi utilizado para que o programa pudesse funcionar em loop, exceto se o 0 for inserido
		printf(
			"Escolha uma das opções abaixo: \n"
			"+----+-----------------------------------+ \n"  //O menu de opções foi criado utilizando-se o sute Ascii Table
			"| OP |             Descrição             | \n"
			"+----+-----------------------------------+ \n"
			"|  1 | Cria a matriz a partir do teclado | \n"
			"|  2 | Imprime a Matriz                  | \n"
			"|  3 | Solicita uma palavra              | \n"
			"|  4 | Pesuisa a palavra na matriz       | \n"
			"|  5 | Executa o teste padrão            | \n"
			"|  0 | Fecha o programa                  | \n"
			"+----+-----------------------------------+ \n"
		);
		scanf("%d", &escolha);  //O programa interpreta a escolha do usuário e a distribui nos switch case
		switch(escolha){

			case 1:
				criamat(matteste);  //Função para a criação manual de uma matriz
				break;
			case 2:
				imprimemat(matteste);  //Função que vai imprimir a matriz criada
				break;
			case 3:
				palavra(pal);  //Função que irá receber a palavra a ser procurada
				break;
			case 4:
				printf("Escolha o sentido da pesquisa: \n"
						"+----+-------------------------+ \n"  //Ao selecionar a opção de pesquisa, o usuário deve
						"| OP |        Descrição        | \n"  //escolher a direção desejada para a pesquisa
						"+----+-------------------------+ \n"
						"|  1 | Esquerda para a direita | \n"
						"|  2 | Direita para a esquerda | \n"
						"|  3 | Cima para baixo         | \n"
						"|  4 | Baixo para cima         | \n"
						"+----+-------------------------+ \n"
				);
				scanf("%d", op);
				switch (op){ //Outro switch case que chama as funções, dessa vez, as direções de pesquisa
					case 1:
						EsqDir(pal, matteste);  //Esquerda->Direita
						break;
					case 2:
						DirEsq(pal, matteste);  //Direita->Esquerda
						break;
					case 3:
						AltoBaixo(pal, matteste);  //Cima->Baixo
						break;
					case 4:
						BaixoAlto(pal, matteste);	//Baixo->Cima
						break;		
				}
			case 5: //Essa opção pega a matriz de teste e realiza o ciclo completo, sendo necessária apenas a escolha da palavra e da direção
				matTeste(matteste);
				imprimemat(matteste);
				palavra(pal);
				printf("Escolha o sentido da pesquisa: \n"
						"+----+-------------------------+ \n"
						"| OP |        Descrição        | \n"
						"+----+-------------------------+ \n"
						"|  1 | Esquerda para a direita | \n"
						"|  2 | Direita para a esquerda | \n"
						"|  3 | Cima para baixo         | \n"
						"|  4 | Baixo para cima         | \n"
						"+----+-------------------------+ \n"
				);
				scanf("%d", &op);
				switch (op){
					case 1:
						EsqDir(pal, matteste);
						break;
					case 2:
						DirEsq(pal, matteste);
						break;
					case 3:
						AltoBaixo(pal, matteste);
						break;
					case 4:
						BaixoAlto(pal, matteste);
						break;
				}
				break;
			case 0:  //Quando inserir 0, o usuário vai recber esta mensagem e o programa será encerrado
				printf(
				"+---------------------------------+ \n"
				"|   Trabalho 1 de Algoritmo II    | \n"
				"+---------------------------------+ \n"
				"|         Caça Palavras           | \n"
				"| Feito por: João Pedro R. Vilela | \n"
				"+---------------------------------+ \n"
				);
				system ("pause");			
		}
	}	
}

void criamat(char matteste[10][10]){  //A função de criar matriz 
	int i,j;  //Variáveis auxiliares para o funcionamento da função
	char matriz[10][10];  //Uma matriz de caracteres é gerada nesse array

	printf("Insira uma linha com dez elementos para seu caçaa palavras (com as letras separadas por espaço");  //Apenas uma recomendação
	for (i=0; i<10; i++){  //Loop for que irá distribuir os elementos digitados em linhas e colunas
		for (j=0; j<10; j++){
			scanf(" %c", &matriz[i][j]);
		}
	}

	for (i=0; i<10; i++){  //Loop for que passa a matriz criada para uma matriz "principal", que será utilizada em todas as funções
		for (j=0; j<10; j++){
			matteste[i][j]=matriz[i][j];
		}
	}
}

void matTeste(char matteste[10][10]){  //Função para a criação da matriz de teste

	char mat[10][10];  //Mais uma vez, a matriz é gerada localmente
	int i,j;

	mat[0][0]='a'; mat[0][1]='b'; mat[0][2]='a'; mat[0][3]='c'; mat[0][4]='a'; mat[0][5]='x'; mat[0][6]='a'; mat[0][7]='b'; mat[0][8]='a'; mat[0][9]='a';
	mat[1][0]='c'; mat[1][1]='b'; mat[1][2]='y'; mat[1][3]='f'; mat[1][4]='a'; mat[1][5]='z'; mat[1][6]='a'; mat[1][7]='a'; mat[1][8]='a'; mat[1][9]='l';
	mat[2][0]='i'; mat[2][1]='t'; mat[2][2]='a'; mat[2][3]='e'; mat[2][4]='h'; mat[2][5]='p'; mat[2][6]='e'; mat[2][7]='r'; mat[2][8]='o'; mat[2][9]='a';
	mat[3][0]='p'; mat[3][1]='i'; mat[3][2]='r'; mat[3][3]='a'; mat[3][4]='v'; mat[3][5]='e'; mat[3][6]='r'; mat[3][7]='o'; mat[3][8]='f'; mat[3][9]='f';
	mat[4][0]='o'; mat[4][1]='z'; mat[4][2]='t'; mat[4][3]='a'; mat[4][4]='z'; mat[4][5]='m'; mat[4][6]='a'; mat[4][7]='d'; mat[4][8]='i'; mat[4][9]='f';
	mat[5][0]='i'; mat[5][1]='x'; mat[5][2]='q'; mat[5][3]='m'; mat[5][4]='u'; mat[5][5]='a'; mat[5][6]='l'; mat[5][7]='a'; mat[5][8]='l'; mat[5][9]='i';
	mat[6][0]='t'; mat[6][1]='c'; mat[6][2]='w'; mat[6][3]='n'; mat[6][4]='u'; mat[6][5]='s'; mat[6][6]='u'; mat[6][7]='l'; mat[6][8]='g'; mat[6][9]='n';
	mat[7][0]='t'; mat[7][1]='e'; mat[7][2]='s'; mat[7][3]='t'; mat[7][4]='e'; mat[7][5]='d'; mat[7][6]='e'; mat[7][7]='l'; mat[7][8]='i'; mat[7][9]='n';
	mat[8][0]='h'; mat[8][1]='o'; mat[8][2]='m'; mat[8][3]='a'; mat[8][4]='r'; mat[8][5]='o'; mat[8][6]='b'; mat[8][7]='o'; mat[8][8]='b'; mat[8][9]='a';
	mat[9][0]='k'; mat[9][1]='o'; mat[9][2]='a'; mat[9][3]='z'; mat[9][4]='z'; mat[9][5]='z'; mat[9][6]='a'; mat[9][7]='m'; mat[9][8]='a'; mat[9][9]='l'; 


	for(i=0; i<10; i++){   //E passada para a variável principal
		for (j=0; j<10; j++){
			matteste[i][j]=mat[i][j];
		}
	}
}

void imprimemat(char matteste[10][10]){  //Função que imprime a matriz
	int i,j;

	for(i=0; i<10; i++){  //Loop for que corre pelos elementos da matriz, fazendo os devidos prints
		printf("\n");  //Formatação da matriz
		for (j=0; j<10; j++){
			printf("%c  ", matteste[i][j]);
		}
	}	
}

void palavra(char pal[10]){  //Função que aceita a palavra ou letra a ser pesquisada na matriz
	char palavra[10];
	int i;

	printf("\nInsira a palavra ou o trecho que se deseja procurar: \n");
	scanf("%s", palavra);  

	for (i=0; i<10; i++){  //Converte a matriz gerada localmente em uma variável principal
		pal[i]=palavra[i];
	}
}

void EsqDir(char pal[10], char matteste[10][10]){  //A primeira função de seleção, note que todas funcionarão da mesma forma
	int i,j,k,c;  //Variáveis locais para a operação
	int tam;  //Tamanho da palavra
	tam=0;  

	setlocale(LC_ALL, "Portuguese");

	while(pal[tam] != '\0'){  //Pequena loop para que se possa saber o tamanho da palavra inserida
	tam++;
	}


	printf("O trecho designado foi encontrado nas seguintes coordenadas: \n");
	for(i=0; i<10; i++){  //Junção de for para que todos os elementos da matriz sejam lidos
		for(j=0; j<10; j++){
			if (pal[0]==matteste[i][j]){  //Se o primeiro elemento da palavra for igual à qualquer posição da matriz
				c=1;					  //C se torna um, funcionando como um true	
				for(k=0; k<tam; k++){  //O for executado dentro do if confere se o resto da palavra bate com as próximas posições na horizontal e da esquerda para a direita na matriz
					if (pal[k]!=matteste[i][j+k]){   //Se for diferente, o loop é interrompido
						c=0;                         //e C retorna 0
						break;
					}
				}
				if(c==1){	//Se C=1 a função irá imprimir as coordenadas correspondentes
					printf("Linha: %d || Coluna: %d\n", i, j);
				}		
			}	
		}
	}
}

void DirEsq(char pal[10], char matteste[10][10]){  //Funciona da mesma maneira que a anterior
	int i,j,k,c;
	int tam;
	tam=0;

	while(pal[tam] != '\0'){
	tam++;
	}

	printf("O trecho designado foi encontrado nas seguintes coordenadas: \n");
	for(i=0; i<10; i++){
		for(j=9; j>=0; j--){  //Alterando-se o sentido da pesquisa de J(direita->esquerda)
			if (pal[0]==matteste[i][j]){
				c=1;
				for(k=0; k<tam; k++){
					if (pal[k]!=matteste[i][j-k]){  //E subtraindo k de j, já que a palavra estará na orientação contrária
						c=0;
						break;
					}
				}
				if(c==1){	
					printf("Linha: %d || Coluna: %d\n", i, j);
				}		
			}	
		}
	}
}

void AltoBaixo(char pal[10], char matteste[10][10]){   //Funciona da mesma maneira que a anterior
	int i,j,k,c;
	int tam;
	tam=0;

	while(pal[tam] != '\0'){
	tam++;
	}

	printf("O trecho designado foi encontrado nas seguintes coordenadas: \n");
	for(i=0; i<10; i++){
		for(j=0; j<10; j++){
			if (pal[0]==matteste[i][j]){
				c=1;
				for(k=0; k<tam; k++){
					if (pal[k]!=matteste[i+k][j]){  //Só se altera a posição do K, já que agora se quer saber sobre o elemento abaixo, e não na mesma linha
						c=0;
						break;
					}
				}
				if(c==1){	
					printf("Linha: %d || Coluna: %d\n", i, j);
				}		
			}	
		}
	}
}

void BaixoAlto(char pal[10], char matteste[10][10]){  //Funciona da mesma maneira que a anterior
	int i,j,k,c;
	int tam;
	tam=0;

	printf("O trecho designado foi encontrado nas seguintes coordenadas: \n");
	while(pal[tam] != '\0'){
	tam++;
	}

	for(i=9; i>=0; i--){  //Altera a forma de pesquisa, já que será de cima para baixo
		for(j=0; j<10; j++){
			if (pal[0]==matteste[i][j]){
				c=1;
				for(k=0; k<tam; k++){
					if (pal[k]!=matteste[i-k][j]){  //E o k será subtraído de i, posto que a palavra estará "subindo", e não na direção padrão
						c=0;
						break;
					}
				}
				if(c==1){	
					printf("Linha: %d || Coluna: %d\n", i, j);
				}		
			}	
		}
	}
}