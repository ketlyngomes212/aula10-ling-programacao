#include <stdio.h>
#include <stdlib.h>

int main(){
    int num,i;
    int *vetor;

    printf("Quantos números vc quer digitar? ");
    scanf("%d", &num);

    vetor = (int *) malloc(num * sizeof(int));
    if(vetor == NULL){
        printf("ERRO de alocação");
        return 1;
    }

    for ( i = 0; i < num; i++){
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\n=== Números pares===\n");
    for ( i = 0; i < num; i++){
        if(vetor[i] % 2 ==0){
            printf("%d\n", vetor[i]);
        }
    }
    free(vetor);

    return 0;
}
