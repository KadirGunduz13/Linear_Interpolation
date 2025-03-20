#include <stdio.h>
#include <math.h>

// Fonksiyon tanımı: f(x) = x^3 - 5x^2 + 9x - 1
double f(double x) {
    return pow(x, 3) - 5 * pow(x, 2) + 9 * x - 1;
}

// Doğrusal interpolasyon (false position) yöntemi
void linear_interpolation(double a, double b, double tol) {
    double x_n;

    if (f(a) * f(b) > 0) {
        printf("Bu aralikta kok yoktur veya birden fazla kok olabilir!\n");
        return;
    }

    printf("Iterasyon\t a\t\t b\t\t x_n\t\t f(x_n)\n");
    int iterasyon = 0;

    do {
        // Doğrusal interpolasyon formülü
        x_n = (a * f(b) - b * f(a)) / (f(b) - f(a));

        printf("%d\t\t %.5lf\t %.5lf\t %.5lf\t %.5lf\n", iterasyon, a, b, x_n, f(x_n));

        if (fabs(f(x_n)) < tol) {
            printf("\nYaklasik kok: %.5lf (Hata toleransi icinde)\n", x_n);
            return;
        }

        // Kökün hangi aralıkta olduğunu kontrol et
        if (f(a) * f(x_n) < 0)
            b = x_n;
        else
            a = x_n;

        iterasyon++;

    } while (fabs(b - a) > tol);  // Durma koşulu

    printf("\nYaklasik kok: %.5lf (Hata toleransi icinde)\n", x_n);
}

int main() {
    double a = 0, b = 1;  // Başlangıç aralığı [0,1]
    double tol = 0.01;    // Hata toleransı (10^-2)

    linear_interpolation(a, b, tol);

    return 0;
}
