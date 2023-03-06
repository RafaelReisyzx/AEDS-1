#include "Matriz.h"

void Iniciar()
{
	int i;
	Matriz m;
	SetMatriz();
    for(i=0;i<QuantMatriz;i++) {
        SaveMatriz(&m);
        printf("\nMatriz %d:\n",i+1);
        PrintMatriz(&m);
        CriarVizinhos(&m);
        Matrizes[i]=m;
    
    }
}
void GenerateMatriz(Matriz *mat) {
    srand(time(NULL));
    int i,j;
    for(i = 0; i < MAXLINHA; i++) {
        for(j = 0; j < MAXCOLUNA; j++) {
            mat->m[i][j].val = rand() % 999;
        
	}
    }

    
}
void CriarVizinhos(Matriz *mat)
{
	int i,j;
    for(i = 0; i < MAXLINHA; i++) {
        for(j = 0; j < MAXCOLUNA; j++) {
            if(i==MINLINHA&&j==MINCOLUNA){
           mat->m[i][j].direita = mat->m[i][j+1].val;
            mat->m[i][j].esquerda = -1;
            mat->m[i][j].baixo = mat->m[i+1][j].val;
            mat->m[i][j].diagonal = mat->m[i+1][j+1].val;
            	
			}else{
			 if(i==MINLINHA&&j==MAXCOLUNA){
			mat->m[i][j].direita = -1;
            mat->m[i][j].esquerda = mat->m[i-1][j].val;
            mat->m[i][j].baixo = mat->m[i+1][j].val;
            mat->m[i][j].diagonal = -1;
			 }else{
			 	if(i==MAXLINHA&&j==MINCOLUNA){
			mat->m[i][j].direita = mat->m[i][j+1].val;
            mat->m[i][j].esquerda = -1;
            mat->m[i][j].baixo = -1;
            mat->m[i][j].diagonal = -1;
				 }else{
				 	if(i==MAXLINHA&&j==MAXCOLUNA){
			mat->m[i][j].direita = -1;
            mat->m[i][j].esquerda = mat->m[i-1][j].val;
            mat->m[i][j].baixo = -1;
            mat->m[i][j].diagonal = -1;	
					 }else{
					 	if(i==MAXLINHA){
		   mat->m[i][j].direita = mat->m[i][j+1].val;
            mat->m[i][j].esquerda = mat->m[i-1][j].val;
            mat->m[i][j].baixo = mat->m[i+1][j].val;
            mat->m[i][j].diagonal = mat->m[i+1][j+1].val;			 		
					 	}else{
					  if(j==MAXCOLUNA){
			mat->m[i][j].direita = -1;
            mat->m[i][j].esquerda = mat->m[i-1][j].val;
            mat->m[i][j].baixo = mat->m[i+1][j].val;
            mat->m[i][j].diagonal = -1;				 			 		
					 	}else{
					   if(i==MINLINHA){			   				 		
			mat->m[i][j].direita = mat->m[i][j+1].val;
            mat->m[i][j].esquerda = mat->m[i-1][j].val;
            mat->m[i][j].baixo = -1;
            mat->m[i][j].diagonal = -1;
				}else{
				 if(j==MINCOLUNA){	 				 		
			mat->m[i][j].direita = mat->m[i][j+1].val;
            mat->m[i][j].esquerda = -1;
            mat->m[i][j].baixo = mat->m[i+1][j].val;
            mat->m[i][j].diagonal = mat->m[i+1][j+1].val;
				}else{
					 		
			mat->m[i][j].direita = mat->m[i][j+1].val;
            mat->m[i][j].esquerda = mat->m[i-1][j].val;
            mat->m[i][j].baixo = mat->m[i+1][j].val;
            mat->m[i][j].diagonal = mat->m[i+1][j+1].val;		 		
						 }}}}}}}}
	}
    }
	
	
}

void SetMatriz() {
    FILE *f = fopen("arquivo.txt", "w");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo para escrita\n");
        exit(EXIT_FAILURE);
    }
    fprintf(f, "%d %d\n",MAXLINHA, MAXCOLUNA);
    fclose(f);
}

void SaveMatriz(Matriz *mat) {
    int i,j;
    FILE *f = fopen("arquivo.txt", "a");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo para escrita\n");
        exit(EXIT_FAILURE);
    }
    GenerateMatriz(mat);
    for (i = 0; i < MAXLINHA; i++) {
        for (j = 0; j < MAXCOLUNA; j++)
            fprintf(f, "%d ", mat->m[i][j].val);
        fprintf(f, "\n");
    }
    fprintf(f, "\n");
    fclose(f);
}

void PrintMatriz(Matriz *mat) {
    int i,j;
    for (i = 0; i < MAXLINHA; i++) {
        for (j = 0; j < MAXCOLUNA; j++)
            printf("%d ", mat->m[i][j].val);
        printf("\n");
    }
    printf("\n");
   
}

void CaminharMapa() {
    int i, j, k, linha = 0, coluna = 0, soma = 0, maior = -1, movimento;
    int caminho[MAXCOLUNA * MAXLINHA];
    bool visitado[MAXLINHA][MAXCOLUNA] = { false };
    for (k = 0; k < QuantMatriz; k++) {
        printf("\nCaminho da matriz %d:\n", k + 1);
        soma = 0;
        linha = 0;
        coluna = 0;
        int pos = 0;
        while (linha != MAXLINHA - 1 || coluna != MAXCOLUNA - 1) {
            visitado[linha][coluna] = true;
            caminho[pos++] = linha * MAXCOLUNA + coluna;
            maior = -1;
            movimento = -1;
            if (coluna < MAXCOLUNA - 1 && !visitado[linha][coluna + 1] && Matrizes[k].m[linha][coluna].direita > maior) {
                maior = Matrizes[k].m[linha][coluna].direita;
                movimento = 1;
            }
            if (coluna > 0 && !visitado[linha][coluna - 1] && Matrizes[k].m[linha][coluna].esquerda > maior) {
                maior = Matrizes[k].m[linha][coluna].esquerda;
                movimento = 2;
            }
            if (linha < MAXLINHA - 1 && !visitado[linha + 1][coluna] && Matrizes[k].m[linha][coluna].baixo > maior) {
                maior = Matrizes[k].m[linha][coluna].baixo;
                movimento = 3;
            }
            if (linha < MAXLINHA - 1 && coluna < MAXCOLUNA - 1 && !visitado[linha + 1][coluna + 1] && Matrizes[k].m[linha][coluna].diagonal > maior) {
                maior = Matrizes[k].m[linha][coluna].diagonal;
                movimento = 4;
            }
            if (movimento == 1) {
                coluna++;
            }
            else if (movimento == 2) {
                coluna--;
            }
            else if (movimento == 3) {
                linha++;
            }
            else if (movimento == 4) {
                linha++;
                coluna++;
}
if (movimento != -1) {
soma += maior;
}
else {
break;
}
}
caminho[pos++] = linha * MAXCOLUNA + coluna;
printf("Caminho: ");
for (i = 0; i < pos; i++) {
printf("(%d, %d) ", caminho[i] / MAXCOLUNA, caminho[i] % MAXCOLUNA);
}
printf("\nSoma: %d\n", soma);
}
}