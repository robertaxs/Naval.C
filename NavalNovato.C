#include <stdio.h>

#define TAM 10     // Tamanho do tabuleiro 10x10
#define NAVIO 3    // Cada navio tem tamanho 3

int main() {

    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro inteiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // -----------------------------
    // COORDENADAS INICIAIS DOS NAVIOS
    // -----------------------------

    // NAVIO HORIZONTAL (tamanho 3)
    int linhaH = 2;     // linha inicial
    int colunaH = 4;    // coluna inicial

    // NAVIO VERTICAL (tamanho 3)
    int linhaV = 5;     // linha inicial
    int colunaV = 7;    // coluna inicial

    // -----------------------------
    // VALIDAÇÃO DO NAVIO HORIZONTAL
    // -----------------------------
    if (colunaH + NAVIO > TAM) {
        printf("Erro: navio horizontal fora dos limites!\n");
        return 0;
    }

    // -----------------------------
    // VALIDAÇÃO DO NAVIO VERTICAL
    // -----------------------------
    if (linhaV + NAVIO > TAM) {
        printf("Erro: navio vertical fora dos limites!\n");
        return 0;
    }

    // -----------------------------
    // VERIFICAR SOBREPOSIÇÃO ENTRE OS NAVIOS
    // -----------------------------
    for (int i = 0; i < NAVIO; i++) {
        if (linhaH == linhaV + i && (colunaV == colunaH || colunaV == colunaH + 1 || colunaV == colunaH + 2)) {
            printf("Erro: navios se sobrepoem!\n");
            return 0;
        }
    }

    // -----------------------------
    // POSICIONAR NAVIO HORIZONTAL
    // -----------------------------
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = 3;
    }

    // -----------------------------
    // POSICIONAR NAVIO VERTICAL
    // -----------------------------
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = 3;
    }

    // -----------------------------
    // EXIBIR TABULEIRO COMPLETO
    // -----------------------------
    printf("\n===== TABULEIRO BATALHA NAVAL =====\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
