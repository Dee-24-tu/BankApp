#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include "BANK_USERS.cpp"
using namespace std;

/// 'Base' first class representing a bank account
class New_Bank_Acc
{
public:
    /// Default constructor
    New_Bank_Acc();
    /// Overloaded constructor with initial balance
    New_Bank_Acc(float openBalance);

    /// Methods to access the class
    int get_Acc_No();
    float get_ini_Balance();
    string get_Branch_Code();
    string get_Open_Date();
    ///Account user details
    string set_Username();

    /// Deposit and withdraw methods
    virtual void deposit(double amount);
    virtual void withdraw(double amount);

    /// Display amount details
    void display_Basic_Acc(int acc_No[], int openBalance[], int size);
    double get_Balance();


private:
    /// Member variables
    int dm_Account_No;
    float dm_balance;
    float dm_open_Balance;
    string dm_Branch_Code;
    string dm_Open_Date;
    string dm_username;

    int size;
    float amount;
    float openBalance[];
    float Balance;
    string branchCode;
    std::vector<std::string> dateCreated;
    ///static variable to keep tract of A/C no.
    static int acc_No;
    ///  Static array to store transaction history
};



/// New customer accounting method implementation
string New_Bank_Acc::set_Username()
{
    cin.ignore();
    string username;
    cout << "| " << setw(22) << "Enter customer name: ";
    getline(cin, dm_username);
    return dm_username;
}


/// Member function definitions
string New_Bank_Acc::get_Branch_Code()
{
    dm_Branch_Code = "99-11-77";
    return dm_Branch_Code;
}


string New_Bank_Acc::get_Open_Date()
{
    return dm_Open_Date;
}


/// Initializing stactic A/C no.
int New_Bank_Acc::acc_No = 30083001;

New_Bank_Acc::get_Acc_No(){return dm_Account_No;}
float New_Bank_Acc::get_ini_Balance(){return dm_open_Balance;}
double New_Bank_Acc::get_Balance(){return dm_balance;}


/// Default constructor
New_Bank_Acc::New_Bank_Acc()
{
    dm_Account_No = acc_No++;
    cout << "| " << setw(27) << "Enter opening amount: ";
    cin >> dm_balance;
    cout << "| " << " Enter opened date DDMMYY: ";
    cin >> dm_Open_Date;
}


///  Overloaded constructor with initial balance
New_Bank_Acc::New_Bank_Acc(float openBalance)
{
    dm_Account_No = acc_No++;
    dm_open_Balance = openBalance;
}


void New_Bank_Acc::deposit(double amount)
{
    dm_balance += amount;
}


void New_Bank_Acc::withdraw(double amount)
{
    dm_balance -= amount;
}


/// Constructor Implementation to print out
void New_Bank_Acc::display_Basic_Acc(int acc_No[], int openBalance[], int size)
{
    cout << "-----------------------------------------------" << endl;
    cout << "| " << setw(19) << "Account numbers" << " | " << setw(13) << "Balance" << setw(10) << "|" << endl;
    cout << "-----------------------------------------------" << endl;
    for (int i = 0; i < 4; ++i)
    {
        cout << "| " << setw(13) << acc_No[0] << setw(9) <<" | "
        << setw(13) << openBalance[0] << setw(10) << " |" << endl;
    }

    cout << "-----------------------------------------------" << endl;
}




/// Second class - derived class
class Current_Acc:public New_Bank_Acc
{
public:
    /// Contructor
    Current_Acc();
    Current_Acc(float ini_balance, float overDraft_limit);

    /// Methods to access the class
    string get_Current_Acc_Type();
    float get_OverDraft_Limit();

private:
    /// Member variables
    string dm_type;
    float dm_OverDraft;
};


Current_Acc::Current_Acc()
{
    cout << "| " << setw(27) << "Key in A/C type" << setw(18) << " |" << endl;
    cout << "| " << setw(27) << "Student or Graduate: ";
    cin >> dm_type;
    cout << "| " << setw(27) << "Key in overdraft amount" << setw(18) << " |" << endl;
    cout << "| " << setw(27) << "3000 or 5000: ";
    cin >> dm_OverDraft;
}


string Current_Acc::get_Current_Acc_Type(){return dm_type;}
float Current_Acc::get_OverDraft_Limit(){return dm_OverDraft;}


/// Overloaded constructor with initial balance and overdraft limit
Current_Acc::Current_Acc(float ini_balance, float overDraft_limit):New_Bank_Acc(ini_balance)
{
    dm_OverDraft = overDraft_limit;

}




/// Third class - derived class
class Savings_Acc: public New_Bank_Acc
{
public:
    /// Contructor
    Savings_Acc();
    /// Overloaded constructor with initial balance and interest rate
    Savings_Acc(float ini_balance, float interest_rate);

    /// Methods to access the class
    string get_Savings_Acc_Type();
    float get_Savings_interest();

private:
    /// Member variables
    string dm_Savings_Type;
    float dm_Interest_Rate;
};


/// Constructor Implementation
Savings_Acc::Savings_Acc()
{
    cout << "| " << setw(27) <<  "Key in A/C type" << setw(18) << " |" << endl;
    cout << "| " << setw(27) <<  "Standard or Regular: ";
    cin >> dm_Savings_Type;
    cout << "| " << setw(27) <<  "Key in interest rate choice" << setw(18) << " |" << endl;
    cout << "| " << setw(27) <<  ".075 or 0.03: ";
    cin >> dm_Interest_Rate;
}


/// Constructor Implementation
string Savings_Acc::get_Savings_Acc_Type(){return dm_Savings_Type;}
float Savings_Acc::get_Savings_interest(){return dm_Interest_Rate;}


/// Overloaded constructor with initial balance and interest rate
Savings_Acc::Savings_Acc(float ini_balance, float interest_rate) : New_Bank_Acc(ini_balance)
{
    dm_Interest_Rate = interest_rate;
}





/// Arrays to store account details
int AccNo[4] = {30083001, 30083002, 30083003, 30083004};
float OpenBalance[4] = {500,350,290,850};
float Deposit[4] = {450,650,200,125};
float Withdraw[4] = {100,50,50,50};
float Balance[4];
string BranchCode[2] = {"99-11-77"};
string dateCreated[4] = {"010224", "020224", "030224", "040224"};
string AccType[2];
float OverDraft[2];
string response;
string Type[2];
string NewCustomer[100];
string newAccount;
int CurrentOption;
float InterestRate[2];
int choice;
bool validChoice = false;


int main()
{

    class Bank_Users Customer(12345678, 9887, "01021999");
    class Bank_Users Staff_User1("Manager", 1234, "Password.1x");
    class Bank_Users Staff_User2("Trainee", 2334, "Password.2x");

    cout << "| " << setw(20) << "Welcome to the Bank System." << setw(17) << "|" << endl;

    bool staffValidation = false;

    if (Staff_User1.Validate_User() || Staff_User2.Validate_User())
    {
        staffLogin = true;
        cout << "|" << setw(23) << "Staff Validated!" << setw(22) << "|" << endl;
        staffValidation = true;

        Staff_User1.formatLine();

        /// Ask if staff wants to validate a customer
        cout << "| Would you like to validate a customer?" << endl;
        cout << "| (Y/N): ";
            char option;
            cin >> option;

            if (toupper(option) == 'Y'  && staffValidation)
            {
                bool customerLogin = Customer.Validate_Customer();

                cout << time(0) << endl;
                Staff_User1.formatLine();
            }
            else
            {
                if (!staffValidation)
                {
                    cout << "|" << setw(45) << "|" << endl;
                    cout << "|" << setw(23) << "Invalid Staff!" << setw(22) << "|" << endl;
                    cout << "---------------------------------------------" << endl;
                }
            }
    }

    /// VALIDATION CODE END ********************************************

    cout << "-----------------------------------------------" << endl;
    cout << "| " << setw(45) << " |" << endl;
    cout << "| " << setw(22) << "Menu options" << setw(23) << "|" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "| " << setw(22) << "C for Customer" << setw(23) << "|" << endl;
    cout << "| " << setw(22) << "S for Staff" << setw(23) << "|" << endl;
    cout << "| " << setw(22) << "E for Exit" << setw(23) << "|" << endl;
    cout << "| " << setw(23) << "Enter your option: ";
        char UserType;
        cin >> UserType;
        UserType = tolower(UserType); /// Removes case sensitivity

        switch (UserType)
        {
            case 'c':
            {
                cout << "| " << setw(45) << " |" << endl;
                cout << "-----------------------------------------------" << endl;
                cout << "| " << " Enter 8 digits of A/C no. " << setw(18) << "|" << endl;
                cout << "| " << setw(27) << "80045001-30083001: ";
                cin >> choice;

                /// Validate account number
                bool found = false;
                int index = -1;
                for (int i = 0; i < 4; i++)
                {
                    if (AccNo[i] == choice)
                    {
                        found = true;
                        index = i;
                        break;
                    }
                }

                if (!found)
                {
                    cout << "| " << setw(27) << "Account not found!" << setw(18) << "|" << endl;
                    break;
                }

                /// Validate branch code, opened date, and opening balance
                cout << "| " << setw(27) << "Enter branch code " << setw(18) << "|" << endl;
                cout << "| " << setw(27) << "For example 99-11-77: ";
                cin >> response;

                /// Validate branch code against BranchCode array
                bool validBranch = false;
                for (int i = 0; i < 2; i++)
                {
                    if (response == BranchCode[i])
                    {
                        validBranch = true;
                        break;
                    }
                }

                if (!validBranch)
                {
                    cout << "| " << setw(27) << "Invalid branch code!" << setw(18) << "|" << endl;
                    break;
                }

                New_Bank_Acc accountInstance;
                double WithdrawAmount;
                double DepositAmount;
                int AccountNumber;

                cout << "-----------------------------------------------" << endl;
                cout << "| " << setw(45) << " |" << endl;
                cout << "| " << setw(22) << "Transaction Menu" << setw(23) << "|" << endl;
                cout << "-----------------------------------------------" << endl;
                cout << "| " << setw(22) << "Deposit 1*" << setw(23) << "|" << endl;
                cout << "| " << setw(22) << "Withdraw 2*" << setw(23) << "|" << endl;
                cout << "| " << setw(22) << "View Balance 3*" << setw(23) << "|" << endl;
                cout << "| " << setw(22) << "View Transaction 4*" << setw(23) << "|" << endl;
                cout << "| " << setw(22) << "Exit 5*" << setw(23) << "|" << endl;
                cout << "| " << setw(22) << "Enter your option: ";
                    cin >> CurrentOption;

                    switch (CurrentOption)
                    {
                        case 1:/// Deposit Option
                        {
                            cout << "| " << setw(45) << " |" << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "| " << setw(45) << " |" << endl;

                            cout << "| " << setw(27) << "Enter amount to deposit: ";
                            cin >> DepositAmount;

                            if (DepositAmount <= 0)
                            {
                                cout << "| " << setw(27) << "Invalid amount!" << setw(18) << "|" << endl;
                                exit(EXIT_FAILURE);
                            }

                            int AccIndex = -1;
                            for (int i = 0; i < 4; i++)
                            {
                                if (AccNo[i] == choice)
                                {
                                    AccIndex = i;
                                    break;
                                }
                            }

                            if (AccIndex == -1)
                            {
                                cout << "| " << setw(27) << "Account not found!" << setw(18) << "|" << endl;
                                exit(EXIT_FAILURE);
                            }

                            accountInstance.deposit(DepositAmount);
                            OpenBalance[AccIndex] += DepositAmount;

                            cout << "| " << setw(27) << "Deposit successful!" << setw(18) << "|" << endl;
                            cout << "| " << setw(27) << "Updated balance: " << OpenBalance[AccIndex] << setw(14) << "|" << endl;
                            exit(EXIT_FAILURE);
                        } /// Deposit end option

                        case 2:///Withdraw Option
                        {
                            cout << "| " << setw(45) << " |" << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "| " << setw(45) << " |" << endl;
                            cout << "| " << setw(27) << "Enter amount to withdraw: ";
                            cin >> WithdrawAmount;

                            if (WithdrawAmount <= 0)
                            {
                                cout << "| " << setw(27) << "Invalid amount!" << setw(18) << "|" << endl;
                                break;
                            }

                            int Transact_Index = -1;
                            for (int i = 0; i < 4; i++)
                            {
                                if (AccNo[i] == choice)
                                {
                                    Transact_Index = i;
                                    break;
                                }
                            }

                            if (Transact_Index == -1)
                            {
                                cout << "| " << setw(27) << "Account not found!" << setw(18) << "|" << endl;
                                exit(EXIT_FAILURE);
                            }

                            accountInstance.withdraw(WithdrawAmount);
                            OpenBalance[Transact_Index] -= WithdrawAmount;

                            cout << "| " << setw(27) << "Withdraw successful!" << setw(18) << "|" << endl;
                            cout << "| " << setw(27) << "Updated balance: " << OpenBalance[Transact_Index] << endl;
                            exit(EXIT_FAILURE);
                        }/// End the withdraw option

                        case 3:///Balance details option
                        {
                            int BalanceIndex = -1;
                            int BranchIndex = -1;
                            for (int i = 0; i < 4; i++)
                            {
                                if (AccNo[i] == choice)
                                {
                                    BalanceIndex = i;
                                    break;
                                }
                            }

                            if (BalanceIndex == -1)
                            {
                                cout << "| " << setw(27) << "Account not found!" << setw(18) << "|" << endl;
                                exit(EXIT_FAILURE);
                            }

                            string openDate = accountInstance.get_Open_Date();
                            string username = accountInstance.set_Username();
                            string branchCode = accountInstance.get_Branch_Code();

                            for (int i = 0; i < 2; i++)
                            {
                                if (branchCode == BranchCode[i])
                                {
                                    BranchIndex = i;
                                    break;
                                }
                            }

                            if (BranchIndex == -1)
                            {
                                cout << "| " << setw(22) << "Branch code not found!" << setw(23) << "|" << endl;
                                exit(EXIT_FAILURE);
                            }

                            /// Displays account details
                            cout << "| " << setw(45) << " |" << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "| " << setw(45) << " |" << endl;
                            cout << "| " << setw(10) << "Account Balance Details "<< setw(21) << "|" << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "| " << setw(18) << "Customer Name: " << setw(25) << username << " |" << endl;
                            cout << "| " << setw(18) << "Branch Code: " << setw(25) << branchCode << " |" << endl;
                            cout << "| " << setw(18) << "Opened Date: " << setw(25) << openDate << " |" << endl;
                            cout << "| " << setw(18) << "Bank Account: " << setw(25) << AccNo[BalanceIndex] << " |" << endl;
                            cout << "| " << setw(17) << " Opening Balance: " << setw(25) << OpenBalance[BalanceIndex] << " |" << endl;
                            cout << "| " << setw(45) << " |" << endl;
                            cout << "-----------------------------------------------" << endl;
                            exit(EXIT_FAILURE);
                        }///end of Balance details option

                        case 4: /// Full transaction history
                        {
                             int TransactionIndex = -1;

                            for (int i = 0; i < 4; i++)
                            {
                                if (AccNo[i] == choice)
                                {
                                    TransactionIndex = i;
                                    break;
                                }
                            }

                            if (TransactionIndex == -1)
                            {
                                cout << "| " << setw(27) << "Account not found!" << setw(18) << "|" << endl;
                                exit(EXIT_FAILURE);
                            }

                            /// Get account details
                            string username = accountInstance.set_Username();
                            string branchCode = accountInstance.get_Branch_Code();
                            string openDate = accountInstance.get_Open_Date();
                            float openingBalance = OpenBalance[TransactionIndex];

                            /// Displays account history
                            cout << "| " << setw(45) << " |" << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "| " << setw(45) << " |" << endl;
                            cout << "| " << setw(22) << "Transaction Details " << setw(23) << "|" << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "| " << setw(18) << "Customer Name: " << setw(25) << username << " |" << endl;
                            cout << "| " << setw(18) << "Bank Account: " << setw(25) << AccNo[TransactionIndex] << " |" << endl;
                            cout << "| " << setw(18) << "Branch Code: " << setw(25) << branchCode << " |" << endl;
                            cout << "| " << setw(18) << "Opened Date: " << setw(25) << openDate << " |" << endl;
                            cout << "-----------------------------------------------" << endl;

                            /// Displays transaction table headers
                            cout << "| " << "Date" << setw(13) << "| Balance" << setw(13) << "| Deposit" << setw(13) << "| Withdrawal" << " |" << endl;
                            cout << "-----------------------------------------------" << endl;

                            /// Display all transactions
                            for (int i = 0; i < 4; i++)
                            {
                                 if (AccNo[i] == choice)
                                {
                                    cout << "| " << dateCreated[i] << setw(4) << "| " << OpenBalance[i] << setw(10) << "| " << Deposit[i] << setw(7) << "| " << Withdraw[i] << setw(9) <<" |" << endl;
                                }
                            }

                            cout << "-----------------------------------------------" << endl;
                            exit(EXIT_FAILURE);
                        }

                        case 5:
                        {
                            exit(0);
                            break;
                        }

                        default: /// Return invalid response
                        {
                            cout << "| " << setw(22) << "Invalid Option!" << setw(23) << "|" << endl;
                            cout << "| " << setw(45) << "|" << endl;
                            exit(EXIT_FAILURE);
                        }
                    }/// customer transaction end menu
            } /// customer option end

            case 's':
            {
                cout << "-----------------------------------------------" << endl;
                cout << "| " << setw(45) << " |" << endl;
                cout << "| " << setw(15) << "Staff Accounts Management Menu" << setw(15) << "|" << endl;
                cout << "-----------------------------------------------" << endl;
                cout << "| " << setw(25) << "Create Account 1*" << setw(20) << "|" << endl;
                cout << "| " << setw(25) << "Accounts Transactions 2*" << setw(20) << "|" << endl;
                cout << "| " << setw(25) << "View Bank Report 3*" << setw(20) << "|" << endl;
                cout << "| " << setw(25) << " Exit 4*" << setw(20) << "|" << endl;
                cout << "| " << setw(25) << " Enter your option: ";
                cin >> CurrentOption;

                    switch (CurrentOption)
                    {
                        case 1: /// Create account option
                        {

                            int accountTypeChoice;
                            cout << "| " << setw(45) << " |" << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "| " << setw(45) << " |" << endl;
                            cout << "| " << setw(25) << "Choose Account Type" << setw(20) << "|" << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "| " << setw(27) << "Current Account 1*" << setw(18) << "|" << endl;
                            cout << "| " << setw(27) << "Savings Account 2*" << setw(18) << "|" << endl;
                            cout << "| " << setw(27) << "Enter your choice: ";
                                cin >> accountTypeChoice;

                                if (accountTypeChoice == 1)
                                {
                                    Current_Acc newCurrentAccount;
                                    string username = newCurrentAccount.set_Username();
                                    cout << "| " << setw(45) << " |" << endl;
                                    cout << "| " << setw(27) <<"Account Created successfully" << setw(17) << "|" << endl;
                                    system("PAUSE");
                                    cout << "-----------------------------------------------" << endl;
                                    Current_Acc display_Basic_Acc(int AccNo[], int OpenBalance[], int size);
                                    break;
                                }
                                else if (accountTypeChoice == 2)
                                {
                                    Savings_Acc newSavingsAccount;
                                    string username = newSavingsAccount.set_Username();
                                    cout << "| " << setw(45) << " |" << endl;
                                    cout << "| " << setw(27)<< "Account Created successfully" << setw(17) << "|" << endl;
                                    system("PAUSE");
                                    cout << "-----------------------------------------------" << endl;
                                    Savings_Acc display_Basic_Acc(int AccNo[], int OpenBalance[], int size);
                                    break;
                                }
                                else
                                {
                                    cout << "| " << setw(22) << "Invalid Account Type!" << setw(23) << "|" << endl;
                                }
                            break;
                        } /// end of create account option

                        case 2:
                        {
                             /// Displays transaction table headers
                            cout << "-----------------------------------------------" << endl;
                            cout << "| " << setw(45) << " |" << endl;
                            cout << "| " << setw(10) << " Customer Transaction Accounts" << setw(15) << "|" << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "| " << "Account" << setw(11) << "| Balance" << setw(8) << " | Deposit" << setw(13) << "| Withdrawal" << setw(4) << " |" << endl;
                            cout << "-----------------------------------------------" << endl;

                            for (int i = 0; i < 4; ++i)
                            {
                                cout << "| " << AccNo[i] << setw(3) << " | "
                                    << setw(3) << OpenBalance[i] << setw(7) << " | "
                                     << setw(3) << Deposit[i] << setw(7) << " | "
                                     << setw(3) << Withdraw[i] << setw(11) << " |" << endl;
                            }
                            cout << "-----------------------------------------------" << endl;
                            exit(EXIT_FAILURE);
                        }

                        case 3:
                        {
                            cout << "| " << setw(45) << "|" << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "| " << setw(45) << "|" << endl;
                            cout << "| " << setw(22) << "Customers A/C Bank Report" << setw(23) << "|" << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "| " << setw(19) << "Account numbers" << " | " << setw(13) << "Balance" << setw(10) << "|" << endl;
                            cout << "-----------------------------------------------" << endl;
                            for (int i = 0; i < 4; ++i)
                            {
                                cout << "| " << setw(13) << AccNo[i] << setw(9) <<" | "
                                     << setw(13) << OpenBalance[i] << setw(10) << " |" << endl;
                            }

                            cout << "-----------------------------------------------" << endl;
                            break;
                        }

                        case 4:
                        {
                            exit(0);
                            break;
                        }

                        default: /// Return invalid response
                        {
                            cout << "| " << setw(22) << "Invalid Option!" << setw(23) << "|" << endl;
                            cout << "| " << setw(45) << "|" << endl;
                            break;
                        }

                    } /// end of staff options menu
            }/// staff option end

            case 'e': /// Exit the staff and customer menu
            {
                exit(0);
                break;
            }

            default: /// Return invalid response
            {
                cout << "| " << setw(22) << "Invalid Option!" << setw(23) << "|" << endl;
                cout << "| " << setw(45) << "|" << endl;
                break;
            }
        }
    return 0;
    system("PAUSE");
}
