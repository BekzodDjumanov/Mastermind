#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <ctime>
#include <set>
#include <algorithm>

void displayColor(vector<string> colorLst) {
    for (int i = 0; i < 4; i++) {
        cout << colorLst[i] << " " << endl;
    }
}

void guessColor(vector<string> colorLst) {
    bool win = false;
    string playerColor = "";
    vector<string> colorGuess(4);
    int color = 0;
    int count = 1;

    while (!win) {
        cout << "\n\nRound #" << count << endl;
        for (int index = 0; index < 4; index++) {
            cout << "Enter Peg " << "#" << index + 1 << ":" << endl;
            cin >> color;
            if (cin.fail()) {
                cout << "OPERATION ABORTED! YOU BROKE THE PROGRAM!!" << endl;
                exit(0);
            }
            else {
                switch(color){
                    case 0:
                        playerColor = "blue";
                        colorGuess[index] = playerColor;
                        break;
                    case 1:
                        playerColor = "red";
                        colorGuess[index] = playerColor;
                        break;
                    case 2:
                        playerColor = "orange";
                        colorGuess[index] = playerColor;
                        break;
                    case 3:
                        playerColor = "yellow";
                        colorGuess[index] = playerColor;
                        break;
                    case 4:
                        playerColor = "green";
                        colorGuess[index] = playerColor;
                        break;
                    case 5:
                        playerColor = "pink";
                        colorGuess[index] = playerColor;
                        break;
                    case 6:
                        playerColor = "grey";
                        colorGuess[index] = playerColor;
                        break;
                    default:
                        cout << "Invalid color" << endl;
                        break;
            }
            }
            
        }
        cout << "Guess: ";
        for (int k = 0; k < 4;k++) { // displays guess
            cout << colorGuess[k] << " ";
        }

        if (set<string>(colorGuess.begin(), colorGuess.end()).size() != colorGuess.size()) {
            cout << "\nYou have entered a duplicate color, try again!" << endl;
        } else {
            cout << "\nHint: ";
            for (int i = 0; i < 4; i++) {
            if (colorGuess[i] == colorLst[i]) {
                cout << "B";
            }
            else if(find(colorLst.begin(), colorLst.end(), colorGuess[i]) != colorLst.end()) {
                cout << "W";
            }
        }
            count++;
        }


        if (colorLst == colorGuess) {
            cout << "\n\nYou win!" << endl;
            win = true;
            cout << "\nThe colors were: " << endl;
            displayColor(colorLst);
            break;
        }
        else if(count > 10) {
            cout << "\n\nYou lose!" << endl;
            win = false;
            cout << "\nThe colors were: " << endl;
            displayColor(colorLst);
            break;
        }
    }
}
int main() {
    vector<string> colors = {"blue", "red", "orange", "yellow", "green", "pink", "grey"};
    vector<string> colorLst(4);
    set<string> usedColors;
    int again;

    for (int count = 0; count < 7; count++) {
        cout << "Enter " << count << " for " << colors[count] << endl;
    }
    
    srand(time(0));

    int i = 0;
    while (i < 4) {
        int guess = rand() % 7;
        string color = colors[guess];
        if (usedColors.find(color) == usedColors.end()) {
            colorLst[i] = color;
            usedColors.insert(color);
            i++;  
        }
    }

    guessColor(colorLst);
    cout << "\nWould you like to play again? (1 for yes, 0 for no)" << endl;
    cin >> again;
    if (again == 1) {
        cout << "Let's play again!" << endl;
        main();
    }
    else if (again == 0 || cin.fail() || again > 1 || again < 0) {
        cout << "\nThanks for playing, Goodbye!" << endl;
    }
    return 0;
}

