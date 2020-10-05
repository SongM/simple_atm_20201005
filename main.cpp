#include <iostream>
#include <unordered_map>
using namespace std;
class Account{
    private:
        int accountNumber;
        int pinNumber;
        int balance[3];
    public:
        Account() {};
        Account(int _accountNumber, int _pinNumber, int _balance1, int _balance2, int _balance3)
        {
            accountNumber = _accountNumber;
            pinNumber = _pinNumber;
            balance[0] = _balance1;
            balance[1] = _balance2;
            balance[2] = _balance3;
        }
        bool isPinCorrect(int pin_input)
        {
//            cout<<pin_input<<","<<pinNumber;
            return(pin_input==pinNumber);
        }
        void displayBalance(int account_num)
        {
            cout<<"Account "<<account_num<<" balance: "<<balance[account_num-1]<<endl;
        }
        void withdraw(int account_num, int withdraw_amount)
        {
            balance[account_num-1] -= withdraw_amount;
        }
        void deposit(int account_num, int deposit_amount)
        {
            balance[account_num-1] += deposit_amount;
        }


        void displayAllInformation()
        {
            cout<<"AccountNumber: "<<accountNumber<<endl;
            cout<<"PinNumber: "<<pinNumber<<endl;
            for (int account_num=1;account_num<=3;account_num++)
                cout<<"Account "<<account_num<<" balance: "<<balance[account_num-1]<<endl;
        }
};

unordered_map<int, Account> users;

bool isValidInsertCard(Account*& user)
{
    int input_account;
    cin>>input_account;
    if(users.find(input_account)==users.end()) return(false);
    user = &users[input_account];
    return(true);

}

int main()
{
    for (int i=1000;i<1010;i++)
    {
        Account user(i,i+100000,i/10,i*10,i-100);
        users[i] = user;
    }
    while(1)
    {
        cout<<"**********************************"<<endl;
        cout<<"welcome"<<endl;
        cout<<"***insert card/input account number: "<<endl;
        Account* user;
        if (isValidInsertCard(user)==false)
        {
            cout<<"account does not exist"<<endl;
            continue;
        }

        cout<<"***input pin number"<<endl;
        int input_pin;
        cin>>input_pin;
        if(user->isPinCorrect(input_pin)==false)
        {

            cout<<"pin is not correct"<<endl;
            continue;
        }

        cout<<"***select account"<<endl;
        cout<<"1. Account 1"<<endl;
        cout<<"2. Account 2"<<endl;
        cout<<"3. Account 3"<<endl;
        int account_num;
        cin>>account_num;
        cout<<"***choose operations"<<endl;
        cout<<"1. show balance"<<endl;
        cout<<"2. withdraw"<<endl;
        cout<<"3. deposit"<<endl;
        int op_ind;
        cin>>op_ind;
        if (op_ind==1) user->displayBalance(account_num);
        else if(op_ind==2)
        {
            cout<<"***input withdraw amount"<<endl;
            int withdraw_amount;
            cin>>withdraw_amount;
            user->withdraw(account_num, withdraw_amount);
        }
        else if(op_ind==3)
        {
            cout<<"***input deposit amount"<<endl;
            int deposit_amount;
            cin>>deposit_amount;
            user->deposit(account_num, deposit_amount);
        }
        user->displayAllInformation();
    }
    return 0;
}
