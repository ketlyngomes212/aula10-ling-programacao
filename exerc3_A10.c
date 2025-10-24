#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char **lista = NULL;
    int qtd = 2;
    int i;
    char item[50], opcao;

    lista = (char **) malloc(qtd * sizeof(char *));
    if (lista == NULL) {
        printf("Erro de alocacao\n");
        return 1;
    }

    for (i = 0; i < qtd; i++) {
        printf("Digite o item %d: ", i + 1);
        scanf(" %49[^\n]", item);

        lista[i] = (char *) malloc((strlen(item) + 1) * sizeof(char));
        strcpy(lista[i], item);
    }

    do {
        printf("\nDeseja adicionar mais um item? (s/n): ");
        scanf(" %c", &opcao);

        if (opcao == 's' || opcao == 'S') {
            qtd++;
            lista = (char **) realloc(lista, qtd * sizeof(char *));
            if (lista == NULL) {
                printf("Erro de realocacao!\n");
                return 1;
            }

            printf("Digite o novo item: ");
            scanf(" %49[^\n]", item);

            lista[qtd - 1] = (char *) malloc((strlen(item) + 1) * sizeof(char));
            strcpy(lista[qtd - 1], item);
        }
    } while (opcao == 's' || opcao == 'S');

    printf("\nLista de compras:\n");
    for (i = 0; i < qtd; i++) {
        printf("- %s\n", lista[i]);
    }

    for (i = 0; i < qtd; i++) {
        free(lista[i]);
    }
    free(lista);

    return 0;
}
