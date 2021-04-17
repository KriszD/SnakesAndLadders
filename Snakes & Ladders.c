//Kathrine Mondshain helped me with this project.
#include <stdio.h>
	//This is used for the rand function and makes srand and rand available for use.
#include <stdlib.h>
    //This makes time(NULL) available for use.
#include <time.h>

int gameBoard(int currpos, int roll); //This creates the function "gameBoard."

int rollDice(void);	//This creates the function "rollDice".

int main(void)	//This creates the function "main".

{
	//This prints greetings!
	printf("Greetings! Welcome to Snakes & Ladders!\n\n");
	int choice = 0;

	//This while loop repeats the game.
	while (choice != 3)
	{
		//This initializes the variables "choice, currpos_one, and currpos_two" and then prints out the options and asks the user to choose an option.
        int currpos_one = 0;
        int currpos_two = 0;
		printf("Options:\n");
		printf("1.Play Snakes & Ladders!\n2.Rules & How to play\n3.Quit\n\n");
		printf("Enter your selection:\n\n");
		scanf("%d", &choice);

		//This if statement is for option 1, it initializes the variables "choice_roll_dice, roll_one, and roll_two" and then tells the player that they have to roll the dice to become player 1.
		if (choice == 1)
		{
			int choice_roll_dice = 0;
			int roll_one = 0;
			int roll_two = 0;
			printf("\nEach player will roll, the person with the larger roll becomes player 1.\n");

			//This while loop repeats when the two rolls are equal, and there is a tie.
			while (roll_one == roll_two)
			{
				//This tells the user to press any key to roll the dice, it rolls the dice and sets roll_one to their roll. It then tells them the user the number they rolled.
				printf("Press any number to roll the dice\n\n");
				scanf("%d", &choice_roll_dice);
				roll_one = rollDice();
				printf("\nYour roll is %d\n", roll_one);

				//This tells the next user to press any key to roll the dice, it rolls the dice and sets roll_two to their roll. It then tells them the user the number they rolled.
				printf("Press any number to roll the dice\n\n");
				scanf("%d", &choice_roll_dice);
				roll_two = rollDice();
				printf("\nYour roll is %d\n", roll_two);

				//If user one's roll is greater, they are player one.
				if (roll_one > roll_two)
				{
					printf("The person who rolled first is player 1\n");
				}

				//If user two's roll is greater, they are player one.
				else if (roll_one < roll_two)
				{
					printf("The person who rolled second is player 1\n");
				}

				//If both rolls are equal, it tells them to reroll the dice.
				else if (roll_one == roll_two)
				{
					printf("There was a tie, there will be a reroll\n");
				}
			}

			//This tells the users the game has begun, and then loops the code until one user's position on the tiles is 100.
			printf("The game has begun\n");
			while (currpos_two < 100)
			{
				//This tells player 1  to roll the dice, it sets roll_one to the to the roll, and then adds their roll to their current position.
				printf("Player 1 press any number to roll the dice\n\n");
				scanf("%d", &choice_roll_dice);
				roll_one = rollDice();
				printf("Your roll is %d\n", roll_one);
				currpos_one = currpos_one + roll_one;
				currpos_one = gameBoard(currpos_one, roll_one);

				if (currpos_one == 100)
                {
                    break;
                }

				//This tells player 2 to roll the dice, it sets roll_two to the to the roll, and then adds their roll to their current position.
				printf("Player 2 press any number to roll the dice\n\n");
				scanf("%d", &choice_roll_dice);
				roll_two = rollDice();
				printf("Your roll is %d\n", roll_two);
				currpos_two = currpos_two + roll_two;
				currpos_two = gameBoard(currpos_two, roll_two);
			}
		}

		//If the user chooses option 2, it displays the rules of Snakes & Ladders.
		else if (choice == 2)
		{
            printf("\nRules of Snakes & Ladders:\n");
			printf("1.Each player begins on tile 1.\n");
            printf("2.Players take turns to roll the dice.\n");
            printf("3.You will move forward the number of spaces rolled on the dice.\n");
            printf("4.If your roll lands on a tile that is at the bottom of a ladder, you can move up to the tile that is at the top of the ladder.\n");
            printf("5.If your roll lands on a tile with the head of a snake, you will move down to the tile with the bottom of the snake.\n");
            printf("6.The first player to get to tile 100 is the winner.\n\n");
		}
		 //If the user chooses option 3, it says goodbye and ends the program.
		else if (choice == 3)
        {
            printf("\nGoodbye! Have a nice day!\n");
        }

		//If the user does not choose is not 1, 2, or 3, it will redisplay their options.
		else
		{
			printf("\nInvalid Response!\n\n");
		}
	}
}

//This is the beginning of the function "rollDice".
int rollDice(void)
{
	int roll = 0;

	srand(time(NULL)); //This sets the seed.
	roll = rand(); //This sets the roll to a random number.
	roll %= (6 - 1 + 1); //This sets the boundaries of the random number from 0-5.
	roll += 1; //This makes the roll from 1-6.
	return roll; //This function returns the variable "roll" to main
}

//This is the beginning of the function "gameBoard".
int gameBoard(int currpos, int roll)
{
	//This creates a switch case for each tile that is a snake or a ladder. It also has a case for tile 100, and tile 101-104.
	switch (currpos)
	{
		case 2:
			currpos = 38;
			printf("Your roll landed on tile 2, it's a ladder! You are now on tile 38\n");
			break;
		case 7:
			currpos = 14;
			printf("Your roll landed on tile 7, it's a ladder! You are now on tile 14\n");
			break;
		case 15:
			currpos = 26;
			printf("Your roll landed on tile 15, it's a ladder! You are now on tile 26\n");
			break;
		case 16:
			currpos = 6;
			printf("Your roll landed on tile 16, it's a snake! You are now on tile 6\n");
			break;
		case 28:
			currpos = 84;
			printf("Your roll landed on tile 28, it's a ladder! You are now on tile 84\n");
			break;
		case 36:
			currpos = 44;
			printf("Your roll landed on tile 36, it's a ladder! You are now on tile 44\n");
			break;
		case 46:
			currpos = 25;
			printf("Your roll landed on tile 46, it's a snake!  You are now on tile 25\n");
			break;
		case 49:
			currpos = 11;
			printf("Your roll landed on tile 49, it's a snake!  You are now on tile 11\n");
			break;
		case 51:
			currpos = 67;
			printf("Your roll landed on tile 51, it's a ladder! You are now on tile 67\n");
			break;
		case 62:
			currpos = 19;
			printf("Your roll landed on tile 62, it's a snake!  You are now on tile 19\n");
			break;
		case 64:
			currpos = 60;
			printf("Your roll landed on tile 64, it's a snake!  You are now on tile 60\n");
			break;
		case 71:
			currpos = 91;
			printf("Your roll landed on tile 71, it's a ladder! You are now on tile 91\n");
			break;
		case 74:
			currpos = 53;
			printf("Your roll landed on tile 74, it's a snake!  You are now on tile 53\n");
			break;
		case 89:
			currpos = 69;
			printf("Your roll landed on tile 89, it's a snake!  You are now on tile 69\n");
			break;
		case 92:
			currpos = 88;
			printf("Your roll landed on tile 92, it's a snake!  You are now on tile 88\n");
			break;
		case 95:
			currpos = 75;
			printf("Your roll landed on tile 95, it's a snake!  You are now on tile 75\n");
			break;
		case 99:
			currpos = 80;
			printf("Your roll landed on tile 99, it's a snake!  You are now on tile 80\n");
			break;
		case 100: //This isn't a special tile, but it will tell the player that they won.
			currpos = 100;
			printf("You are on tile 100! You have won snakes and ladders!\n\n");
			break;
		case 101:case 102:case 103:case 104: //If the player goes over 100 they go back to the position before their last roll.
			currpos = currpos - roll;
			printf("You went past tile 100!  You are now back on tile %d\n", currpos);
			break;

			//This sets a default case that displays the user's tile if they don't land on a snake or ladder.
		default:
			printf("You are on tile %d\n", currpos);
			break;
	}

	//This function returns the variable "currpos" to main
	return currpos;
}
