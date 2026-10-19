#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <math.h>


double calc_q(double x)
{
    if (x < 2.0) {
        return (x - 2.0) * (x - 2.0) + 10.0;
    }
    else if (x <= 5.0) {
        return 3.0 * (x - 3.5) + 50.0;
    }
    else {
        return 2.0 * sqrt(x - 5.0 + 1.0) + 60.0;
    }
}


int c_check(double q, double q0, double delt_q)
{
    if (fabs(q - q0) > delt_q) {
        return 1;
    }
    return 0;
}

int main()
{
    const double q0 = 50.0, delt_q = 11.0;
    double x, q;

    setlocale(LC_ALL, "Russian");

    printf("Введите от 1 до 8 бар \n");
    if (scanf("%lf", &x) != 1) {
        printf("Ошибка: нужно ввести число.\n");
        return 1;
    }
    
    if (x < 1.0 || x > 8.0) {
        printf("Ошибка: значение x должно быть в диапазоне от 1 до 8 бар.\n");
        return 1;
    }

    q = calc_q(x);
    printf("q = %.2f\n", q);

    if (c_check(q, q0, delt_q) == 1) {
        printf("Состояние: ПРЕДУПРЕЖДЕНИЕ\n");
    }
    else {
        printf("Состояние: НОРМА\n");
    }
    return 0;
}