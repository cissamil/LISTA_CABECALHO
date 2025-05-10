#include <stdio.h>

#include <stdlib.h>

#include "lista.h"

Lista* criarLista() {

Lista* lista = (Lista*)malloc(sizeof(Lista));

lista->cabeca = (No*)malloc(sizeof(No)); // nó de cabeçalho

lista->cabeca->prox = NULL;

return lista;

}

void inserirInicio(Lista* lista, int valor) {

No* novo = (No*)malloc(sizeof(No));

novo->dado = valor;

novo->prox = lista->cabeca->prox;

lista->cabeca->prox = novo;

}

void imprimirLista(Lista* lista) {

No* atual = lista->cabeca->prox;

while (atual != NULL) {

printf("%d -> ", atual->dado);

atual = atual->prox;

}

printf("NULL\n");

}

int remover(Lista* lista, int valor) {

No* ant = lista->cabeca;

No* atual = ant->prox;

while (atual != NULL && atual->dado != valor) {

ant = atual;

atual = atual->prox;

}

if (atual == NULL) return 0; // não encontrado

ant->prox = atual->prox;

free(atual);

return 1; // removido com sucesso

}

void liberarLista(Lista* lista) {

No* atual = lista->cabeca;

while (atual != NULL) {

No* temp = atual;

atual = atual->prox;

free(temp);

}

free(lista);

}

void reverterLista(Lista* lista) {
    No* anterior = NULL;
    No* atual = lista->cabeca->prox;
    No* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;   // salva o próximo
        atual->prox = anterior;  // inverte o ponteiro
        anterior = atual;        // move o anterior para o atual
        atual = proximo;         // avança o atual para o próximo
    }

    lista->cabeca->prox = anterior; // atualiza o ponteiro do cabeçalho
}




// Retorna o maior valor da lista. Se estiver vazia, retorna -1.

int obterMaior(Lista* lista) {
    No* atual = lista->cabeca->prox;

    if (atual == NULL) {
        printf("A lista está vazia.\n");
        return -1;
    }

    int maior = atual->dado;

    while (atual != NULL) {
        if (atual->dado > maior) {
            maior = atual->dado;
        }
        atual = atual->prox;
    }

    return maior;
}

int obterMenor(Lista* lista) {
    No* atual = lista->cabeca->prox;

    if (atual == NULL) {
        printf("A lista está vazia.\n");
        return -1;
    }

    int menor = atual->dado;

    while (atual != NULL) {
        if (atual->dado < menor) {
            menor = atual->dado;
        }
        atual = atual->prox;
    }

    return menor;
}

// Verifica se a lista está vazia
int estaVazia(Lista* lista) {
    // Se o primeiro nó de dados (após o cabeçalho) for NULL, está vazia
    if (lista->cabeca->prox == NULL) {
        return 1; // Vazia
    } else {
        return 0; // Não está vazia
    }
}

// Cria uma cópia profunda da lista
Lista* copiarLista(Lista* lista) {
    Lista* copia = criarLista(); // Cria nova lista com nó de cabeçalho
    No* atual = lista->cabeca->prox;
    No* fim = copia->cabeca; // Ponteiro para o fim da nova lista

    while (atual != NULL) {
        // Cria novo nó com os mesmos dados
        No* novo = (No*)malloc(sizeof(No));
        novo->dado = atual->dado;
        novo->prox = NULL;

        // Encadeia o novo nó ao final da lista copiada
        fim->prox = novo;
        fim = novo;

        atual = atual->prox;
    }

    return copia;
}

void concatenarListas(Lista* l1, Lista* l2) {
    No* atual = l1->cabeca;

    // Vai até o último nó de l1
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    // Conecta l2 no final de l1
    atual->prox = l2->cabeca->prox;

    // Esvazia l2
    l2->cabeca->prox = NULL;
}

void removerDuplicatas(Lista* lista) {
    No* atual = lista->cabeca->prox;

    while (atual != NULL) {
        No* ant = atual;
        No* temp = atual->prox;

        while (temp != NULL) {
            if (temp->dado == atual->dado) {
                ant->prox = temp->prox;
                free(temp);
                temp = ant->prox;
            } else {
                ant = temp;
                temp = temp->prox;
            }
        }

        atual = atual->prox;
    }
}

void inserirFim(Lista* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;

    No* atual = lista->cabeca;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo;
}

int contarElementos(Lista* lista) {
    int count = 0;
    No* atual = lista->cabeca->prox;

    while (atual != NULL) {
        count++;
        atual = atual->prox;
    }

    return count;
}

int buscar(Lista* lista, int valor) {
    No* atual = lista->cabeca->prox;

    while (atual != NULL) {
        if (atual->dado == valor) {
            return 1;
        }
        atual = atual->prox;
    }

    return 0;
}



