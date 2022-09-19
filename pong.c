#include <stdio.h>
#include <stdlib.h>

void playerOneWinningScreen();
void playerTwoWinningScreen();

void Draw(int xBall, int yBall, int topPlayerOneRacket, int midPlayerOneRacket, int bottomPlayerOneRacket,
          int topPlayerTwoRacket, int midPlayerTwoRacket, int bottomPlayerTwoRacket, int playerOneScore,
          int playerTwoScore);

int main() {
    //  z = left up, c = left down, a = right up, d = right down;
    int xBall = 1;
    int yBall = 15;

    int topPlayerOneRacket = 14;
    int midPlayerOneRacket = 15;
    int bottomPlayerOneRacket = 16;

    int topPlayerTwoRacket = 14;
    int midPlayerTwoRacket = 15;
    int bottomPlayerTwoRacket = 16;

    int playerOneScore = 0;
    int playerTwoScore = 0;

    char moveBall = 'a';

    printf("\033[0D\033[2J");
    printf("\n");
    printf("                                Rules\n");
    printf("To move the rackets use A/Z for Player 1 and K/M for Player 2, ");
    printf("to skip an action\nuse Space Bar. ");
    printf("The game ends when one of the players scores 21 points.\n");

    Draw(xBall, yBall, topPlayerOneRacket, midPlayerOneRacket, bottomPlayerOneRacket, topPlayerTwoRacket,
         midPlayerTwoRacket, bottomPlayerTwoRacket, playerOneScore, playerTwoScore);

    while (playerOneScore != 21 && playerTwoScore != 21) {

        char movement;
        char pl_1_key = '\0';
        char pl_2_key = '\0';
        char symb = '\0';

        movement = getchar();

        while (movement != '\n') {
            if (movement == 'A' || movement == 'a') {
                pl_1_key = 'A';
            } else if (movement == 'Z' || movement == 'z') {
                pl_1_key = 'Z';
            } else if (movement == 'K' || movement == 'k') {
                pl_2_key = 'K';
            } else if (movement == 'M' || movement == 'm') {
                pl_2_key = 'M';
            } else if (movement == ' ') {
                symb = ' ';
            } else if (movement == 'Q' || movement == 'q') {
                printf("\033[0D\033[2J");
                exit(1);
            }
            movement = getchar();
        }

        if (pl_1_key == 'A' && topPlayerOneRacket > 3) {
            topPlayerOneRacket--;
            midPlayerOneRacket--;
            bottomPlayerOneRacket--;
        } else if (pl_1_key == 'Z' && bottomPlayerOneRacket < 26) {
            topPlayerOneRacket++;
            midPlayerOneRacket++;
            bottomPlayerOneRacket++;
        }

        if (pl_2_key == 'K' && topPlayerTwoRacket > 3) {
            topPlayerTwoRacket--;
            midPlayerTwoRacket--;
            bottomPlayerTwoRacket--;
        } else if (pl_2_key == 'M' && bottomPlayerTwoRacket < 26) {
            topPlayerTwoRacket++;
            midPlayerTwoRacket++;
            bottomPlayerTwoRacket++;
        }

        if (pl_1_key == 'A' || pl_1_key == 'Z' || pl_2_key == 'K' || pl_2_key == 'M' || symb == ' ') {
            if (xBall == 1) {
                if (yBall == midPlayerOneRacket || yBall == topPlayerOneRacket ||
                    yBall == bottomPlayerOneRacket) {
                    if (moveBall == 'z') {
                        moveBall = 'a';
                    } else if (moveBall == 'c') {
                        moveBall = 'd';
                    }
                } else if (yBall == topPlayerOneRacket - 1) {
                    if (moveBall == 'c') {
                        moveBall = 'a';
                    }
                } else if (yBall == bottomPlayerOneRacket + 1) {
                    if (moveBall == 'z') {
                        moveBall = 'd';
                    }
                }
            } else if (xBall == 78) {
                if (yBall == midPlayerTwoRacket || yBall == topPlayerTwoRacket ||
                    yBall == bottomPlayerTwoRacket) {
                    if (moveBall == 'd') {
                        moveBall = 'c';
                    } else if (moveBall == 'a') {
                        moveBall = 'z';
                    }
                } else if (yBall == topPlayerTwoRacket - 1) {
                    if (moveBall == 'd') {
                        moveBall = 'z';
                    }
                } else if (yBall == bottomPlayerTwoRacket + 1) {
                    if (moveBall == 'a') {
                        moveBall = 'c';
                    }
                }
            } else if (xBall == 0) {

                playerTwoScore++;
                xBall = 1;
                yBall = 15;

                topPlayerOneRacket = 14;
                midPlayerOneRacket = 15;
                bottomPlayerOneRacket = 16;

                topPlayerTwoRacket = 14;
                midPlayerTwoRacket = 15;
                bottomPlayerTwoRacket = 16;

                if (playerTwoScore == 21) {
                    printf("\033[0D\033[2J");
                    playerTwoWinningScreen();
                    getchar();
                }
                continue;
            } else if (xBall == 79) {

                playerOneScore++;
                xBall = 78;
                yBall = 15;
                
                topPlayerOneRacket = 14;
                midPlayerOneRacket = 15;
                bottomPlayerOneRacket = 16;

                topPlayerTwoRacket = 14;
                midPlayerTwoRacket = 15;
                bottomPlayerTwoRacket = 16;

                if (playerOneScore == 21) {
                    printf("\033[0D\033[2J");
                    playerOneWinningScreen();
                    getchar();
                }
                continue;
            }
            if (yBall == 3) {
                if (moveBall == 'z') {
                    moveBall = 'c';
                } else if (moveBall == 'a') {
                    moveBall = 'd';
                }
            }

            if (yBall == 26) {
                if (moveBall == 'c') {
                    moveBall = 'z';
                } else if (moveBall == 'd') {
                    moveBall = 'a';
                }
            }

            switch (moveBall) {
                case 'a':
                    xBall++;
                    yBall--;
                    break;
                case 'd':
                    xBall++;
                    yBall++;
                    break;
                case 'z':
                    xBall--;
                    yBall--;
                    break;
                case 'c':
                    xBall--;
                    yBall++;
                    break;
            }
        }
        printf("\033[0D\033[2J");
        if (playerOneScore != 21 && playerTwoScore != 21) {
            Draw(xBall, yBall, topPlayerOneRacket, midPlayerOneRacket, bottomPlayerOneRacket,
                 topPlayerTwoRacket, midPlayerTwoRacket, bottomPlayerTwoRacket, playerOneScore,
                 playerTwoScore);
        }
    }
}

void Draw(int xBall, int yBall, int topPlayerOneRacket, int midPlayerOneRacket, int bottomPlayerOneRacket,
          int topPlayerTwoRacket, int midPlayerTwoRacket, int bottomPlayerTwoRacket, int playerOneScore,
          int playerTwoScore) {
    printf(
        "Player 1:    %.02d                                                   "
        "Player 2:   %.02d\n",
        playerOneScore, playerTwoScore);
    printf("\n");
    
    for (int y = 2; y <= 27; ++y) {
        for (int x = 0; x < 80; ++x) {
            if (y == 2 || y == 27) {
                printf("-");
            } else {
                if (x == 0) {
                    if (y == bottomPlayerOneRacket || y == midPlayerOneRacket || y == topPlayerOneRacket) {
                        printf("|");
                    } else {
                        printf(" ");
                    }
                } else if (x == 79) {
                    if (y == bottomPlayerTwoRacket || y == midPlayerTwoRacket || y == topPlayerTwoRacket) {
                        printf("|");
                    } else {
                        printf(" ");
                    }
                } else if (x == xBall && y == yBall) {
                    printf("o");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

void playerOneWinningScreen() {
    printf(
        " ------------------------------------------------------------------"
        "-"
        "--------\n");
    printf(
        "|     ***  *    ****  *   *  ***  ***      **    *  *  *   ****   **  *"
        " "
        "    |\n");
    printf(
        "|     * *  *    *  *  *   *  *    * *    *  *    *  *  *   *  *   **  *"
        " "
        "    |\n");
    printf(
        "|     ***  *    ****   * *   ***  ***       *    *  *  *   *  *   * * *"
        " "
        "    |\n");
    printf(
        "|     *    *    *  *    *    *    *  *      *    * *** *   *  *   * * *"
        " "
        "    |\n");
    printf(
        "|     *    ***  *  *    *    ***  *  *     ***   ** * **   ****   *  **"
        " "
        "    |\n");
    printf(
        " ------------------------------------------------------------------"
        "-"
        "--------\n");
}

void playerTwoWinningScreen() {
    printf(
        " -------------------------------------------------------------------"
        "-"
        "--------\n");
    printf(
        "|     ***  *    ****  *   *  ***  ***      ***    *  *  *   ****   **  *"
        " "
        "    |\n");
    printf(
        "|     * *  *    *  *  *   *  *    * *        *    *  *  *   *  *   **  *"
        " "
        "    |\n");
    printf(
        "|     ***  *    ****   * *   ***  ***      ***    *  *  *   *  *   * * *"
        " "
        "    |\n");
    printf(
        "|     *    *    *  *    *    *    *  *     *      * *** *   *  *   * * *"
        " "
        "    |\n");
    printf(
        "|     *    ***  *  *    *    ***  *  *     ***    ** * **   ****   *  **"
        " "
        "    |\n");
    printf(
        " -------------------------------------------------------------------"
        "-"
        "--------\n");
}
