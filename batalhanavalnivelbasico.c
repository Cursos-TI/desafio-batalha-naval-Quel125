
#include <stdio.h>

void inicializarTabuleiro(int tabuleiro[10][10]) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

int posicionarNavio(int tabuleiro[10][10], int tamanho, int x, int y, int horizontal) {
    int i, j;
    
    // Verifica se o navio cabe na posição escolhida
    if (horizontal) {
        if (y + tamanho > 10) return 0; // 0 indica falha
        for (j = y; j < y + tamanho; j++) {
            if (tabuleiro[x][j] != 0) return 0;
        }
        for (j = y; j < y + tamanho; j++) {
            tabuleiro[x][j] = 3; // 3 representa navio
        }
    } else {
        if (x + tamanho > 10) return 0;
        for (i = x; i < x + tamanho; i++) {
            if (tabuleiro[i][y] != 0) return 0;
        }
        for (i = x; i < x + tamanho; i++) {
            tabuleiro[i][y] = 3;
        }
    }
    return 1; // 1 indica sucesso
}

void exibirTabuleiro(int tabuleiro[10][10]) {
    int i, j;
    
    printf("\n  ");
    for (j = 0; j < 10; j++) {
        printf("%d ", j);
    }
    printf("\n");
    
    for (i = 0; i < 10; i++) {
        printf("%d ", i);
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[10][10];
    inicializarTabuleiro(tabuleiro);
    
    // Posicionando navios (tamanho 3)
    // 1 = horizontal, 0 = vertical
    if (!posicionarNavio(tabuleiro, 3, 2, 3, 1)) {
        printf("Erro ao posicionar navio horizontal!\n");
        return 1;
    }
    
    if (!posicionarNavio(tabuleiro, 3, 5, 7, 0)) {
        printf("Erro ao posicionar navio vertical!\n");
        return 1;
    }
    
    printf("Tabuleiro do Batalha Naval:\n");
    printf("0 = Agua, 3 = Navio\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}