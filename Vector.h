#ifndef UNTITLED_VECTOR_H
#define UNTITLED_VECTOR_H

typedef struct Vector{
    int* mas;
    int size;
} Vector;

typedef struct Matrix{
    Vector* mas;
    int size;
} Matrix;

Matrix* createMatrix(const Vector*);
int minInRow(const Matrix*, int);
int minInMatrix(const Matrix*);
void insert(Matrix*, int, int, int);

void sortVector(Vector*);
void sort(Matrix*);

#endif //UNTITLED_VECTOR_H
