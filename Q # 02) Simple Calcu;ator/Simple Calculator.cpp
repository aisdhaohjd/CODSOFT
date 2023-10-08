#include <iostream>

int main() {
    char operation;
    double num1, num2, result;

    std::cout << "Welcome to the Basic Calculator!" << std::endl;

    // Input the first number
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    // Input the second number
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    // Choose the operation
    std::cout << "Choose an operation (+, -, *, /): ";
    std::cin >> operation;

    // Perform the selected operation and display the result
    switch (operation) {
        case '+':
            result = num1 + num2;
            std::cout << "Result: " << num1 << " + " << num2 << " = " << result << std::endl;
            break;
        case '-':
            result = num1 - num2;
            std::cout << "Result: " << num1 << " - " << num2 << " = " << result << std::endl;
            break;
        case '*':
            result = num1 * num2;
            std::cout << "Result: " << num1 << " * " << num2 << " = " << result << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                std::cout << "Result: " << num1 << " / " << num2 << " = " << result << std::endl;
            } else {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
            }
            break;
        default:
            std::cout << "Invalid operation. Please choose +, -, *, or /." << std::endl;
    }

    return 0;
}
