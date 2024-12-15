#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
using namespace std;

class Employee
{
private:
    int id = 1, password[100];

public:
    char name[100][100];
    void signUp(void);
    void logIn(void);
    void display(void);
    void choice(void);
};

int main()
{
    Employee employee;
    while (true)
    {
        employee.choice();
    }
    return 0;
}

void Employee ::signUp()
{
    cout << "Enter your name: ";
    cin.ignore();
    cin.getline(name[id], 100);
    cout << "Enter the password: " << endl;
    cin >> password[id];
    cout << "New employee added!" << endl;
    cout << "Your id is " << id << "\nPlease note down the id as it will be required at the time of login" << endl;
    id++;
    logIn();
}

void Employee ::logIn()
{
    char n[100];
    int p, i;
    cout << "\nWelcome back!\n"
         << endl;
    cout << "Login to your account\n";
    cout << "Enter your id number: ";
    cin >> i;
    cout << "Enter your name: ";
    cin.ignore();
    cin.getline(n, 100);
    cout << "Enter the password: ";
    cin >> p;

    if (i >= 1 && i < id && strcmp(n, name[i]) == 0 && p == password[i])
    {
        cout << "Login successful!\n";
    }
    else
    {
        cout << "Invalid\n";
    }
}

void Employee ::choice()
{
    int input;
    cout << "Select an option below:\n1. Display all employees\n2. New employee\n3. Exit\n";
    cout << "Enter your choice (1, 2, or 3): ";
    cin >> input;
    switch (input)
    {
    case 1:
        display();
        break;
    case 2:
        signUp();
        break;
    case 3:
        cout << "Exiting program. Goodbye!\n";
        exit(0);
        break;
    default:
        cout << "Wrong option! Please try again.\n";
        choice();
    }
}

void Employee ::display()
{
    for (int i = 1; i <= id; i++)
    {
        cout << "\n id = " << i
             << ", name = " << name[i]
             << "and password = " << password[i];
    }
    cout << endl;
    choice();
}
