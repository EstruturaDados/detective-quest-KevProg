#include <stdio.h>

int main(){

    int Tabuleiro[10][10];

    //Tabuleiro Da Batalha Naval
    for (int y = 0; y < 10; y++){
        for (int x = 0; x < 10; x++){
            Tabuleiro[y][x] = 0;
        }
    }

    // Localização dos Navios

    //Localização dos Barcos Vertical
    Tabuleiro[0][5] = 3; 
    Tabuleiro[1][5] = 3;
    Tabuleiro[2][5] = 3;

    // Localização dos Barcos na Diagonal 1
    Tabuleiro[4][4] = 3; 
    Tabuleiro[5][5] = 3;
    Tabuleiro[6][6] = 3;

    // Localização dos Barcos na Diagonal 2
    Tabuleiro[7][2] = 3; 
    Tabuleiro[6][3] = 3;
    Tabuleiro[5][4] = 3;

    // Matriz das Habilidades
    int meioMatriz = 5 / 2;

    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // Cone
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            if (x >= meioMatriz - y && x <= meioMatriz + y)
                cone[y][x] = 1;
            else
                cone[y][x] = 0;
        }
    }

    // Cruz
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            if (y == meioMatriz || x == meioMatriz)
                cruz[y][x] = 1;
            else
                cruz[y][x] = 0;
        }
    }

    // Octaedro
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {

            int distLinha = y - meioMatriz;
            if (distLinha < 0) distLinha = -distLinha;

            int distColuna = x - meioMatriz;
            if (distColuna < 0) distColuna = -distColuna;

            if (distLinha + distColuna <= meioMatriz)
                octaedro[y][x] = 1;
            else
                octaedro[y][x] = 0;
        }
    }

    // Origens
    int OrigemConeLinha = 2;
    int OrigemConeColuna = 2;

    int OrigemCruzLinha = 6;
    int OrigemCruzColuna = 7;

    int OrigemOctaedroLinha = 8;
    int OrigemOctaedroColuna = 3;

    // Aplicação das Habilidades

    // CONE
    for (int y = 0; y < 5; y++){
        for (int x = 0; x < 5; x++) {

            int LinhaTab = OrigemConeLinha + (y - meioMatriz);
            int ColunaTab = OrigemConeColuna + (x - meioMatriz);

            if (LinhaTab >= 0 && LinhaTab < 10 &&
                ColunaTab >= 0 && ColunaTab < 10) {

                if (cone[y][x] == 1 && Tabuleiro[LinhaTab][ColunaTab] == 0)
                    Tabuleiro[LinhaTab][ColunaTab] = 5;
            }
        }
    }

    // CRUZ
    for (int y = 0; y < 5; y++){
        for (int x = 0; x < 5; x++) {

            int LinhaTab = OrigemCruzLinha + (y - meioMatriz);
            int ColunaTab = OrigemCruzColuna + (x - meioMatriz);

            if (LinhaTab >= 0 && LinhaTab < 10 &&
                ColunaTab >= 0 && ColunaTab < 10) {

                if (cruz[y][x] == 1 && Tabuleiro[LinhaTab][ColunaTab] == 0)
                    Tabuleiro[LinhaTab][ColunaTab] = 5;
            }
        }
    }

    // OCTAEDRO
    for (int y = 0; y < 5; y++){
        for (int x = 0; x < 5; x++) {

            int LinhaTab = OrigemOctaedroLinha + (y - meioMatriz);
            int ColunaTab = OrigemOctaedroColuna + (x - meioMatriz);

            if (LinhaTab >= 0 && LinhaTab < 10 &&
                ColunaTab >= 0 && ColunaTab < 10) {

                if (octaedro[y][x] == 1 && Tabuleiro[LinhaTab][ColunaTab] == 0)
                    Tabuleiro[LinhaTab][ColunaTab] = 5;
            }
        }
    }

    // Exibidor do tabuleiro
    
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            printf("%d ", Tabuleiro[y][x]);
        }
        printf("\n");
    }

    return 0;
}