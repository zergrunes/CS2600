
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// initializing global var
int maxNum = 10;

/* 
Create an interactive program that allows a user to guess a number between 1-10. 
You should create a menu that will have options 
(this should be displayed on the screen):
    Press 1 to play a game
	Press 2 to change the max number
	Press 3 to quit
*/
int main(){

    int numOfGuess, userGuess, userOption, max, wins = 0;
    int randNum;
    srand(time(0));
    
// listing the menu
    do{
        printf("Press 1 to play a game\n"
               "Press 2 to change the max number\n"
               "Press 3 to quit\n");
        scanf("%d",&userOption);

    // Will use switch statements here
    switch(userOption){
        /* If option 1 is selected the program should prompt the user to enter a number.*/
        case 1:
            numOfGuess = 0;
                printf("If you would like to exit, enter q, otherwise\n"
                       "Enter a number:\n");
                char input = getchar();
                switch(input){
                    case 'q':
                        return 0;
                        break;
                    default: // okay this is where i went wrong lol
                        scanf("%d",&userGuess);
                        randNum = rand()%maxNum+1;
                        if(userGuess>randNum){printf("Too high!\n");} 
                        else if(userGuess<randNum) {printf("Too low!\n");}
                        else{
                            wins = 1;
                            printf("You guessed it!\n");
                            break;
                        }
                        numOfGuess++;
                }
            
            /* end of case 1 */
        /* If option 2 is chosen, then tell them the max value they can set the number.*/
        case 2:
            printf("Enter the new maximum number:\n");
            do{
                scanf("%d", &max);
                /* user input validation */
                if(max < 0 || max >= 10)
                    printf("The number you have inputted is invalid.\n"
                           "Enter a valid number from 1-10.\n");
                else maxNum = max;
            }

            while(max < 0 || max >= 10);
                printf("New number range will be between 0 to %d\n", maxNum);
            break;
            /* end of case 2 */
        /*
            If option 3 is chosen complete the following three:
                1)	thank the user for playing, 
                2)	print out the result of all the games played. Number of guesses required to win. 
            NOTE: They could quit a game if this occurs indicate game was lost. 
                3)	end the game.
        */
        case 3:
            printf("Thank you for playing.\n");
            printf("Final Result:\n");
            if(wins == 1){
                printf("Congratulations, you've won!\n");
                printf("Only took you like %d times.\n", numOfGuess);
            }
            else{
                printf("Sorry you lost lol. Maybe try again?");
            }
            break;
        }
    }
    while(userOption != 3);
        return 0;
}

/** NOTE FOR PROFESSOR: 
 * I'm like 100% sure a part of this code does not run the way you wanted it to.
 * I was confused about the persist part and understanding the syntax for C, and
 * I would appreciate it if you can explain where I went wrong (or I can go to your office hours to talk about it)
 * thank you professor. 
 **/