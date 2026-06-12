#include <stdio.h>
#include <string.h>
#include "lista.h"

void menuLista(Lista *l, char nome[]) {

    int op, pos;
    char texto[100];

    do {

        printf("\n===== %s =====\n", nome);
        printf("1 - Adicionar no inicio\n");
        printf("2 - Adicionar no final\n");
        printf("3 - Adicionar em uma posicao\n");
        printf("4 - Remover primeiro item\n");
        printf("5 - Remover ultimo item\n");
        printf("6 - Remover por posicao\n");
        printf("7 - Exibir lista\n");
        printf("0 - Voltar\n");

        printf("Opcao: ");
        scanf("%d", &op);
        getchar();

        switch(op) {

            case 1:

                printf("Digite o item: ");
                fgets(texto, 100, stdin);
                texto[strcspn(texto, "\n")] = '\0';

                adicionarInicio(l, texto);
                break;

            case 2:

                printf("Digite o item: ");
                fgets(texto, 100, stdin);
                texto[strcspn(texto, "\n")] = '\0';

                adicionarFinal(l, texto);
                break;

            case 3:

                printf("Digite o item: ");
                fgets(texto, 100, stdin);
                texto[strcspn(texto, "\n")] = '\0';

                printf("Posicao: ");
                scanf("%d", &pos);
                getchar();

                adicionarPosicao(l, texto, pos);
                break;

            case 4:

                removerPrimeiro(l);
                printf("Primeiro item removido!\n");
                break;

            case 5:

                removerUltimo(l);
                printf("Ultimo item removido!\n");
                break;

            case 6:

                printf("Posicao: ");
                scanf("%d", &pos);
                getchar();

                removerPosicao(l, pos);
                break;

            case 7:

                printf("\n--- LISTA ---\n");
                exibir(l);
                break;

            case 0:
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(op != 0);
}

int main() {

    Lista tarefas;
    Lista mercado;
    Lista contatos;

    criarLista(&tarefas);
    criarLista(&mercado);
    criarLista(&contatos);

    int op;

    do {

        printf("\n===== ORGANIZADOR PESSOAL =====\n");
        printf("1 - Tarefas\n");
        printf("2 - Supermercado\n");
        printf("3 - Contatos\n");
        printf("0 - Sair\n");

        printf("Opcao: ");
        scanf("%d", &op);
        getchar();

        switch(op) {

            case 1:
                menuLista(&tarefas, "TAREFAS");
                break;

            case 2:
                menuLista(&mercado, "SUPERMERCADO");
                break;

            case 3:
                menuLista(&contatos, "CONTATOS");
                break;

            case 0:
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(op != 0);

    liberarLista(&tarefas);
    liberarLista(&mercado);
    liberarLista(&contatos);

    printf("\nPrograma encerrado.\n");

    return 0;
}