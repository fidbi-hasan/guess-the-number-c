#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  FILE *fptr; // creating a file pointer
  fptr = fopen("game_info.txt", "wb"); // opening a file with write (append) access 

  fprintf(fptr, "##-> Number Guessing Game <-##\n");
  fprintf(fptr, "Score count criteria: \n"); 
  fprintf(fptr, "Total Points = (10 * Total Rounds) - Total Guesses + Total Rounds\n");

  int randomNum, guessedNum;
  int totalAttempts, totalRounds = 0, totalGameAttempts = 0;
  char decision = 'y';
  char name[100];

  srand(time(NULL));

  printf("Welcome to Guessing Number Game\n\n");

  printf("Enter your name: ");
  fgets(name, 100, stdin);

  for (int i = 0; name[i] != '\0'; i++) {
    if(name[i] == '\n') name[i] = '\0';
    if(name[i] >= 'A' && name[i] <= 'Z') name[i] += 32;
  }

  printf("Hello, %s!\n", name);

  while (decision == 'y') {
    totalAttempts = 0;
    randomNum = rand() % 100 + 1;

    do {
      printf("Please guess a number (From 1 to 100): ");
      scanf("%d", &guessedNum);
      totalAttempts++;

      if(totalAttempts < 10) {
        if(guessedNum > randomNum) {
          printf("\nGuess a smaller number.\n\n");
        } else if(guessedNum < randomNum) {
          printf("\nGuess a larger number.\n\n");
        } else {
          printf("\nCongratulations!!! You have guessed the correct number!\n");
          printf("\nTotal attempts: %d\n\n", totalAttempts);
        }
      } else {
        printf(":( Poor guessing skill!\n");
        printf(":( Game over! Better luck next time.\n");
        break;
      }
      
    } while(guessedNum != randomNum);

    totalRounds++;
    totalGameAttempts += totalAttempts;

    printf("Do you want to play another round? (y/n): ");
    scanf(" %c", &decision);
  }

  int totalPoints = (10 * totalRounds) - totalGameAttempts + totalRounds;
  int average = totalPoints / totalRounds;
  char *grade;

  switch(average) {
    case 10:
      grade = "A+";
      break;
    case 9:
      grade = "A";
      break;
    case 8:
      grade = "B+";
      break;
    case 7:
      grade = "B";
      break;
    case 6:
      grade = "C+";
      break;
    case 5:
      grade = "C";
      break;
    case 4:
      grade = "D+";
      break;
    case 3:
      grade = "D";
      break;
    case 2:
      grade = "F";
      break;
    case 1:
      grade = "F";
      break;
    default:
      grade = "F";
  }

  printf("====================X====================\n");
  printf("Game Summary:\n");
  printf("-> Player name: %s\n", name);
  printf("-> Total rounds played: %d\n", totalRounds);
  printf("-> Total attempts In today's game: %d\n", totalGameAttempts);
  printf("-> Total points: %d", totalPoints);
  printf("-> Average: %d\n", average);
  printf("-> Grade: %s", grade);
  printf("\n====================X====================");

  /* write in file */
  
  fprintf(fptr, "\n====================X====================\n");
  fprintf(fptr, "Game Summary:\n");
  fprintf(fptr, "-> Player name: %s\n", name);
  fprintf(fptr, "-> Total rounds played: %d\n", totalRounds);
  fprintf(fptr, "-> Total attempts In today's game: %d\n", totalGameAttempts);
  fprintf(fptr, "-> Total points: %d\n", totalPoints);
  fprintf(fptr, "-> Average: %d\n", average);
  fprintf(fptr, "-> Grade: %s", grade);
  fprintf(fptr, "\n====================X====================\n");

  printf("\nThanks for playing The Game!\t");
  printf("## Developed by: CodingComrade. ##");

  fclose(fptr);

  return 0;
}