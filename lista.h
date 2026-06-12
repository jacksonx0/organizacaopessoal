#ifndef LISTA_H
#define LISTA_H

typedef struct nodo {
    char dado[100];
    struct nodo *prox;
} Nodo;

typedef struct {
    Nodo *inicio;
} Lista;

void criarLista(Lista *l);

void adicionarInicio(Lista *l, char valor[]);
void adicionarFinal(Lista *l, char valor[]);
void adicionarPosicao(Lista *l, char valor[], int pos);

void removerPrimeiro(Lista *l);
void removerUltimo(Lista *l);
void removerPosicao(Lista *l, int pos);

void exibir(Lista *l);

void liberarLista(Lista *l);

#endif