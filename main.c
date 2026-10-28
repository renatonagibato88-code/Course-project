#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "functions.h"


double read_input(void) {
    double x;
    printf("Введите давление на выходе X (диапазон от 0.5 до 5.0): ");
    if (scanf("%lf", &x) != 1) {
        printf("Ошибка: введено не числовое значение.\n");
        return -1.0; 
    }
    
    if (x < 0.5 || x > 5.0) {
        printf("АВАРИЯ: Показания датчика давления (%.2f бар) вне диапазона работы [0.5; 5.0]!\n", x);
        return -1.0;
    }
    return x;
}


double calculateQ(double x) {
    if (x < 1.5) {
        return (x - 1.5) * (x - 1.5) / 1.0 + 8.0;
    } 
    else if (x <= 3.5) {
        return 2.0 * sqrt(x - 2.5 + 2.0) + 42.0;
    } 
    else {
        return 3.0 * (x - 3.5) + 60.0;
    }
}


int control(double x) {
    if (x >= 1.5 && x <= 3.5) {
        return 1; 
    }
    return 0; 
}


void print_state(int is_nominal) {
    if (is_nominal) {
        printf("Состояние: Штатный режим работы реактора.\n");
    } else {
        printf("Состояние: Отклонение технологического процесса!\n");
    }
}


void statistics(void) {
    
    printf("[Заглушка]: Расчет статистики по массиву выборки будет реализован на следующем этапе.\n");
}

int main(void) {
    double x = read_input();
    
    
    if (x < 0) {
        return 1; 
    }

    double q = calculateQ(x);
    printf("Вычислено значение Q = %.2f\n", q);

    
    int is_nominal = control(x);
    print_state(is_nominal);
    
    
    statistics();

    return 0;
}
