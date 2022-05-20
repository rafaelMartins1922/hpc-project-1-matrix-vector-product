#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 1000;
    double *A,*b,*x;
    int i, j;
    double time_spent = 0.0;
    FILE *graphDataFile;

    graphDataFile = fopen("loop_column_row_c.txt","w");
    while (n <= 15000) {
        A = malloc(n*n*sizeof(double));
        x = malloc(n*sizeof(double));
        b = malloc(n*sizeof(double));

        for (i = 0; i < n; i++) {
            b[i] = 0;
            x[i] = (double) rand()/rand();
            for (j = 0; j < n; j++) {
                A[i*n + j] = (double) rand()/rand();
            }
        }

        clock_t begin = clock();
        for (j = 0; j < n; j++) {
            for (i = 0; i < n; i++) {
                b[i] = b[i] + A[i*n + j]*x[j];
            }
        }
        clock_t end = clock();

        fprintf(graphDataFile,"%d %f\n", n, (double) (end-begin) / CLOCKS_PER_SEC);

        free(A);
        free(x);
        free(b);

        n += 1000;
    }
}
