#include <iostream>
#include <limits>
#include <algorithm>
#include <stdexcept> /* To gain access to a variety of standard exceptions, including runtime_error, invalid_argument.*/
#include <string>
#include <cctype>

using namespace std;

/* Calculation Function Prototype */
double calculate (double numOne, double numTwo, char operation);

int main()
{
    double numOne, numTwo;
    char operation;
    bool continueCalculation = true;

    while (continueCalculation)
    {
        cout << "Enter first number: ";
        while (!(cin >> numOne))
        {
            cout << "Invalid input. Please enter a number: ";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input.
        }

        cout << "Enter an operation (+, -, *, /): ";
        cin >> operation;
        
        cout << "Enter second number: ";
        while (!(cin >> numTwo))
        {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        try
        {
            double result = calculate(numOne, numTwo, operation);
            cout << "Result: " << result << endl;
        }
        catch (const exception& e)
        {
            cout << e.what() << endl;
        }

        cout << "Do you want to perform another calculation? (y/n): ";
        string choice;
        cin >> choice;
        continueCalculation = (choice == "Y" || choice == "YES");

    }
    
    cout << "Calculator exited. " << endl;
    return 0;
}

/* Calculation Function Declaration */
double calculate (double numOne, double numTwo, char operation)
{
    switch (operation)
    {
    case '+':
        return numOne + numTwo;
    case '-':
        return numOne - numTwo;
    case '*':
        return numOne * numTwo;
    case '/':
        if(numTwo == 0)
        {
            throw runtime_error("Error: Division by zero.");
        }

        return numOne / numTwo;
    
    default:
        throw invalid_argument("\nInvalid input, Enter a valid operator.");
    }

}