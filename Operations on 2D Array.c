#include <stdio.h>

// Function to print a matrix
void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("/n");
    }
}

void addMatrices(int r1, int c1, int matrix1[r1][c1], int r2, int c2, int matrix2[r2][c2], int result[r1][c1]) {
    if (r1 != r2 || c1 != c2) {
        printf("Error: Matrices must have the same dimensions for addition.\n");
        return;
    }
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int r1, int c1, int matrix1[r1][c1], int r2, int c2, int matrix2[r2][c2], int result[r1][c1]) {
    if (r1 != r2 || c1 != c2) {
        printf("Error: Matrices must have the same dimensions for subtraction.\n");
        return;
    }
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function for matrix multiplication
void multiplyMatrices(int r1, int c1, int matrix1[r1][c1], int r2, int c2, int matrix2[r2][c2], int result[r1][c2]) {
    if (c1 != r2) {
        printf("Error: Number of columns of first matrix must equal number of rows of second matrix for multiplication.\n");
        return;
    }
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0; // Initialize result element
            for (int k = 0; k < c1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function for matrix transpose
void transposeMatrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int r1, c1, r2, c2;

    printf("Enter dimensions of matrix 1 (rows columns): ");
    scanf("%d %d", &r1, &c1);

    int matrix1[r1][c1];
    printf("Enter elements of matrix 1:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter dimensions of matrix 2 (rows columns): ");
    scanf("%d %d", &r2, &c2);

    int matrix2[r2][c2];
    printf("Enter elements of matrix 2:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Matrix Addition
    if (r1 == r2 && c1 == c2) {
        int sumMatrix[r1][c1];
        addMatrices(r1, c1, matrix1, r2, c2, matrix2, sumMatrix);
        printf("\nSum of matrices:\n");
        printMatrix(r1, c1, sumMatrix);
    } else {
        printf("\nMatrix addition not possible due to dimension mismatch.\n");
    }

    // Matrix Subtraction
    if (r1 == r2 && c1 == c2) {
        int diffMatrix[r1][c1];
        subtractMatrices(r1, c1, matrix1, r2, c2, matrix2, diffMatrix);
        printf("\nDifference of matrices (Matrix1 - Matrix2):\n");
        printMatrix(r1, c1, diffMatrix);
    } else {
        printf("\nMatrix subtraction not possible due to dimension mismatch.\n");
    }

    // Matrix Multiplication
    if (c1 == r2) {
        int productMatrix[r1][c2];
        multiplyMatrices(r1, c1, matrix1, r2, c2, matrix2, productMatrix);
        printf("\nProduct of matrices:\n");
        printMatrix(r1, c2, productMatrix);
    } else {
        printf("\nMatrix multiplication not possible due to dimension mismatch.\n");
    }

    // Transpose of Matrix 1
    int transposeMatrix1[c1][r1];
    transposeMatrix(r1, c1, matrix1, transposeMatrix1);
    printf("\nTranspose of Matrix 1:\n");
    printMatrix(c1, r1, transposeMatrix1);

    return 0;
}