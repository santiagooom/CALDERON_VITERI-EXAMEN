#ifndef VENTAS_H
#define VENTAS_H
 
#define TAM_MAX 30
 
void leerVentas(float ventas[], int n);
float calcularTotal(const float ventas[], int n);
float calcularPromedio(const float ventas[], int n);
float calcularMaxima(const float ventas[], int n);
void mostrarResultados(float total, float promedio, float maxima);
 
#endif