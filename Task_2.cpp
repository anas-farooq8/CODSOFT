#include <iostream>
using namespace std;

class Calculator{
private:
    Calculator() {};
    
public:
    double static addition(double num1, double num2){
        return num1 + num2;
    }
    double static subtraction(double num1, double num2){
        return num1 - num2;
    }
    double static multiplication(double num1, double num2){
        return num1 * num2;
    }
    double static division(double num1, double num2){
        return num1 / num2;
    }
};

int main(int argc, char** argv) {
    int operation;
    double num1, num2;

    cout << "Enter first Number: ";
    cin >> num1;
    cout << "Enter second Number: ";
    cin >> num2;

    cout << "1: +, 2: -, 3: *, 4: /" << endl;
    cout << "Select Operation: ";
    cin >> operation;

    switch (operation)
    {
    case 1:
        cout << "The addition of numbers is: " << Calculator::addition(num1, num2);
        break;
    case 2:
        cout << "The subtraction of numbers is: " << Calculator::subtraction(num1, num2);
        break;
    case 3:
        cout << "The multiplication of numbers is: " << Calculator::multiplication(num1, num2);
        break;
    case 4:
        cout << "The division of numbers is: " << Calculator::division(num1, num2);
        break;
    default:
        cout << "Wrong Input!" << endl;
        break;
    }

    return 0;
}