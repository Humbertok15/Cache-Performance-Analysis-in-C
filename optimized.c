#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4000

int main() {
    int **matrix = malloc(N * sizeof(int *));
    for(int i = 0; i < N; i++) {
        matrix[i] = malloc(N * sizeof(int));
    }

    clock_t start = clock();

    long long sum = 0;

    /* Row-major traversal (optimized) */
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            sum += matrix[i][j];
        }
    }

    clock_t end = clock();

    printf("Sum: %lld\n", sum);
    printf("Time: %f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    for(int i = 0; i < N; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}
