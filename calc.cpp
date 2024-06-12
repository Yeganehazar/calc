#include <iostream>

using namespace std;

struct Calculator {
    
    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (b == 0) {
            cout << "Error: Division by zero is not allowed." << endl;
            return 0;
        }
        return a / b;
    }

    int modulus(int a, int b) {
        if (b == 0) {
            cout << "Error: Division by zero is not allowed." << endl;
            return 0;
        }
        return a % b;
    }

    double power(double base, int exponent) {
        if (exponent == 0) return 1;
        if (exponent < 0) return 1 / power(base, -exponent);
        return base * power(base, exponent - 1);
    }

    
    void performCalculation() {
        double num1, num2;
        char operation;
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter an operator (+, -, *, /, %, ^): ";
        cin >> operation;

        
        if (operation != '^') {
            cout << "Enter second number: ";
            cin >> num2;
        }

        switch (operation) {
            case '+':
                cout << "Result: " << add(num1, num2) << endl;
                break;
            case '-':
                cout << "Result: " << subtract(num1, num2) << endl;
                break;
            case '*':
                cout << "Result: " << multiply(num1, num2) << endl;
                break;
            case '/':
                cout << "Result: " << divide(num1, num2) << endl;
                break;
            case '%':
                
                cout << "Result: " << modulus(static_cast<int>(num1), static_cast<int>(num2)) << endl;
                break;
            case '^':
                
                cout << "Enter exponent: ";
                int exponent;
                cin >> exponent;
                cout << "Result: " << power(num1, exponent) << endl;
                break;
            default:
                cout << "Error: Invalid operator entered." << endl;
        }
    }
};

int main() {
    Calculator calc;
    char continueCalculation = 'y';

    while (continueCalculation == 'y' || continueCalculation == 'Y') {
        calc.performCalculation();
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> continueCalculation;
    }

    return 0;
}
