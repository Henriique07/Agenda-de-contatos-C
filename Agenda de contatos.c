#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 100

void pausar(){// Função para pausar 
	printf ("Aperte enter para continuar...\n");
	getchar();
}

char nomes[tam][100];
char numero[tam][100];
int contato_ativo = 0;

void adicionar(){// Uma função é alocada dentro das chaves para ser chamada dentro main

	if (contato_ativo >= tam) {// Função para não ultrpassar o limite de contatos que pode ser adicionados
        printf("Limite de contatos atingido! Nao e possivel adicionar mais contatos\n");
        pausar();
        system("cls");
        return;
    }
    
	printf ("=-=-=[Adicionar contato]=-=-=\n");
	printf ("Nome: ");// Recebe o nome que sera colocado no contato
	fgets (nomes[contato_ativo], 100, stdin);// Recebe o que for digitado no teclado
	nomes[contato_ativo][strcspn(nomes[contato_ativo], "\n")] = '\0';// Remove o \n
	
	printf ("Numero: ");// Recebe o numero do contato
	fgets (numero[contato_ativo], 100, stdin);
    numero[contato_ativo][strcspn(numero[contato_ativo], "\n")] = '\0';
	contato_ativo++;// Cada contato adicionado recebe +1 para mostrar que o contato está ativo
	
	printf ("\n");// Pula uma linha
	printf ("Contato adicionado com sucesso!\n");
	pausar();// Da um pause no programa
	system ("cls");// Limpa a pagina
}// end adicionar

void listar(){
	
	printf ("=-=-=[Lista de contatos]=-=-=\n");
	for (int i=0;i<contato_ativo;i++){// Loop finito para mostrar os contatos adicionados
		printf ("Nome: %s\n", nomes[i]);// Exbie o nome do contato
		printf ("Numero: %s\n", numero[i]);// Exibe o numero do contato
	}
	pausar();
	system ("cls");
}// end listar

void excluir(){// Função para excluir um contato desejado

	char nome[100];
	printf ("=-=-=[Excluir contato]=-=-=\n");
	printf ("Digite o nome do contato que deseja excluir: ");
	fgets (nome, 100, stdin);// Recebe o nome do contato que está adicionado para excluir
	nome[strcspn(nome, "\n")] = '\0';
	
	int encontrado = 0;
	
	for (int i=0;i<contato_ativo;i++){// Procura os contatos
		if (strcmp(nomes[i], nome) == 0){// Comapara o nome digitado pelo usuario com os nomes dos contatos que ja estão adicioando
			for (int j = i; j < contato_ativo - 1; j++) {// Se encontrou desloca os contatos seguintes uma posição para trás
                strcpy(nomes[j], nomes[j + 1]);// Serve para tapar o buraco ao exlcuir um contato
                strcpy(numero[j], numero[j + 1]);
            }
            contato_ativo--;// Diminui a quantidade de contatos ativos para não ficar contatos duplicados
            encontrado = 1;// Marca que encontrou
            printf("Contato excluido com sucesso!\n");
            break;
		}
	}
	if (!encontrado) {// Se não encontrou
        printf("Erro: contato nao encontrado!\n");
    }
}// end excluir

int main(){
	
	int opcao;
	
	do{
		printf ("=-=-=[MENU]=-=-=\n");
		printf ("1 - Adicionar contato\n");
		printf ("2 - Listar contatos\n");
		printf ("3 - Excluir contato\n");
		printf ("4 - Sair\n");
		scanf ("%d", &opcao);// Recebe a opção que o usuario escolheu
		getchar();
	
		system("cls");
	
		switch (opcao){// É recebido a opção do usuario e de acordo com a opcçao uma funçao ira ser executada
			case 1:
				adicionar();// Caso 1 vai para função que vai adicionar um novo contato
				break;
			case 2:
				listar();// Caso 2 vai para função que vai mostrar os contatos que estão adicionado
				break;
			case 3:
				excluir();// Caso 3 vai para função que vai excluir um contato desejado pelo usuario
				break;
			case 4:
				printf ("Programa encerrado!\n");// Encerra o programa
				break;
			default:
				printf ("Erro: opcao invalida!\n");// Caso o usuario digite uma opção que não está listada
		}// end swithc	
	}while(opcao != 4);// end while
	
 return 0;
}// end main
