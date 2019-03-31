#include <stdio.h>
#include <stdlib.h>

#include "matrixio.h"

int extendMatrix(int ***matrixPtr, int newSize) {
  (*matrixPtr) = (int**) realloc(*matrixPtr, newSize * sizeof(int*));

  return matrixPtr != NULL || newSize == 0;
}

int extendArray(int **arrayPtr, int newSize) {
  (*arrayPtr) = (int*) realloc(*arrayPtr, newSize * sizeof(int));

  return arrayPtr != NULL || newSize == 0;
}

int powi(int base, int power) {
  int num = 1;
  while (power) {
    num *= base;
    power--;
  }

  return num;
}

int reverse(int num) {
  int ret = 0;

  while (num) {
    ret *= 10;
    ret += num % 10;
    num /= 10;
  }

  return ret;
}

int * readLine(FILE *file, int *columns) {

  int size = 0;
  int *row = NULL;
  *columns = 0;

  char c = fgetc(file);
  while (1) {
    if (c == '\n' || c == -1) {
      break;
    }

    if (c >= '0' && c <= '9'){

      int number = 0;
      int power = 0;
      while (c >= '0' && c <= '9') {
        number += powi(10, power++) * (c - '0');
        c = fgetc(file);
      }

      extendArray(&row, ++size);
      row[size - 1] = reverse(number);
      continue;
    } else if (c != ' ') {
      break;
    }

    c = (char) fgetc(file);
  }
  *columns = size;
  return row;
}

int ** readMatrix(const char *fileName, int *rowsPtr, int *colsPtr) {
  int **matrix = NULL;

  int rows = 0;
  int columns = -1;

  FILE *file = fopen(fileName, "r");

  if (ferror(file) > 0) {
    return NULL;
  }

  while (1) {
    int oldColumns = columns;

    int *newRow = readLine(file, &columns);

    if (newRow == NULL) {
      columns = oldColumns;
      break;
    }

    if (oldColumns >= 0 && oldColumns != columns) {
      return NULL;
    }

    extendMatrix(&matrix, ++rows);
    matrix[rows - 1] = newRow;

  }

  *rowsPtr = rows;
  *colsPtr = columns;
  return matrix;
}
