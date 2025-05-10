#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void mostrarMenu() {
    printf("\n====== MENU  ======\n");
    printf("1. Inserir no inicio\n");
    printf("2. Inserir no final\n");
    printf("3. Remover valor\n");
    printf("4. Imprimir lista\n");
    printf("5. Contar elementos\n");
    printf("6. Buscar valor\n");
    printf("7. Reverter lista\n");
    printf("8. Obter maior valor\n");
    printf("9. Obter menor valor\n");
    printf("10. Criar copia da lista\n");
    printf("11. Concatenar com nova lista\n");
    printf("12. Remover duplicatas\n");
    printf("0. Sair\n");
    printf("========================================\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Lista* lista = criarLista();
    int opcao, valor, resultado;

    do {
        mostrarMenu();
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("Digite o valor a inserir no inicio: ");
            scanf("%d", &valor);
            inserirInicio(lista, valor);
            break;

        case 2:
            printf("Digite o valor a inserir no final: ");
            scanf("%d", &valor);
            inserirFim(lista, valor);
            break;

        case 3:
            printf("Digite o valor a remover: ");
            scanf("%d", &valor);
            resultado = remover(lista, valor);
            if (resultado)
                printf("Valor removido com sucesso.\n");
            else
                printf("Valor noo encontrado.\n");
            break;

        case 4:
            printf("Conteudo da lista:\n");
            imprimirLista(lista);
            break;

        case 5:
            printf("A lista contém %d elemento(s).\n", contarElementos(lista));
            break;

        case 6:
            printf("Digite o valor a buscar: ");
            scanf("%d", &valor);
            resultado = buscar(lista, valor);
            if (resultado)
                printf("Valor encontrado na lista.\n");
            else
                printf("Valor nao encontrado.\n");
            break;

        case 7:
            reverterLista(lista);
            printf("Lista revertida com sucesso.\n");
            break;

        case 8:
            resultado = obterMaior(lista);
            if (resultado == -1)
                printf("Lista vazia.\n");
            else
                printf("Maior valor: %d\n", resultado);
            break;

        case 9:
            resultado = obterMenor(lista);
            if (resultado == -1)
                printf("Lista vazia.\n");
            else
                printf("Menor valor: %d\n", resultado);
            break;

        case 10: {
            Lista* copia = copiarLista(lista);
            printf("Copia da lista: ");
            imprimirLista(copia);
            liberarLista(copia);
            break;
        }

        case 11: {
            Lista* nova = criarLista();
            int n, val;
            printf("Quantos valores deseja inserir na nova lista? ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++) {
                printf("Valor %d: ", i + 1);
                scanf("%d", &val);
                inserirFim(nova, val);
            }
            concatenarListas(lista, nova);
            liberarLista(nova); // opcional, pois já foi esvaziada
            printf("Listas concatenadas com sucesso.\n");
            break;
        }

        case 12:
            removerDuplicatas(lista);
            printf("Duplicatas removidas com sucesso.\n");
            break;

        case 0:
            printf("Encerrando programa.\n");
            liberarLista(lista);
            break;

        default:
            printf("Opção invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

