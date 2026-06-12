#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void criarLista(Lista *l) {
    l->inicio = NULL;
}

void adicionarInicio(Lista *l, char valor[]) {

    Nodo *novo = (Nodo*) malloc(sizeof(Nodo));

    strcpy(novo->dado, valor);

    novo->prox = l->inicio;
    l->inicio = novo;
}

void adicionarFinal(Lista *l, char valor[]) {

    Nodo *novo = (Nodo*) malloc(sizeof(Nodo));

    strcpy(novo->dado, valor);
    novo->prox = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
        return;
    }

    Nodo *aux = l->inicio;

    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    aux->prox = novo;
}

void adicionarPosicao(Lista *l, char valor[], int pos) {

    if (pos == 0) {
        adicionarInicio(l, valor);
        return;
    }

    Nodo *novo = (Nodo*) malloc(sizeof(Nodo));

    strcpy(novo->dado, valor);

    Nodo *aux = l->inicio;

    int i = 0;

    while (aux != NULL && i < pos - 1) {
        aux = aux->prox;
        i++;
    }

    if (aux == NULL) {
        printf("Posicao nao encontrada!\n");
        free(novo);
        return;
    }

    novo->prox = aux->prox;
    aux->prox = novo;
}

void removerPrimeiro(Lista *l) {

    if (l->inicio == NULL)
        return;

    Nodo *aux = l->inicio;

    l->inicio = aux->prox;

    free(aux);
}

void removerUltimo(Lista *l) {

    if (l->inicio == NULL)
        return;

    if (l->inicio->prox == NULL) {
        free(l->inicio);
        l->inicio = NULL;
        return;
    }

    Nodo *aux = l->inicio;

    while (aux->prox->prox != NULL) {
        aux = aux->prox;
    }

    free(aux->prox);
    aux->prox = NULL;
}

void removerPosicao(Lista *l, int pos) {

    if (pos == 0) {
        removerPrimeiro(l);
        return;
    }

    Nodo *aux = l->inicio;

    int i = 0;

    while (aux != NULL && i < pos - 1) {
        aux = aux->prox;
        i++;
    }

    if (aux == NULL || aux->prox == NULL) {
        printf("Posicao nao encontrada!\n");
        return;
    }

    Nodo *temp = aux->prox;

    aux->prox = temp->prox;

    free(temp);
}

void exibir(Lista *l) {

    Nodo *aux = l->inicio;

    if (aux == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    while (aux != NULL) {
        printf("- %s\n", aux->dado);
        aux = aux->prox;
    }
}

void liberarLista(Lista *l) {

    Nodo *aux = l->inicio;

    while (aux != NULL) {

        Nodo *temp = aux;

        aux = aux->prox;

        free(temp);
    }

    l->inicio = NULL;
}