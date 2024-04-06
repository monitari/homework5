#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// allocation_matrix �Լ��� ��� ���� ������ �Է¹޾� 2���� �迭�� �������� �Ҵ��ϰ� ��ȯ�ϴ� �Լ�
int** allocation_matrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*)); // ���� ������ŭ �޸� �Ҵ�
    for (int i = 0; i < rows; i++) matrix[i] = (int*)malloc(cols * sizeof(int)); // ���� ������ŭ �޸� �Ҵ�
    return matrix; // 2���� �迭 ��ȯ
}

// fill_matrix �Լ��� 2���� �迭�� ��� ���� ������ �Է¹޾� �迭�� ������ ������ ä��� �Լ�
void fill_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) matrix[i][j] = rand() % 10; // 0���� 9������ ������ ������ ä��
    }
}

// print_matrix �Լ��� 2���� �迭�� ��� ���� ������ �Է¹޾� �迭�� ����ϴ� �Լ�
void print_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) { 
        for (int j = 0; j < cols; j++) printf("%-3d ", matrix[i][j]); // 3�ڸ��� ���
        printf("\n");
    }
}

// addition_matrix �Լ��� �� ����� ���ϴ� �Լ�
int** addition_matrix(int** matrixA, int** matrixB, int rows, int cols) {
    int** result = allocation_matrix(rows, cols); // ��� ����� �Ҵ�
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) result[i][j] = matrixA[i][j] + matrixB[i][j]; // �� ����� ���� ����
    }
    return result; // ��� ��� ��ȯ
}

// subtraction_matrix �Լ��� �� ����� ���� �Լ�
int** subtraction_matrix(int** matrixA, int** matrixB, int rows, int cols) {
    int** result = allocation_matrix(rows, cols); // ��� ����� �Ҵ�
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) result[i][j] = matrixA[i][j] - matrixB[i][j]; // �� ����� ���� ����
    }
    return result; // ��� ��� ��ȯ
}

// transpose_matrix �Լ��� ����� ��ġ�ϴ� �Լ�
int** transpose_matrix(int** matrix, int rows, int cols) {
    //printf("%s : %s at %d\n",__FILE__,__func__,__LINE__);
    int** result = allocation_matrix(cols, rows); // ��ġ ����� �Ҵ�
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) result[j][i] = matrix[i][j]; // ��ġ ��� ����
    }
    return result; // ��ġ ��� ��ȯ
}

// multiply_matrix �Լ��� �� ����� ���ϴ� �Լ�
int** multiply_matrix(int** matrixA, int** matrixB, int rowsA, int colsA, int colsB) {
    int** result = allocation_matrix(rowsA, colsB); // ��� ����� �Ҵ�
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0; 
            for (int k = 0; k < colsA; k++) 
                result[i][j] += matrixA[i][k] * matrixB[k][j]; // �� ����� ���� ����
        }
    }
    return result; // ��� ��� ��ȯ
}

// free_matrix �Լ��� 2���� �迭�� �����ϴ� �Լ�
void free_matrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) free(matrix[i]); // ���� ������ŭ �޸� ����
    free(matrix); // ���� ������ŭ �޸� ����
}

int main() {
    int rowsA, colsA, rowsB, colsB; // A, B ����� ��� ���� ����
    srand(time(NULL)); // ���� �õ� ����

    // ��� A�� ��� ���� ���� �Է�
    printf("��� A�� ��� ���� ������ �Է��Ͻÿ�: ");
    scanf("%d %d", &rowsA, &colsA);
    // ��� B�� ��� ���� ���� �Է�
    printf("��� B�� ��� ���� ������ �Է��Ͻÿ�: ");
    scanf("%d %d", &rowsB, &colsB);

    // matrixA�� matrixB�� ����� �Ҵ�
    int** matrixA = allocation_matrix(rowsA, colsA);
    int** matrixB = allocation_matrix(rowsB, colsB);

    // matrixA�� matrixB�� ������ ������ ä��
    fill_matrix(matrixA, rowsA, colsA);
    fill_matrix(matrixB, rowsB, colsB);
    printf("========== 2023041018 ������ ==========\n");

    // matrixA�� matrixB ���
    printf("��� A : \n");
    print_matrix(matrixA, rowsA, colsA);
    printf("��� B : \n");
    print_matrix(matrixB, rowsB, colsB);

    // matrixA�� matrixB�� �� ���
    printf("��� A + ��� B : \n");
    print_matrix(addition_matrix(matrixA, matrixB, rowsA, colsA), rowsA, colsA);

    // matrixA�� matrixB�� �� ���
    printf("��� A - ��� B : \n");
    print_matrix(subtraction_matrix(matrixA, matrixB, rowsA, colsA), rowsA, colsA);

    // matrixA�� matrixB�� ��ġ ���
    printf("��� A�� ��ġ : \n");
    print_matrix(transpose_matrix(matrixA, rowsA, colsA), colsA, rowsA);
    printf("��� B�� ��ġ : \n");
    print_matrix(transpose_matrix(matrixB, rowsB, colsB), colsB, rowsB);

    // matrixA�� matrixB�� �� ���
    printf("��� A X ��� B : \n");
    print_matrix(multiply_matrix(matrixA, matrixB, rowsA, colsA, colsB), rowsA, colsB);

    // matrixA�� matrixB�� ����
    free_matrix(matrixA, rowsA);
    free_matrix(matrixB, rowsB);

    return 0;
}