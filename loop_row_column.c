#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 15000;
    double *A,*b,*x;
    int i, j;
    double time_spent = 0.0;
    FILE *graphDataFile;

    graphDataFile = fopen("loop_row_column_c.txt","w");
    while (n <= 20000) {
        A = malloc(n*n*sizeof(double));
        x = malloc(n*sizeof(double));
        b = malloc(n*sizeof(double));

        if(A == NULL) printf("A is null");
        if(x == NULL) printf("x is null");
        if(b == NULL) printf("b is null");
        if(n > 15000) printf("%d\n",n);
        for (i = 0; i < n; i++) {
            if(n > 15000) printf("%d\n",n);
            b[i] = 0;
            if(n > 15000) printf("%d\n",n);
            x[i] = (double) rand()/rand();
            if(n > 15000) printf("%d\n",n);
            for (j = 0; j < n; j++) {
                if(n > 15000) printf("%d %d\n",j,i);
                A[i*n + j] = (double) rand()/rand();
                if(n > 15000) printf("%d %d\n",j,i);
            }
        }

        clock_t begin = clock();
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
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
