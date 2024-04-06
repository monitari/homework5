#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// allocation_matrix 함수는 행과 열의 개수를 입력받아 2차원 배열을 동적으로 할당하고 반환하는 함수
int** allocation_matrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*)); // 행의 개수만큼 메모리 할당
    for (int i = 0; i < rows; i++) matrix[i] = (int*)malloc(cols * sizeof(int)); // 열의 개수만큼 메모리 할당
    return matrix; // 2차원 배열 반환
}

// fill_matrix 함수는 2차원 배열과 행과 열의 개수를 입력받아 배열을 랜덤한 값으로 채우는 함수
void fill_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) matrix[i][j] = rand() % 10; // 0부터 9까지의 랜덤한 값으로 채움
    }
}

// print_matrix 함수는 2차원 배열과 행과 열의 개수를 입력받아 배열을 출력하는 함수
void print_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) { 
        for (int j = 0; j < cols; j++) printf("%-3d ", matrix[i][j]); // 3자리로 출력
        printf("\n");
    }
}

// addition_matrix 함수는 두 행렬을 더하는 함수
int** addition_matrix(int** matrixA, int** matrixB, int rows, int cols) {
    int** result = allocation_matrix(rows, cols); // 결과 행렬을 할당
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) result[i][j] = matrixA[i][j] + matrixB[i][j]; // 두 행렬의 합을 저장
    }
    return result; // 결과 행렬 반환
}

// subtraction_matrix 함수는 두 행렬을 빼는 함수
int** subtraction_matrix(int** matrixA, int** matrixB, int rows, int cols) {
    int** result = allocation_matrix(rows, cols); // 결과 행렬을 할당
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) result[i][j] = matrixA[i][j] - matrixB[i][j]; // 두 행렬의 차를 저장
    }
    return result; // 결과 행렬 반환
}

// transpose_matrix 함수는 행렬을 전치하는 함수
int** transpose_matrix(int** matrix, int rows, int cols) {
    //printf("%s : %s at %d\n",__FILE__,__func__,__LINE__);
    int** result = allocation_matrix(cols, rows); // 전치 행렬을 할당
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) result[j][i] = matrix[i][j]; // 전치 행렬 저장
    }
    return result; // 전치 행렬 반환
}

// multiply_matrix 함수는 두 행렬을 곱하는 함수
int** multiply_matrix(int** matrixA, int** matrixB, int rowsA, int colsA, int colsB) {
    int** result = allocation_matrix(rowsA, colsB); // 결과 행렬을 할당
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0; 
            for (int k = 0; k < colsA; k++) 
                result[i][j] += matrixA[i][k] * matrixB[k][j]; // 두 행렬의 곱을 저장
        }
    }
    return result; // 결과 행렬 반환
}

// free_matrix 함수는 2차원 배열을 해제하는 함수
void free_matrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) free(matrix[i]); // 열의 개수만큼 메모리 해제
    free(matrix); // 행의 개수만큼 메모리 해제
}

int main() {
    int rowsA, colsA, rowsB, colsB; // A, B 행렬의 행과 열의 개수
    srand(time(NULL)); // 난수 시드 설정

    // 행렬 A의 행과 열의 개수 입력
    printf("행렬 A의 행과 열의 개수를 입력하시오: ");
    scanf("%d %d", &rowsA, &colsA);
    // 행렬 B의 행과 열의 개수 입력
    printf("행렬 B의 행과 열의 개수를 입력하시오: ");
    scanf("%d %d", &rowsB, &colsB);

    // matrixA와 matrixB에 행렬을 할당
    int** matrixA = allocation_matrix(rowsA, colsA);
    int** matrixB = allocation_matrix(rowsB, colsB);

    // matrixA와 matrixB에 랜덤한 값으로 채움
    fill_matrix(matrixA, rowsA, colsA);
    fill_matrix(matrixB, rowsB, colsB);
    printf("========== 2023041018 김준후 ==========\n");

    // matrixA와 matrixB 출력
    printf("행렬 A : \n");
    print_matrix(matrixA, rowsA, colsA);
    printf("행렬 B : \n");
    print_matrix(matrixB, rowsB, colsB);

    // matrixA와 matrixB의 합 출력
    printf("행렬 A + 행렬 B : \n");
    print_matrix(addition_matrix(matrixA, matrixB, rowsA, colsA), rowsA, colsA);

    // matrixA와 matrixB의 차 출력
    printf("행렬 A - 행렬 B : \n");
    print_matrix(subtraction_matrix(matrixA, matrixB, rowsA, colsA), rowsA, colsA);

    // matrixA와 matrixB의 전치 출력
    printf("행렬 A의 전치 : \n");
    print_matrix(transpose_matrix(matrixA, rowsA, colsA), colsA, rowsA);
    printf("행렬 B의 전치 : \n");
    print_matrix(transpose_matrix(matrixB, rowsB, colsB), colsB, rowsB);

    // matrixA와 matrixB의 곱 출력
    printf("행렬 A X 행렬 B : \n");
    print_matrix(multiply_matrix(matrixA, matrixB, rowsA, colsA, colsB), rowsA, colsB);

    // matrixA와 matrixB를 해제
    free_matrix(matrixA, rowsA);
    free_matrix(matrixB, rowsB);

    return 0;
}