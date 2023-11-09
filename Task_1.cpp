#include <iostream>
#include <ctime>
using namespace std;

int randInt(int max) {
    // Generating random number between 1 - max
    return (rand() % max) + 1;
}


int main(int argc, char** agrv) {
    // generate a random seed
    srand(time(NULL));
    int chances = 5;

    int guessedNum;
    int proximity;
    int randNum = randInt(10);
    const string heart = "\u2764";

    while(chances > 0) {
        for(int i = 0; i < chances; i++){
            cout << heart;
        }
        cout << endl << "Enter your guess: ";
        cin >> guessedNum;

        proximity = randNum - guessedNum;

        if(proximity == 0)
            break;

        else if(proximity < 0){
            cout << "Your guess is high. Try Again!" << endl;
            chances--;
        }

        else if(proximity > 0){
            cout << "Your guess is low. Try Again!" << endl;
            chances--;
        }
    }

    if(chances == 0){
        cout << "You lose!" << endl;
    } else{
        cout << "YaY. You found the number: " << randNum << endl;
    }

    return 0;
}