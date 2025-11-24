#include <stdio.h>
#include "ventas.h"
 
void leerVentas(float ventas[], int n) {
    for (int i = 0; i < n; i++) {
        float valor;
        int lectura;
 
        do {
            printf("Ingrese el monto de ventas del dia %d: ", i + 1);
            lectura = scanf("%f", &valor);
 
            if (lectura != 1) {
                printf("Tu entrada es invalida, solo se acepetan numeros\n");
                while (getchar() != '\n');
                continue;
            }
 
            if (valor < 0) {
                printf("La venta no puede ser negativa. Intente nuevamente\n");
            }
 
        } while (lectura != 1 || valor < 0);
 
        ventas[i] = valor;
    }
}
 
float calcularTotal(const float ventas[], int n) {
    float total = 0.0f;
    for (int i = 0; i < n; i++) {
        total += ventas[i];
    }
    return total;
}
 
float calcularPromedio(const float ventas[], int n) {
    if (n <= 0) {
        return 0.0f;
    }
    float total = calcularTotal(ventas, n);
    return total / n;
}
 
float calcularMaxima(const float ventas[], int n) {
    if (n <= 0) {
        return 0.0f;
    }
    float maxima = ventas[0];
    for (int i = 1; i < n; i++) {
        if (ventas[i] > maxima) {
            maxima = ventas[i];
        }
    }
    return maxima;
}
 
void mostrarResultados(float total, float promedio, float maxima) {
    printf("\nRESULTADOS DEL EJERCICIO DE VENTAS\n");
    printf("Total de ventas: %.2f\n", total);
    printf("Promedio de ventas: %.2f\n", promedio);
    printf("Venta maxima: %.2f\n", maxima);
}