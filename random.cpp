#include <iostream>
#include <cstdlib>
#include <ctime>

void numberGuessingGame() {
    // Initialize random seed
    std::srand(std::time(0));
    // Generate random number between 1 and 100
    int numberToGuess = std::rand() % 100 + 1;
    int guess = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have selected a number between 1 and 100. Try to guess it!" << std::endl;

    // Loop until the user guesses the correct number
    while (guess != numberToGuess) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if (guess < numberToGuess) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > numberToGuess) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number: " << numberToGuess << std::endl;
        }
    }
}

int main() {
    numberGuessingGame();
    return 0;
}
