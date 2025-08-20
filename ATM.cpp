#include <iostream>
#include <string>
using namespace std;

class ATM {
private:
    double balance;
    string pin;

public:
    ATM(double bal = 1000.0, string p = "1234") {
        balance = bal;
        pin = p;
    }

    // Verify PIN with 3 attempts
    bool authenticate() {
        string enteredPin;
        int attempts = 3;
        while (attempts > 0) {
            cout << "Enter PIN: ";
            cin >> enteredPin;
            if (enteredPin == pin) {
                cout << "PIN verified!\n";
                return true;
            } else {
                attempts--;
                cout << "Wrong PIN. Attempts left: " << attempts << "\n";
            }
        }
        cout << "Too many wrong attempts. Card blocked.\n";
        return false;
    }

    void showMenu() {
        cout << "\n--- ATM Menu ---\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Change PIN\n";
        cout << "5. Exit\n";
    }

    void checkBalance() {
        cout << "Balance: $" << balance << "\n";
    }

    void deposit() {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << "\n";
        } else {
            cout << "Invalid amount.\n";
        }
    }

    void withdraw() {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << "\n";
        } else {
            cout << "Not enough balance or invalid amount.\n";
        }
    }

    void changePin() {
        string oldPin, newPin;
        cout << "Enter current PIN: ";
        cin >> oldPin;
        if (oldPin == pin) {
            cout << "Enter new 4-digit PIN: ";
            cin >> newPin;
            if (newPin.size() == 4) {
                pin = newPin;
                cout << "PIN changed successfully.\n";
            } else {
                cout << "PIN must be 4 digits.\n";
            }
        } else {
            cout << "Wrong current PIN.\n";
        }
    }

    void run() {
        cout << "Welcome to ATM!\n";
        if (!authenticate()) return;

        int choice;
        do {
            showMenu();
            cout << "Choose: ";
            cin >> choice;

            switch (choice) {
                case 1: checkBalance(); break;
                case 2: deposit(); break;
                case 3: withdraw(); break;
                case 4: changePin(); break;
                case 5: cout << "Goodbye!\n"; break;
                default: cout << "Invalid choice.\n";
            }
        } while (choice != 5);
    }
};

int main() {
    ATM atm;
    atm.run();
    return 0;
}

