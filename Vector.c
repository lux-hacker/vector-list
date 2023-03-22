#include "Vector.h"
#include "stdlib.h"

Matrix* createMatrix(const Vector* sizes){
    Matrix* matrix = malloc(sizeof(Matrix));
    matrix->size = sizes->size;
    matrix->mas = malloc(matrix->size * sizeof(Vector));
    for(int i = 0; i < matrix->size; i++){
        matrix->mas[i].size = sizes->mas[i];
        matrix->mas[i].mas = malloc(matrix->mas[i].size * sizeof(int));

        for(int j = 0; j < matrix->mas[i].size; j++){
            matrix->mas[i].mas[j] = rand() % 100 + 1;
        }
    }
    return matrix;
}

int minInRow(const Matrix* matrix, int row){
    int min = matrix->mas[row].mas[0];
    for(int i = 1; i < matrix->mas[row].size; i++){
        if(min > matrix->mas[row].mas[i])
            min = matrix->mas[row].mas[i];
    }
    return min;
}

int minInMatrix(const Matrix* matrix){
    int min = minInRow(matrix, 0);
    for(int i = 1; i < matrix->size; i++){
        int t = minInRow(matrix, i);
        if(min > t)
            min = t;
    }
    return min;
}

void insert(Matrix* matrix, int row, int column, int src){
    if(row < matrix->size) {
        matrix->mas[row].mas = realloc(matrix->mas[row].mas,
                                       (matrix->mas[row].size + 1) * sizeof(int));
        for (int i = matrix->mas[row].size; i > column; i--)
            matrix->mas[row].mas[i] = matrix->mas[row].mas[i - 1];
        matrix->mas[row].mas[column] = src;
        matrix->mas[row].size++;
    } else if (row == matrix->size) {
        matrix->mas = realloc(matrix->mas,
                              (matrix->size + 1) * sizeof(Vector));
        matrix->mas[row].size = 1;
        matrix->mas[row].mas = malloc(sizeof(int));
        matrix->mas[row].mas[0] = src;
        matrix->size++;
    }
}

void sortVector(Vector* vector){
    for(int i = 0; i < vector->size; i++){
        for(int j = 0; j < vector->size; j++){
            if(vector->mas[j] > vector->mas[i]){
                int t = vector->mas[j];
                vector->mas[j] = vector->mas[i];
                vector->mas[i] = t;
            }
        }
    }
}

void sort(Matrix* matrix){
    for(int i = 0; i < matrix->size; i++)
        sortVector(matrix->mas + i);

    for(int i = 0; i < matrix->size; i++){
        for(int j = 0; j < matrix->size; j++){
            if(matrix->mas[j].mas[0] > matrix->mas[i].mas[0] ){
                Vector t = matrix->mas[j];
                matrix->mas[j] = matrix->mas[i];
                matrix->mas[i] = t;
            }
        }
    }
}
