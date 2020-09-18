#include <stdio.h> 
#include <stdlib.h>

//#include <conio.h> //para usar a função GET
#include <string.h>

/*
int main(){
	int a = 22;
	int i;
	for(i = 0; i <= a; i++)
		printf("I = %d\n", i);
		return 0;
	
}

struct Aluno{
	int ra;
	float nota[3];
	float media;
};

int main(){
	struct Aluno Ano;
	Ano.ra = 1234;
	Ano.nota[0] = 6.5;
	Ano.nota[1] = 5.5;
	Ano.nota[2] = 8.5;
	Ano.nota[3] = 8.0;
	
	Ano.media = (Ano.nota[0] + Ano.nota[1] + Ano.nota[2] + Ano.nota[3]) / 4;
	printf("RA: %d \n", Ano.ra);
	printf("Media: %.2f", Ano.media);
	printf("\n\n");
	system("PAUSE");
	return 0;
}*/

//exemplo Malloc

/*int main(){
	int *pi;
	pi = (int *) malloc(sizeof(int));
	puts("Digite um numero: ");
	scanf("%d", pi);
	printf("\nVoce digitou o numero %d\n", *pi);
	free(pi);
	printf("\n\n");
	system("PAUSE");
	return 0;
}*/
/*
typedef struct Livro{
	char Titulo[30];
	char Autor[30];
	int NumReg;
	double Preco;
	struct Livro *Proximo;
} Livro;

 Livro *primeiro, *atual, *NovoLivro;
 void GetLivro(){
 	char temp[80];
 	NovoLivro = (Livro *)malloc (sizeof(Livro));
 	
 	if(primeiro == (Livro *) NULL){
 		primeiro= atual = NovoLivro;
	 }
	 else{
	 	atual = primeiro;
	 	while(atual ->Proximo !=(Livro *) NULL)
	 	atual= atual ->Proximo;
	 	atual ->Proximo = NovoLivro;
	 	atual = NovoLivro;
	 }
	 printf("Digite Titulo : ");
	 gets(atual -> Titulo);
	 printf("Digite Autor : ");
	 gets(atual -> Autor);
	 printf("Digite o numero do registro : ");
	 gets(temp);
	 atual -> NumReg = atoi(temp);
	 printf("Digite o preco : ");
	 atual -> Preco = atof(temp);
	 atual -> Proximo =(Livro *)NULL;
 }
 
 	void PrintLivro(){
 		if(primeiro == (Livro *) NULL){
 			puts("Lista VAZIA");
 			return;
		 }
		 atual = primeiro;
		 do{
		 	printf("Titulo : %s\n", atual -> Titulo);
		 	printf("Autor : %s\n", atual -> Autor);
		 	printf("Numero do Registro : %d\n", atual -> NumReg);
		 	printf("Preco : %.2f\n\n", atual -> Preco);
		 	atual = atual -> Proximo;
		 }while(atual != NULL);
	 }
	 
int main(){
	char ch;
	primeiro = (Livro *) NULL;
	
	do{
		GetLivro();
		puts("\nInserir outro livro(s/n?)");
		ch = getch();
	}while ((ch != 'n') && (ch != 'N'));
	puts("\nLista dos livros Cadastrados");
	puts("=============================");
	PrintLivro();
	system("PAUSE");
	return 0;
}
*/

// Exemplo Arvore

typedef struct stNo{
	int info;
	struct stNo *esq, *dir;
} tNo;

tNo *cria_arvore(int);
tNo *cria_no();
void pos_esq (tNo *, int);
void pos_dir (tNo *, int);

void main(){	
	tNo *raiz, *p, *q;
	char linha[80], *numero;
	int num;
	
	gets(linha);
	numero = strtok(linha, " ");
	num = atoi(numero);
	raiz = cria_arvore(num);
	numero = strtok(NULL, " ");
	while (numero){
		q = raiz; p = raiz;
		printf("Li numero %d\n", num);
		num = atoi(numero);
		while(num < p -> info && q){
			p = q;
			if(num < p -> info){
				q = p -> esq;
			}
			else{
				q = p -> dir;
			}
		}
		
		if (num == p -> info){
			printf("O numero %d já existe na arvore.\n", num);
		}
		else{
			if (num < p -> info)
		pos_esq(p, num);
			
			else
		pos_dir(p, num);
			
		}
		numero = strtok(NULL, " ");
	}
}

tNo *cria_arvore (int x){
	tNo *p;
	
	p = cria_no ();
	if(p){
		p -> info = x;
		return p;
	}
	else{
		puts("Faltou espaco para alocar no.");
		exit(1);
	}
}

tNo *cria_no(){
	tNo *p;
	
	if ((p = (tNo *) malloc(sizeof(tNo))) == NULL){
		return NULL;
	}
	else{
		p -> esq = NULL, p -> dir = NULL;
		return p;
	}
}

void pos_esq(tNo *p, int x) { 
  tNo *q; 

  if (p->esq) 
    puts("Operacao de insercao a esquerda ilegal."); 
  else { 
    q = cria_arvore(x); 
    p->esq = q; 
  } 
} 
  

void pos_dir(tNo *p, int x) { 
  tNo *q; 

  if (p->dir) 
    puts("Operacao de insercao a direita ilegal."); 
  else { 
    q = cria_arvore(x); 
    p->dir = q; 
  } 
} 


