// Second example: Work on R matrix
#include <RcppEigen.h>
#include <GenEigs.h>
#include <RMatOp.h>

RcppExport SEXP example2(SEXP mat)
{
    BEGIN_RCPP

    // Construct matrix operation object from R matrix
    Rcpp::NumericMatrix m(mat);
    MatProd_matrix op(mat, m.nrow(), m.ncol());

    // Construct eigen solver object, requesting the largest three eigenvalues
    GenEigsSolver< double, LARGEST_MAGN, MatProd_matrix > eigs(&op, 3, 10);

    // Initialize and compute
    eigs.init();
    int nconv = eigs.compute();

    // Return results
    if(nconv > 0)
        return Rcpp::wrap(eigs.eigenvalues());

    return R_NilValue;

    END_RCPP
}
