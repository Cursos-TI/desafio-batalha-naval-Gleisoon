#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa todas as posições com água (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }

    // Coordenadas iniciais para os navios
    int linha_h = 2, coluna_h = 5; // navio horizontal
    int linha_v = 6, coluna_v = 2; // navio vertical

    // Posicionamento do navio horizontal
    if (coluna_h + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;

        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_h][coluna_h + i] != VALOR_AGUA) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_h][coluna_h + i] = VALOR_NAVIO;
            }
        } else {
            printf("Erro: Sobreposição ao posicionar navio horizontal.\n");
            return 1;
        }
    } else {
        printf("Erro: Navio horizontal ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Posicionamento do navio vertical
    if (linha_v + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;

        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_v + i][coluna_v] != VALOR_AGUA) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_v + i][coluna_v] = VALOR_NAVIO;
            }
        } else {
            printf("Erro: Sobreposição ao posicionar navio vertical.\n");
            return 1;
        }
    } else {
        printf("Erro: Navio vertical ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Exibe o tabuleiro
    printf("\n=== Tabuleiro Batalha Naval ===\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
