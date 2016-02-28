example1 <- function() {
    invisible(.Call('example1', PACKAGE = 'RSpectraLink'))
}

example2 <- function() {
    m = matrix(rnorm(20^2), 20)
    cat("All eigenvalues calculated by eigen():\n")
    print(eigen(m, only.values = TRUE)$values)
    cat("Eigenvalues calculated by RSpectra:\n")
    print(.Call('example2', m, PACKAGE = 'RSpectraLink'))
}

example3 <- function() {
    print(.Call('example3', PACKAGE = 'RSpectraLink'))
}
