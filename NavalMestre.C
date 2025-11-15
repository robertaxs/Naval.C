#include <stdio.h>

#define TAM 10

void inicializarTabuleiro(int tab[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tab[i][j] = 0;
}

void mostrarTabuleiro(int tab[TAM][TAM]) {
    printf("\n    ");
    for (int j = 0; j < TAM; j++) printf("%2d ", j);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d  ", i);
        for (int j = 0; j < TAM; j++)
            printf("%2d ", tab[i][j]);
        printf("\n");
    }
}

void colocarNavios(int tab[TAM][TAM]) {
    int x, y, qnt;

    printf("\nQuantos navios deseja posicionar? ");
    scanf("%d", &qnt);

    for (int n = 0; n < qnt; n++) {
        printf("\nPosição do navio %d (linha e coluna): ", n + 1);
        scanf("%d %d", &x, &y);

        if (x >= 0 && x < TAM && y >= 0 && y < TAM)
            tab[x][y] = 1;
        else {
            printf("Posição inválida! Tente novamente.\n");
            n--;
        }
    }
}

void habilidadeCone(int tab[TAM][TAM], int x, int y) {
    for (int i = x - 1; i <= x + 1; i++)
        for (int j = y - 1; j <= y + 1; j++)
            if (i >= 0 && i < TAM && j >= 0 && j < TAM)
                tab[i][j] = 2;
}

void habilidadeCruz(int tab[TAM][TAM], int x, int y) {
    for (int i = 0; i < TAM; i++) {
        tab[x][i] = 3;
        tab[i][y] = 3;
    }
}

void habilidadeQuadrado(int tab[TAM][TAM], int x, int y) {
    for (int i = x - 1; i <= x + 1; i++)
        for (int j = y - 1; j <= y + 1; j++)
            if (i >= 0 && i < TAM && j >= 0 && j < TAM)
                tab[i][j] = 4;
}

int main() {
    int tab[TAM][TAM];
    int x, y, escolha;

    inicializarTabuleiro(tab);

    printf("\n=== POSICIONAMENTO DE NAVIOS ===\n");
    colocarNavios(tab);
    mostrarTabuleiro(tab);

    while (1) {
        printf("\n=== HABILIDADES ===");
        printf("\n1 - Cone (3x3)");
        printf("\n2 - Cruz (linha e coluna)");
        printf("\n3 - Quadrado (3x3 compacto)");
        printf("\n0 - Sair");
        printf("\nEscolha: ");
        scanf("%d", &escolha);

        if (escolha == 0) break;

        printf("Digite a posição da habilidade (linha coluna): ");
        scanf("%d %d", &x, &y);

        switch (escolha) {
            case 1: habilidadeCone(tab, x, y); break;
            case 2: habilidadeCruz(tab, x, y); break;
            case 3: habilidadeQuadrado(tab, x, y); break;
            default: printf("Opção inválida!\n");
        }

        mostrarTabuleiro(tab);
    }

    printf("\nEncerrado.\n");
    return 0;
}
