#include <iostream>
#include <iomanip>
#include <limits>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <string>
using namespace std;

class Bank_Users
{
public:
    /// Constractors for customer object
    Bank_Users(int Customer_ID, int PAC, string DOB); /// 99999999 99881
    Bank_Users(int Customer_ID, int PAC); /// 12345678 98887
    /// Constractors for customer object
    Bank_Users(string Employee_Level, int Employee_ID, string PassWord); /// manager 1234 pass: 1x, trainee 2334 pass:2x

    /// Methods to access the class
    /// Validates customer users
    bool test_PAC(int PAC_no1, int input_PAC1);
    bool test_Employee_ID(int Employee);
    /// Validates staff users
    bool Validate_User();
    bool Validate_Customer();
    static int getLoginAttemptsS(){return a;} /// Staff
    static int getLoginAttemptsC(){return b;} /// Customer

    /// To ignore any character not valid edited by the user
    int getValidIntegerInput(const string& prompt);
    string getValidStringInput(const string& prompt);

     /// To create a line
     void formatLine()
    {
        cout << "|" << setw(45) << "|" << endl;
        cout << "|";
        for(int i = 0; i < 44; i++)
        {
            cout << "-";
        }
        cout << "|" << endl;
    }

private:
    /// Member variables
    int dm_PAC;
    int dm_User_ID;
    int dm_input_PAC;
    string dm_DOB;
    string dm_Level, dm_Password, dm_Password_Input;
    int dm_Employee_ID;
    /// Data entry variable for staff user
    static int a;
    static int b;
    /// Stores Bank account numbers in dynamic arrays
};



/// Initialising static member to 0 for login count
int Bank_Users::a = 0;
int Bank_Users::b = 0;


/// Method to handle the errors for interger input
int Bank_Users::getValidIntegerInput(const string& prompt)
{
    int input;
    while (true)
    {
        cout << prompt;
        if (cin >> input)
        {
            break;
        }
        else
        {
            cout << "| Invalid input! Please enter a valid number." << endl;
            cout << "|" << setw(45) << "|" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return input;
}

/// Method to handle the errors for string input
string Bank_Users::getValidStringInput(const string& prompt)
{
    string input;
    while (true)
    {
        cout << prompt;
        if (cin >> input)
        {
            break;
        }
        else
        {
            cout << "| Invalid input. Please enter a valid alphabet." << endl;
            cout << "|" << setw(45) << "|" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return input;
}


/// Member function definitions
Bank_Users::Bank_Users(string Employee_Level, int Employee_ID, string Password)
{
    dm_Level = Employee_Level;
    dm_Employee_ID = Employee_ID;
    dm_Password = Password;
}


bool Bank_Users::Validate_User()
{
    cout << "---------------------------------------------" << endl;
    cout << "|" << setw(23) << "Login Screen" << setw(22) << "|" << endl;
    cout << "|" << setw(45) << "|" << endl;
    cout << "---------------------------------------------" << endl;
    system("PAUSE");

    int maxAttempts = 3;

    if (this->dm_Level == "Manager" || this->dm_Level == "Trainee")
    {
        maxAttempts = 3; /// for staff
    }
    else
    {
        maxAttempts = 3; /// for customer
    }

    /// Track login attempts
    int loginAttempts = 0;

    while (loginAttempts < maxAttempts)
    {
         int user_input = this->getValidIntegerInput("| Key in user no (1234 or 2334): ");

        cout << "|" << setw(45) << "|" << endl;
        cout << "| " << "You have three attempts to log on..." << setw(8) << "|" << endl;
        cout << "| Key in password " << endl;
        cout << "| (Password.1x or Password.2x): ";
        /// Hide the password
            char c = ' ';
            dm_Password_Input = "";

            while(c != 13)
            {
                c = getch();

                if(c != 13)
                {
                    dm_Password_Input += c;
                    cout << "*";
                }
            }
        cout << endl;
        cout << "|" << setw(45) << "|" << endl;
        /// Check if the user input and password input match the stored values
        if(this->test_Employee_ID(user_input) && dm_Password_Input == dm_Password)
        {
            cout << "|" << setw(23) << "Valid User." << setw(22) << "|" << endl;
            cout << "---------------------------------------------" << endl;

            /// Reset login attempts for the current user type
            if (this->dm_Level == "Manager" || this->dm_Level == "Trainee")  // Staff
            {
                this->a = 0;
            }
             else  /// Same for customer
            {
                this->b = 0;
            }

            return true;
        }
        else
        {
            cout << "|" << setw(22) << "Invalid User!" << setw(23) << "|" << endl;
            cout << "---------------------------------------------" << endl;

            loginAttempts++;

            if (loginAttempts >= maxAttempts)
            {
                cout << "| " << setw(22) << "Goodbye." << setw(22) << "|" << endl;
                cout << "---------------------------------------------" << endl;
                return false;
            }
        }
    }
    return false;
}


bool Bank_Users::Validate_Customer()
{
    this->formatLine();
    cout << "|" << setw(23) << "Customer Login" << setw(22) << "|" << endl;
    cout << "|" << setw(45) << "|" << endl;

    int maxAttempts = 3;
    int loginAttempts = 0;

    while (loginAttempts < maxAttempts)
    {
        cout << "| " << setw(23) << "Key in your 8 digits User ID " << setw(15) << "|"  << endl;
        int userId = this->getValidIntegerInput("| Enter your ID(12345678): ");
        cout << "| " << setw(23) << "Enter DOB DD-MM-Y (01021999): ";
            cin >> dm_DOB;
        cout << "| " << setw(23) << "Enter 3 random requested digits" << setw(13) << "|" << endl;
        cout << "| " << setw(23) << "of your five digits." << setw(21) << "|" << endl;
        cout << "| " << setw(23) << "Enter first number(98887): ";

            int userPac1 = this->getValidIntegerInput("");
            int userPac2, userPac3;
            int pac1, pac2, pac3;

            pac1 = 1 + (rand() % 5);
            pac2 = 1 + (rand() % 5);
            pac3 = 1 + (rand() % 5);

            while (pac2 == pac1)
            {
                pac2 = 1 + (rand() % 5);
            }

            while (pac3 == pac1 || pac3 == pac2)
            {
                pac3 = 1 + (rand() % 5);
            }

            cout << "|" << setw(23) << "Enter PAC " << setw(2) << pac1 << setw(3) << ":";
            pac1 = this->getValidIntegerInput("");
            cout << "|" << setw(23) << "Enter PAC " << setw(2) << pac2 << setw(3) << ":";
            pac2 = this->getValidIntegerInput("");
            cout << "|" << setw(23) << "Enter PAC " << setw(2) << pac3 << setw(3) << ":";
            pac3 = this->getValidIntegerInput("");

            if(this->test_PAC(1, userPac1) &&
                this->test_PAC(pac1, userPac2) &&
                this->test_PAC(pac2, userPac3))
            {
                cout << "|" << setw(45) << "|" << endl;
                cout << "|" << setw(23) << "Valid User." << setw(22) << "|" << endl;
                cout << "---------------------------------------------" << endl;
                return true;
            }
            else
            {
                cout << "|" << setw(45) << "|" << endl;
                cout << "|" << setw(23) << "Invalid login details!" << setw(22) << "|" << endl;
                cout << "---------------------------------------------" << endl;
                loginAttempts++;

                if (loginAttempts >= maxAttempts)
                {
                    cout << "|" << setw(45) << "|" << endl;
                    cout << "| " << setw(22) << "Goodbye." << setw(22) << "|" << endl;
                    return false;
                }
            }
    }
    return false;
}




Bank_Users::Bank_Users(int User_ID, int PAC, string DOB)
{
    dm_User_ID = User_ID;
    dm_PAC = PAC;
    dm_DOB = DOB;
}


bool Bank_Users::test_Employee_ID(int Employee)
{
    dm_Employee_ID = Employee;

    if(Employee == 1234 || Employee == 2334)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool Bank_Users::test_PAC(int PAC_no, int input_PAC)
{
    dm_PAC = PAC_no;
    dm_input_PAC = input_PAC;
    if((dm_PAC == 1 && dm_input_PAC != 9)||(dm_PAC == 2 && dm_input_PAC != 8)||
       (dm_PAC == 3 && dm_input_PAC != 8)||(dm_PAC == 4 && dm_input_PAC != 8)||
       (dm_PAC == 5 && dm_input_PAC != 7))
    {
        return false;
    }
     else
    {
        return true;
    }
}




bool staffLogin = false;
bool customerLogin;



int main2()
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
            return 0;
    }
}
