#ifndef READMATRIX_MATRIXIO_H
#define READMATRIX_MATRIXIO_H

int extendMatrix(int ***matrixPtr, unsigned int newSize);
int extendArray(int **arrayPtr, unsigned int newSize);
int powi(int base, int power);
int reverse(int num);
int * readLine(FILE *file, unsigned int *columns);
int ** readMatrix(const char *fileName, unsigned int *rowsPtr, unsigned int *colsPtr);

#endif //READMATRIX_MATRIXIO_H
