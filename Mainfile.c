include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


int roll(void) {
	int static DICE_SIDES = 6;

	/* random number generator + 1 used to range from 1 to 6 rather than 0 to 6 */
	int randNum = (rand()%DICE_SIDES)+1;
	return randNum;
}

/* ply turn handles each persons turn and the choices the plyer makes */
int playTurn(int currentPlayer, int playerScore) {
	int static losing_number = 1;
	int plyer_score = 0;
	_Bool turnDone = false;


	printf("if you are lucky enough to reach 20 click H to claim ur victory \n");
	printf("choose ur destiny roll or hold take control of your life !!!!!!!! \n");
	while(!turnDone) {
		printf("challenger %i - decide ur fate | r = roll | - | h = hold XD | ", currentPlayer);
		fflush(stdin); /* removes clutter */
		char choice = getchar();

	/* if they choose roll */
		if (choice == 'r') {
			int diceNumber = roll();
			printf("(u have chosen roll) result - %i, your score is ", diceNumber);
			if (diceNumber == losing_number) {
				printf("reset total to 0 \n");
				turnDone = true;
				printf("score equals %i.\n\n", playerScore);
				return playerScore;
			}
			else {
				plyer_score += diceNumber;
				printf("%i.\n", plyer_score);
			}
		}

		/* if they cant handle smoke */
		else if (choice == 'h') {
			turnDone = true;
			int totalScore = (playerScore + plyer_score);
			printf("Your score is %i.\n\n", totalScore);
			return totalScore;
		}
	}
}
/* initiating everything and handling switching profiles */
int main(void) {
	int static PLAYER_ONE = 1;
	int static PLAYER_TWO = 2;
	int currentPlayer = PLAYER_ONE;
	int score1 = 0;
	int score2 = 0;
	int winner = 0;
	_Bool gameDone = false;

/* random number using time */
	srand((unsigned)(time(NULL)));

	while (!gameDone) {
		if (currentPlayer == PLAYER_ONE) {
			score1 = playTurn(currentPlayer, score1);
			if (score1 >= 20) {
				winner = PLAYER_ONE;
        printf("challenger 1 wins \n");
				gameDone = true;
			}
			else {
				currentPlayer = PLAYER_TWO;
			}
		}
		else if (currentPlayer == PLAYER_TWO) {
			score2 = playTurn(currentPlayer, score2);
				if (score2 >= 20) {
					winner = PLAYER_TWO;
          printf("challenger 2 wins \n");
					gameDone = true;
				}
				else {
					currentPlayer = PLAYER_ONE;
				}
		}
	}
	printf("Game over challenger %i is victorious\n", winner);
	return 0;
}
