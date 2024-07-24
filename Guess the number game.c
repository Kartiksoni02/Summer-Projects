
#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
map<string, int> mi;
map<string, int> hints;

// Function to play the game

void playGame() {
    string name;
    cout << "Enter your Name\n";
    cin >> name;
    int difficulty;

    cout << "Pick a difficulty level (1: Easy, 2: Medium, 3: Hard): ";

    cin >> difficulty;
    int maxRange, trials;
    switch (difficulty) {

        case 1:
            maxRange = 50; // Easy
            trials = 8;
            break;

        case 2:
            maxRange = 100; // Medium
            trials = 6;
            break;
        case 3:
            maxRange = 150; // Hard
            trials = 4;
            break;

    }

// Generate a random number within the specified range

    int ranNum = rand() % maxRange;

    cout << "┌───────────────────────────────────────────┐" << endl;
    cout << "│                                           │" << endl;
    cout << "│     Let's Play Guess a Number...          │" << endl;
    cout << "│                                           │" << endl;
    cout << "└───────────────────────────────────────────┘" << endl;

    bool win = false;
    int guess;
    int pTries = 0;
    while (!win && pTries != trials) {
        cout << "Guess a Number (0-" << maxRange << "), Let's see your Luck: ";
        cin >> guess;
        pTries++; // Increment the number of tries

        if (guess == ranNum) {
            cout << "Congratulations! You Guessed the Number in " << pTries << " Tries." << endl;

	    // Set win to true if the player guessed the number
            win = true;

            // LEADER board

             if (mi.find(name) == mi.end()) {
                mi[name] = 1;  // Add new player to the leaderboard
            } else {
                mi[name]++;   // Increment the player's score
            }
        } else if (guess < ranNum) {
            int diff = ranNum - guess;
            if (diff <= 10) {
                cout << "low but very close!" << endl;
            } else if (diff <= 20) {
                cout << "Low, but close. Guess again." << endl;
            } else {
                cout << "Too low and too far. Guess again." << endl;
            }
        } else {
            int diff = guess - ranNum;
            if (diff <= 10) {
                cout << "high but very close!" << endl;
            } else if (diff <= 20) {
                cout << "High, but a bit close. Guess again." << endl;
            } else {
                cout << "Too high and too far. Guess again." << endl;
            }
        }
    }


    if (!win) {
        cout << "You failed the game. The correct number was " << ranNum << "." << endl;
    }
}
void displayLeaderBoard() {
    cout << "\n Here is the LeaderBoard:\n";
    cout << "\n";
    cout << "Name\tScore\n";
    cout << "\n";
    for (auto i : mi) {
        cout << i.first << "\t" << i.second << "\t" <<  endl;
    }
    cout << "______________________\n";
}

// FUNCTION WILL BE USED TO DISPLAY THE MENU AND IT WILL HANDLE THE CHOICES OF THE USER

void displayMenu() {
    int choice;
    do {
        cout << "\nOptions:\n"
             << "1. Play\n"
             << "2. View LeaderBoard\n"
             << "3. Exit\n"
             << "Enter your choice: ";

        cin >> choice;
        switch (choice) {
            case 1:
                playGame(); // Call playGame function
                break;
            case 2:
                displayLeaderBoard(); // Call displayLeaderBoard function
                break;
            case 3:
                cout << "Thanks for your game, will meet again\n";
                break;
            default:
                cout << "Please have a valid Choice\n";
                break;
        }
    } while (choice != 3);  // Loop until the user chooses to exit
}
int main() {
    displayMenu();
    return 0;  // End of the program
}
