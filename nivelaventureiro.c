
#include <stdio.h>

void inicializarTabuleiro(int tabuleiro[10][10]) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

int posicionarNavioHorizontal(int tabuleiro[10][10], int tamanho, int x, int y) {
    int j;
    if (y + tamanho > 10) return 0;
    
    for (j = y; j < y + tamanho; j++) {
        if (tabuleiro[x][j] != 0) return 0;
    }
    
    for (j = y; j < y + tamanho; j++) {
        tabuleiro[x][j] = 3;
    }
    return 1;
}

int posicionarNavioVertical(int tabuleiro[10][10], int tamanho, int x, int y) {
    int i;
    if (x + tamanho > 10) return 0;
    
    for (i = x; i < x + tamanho; i++) {
        if (tabuleiro[i][y] != 0) return 0;
    }
    
    for (i = x; i < x + tamanho; i++) {
        tabuleiro[i][y] = 3;
    }
    return 1;
}

int posicionarNavioDiagonal1(int tabuleiro[10][10], int tamanho, int x, int y) {
    int i;
    if (x + tamanho > 10 || y + tamanho > 10) return 0;
    
    for (i = 0; i < tamanho; i++) {
        if (tabuleiro[x+i][y+i] != 0) return 0;
    }
    
    for (i = 0; i < tamanho; i++) {
        tabuleiro[x+i][y+i] = 3;
    }
    return 1;
}

int posicionarNavioDiagonal2(int tabuleiro[10][10], int tamanho, int x, int y) {
    int i;
    if (x + tamanho > 10 || y - tamanho + 1 < 0) return 0;
    
    for (i = 0; i < tamanho; i++) {
        if (tabuleiro[x+i][y-i] != 0) return 0;
    }
    
    for (i = 0; i < tamanho; i++) {
        tabuleiro[x+i][y-i] = 3;
    }
    return 1;
}

void exibirTabuleiro(int tabuleiro[10][10]) {
    int i, j;
    
    printf("\n  0 1 2 3 4 5 6 7 8 9\n");
    
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
    
    // Posicionando navios horizontais e verticais
    if (!posicionarNavioHorizontal(tabuleiro, 3, 2, 3)) {
        printf("Erro ao posicionar navio horizontal!\n");
        return 1;
    }
    
    if (!posicionarNavioVertical(tabuleiro, 3, 5, 7)) {
        printf("Erro ao posicionar navio vertical!\n");
        return 1;
    }
    
    // Posicionando navios diagonais
    if (!posicionarNavioDiagonal1(tabuleiro, 3, 1, 1)) {
        printf("Erro ao posicionar navio diagonal 1!\n");
        return 1;
    }
    
    if (!posicionarNavioDiagonal2(tabuleiro, 3, 0, 8)) {
        printf("Erro ao posicionar navio diagonal 2!\n");
        return 1;
    }
    
    printf("Tabuleiro do Batalha Naval:\n");
    printf("0 = Agua, 3 = Navio\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}