#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAXCOLUNA 7
#define MAXLINHA 7
#define MINLINHA 0
#define MINCOLUNA 0
#define QuantMatriz 3

typedef struct Item {
    int val;
    int direita;
    int esquerda;
    int baixo;
    int diagonal;
} Item;

typedef struct Matriz{
    Item m[MAXLINHA][MAXCOLUNA];
} Matriz;


Matriz Matrizes[QuantMatriz];
Matriz mat;
void GenerateMatriz(Matriz *mat);
void SetMatriz();
void SaveMatriz(Matriz *mat);
void PrintMatriz(Matriz*mat);
void Iniciar();
void CriarVizinhos();
void CaminharMapa();


#endif