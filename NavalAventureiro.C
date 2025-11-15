#include <stdio.h>

#define TAM 10     // Tamanho do tabuleiro
#define NAVIO 3    // Tamanho fixo de cada navio
#define OCUPADO 3  // Valor que representa um navio no tabuleiro

// Função para verificar se um navio pode ser colocado sem sair do tabuleiro
int dentroDosLimites(int linha, int coluna) {
    return (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM);
}

// Função para verificar sobreposição antes de inserir a peça
int podeColocar(int tab[TAM][TAM], int posicoes[][2]) {
    for (int i = 0; i < NAVIO; i++) {
        int l = posicoes[i][0];
        int c = posicoes[i][1];

        if (!dentroDosLimites(l, c)) {
            return 0; // Está fora do tabuleiro
        }

        if (tab[l][c] == OCUPADO) {
            return 0; // Sobreposição detectada
        }
    }
    return 1;
}

// Função para marcar um navio na matriz
void colocarNavio(int tab[TAM][TAM], int posicoes[][2]) {
    for (int i = 0; i < NAVIO; i++) {
        tab[posicoes[i][0]][posicoes[i][1]] = OCUPADO;
    }
}

int main() {

    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // -------------------------------------------------------------
    // DEFINIÇÃO DAS POSIÇÕES DOS 4 NAVIOS (tamanho 3)
    // -------------------------------------------------------------

    // NAVIO 1 — HORIZONTAL
    int navio1[3][2] = {
        {2, 1}, {2, 2}, {2, 3}
    };

    // NAVIO 2 — VERTICAL
    int navio2[3][2] = {
        {5, 7}, {6, 7}, {7, 7}
    };

    // NAVIO 3 — DIAGONAL ↘ (linha++, coluna++)
    int navio3[3][2] = {
        {0, 0}, {1, 1}, {2, 2}
    };

    // NAVIO 4 — DIAGONAL ↗ (linha--, coluna++)
    int navio4[3][2] = {
        {9, 0}, {8, 1}, {7, 2}
    };

    // -------------------------------------------------------------
    // VALIDAÇÃO E COLOCAÇÃO DOS NAVIOS
    // -------------------------------------------------------------

    if (!podeColocar(tabuleiro, navio1)) { printf("Erro no navio 1!\n"); return 0; }
    colocarNavio(tabuleiro, navio1);

    if (!podeColocar(tabuleiro, navio2)) { printf("Erro no navio 2!\n"); return 0; }
    colocarNavio(tabuleiro, navio2);

    if (!podeColocar(tabuleiro, navio3)) { printf("Erro no navio 3!\n"); return 0; }
    colocarNavio(tabuleiro, navio3);

    if (!podeColocar(tabuleiro, navio4)) { printf("Erro no navio 4!\n"); return 0; }
    colocarNavio(tabuleiro, navio4);

    // -------------------------------------------------------------
    // EXIBIÇÃO DO TABULEIRO COMPLETO
    // -------------------------------------------------------------

    printf("\n===== TABULEIRO BATALHA NAVAL (Navios em Linha + Diagonal) =====\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
