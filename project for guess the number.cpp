#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // seed the random number generator
    
    int secretNumber = rand() % 100 + 1; // random number between 1 and 100
    int attempts = 0;
    int guess;
    cout << "Welcome to the Number Guessing Game!" << endl;
    int level;
    cout << "Choose difficulty level: 1, 2 or 3" << endl;
    cin >> level;
    
    cout << "I have picked a number between 1 and 100. Try to guess it!" << endl << endl;
    
    int trials;
    switch (level){
        case 1:
        trials = 8;
        break;
        case 2:
        trials = 6;
        break;
        case 3:
        trials = 3;
        break;
        default:
        cout <<"Enter valid input" << endl;
        exit(0);
    }
    
    do {
        cout << "Enter the guess: ";
        cin >> guess;
        attempts++;
        
        if (guess < secretNumber && secretNumber - guess <= 10) {
            cout << "low! Try again." << endl;
        } 
        else if(guess < secretNumber && secretNumber - guess > 10){
            cout << "Too low! Try again." << endl;
        }
        else if(guess > secretNumber && guess - secretNumber <= 10){
            cout << "high! Try again." << endl;
        }
        else if (guess > secretNumber && guess - secretNumber > 10) {
            cout << "Too high! Try again." << endl;
        } else if(guess == secretNumber){
            cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
        }
        else{
            cout << "You Lost!" << endl;
        }
        
    } while (trials != 1 || guess == secretNumber);
    
    return 0;
}
