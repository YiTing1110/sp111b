#include <stdio.h>

double integrate(double (*f)(double), double a, double b) {
    int n = 1000;
    double dx = (b - a) / n;
    double result = 0.0;

    for (int i = 0; i < n; i++) {
        double x = a + (i + 0.5) * dx;
        result += f(x) * dx;
    }

    return result;
}

double square(double x) {
    return x*x;
}

int main() {
    printf("integrate(square, 0.0, 2.0)=%f\n", integrate(square, 0.0, 2.0));
}
