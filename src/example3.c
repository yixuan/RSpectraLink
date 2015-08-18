/* Third example: Using the C interface */
/* See rARPACK/include/ArpackC.h */
#include <ArpackC.h>
#include <R.h>
#include <Rdefines.h>
#include <Rinternals.h>
#include <R_ext/Rdynload.h>

/* Calculating y = A * x, where A is a diagonal matrix
   with elements 1, 2, ..., n */
void my_matrix_op(double *x_in, double *y_out, int n, void *data)
{
    int i;
    for(i = 0; i < n; i++)
        y_out[i] = x_in[i] * (i + 1);
}

SEXP example3()
{
    int n = 10;   /* size of matrix */
    int k = 3;    /* number of eigenvalues */
    arpack_opts opts = {0,      /* Largest magnitude */
                        6,      /* ncv*/
                        1e-10,  /* Precision */
                        1000,   /* Maximum number of iterations */
                        0       /* Do not return eigenvectors */ };
    int nconv, niter, nops, info;
    SEXP evals = PROTECT(allocVector(REALSXP, k));

    /* Obtain the function call from rARPACK package */
    eigs_sym_c_funtype eigs_sym_fun = (eigs_sym_c_funtype) R_GetCCallable("rARPACK", "eigs_sym_c");

    eigs_sym_fun(my_matrix_op, n, k, &opts, NULL, &nconv, &niter, &nops,
                 REAL(evals), NULL, &info);

    Rprintf("Number of converged eigenvalue: %d\n", nconv);
    Rprintf("Number of iterations: %d\n", niter);
    Rprintf("Number of matrix operations: %d\n", nops);

    UNPROTECT(1);

    return evals;
}
