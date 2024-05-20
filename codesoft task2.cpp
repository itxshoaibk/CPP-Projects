#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;
    bool validOperation = true;

    // Prompt user to enter the first number
    cout << "Enter the first number: ";
    cin >> num1;

    // Prompt user to enter the second number
    cout << "Enter the second number: ";
    cin >> num2;

    // Prompt user to enter the operation
    cout << "Enter the operation (+, -, *, /): ";
    cin >> operation;

    // Perform the desired operation
    switch(operation) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Result: " << num1 / num2 << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
        default:
            validOperation = false;
            cout << "Error: Invalid operation. Please enter +, -, *, or /." << endl;
    }

    // If the operation was invalid, prompt the user to try again
    if (!validOperation) {
        cout << "Please run the program again and enter a valid operation." << endl;
    }

    return 0;
}
