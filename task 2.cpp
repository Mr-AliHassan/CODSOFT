#include <iostream>

using namespace std;

int main() {
    char op;
    float num1, num2;

    cout << "Enter operator either + or - or * or /: ";
    cin >> op;

    cout << "Enter two operands: ";
    cin >> num1 >> num2;

    switch(op) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2;
            break;

        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2;
            break;

        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2;
            break;

        case '/':
            if (num2 == 0) {
                cout << "Error! Division by zero!";
            } else {
                cout << num1 << " / " << num2 << " = " << num1 / num2;
            }
            break;

        default:
            // If the operator is not +, -, * or /, display an error message
            cout << "Error! Invalid operator";
            break;
    }

    return 0;
}
