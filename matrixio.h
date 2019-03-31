#ifndef READMATRIX_MATRIXIO_H
#define READMATRIX_MATRIXIO_H

int extendMatrix(int ***matrixPtr, int newSize);
int extendArray(int **arrayPtr, int newSize);
int powi(int base, int power);
int reverse(int num);
int * readLine(FILE *file, int *columns);
int ** readMatrix(const char *fileName, int *rowsPtr, int *colsPtr);

#endif //READMATRIX_MATRIXIO_H
