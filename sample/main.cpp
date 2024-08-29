#include <iostream>

using namespace std;

int main()
{
    double num1,num2;
    char operation;
    cout<<"enter the first number";//printing message to allow user to enter first number
    cin>>num1;// taking input from the user for first number
    cout<<"enter the second number ";
    cin>> num2;// taking user input for the second number
    // print the message for  user to choose operation
    cout<<"enter the operation (+ ,-,/,*): ";
    // take input of operation
    cin>>operation;
    //implement switch case for menu driven program
    switch(operation)
    {
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
        if (num2 != 0)
            cout << "Result: " << num1 / num2 << endl;
        else
            cout << "Error: Division by zero!" << endl;
        break;
    default:
        cout << "Error: Invalid operator!" << endl;
    }


    return 0;
}
