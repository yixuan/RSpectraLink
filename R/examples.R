example1 <- function() {
    invisible(.Call('example1', PACKAGE = 'rARPACKLink'))
}

example2 <- function() {
    m = matrix(rnorm(20^2), 20)
    cat("All eigenvalues calculated by eigen():\n")
    print(eigen(m, only.values = TRUE)$values)
    cat("Eigenvalues calculated by rARPACK:\n")
    print(.Call('example2', m, PACKAGE = 'rARPACKLink'))
}

example3 <- function() {
    print(.Call('example3', PACKAGE = 'rARPACKLink'))
}
