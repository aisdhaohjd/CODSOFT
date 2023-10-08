#include <iostream>
#include <random>

int main() {
    // Initialize a random number generator
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(1, 100); // Generate random numbers between 1 and 100

    // Generate a random number for the user to guess
    int targetNumber = distribution(generator);

    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;

    do {
        std::cout << "Enter your guess (1-100): ";
        std::cin >> guess;
        attempts++;

        if (guess < targetNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > targetNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number (" << targetNumber << ") in "
                      << attempts << " attempts!" << std::endl;
        }
    } while (guess != targetNumber);

    return 0;
}

