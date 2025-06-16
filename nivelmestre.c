
#include <stdio.h>

void inicializarTabuleiro(int tabuleiro[10][10]) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void criarHabilidadeCone(int matriz[5][5]) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            // Cone apontando para baixo com vértice no topo
            if (j >= i && j <= 4 - i && i <= 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

void criarHabilidadeCruz(int matriz[5][5]) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            // Cruz com centro no meio
            if (i == 2 || j == 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

void criarHabilidadeOctaedro(int matriz[5][5]) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            // Losango (vista frontal do octaedro)
            if ((i + j >= 2) && (i + j <= 6) && 
                (i - j <= 2) && (j - i <= 2)) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

void exibirMatriz(int matriz[5][5], char* nome) {
    int i, j;
    printf("\n%s:\n", nome);
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void aplicarHabilidade(int tabuleiro[10][10], int habilidade[5][5], int x, int y) {
    int i, j;
    printf("\nAplicando habilidade na posicao (%d,%d):\n", x, y);
    
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (habilidade[i][j] == 1) {
                int posX = x + i - 2; // Centraliza na posição (x,y)
                int posY = y + j - 2;
                
                if (posX >= 0 && posX < 10 && posY >= 0 && posY < 10) {
                    printf("Afetando (%d,%d)\n", posX, posY);
                    tabuleiro[posX][posY] = 2; // Marca área afetada
                }
            }
        }
    }
}

int main() {
    int tabuleiro[10][10];
    int cone[5][5], cruz[5][5], octaedro[5][5];
    
    // Inicializa tabuleiro e habilidades
    inicializarTabuleiro(tabuleiro);
    criarHabilidadeCone(cone);
    criarHabilidadeCruz(cruz);
    criarHabilidadeOctaedro(octaedro);
    
    // Exibe padrões das habilidades
    exibirMatriz(cone, "Padrao do Cone");
    exibirMatriz(cruz, "Padrao da Cruz");
    exibirMatriz(octaedro, "Padrao do Octaedro");
    
    // Aplica habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 3, 3);
    aplicarHabilidade(tabuleiro, cruz, 7, 7);
    aplicarHabilidade(tabuleiro, octaedro, 5, 5);
    
    // Exibe tabuleiro com áreas afetadas
    printf("\nTabuleiro com areas de habilidade (2):\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}