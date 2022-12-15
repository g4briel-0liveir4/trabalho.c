

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100
#define LETRAS 20
#define TRUE 1
#define FALSE 0
struct ficha_de_aluno {
  char nome[LETRAS];
  double nota;
  int matricula;
};
struct ficha_de_aluno ficha[TAM];
void clear(){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
void inicializar() {
  for (int i = 0; i < TAM; i++) {
    strcpy(ficha[i].nome, "NULL");
    ficha[i].nota = 0.0;
    ficha[i].matricula = 0;
  }
}
void zerar(int i) {
  strcpy(ficha[i].nome, "NULL");
  ficha[i].matricula = 0;
  ficha[i].nota = 0.0;
}
void adicionar() {
  clear();
	char exit;
  for (int i = 0; i < TAM; i++) {
    if (ficha[i].matricula == 0) {
      printf("Nome do aluno(a): ");
      getchar();
      fgets(ficha[i].nome, LETRAS, stdin);
			
      printf("Aluno adicionado a base\n\n");
      ficha[i].matricula = i + 1;
      break;
    } else {
      continue;
    }
  }
	printf("Pressione enter para sair: ");
	scanf("%c", &exit);
	clear();
}

void remover() {
  clear();
	int i, j;
	char exit;
  printf("Digite a matricula: ");
  scanf("%d", &j);
  for(i = 0; i< TAM; i++){
		if (j == ficha[i].matricula && j!= 0) {
			printf("Aluno removido: %s\n", ficha[i].nome);
      zerar(i);
      break;
    } 
		else if(j != ficha[i].matricula || j == 0 ) 
		{
      continue;
  	}
	}
	printf("pressione enter para sair: ");
	getchar();
	scanf("%c", &exit);
	clear();
}
void botarnota(){
clear();
int matri_proc; 
double nota_digi;
char exit;
	printf("Digite a matricula do aluno: ");
	scanf("%d", &matri_proc);
	for (int i = 0; i< TAM; i++){
		if (matri_proc == ficha[i].matricula && matri_proc != 0)
		{
			printf("Aluno : %s\n", ficha[i].nome);	
			printf("Digite a nota: ");
			scanf("%lf", &nota_digi );
			ficha[i].nota = nota_digi;
			printf("\nNota adicionada.\n");
			break;
		} else if (matri_proc != ficha[i].matricula || matri_proc == 0){
			continue;
		}
	}
	printf("Pressione enter para sair: ");
	getchar();
	scanf("%c", &exit);
	clear();
}
void listar() {
  clear();
	int escolha, i, prox;
	char exit;
	for (i = 0, prox = i + 1; i<TAM; i++) {
    // cmp1 = strcmp(ficha[i].nome, "NULL");
    if (ficha[i].matricula == 0) {
			continue;
    } else {
      printf("Nome: %s       ^ Matricula: %d\tnota: %.1lf\n", ficha[i].nome,
             ficha[i].matricula, ficha[i].nota);
      // prox = i + 1;
      // cmp2  = strcmp(ficha[prox].nome,"NULL");
      if (ficha[prox].matricula == 0) {
        continue;
      } 
			else {
        continue;
      }
    }
  }
	printf("\n\npressione enter para voltar ao menu: ");
	getchar();
	scanf("%c", &exit);
	clear();
}
void menu() {
  int escolha;
  inicializar();
  do {
    printf("1-Adicionar alunos\n");
    printf("2-Listar aluno(a)s\n");
    printf("3-Remover aluno(a)\n");
    printf("4-adicionar nota\n");
    printf("0-Sair\n\nEscolha: ");
    scanf("%d", &escolha);
    switch (escolha) {
    case 1:
      adicionar();
      break;
    case 2:
      listar();
      break;
    case 3:
      remover();
      break;
		case 4:
      botarnota();
      break;
    case 0:
      printf("voce saiu!");
      break;
    }
  } while (escolha != 0);
}
int main(void) {
	clear();
	menu();
  return 0;
}
