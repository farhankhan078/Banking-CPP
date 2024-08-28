#include <iostream>
#include <iomanip> // Required for setprecision

using namespace std;

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main()
{
    double balance = 0;
    int choice = 0;

    do
    {
        cout << "\nEnter your choice:\n";
        cout << "******************\n";
        cout << "1. Show Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        // Simple loop to ensure choice is between 1 and 4
        while (choice < 1 || choice > 4) {
            cout << "Invalid choice. Please enter a number between 1 and 4: ";
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
            showBalance(balance);
            break;
        case 2:
            balance += deposit();
            showBalance(balance);
            break;
        case 3:
            balance -= withdraw(balance);
            showBalance(balance);
            break;
        case 4:
            cout << "Thanks for visiting!\n";
            break;
        }
    } while (choice != 4);

    return 0;
}

void showBalance(double balance)
{
    cout << "Your balance is:  ₹ " << setprecision(2) << fixed << balance << '\n'; //The setprecision(2) function is used to control the number of digits that are displayed for floating-point numbers when outputting them with cout.
}

double deposit()
{
    double amount = 0;

    cout << "Enter amount to be deposited: ";
    cin >> amount;

    if (amount > 0)
    {
        return amount;
    }
    else
    {
        cout << "That's not a valid amount:\n";
        return 0;
    }
}

double withdraw(double balance)
{
    double amount = 0;

    cout << "Enter amount to be withdrawn: ";
    cin >> amount;

    if (amount > balance)
    {
        cout << "Insufficient funds\n\n";
        return 0;
    }
    else if (amount < 0)
    {
        cout << "That's not a valid amount\n\n";
        return 0;
    }
    else
    {
        return amount;
    }
}