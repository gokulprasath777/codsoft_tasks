#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char op;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        cout << "========================================\n";
        cout << "           Simple Calculator\n";
        cout << "========================================\n";

        cout << "Enter first number: ";
        cin >> num1;

        cout << "Choose an operation (+, -, *, /): ";
        cin >> op;

        cout << "Enter second number: ";
        cin >> num2;

        bool validOperation = true;

        switch (op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 == 0) {
                    cout << "\nError: Division by zero is not allowed.\n";
                    validOperation = false;
                } else {
                    result = num1 / num2;
                }
                break;
            default:
                cout << "\nError: Invalid operator. Please use +, -, *, or /.\n";
                validOperation = false;
        }

        if (validOperation) {
            cout << "\nResult: " << num1 << " " << op << " " << num2 << " = " << result << "\n";
        }

        cout << "\nDo you want to perform another calculation? (y/n): ";
        cin >> choice;
        cout << "\n";
    }

    cout << "Thank you for using the calculator. Goodbye!\n";
    return 0;
}