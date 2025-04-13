#include<iostream>
#include<fstream>
#include<map>

using namespace std;

class Bank{
    map<string,double> account;
    public:
        void createAccount(string name)
        {
            if(account.find(name) != account.end())
            {
                cout << "Account already exist!\n";
                return;
            }
            account[name] = 0.0;
            cout << "Account created for "<< name <<"\n";
        }
        
        void deposit(string name, double amount)
        {
            if(account.find(name) == account.end())
            {
                cout << "No such account!\n";
                return;
            }
            account[name] += amount;
            cout << "Deposited Rs. " << amount << " to " << name << "\n";
        }
        
        void withdraw(string name, double amount)
        {
            if(account.find(name) == account.end() || account[name] < amount)
            {
                cout << "Insufficient fund or no such account!\n";
                return;
            }
            account[name] -= amount;
            cout << "Withdraw Rs. " << amount << " from " << name << "\n";
        }
        
        void showBalance(string name)
        {
            if(account.find(name) == account.end())
            {
                cout << "No such account!\n";
                return;
            }
            cout << "Balance for " << name << ": Rs. " << account[name] << "\n";
        }
};

int main(){
    Bank bank;
    int choice;
    string name;
    double amount;
    do{
        cout << "-- Bank Management CLI --\n";
        cout << "1. Create account\n2. Deposit \n3. Withdraw \n4. Show Balance \n5. Exit \nChoose: ";
        cin >> choice;
        
        switch(choice)
        {
            case 1: 
                cout << "Enter name: "; cin >> name;
                bank.createAccount(name);
                break;
            case 2:
                cout << "Enter name and amount "; cin >> name >> amount;
                bank.deposit(name,amount);
                break;
            case 3:
                cout << "Enter name and amount "; cin >> name >> amount;
                bank.withdraw(name,amount);
                break;
            case 4:
                cout << "Enter name :"; cin >> name;
                bank.showBalance(name);
                break;
            case 5:
                cout << "Good Bye!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    }while(choice != 5);
    return 0;
}
