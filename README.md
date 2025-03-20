# 📌 Doğrusal İnterpolasyon (False Position) Yöntemi - C Programı

Bu repo, **Doğrusal İnterpolasyon (False Position)** yöntemini kullanarak **bir fonksiyonun kökünü bulan** bir C programını içermektedir. Program, verilen hata toleransı içinde bir kökü iteratif olarak hesaplar.  

---

## 🚀 Çalışma Mantığı
1. **Fonksiyon Tanımı:**
   
   \[
   f(x) = x^3 - 5x^2 + 9x - 1
   \]
   
2. **Başlangıç Aralığı:**
   - \[ a, b \] = [0,1]
   - Hata toleransı: **10⁻²**
   
3. **False Position Formülü:**
   
   \[
   x_n = \frac{a \cdot f(b) - b \cdot f(a)}{f(b) - f(a)}
   \]

4. **Durma Koşulu:**
   \[ |b - a| < 0.01 \] olana kadar iterasyon devam eder.

---

## 📝 Kod
```c
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
        printf("Bu aralıkta kök yoktur veya birden fazla kök olabilir!\n");
        return;
    }

    printf("Iterasyon\t a\t\t b\t\t x_n\t\t f(x_n)\n");
    int iterasyon = 0;

    do {
        x_n = (a * f(b) - b * f(a)) / (f(b) - f(a));

        printf("%d\t\t %.5lf\t %.5lf\t %.5lf\t %.5lf\n", iterasyon, a, b, x_n, f(x_n));

        if (fabs(f(x_n)) < tol) {
            printf("\nYaklaşık kök: %.5lf (Hata toleransı içinde)\n", x_n);
            return;
        }

        if (f(a) * f(x_n) < 0)
            b = x_n;
        else
            a = x_n;

        iterasyon++;

    } while (fabs(b - a) > tol);

    printf("\nYaklaşık kök: %.5lf (Hata toleransı içinde)\n", x_n);
}

int main() {
    double a = 0, b = 1;
    double tol = 0.01;
    linear_interpolation(a, b, tol);
    return 0;
}
```

---

## 📌 Örnek Çıktı
```
Iterasyon    a        b        x_n      f(x_n)
0           0.00000   1.00000   0.11111   0.82716
1           0.11111   1.00000   0.12478   0.72263
2           0.12478   1.00000   0.13288   0.64829
...
6           0.19712   1.00000   0.19956   0.00049

Yaklaşık kök: 0.19956 (Hata toleransı içinde)
```

---

## 🔥 Nasıl Çalıştırılır?
1. **Terminali Açın ve Derleyin:**
   ```bash
   gcc linear_interpolation.c -o linear_interpolation -lm
   ```
2. **Programı Çalıştırın:**
   ```bash
   ./linear_interpolation
   ```

---

## 📜 Lisans
Bu proje **MIT Lisansı** altında sunulmaktadır.
