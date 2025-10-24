#include <stdio.h>
#include <stdlib.h>

int main(){
    int t1, t2, i;
    int *vet1, *vet2, *vet3;

    printf("Digite o tamanho do primeiro vetor: ");
    scanf("%d", &t1);
    printf("Digite o tamanho do segundo vetor: ");
    scanf("%d", &t2);

    vet1 = (int *) malloc(t1 * sizeof(int));
    vet2 = (int *) malloc(t2 * sizeof(int));

    if(vet1 == NULL || vet2 == NULL){
        printf("ERRO de alocação");
        return 1;
    }

    printf("\n==Preencha o primeiro vetor==\n");
    for (i = 0; i < t1; i++) {
        printf("vet1[%d] = ", i + 1);
        scanf("%d", &vet1[i]);
    }

    printf("\n==Preencha o segundo vetor==\n");
    for (i = 0; i < t2; i++) {
        printf("vet2[%d] = ", i + 1);
        scanf("%d", &vet2[i]);
    }

    vet3 = (int *) malloc((t1 + t2) * sizeof(int));

    for (i = 0; i < t1; i++) {
        vet3[i] = vet1[i];
    }
    for (i = 0; i < t2; i++) {
        vet3[t1 + i] = vet2[i];
    }

    printf("\n==Vetor concatenado==\n");
    for (i = 0; i < t1 + t2; i++) {
        printf("%d\n", vet3[i]);
    }

    free(vet1);
    free(vet2);
    free(vet3);

    return 0;
}