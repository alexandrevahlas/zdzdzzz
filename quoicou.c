#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define LIGNES 10
#define COLONNES 20
#define OISEAU 0xE
#define SNOOPY 0xB
#define COINSUPG 0xDA
#define COINSUPD 0xBF
#define COININFG 0xC0
#define COININFD 0xD9
#define BORDURECOTE '|'
#define BASPLATEAU '-'
#define HAUTPLATEAU 196
#define BLOCINVINCIBLES 0xF
#define BLOCPOUSSABLES 0x1A
#define BLOCPIEGE 0x6
#define BLOCDISPARITION_APPARITION 0xA
#define BLOCTAPISROULANT 0x4
#define BALLE 0x1
#define BLOCCASSABLE 0x5

int nboiseaux=4;
int pause = 0;
int vie = 3;
int temps = 120;
int blocPoussableX, blocPoussableY, blocPoussableX2, blocPoussableY2;

int scoreTotal(int nouveauScore) {
    int score, niv = 1;
    int scores [] = {};
    score = score + nouveauScore;
    scores [niv] = score;
    niv = niv + 1;
    if (nouveauScore == 1) {
        return scores[nouveauScore-1];
    }
    if (nouveauScore == 2) {
        return scores[nouveauScore-1];
    }
    return score;
}

void initialisePlateauniv4(char plateau[LIGNES][COLONNES],int *snoopyX, int *snoopyY) {    // Fonction pour initialiser le plateau de jeu avec des éléments tels que les oiseaux et les obstacles
    // Initialisation du plateau
    for(int i = 0; i < LIGNES; i++) {
        for(int j = 0; j < COLONNES; j++) {
            if (j == 0 || j == COLONNES-1) {
                plateau[i][j] = BORDURECOTE;
            }
            else if (i == 0) {
                plateau[i][j] = HAUTPLATEAU;
            }
            else if (i == LIGNES-1) {
                plateau[i][j] = BASPLATEAU;
            }
            else {
                plateau[i][j] = '.';
            }
        }
    }
    // Position des oiseaux
    plateau[2][2]= OISEAU; // oiseau symbole ♫
    plateau[1][COLONNES-2]= OISEAU; // oiseau symbole ♫
    plateau[LIGNES-2][1]= OISEAU; // oiseau symbole ♫
    plateau[LIGNES-2][COLONNES-2]= OISEAU; // oiseau symbole ♫

    // Coins du plateau
    plateau[0][0] = COINSUPG;  // coin supérieur gauche: ┌
    plateau[0][COLONNES-1] = COINSUPD;  // coin supérieur droit: ┐
    plateau[LIGNES-1][0] =COININFG ;  // coin inférieur gauche: └
    plateau[LIGNES-1][COLONNES-1] = COININFD;  // coin inférieur droit: ┘

    // Position initale de Snoopy
    *snoopyX = 4; // Position initiale de Snoopy en X
    *snoopyY = 9; // Position initiale de Snoopy en Y
    plateau[*snoopyX][*snoopyY] = SNOOPY; // Positionner Snoopy sur le plateau

    // Position blocs invincibles en 2 parties
    for (int i = 1; i <= 4; i++) {
        plateau[i][1] = BLOCINVINCIBLES;
        plateau[i][COLONNES-2] = BLOCINVINCIBLES;
    }
    for (int i = 1; i <= 7; i++) {
        plateau[1][i] = BLOCINVINCIBLES;
        plateau[4][i] = BLOCINVINCIBLES;
    }
    plateau[2][3] = BLOCPIEGE;
    plateau[3][5] = BLOCPIEGE;
    plateau[2][7] = BLOCPIEGE;
    plateau[5][] = BLOCPOUSSABLES;

}

int main() {
    printf("Hello, World!\n");
    return 0;
}
