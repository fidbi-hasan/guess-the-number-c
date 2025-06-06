# 🎮 Number Guessing Game in C

Welcome to the **Number Guessing Game**, a console-based C program where you try to guess a randomly generated number between 1 and 100. The game evaluates your guessing skill, tracks performance, and assigns a final grade based on your average points per round.

## 📌 Features

* Random number generation between 1 and 100
* Score system with performance-based grading
* Multiple round support
* Tracks attempts, rounds, and total score
* Game summary stored in a file (`game_info.txt`)
* Interactive console UI with personalized greetings

## 🧮 Scoring Criteria

```
Total Points = (10 × Total Rounds) - Total Guesses + Total Rounds
```

Your final **grade** is based on the average score per round:

| Average | Grade |
| ------- | ----- |
| 10      | A+    |
| 9       | A     |
| 8       | B+    |
| 7       | B     |
| 6       | C+    |
| 5       | C     |
| 4       | D+    |
| 3       | D     |
| 1–2     | F     |

## 🗃️ Output File

All game summaries are saved in a file named:

```
game_info.txt
```

This includes:

* Player name
* Total rounds played
* Total attempts
* Total points
* Average score
* Grade

## 🛠️ How to Compile and Run

```bash
gcc -o guessing_game guessing_game.c
./guessing_game
```

Make sure you have `gcc` installed.

## 💡 Example Run

```bash
Welcome to Guessing Number Game

Enter your name: alice
Hello, alice!

Please guess a number (From 1 to 100): 50
Guess a larger number.

...
Congratulations!!! You have guessed the correct number!
Total attempts: 5

Do you want to play another round? (y/n): n

Game Summary:
-> Player name: alice
-> Total rounds played: 2
-> Total attempts In today's game: 11
-> Total points: 11
-> Average: 5
-> Grade: C
```

## 👨‍💻 Developer

**Fidbi Hasan**
Thanks for playing the game! Feedback and suggestions are welcome.

---

*this README.md file is written by ChatGPT*
