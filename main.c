#include <stdio.h>
#include "Vector.h"
#include "stdlib.h"

int main() {
    int n;
    scanf("%d", &n);
    int* sizes = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", sizes + i);
    }
    Vector vector = {sizes, n};
    Matrix* matrix = createMatrix(&vector);
    for(int i = 0; i < matrix->size; i++){
        for(int j = 0; j < matrix->mas[i].size; j++){
            printf("%d ", matrix->mas[i].mas[j]);
        }
        printf("\n");
    }

    printf("%d\n", minInRow(matrix,3));
    printf("%d\n", minInMatrix(matrix));

    sort(matrix);
    for(int i = 0; i < matrix->size; i++){
        for(int j = 0; j < matrix->mas[i].size; j++){
            printf("%d ", matrix->mas[i].mas[j]);
        }
        printf("\n");
    }

    return 0;
}
