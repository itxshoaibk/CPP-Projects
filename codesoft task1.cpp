#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Initialize random seed
    std::srand(std::time(0));

    // Generate a random number between 1 and 100
    int randomNumber = std::rand() % 100 + 1;
    int userGuess = 0;

    std::cout << "I have generated a random number between 1 and 100.\n";
    std::cout << "Can you guess what it is?\n";

    // Loop until the user guesses the correct number
    while (userGuess != randomNumber) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        if (userGuess < randomNumber) {
            std::cout << "Your guess is too low. Try again.\n";
        } else if (userGuess > randomNumber) {
            std::cout << "Your guess is too high. Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the correct number.\n";
        }
    }

    return 0;
} 

