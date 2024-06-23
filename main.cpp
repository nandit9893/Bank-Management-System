#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
#include<fstream>
#include<set>
#include<windows.h>
#include<mysql.h>
#include<iomanip>
using namespace std;
struct DOB
    {
        int date;
        int month;
        int year;
    };


int main();

class Validation
{
public:
    string validateString(const string &prompt)
    {
        string input;
        cout<<prompt<<" : ";
        getline(cin >> ws, input);
        if(isValidInput(input))
        {
            return input;
        }
        else
        {
            cout<<"Enter name again, only characters are allowed. ";
            return validateString(prompt);
        }
    }
    bool isValidInput(const string &input)
    {
        for(char c : input)
        {
            if(!isalpha(c) && c!=' ')
            {
                return false;
            }
        }
        return true;
    }
    string validateEmail(const string &prompt)
    {
        string email;
        cout<<prompt<<" : ";
        cin>>email;
        if(isValidEmail(email))
        {
            return email;
        }
        else
        {
            cout<<"Enter email again no special characters are allowed except @."<<endl;
            return validateEmail(prompt);
        }
    }
    bool isValidEmail(const string &email)
    {
        size_t atPos = email.find("@");
        if(atPos==string::npos || email.substr(atPos)!="@gmail.com")
        {
            return false;
        }
        for(size_t i = 0;i<atPos;++i)
        {
            if(!isalnum(email[i]))
            {
                return false;
            }
        }
        return true;
    }
    long long int validatePhoneNumber(const string &prompt)
    {
        long long int phone;
        cout<<prompt<<" : ";
        cin>>phone;
        if(isValidPhoneNumber(phone))
        {
            return phone;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout<<"Enter phone number again no special characters are allowed."<<endl;
            return validatePhoneNumber(prompt);
        }
    }
    bool isValidPhoneNumber(long long int phone)
    {
        string inputStr = to_string(phone);
        return inputStr.length() == 10 && all_of(inputStr.begin(), inputStr.end(), [](char c)
        {
            return isdigit(c);
        });
    }
    string validatePassword(const string &prompt)
    {
        string password;
        cout<<prompt<<" : ";
        cin>>password;
        if(isValidPassword(password))
        {
            return password;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Enter password again with more than 8 characters including digits, alphabets, special, characters."<<endl;
            return validatePassword(prompt);
        }
    }
    bool isValidPassword(const string &password)
    {
        bool hasAlpha = false;
        bool hasDigit = false;
        bool hasSpecial = false;
        for(char c : password)
        {
            if(isalpha(c))
                hasAlpha = true;
            if(isdigit(c))
                hasDigit = true;
            if(!isalnum(c))
                hasSpecial = true;
        }
        return hasAlpha && hasDigit && hasSpecial && password.length() > 8;
    }
    DOB validateDOB(const string &prompt)
    {
        DOB dob;
        string dateOfBirth;
        cout<<"[YYYYMMDD]"<<prompt<<" : ";
        cin>>dateOfBirth;
        if(isValidDOB(dateOfBirth, dob))
        {
            return dob;
        }
        else
        {
            cout<<"Enter DOB again, invalid format."<<endl;
            return validateDOB(prompt);
        }
    }
    bool isValidDOB(const string &dateOfBirth, DOB &dob)
    {
        if(dateOfBirth.length()!=8)
        {
            return false;
        }
        int year = stoi(dateOfBirth.substr(0, 4));
        int month = stoi(dateOfBirth.substr(4, 2));
        int day = stoi(dateOfBirth.substr(6, 2));
        if(day<1 || day>31 || month<1 ||month>12 || year<1980 || year>2030)
        {
            return false;
        }
        dob.date = day;
        dob.month = month;
        dob.year = year;
        return true;
    }
    long long int validateAdharCard(const string &prompt)
    {
        long long int adharNo;
        cout<<prompt<<" : ";
        cin>>adharNo;
        string adharCard = to_string(adharNo);
        if(isValidAdharCard(adharCard))
        {
            return adharNo;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Invalid format, enter again. "<<endl;
            return validateAdharCard(prompt);
        }
    }
    bool isValidAdharCard(const string &adharCard)
    {
        if(adharCard.length()!=12)
        {
            return false;
        }
        for(char c : adharCard)
        {
            if(!isdigit(c))
            {
                return false;
            }
        }
        return true;
    }
    long long int validatePinCode(const string &prompt)
    {
        long long int pinCode;
        cout<<prompt<<" : ";
        cin>>pinCode;
        if(isValidPinCode(pinCode))
        {
            return pinCode;
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Invalid pin code, enter again."<<endl;
            return validatePinCode(prompt);
        }
    }
    bool isValidPinCode(long long int pinCode)
    {
        string pinStr = to_string(pinCode);
        if(pinStr.length()==6)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string validateAddress(const string &prompt)
    {
        string address;
        cout<<prompt<<" : ";
        getline(cin, address);
        if(isValidAddress(address))
        {
            return address;
        }
        else
        {
            cout<<"Enter valid address, invalid format."<<endl;
            return validateAddress(prompt);
        }
    }
    bool isValidAddress(const string &address)
    {
        for(char c : address)
        {
            if((!isalnum(c)) && c!=' ' && c!=',' && c!='-')
            {
                return false;
            }
        }
        return true;
    }
    long int validateAge(const string &prompt)
    {
        long int age;
        cout<<prompt<<" : ";
        cin>>age;
        if(isValidAge(age))
        {
            return age;
        }
        else
        {
            cout<<"Age should be a number and 5 or older. "<<endl;
            return validateAge(prompt);
        }
    }
    bool isValidAge(long int age)
    {
        if(age<5)
        {
            return false;
        }
        string ageStr = to_string(age);
        for(char c : ageStr)
        {
            if(!isdigit(c))
            {
                return false;
            }
        }
        return true;
    }
    long long int createAccountNumber(long long int phoneNo, DOB dob, long long int adharCard, long long int pinCode)
    {
        string phnStr = to_string(phoneNo);
        string dobStr = to_string(dob.date)+to_string(dob.month)+to_string(dob.year);
        string adharCardStr = to_string(adharCard);
        string pinCodeStr = to_string(pinCode);

        string accountNo = phnStr.substr(0, 2)+dobStr.substr(0,1)+adharCardStr.substr(0,3)+pinCodeStr.substr(0,1)+phnStr.substr(4,1)+adharCardStr.substr(10,1)+phnStr.substr(9,1)+dobStr.substr(4,1)+pinCodeStr.substr(5,1);

        long long int accountNumber = stoll(accountNo);
        return accountNumber;
    }
    string validateGender(const string &prompt)
    {
        string input;
        cout<<"[M/F/T] "<<prompt<<" : ";
        cin.ignore();
        getline(cin, input);
        if(isValidGender(input))
        {
            return input;
        }
        else
        {
            cout<<"Enter again, invalid format M for Male/F for Female/T for Transgender. "<<endl;
            return validateGender(prompt);
        }
    }
    bool isValidGender(const string &gender)
    {
        if(gender.length()!=1)
        {
            return false;
        }
        char c = gender[0];
        if(c=='M' || c=='F' || c=='T')
        {
            return true;
        }
        return false;
    }
    string validatePanCard(const string &prompt)
    {
        string input;
        cout<<prompt<<" : ";
        getline(cin>>ws, input);
        if(isValidPanCard(input))
        {
            return input;
        }
        else
        {
            cout<<"Invalid PanCard number, enter again."<<endl;
            return validatePanCard(prompt);
        }
    }
    bool isValidPanCard(const string &panCard)
    {
        int length = panCard.length();
        if(length!=10)
        {
            return false;
        }
        for(int i=0;i<5;i++)
        {
            if(!isalpha(panCard[i]))
            {
                return false;
            }
        }
        for(int i =5;i<9;i++)
        {
            if(!isdigit(panCard[i]))
            {
                return false;
            }
        }
        if(!isalpha(panCard[9]))
        {
            return false;
        }
        return true;
    }
    string createEmpId(long long int phoneNo, long long int adharCard, const string &panCard)
    {
        string phnStr = to_string(phoneNo);
        string adharCardStr = to_string(adharCard);

        string empID = panCard.substr(0, 2)+phnStr.substr(0, 2)+adharCardStr.substr(0,3)+phnStr.substr(4,1)+adharCardStr.substr(10,1)+phnStr.substr(9,1);
        return empID;
    }

};


class MenuAdmin
{
private:
    int makeYourChoice()
    {
        cout<<endl;
        int choice;
        cout<<"1. Update EmailID : "<<endl;
        cout<<"2. Update Phone Number : "<<endl;
        cout<<"3. Leave Permission : [Apply before two days on the commitment of holidays]"<<endl;
        cout<<"4. Quit Job : "<<endl;
        cout<<"5. Log out : "<<endl;
        cout<<"   Enter your choice : ";
        cin>>choice;
        return choice;
    }
    void updateEmailID(MYSQL *conn, string input)
    {
        Validation check;
        cout<<endl;
        string newEmail = check.validateEmail("Email");
        string query = "UPDATE AdminInformation SET EmailID = " + newEmail + " WHERE EmpID = '" + input + "'";
        const char *q = query.c_str();
        if(mysql_query(conn, q)==0)
        {
            MYSQL_RES *res = mysql_store_result(conn);
            if(res)
            {
                if(mysql_num_rows(res)>0)
                {
                    mysql_free_result(res);
                    cout<<"EmailId updated successfully. "<<endl;
                }
            }
        }
        else
        {
            cout<<"Query error "<<mysql_error(conn)<<endl;
        }
    }
    void updateMobileNumber(MYSQL *conn, string input)
    {
        Validation check;
        cout<<endl;
        long long int newPhoneNo = check.validatePhoneNumber("Phone No");
        string query = "UPDATE AdminInformation SET PhoneNo = " + to_string(newPhoneNo) + " WHERE EmpID = '" + input + "'";
        const char *q = query.c_str();
        if(mysql_query(conn, q)==0)
        {
            MYSQL_RES *res = mysql_store_result(conn);
            if(res)
            {
                if(mysql_num_rows(res)>0)
                {
                    mysql_free_result(res);
                    cout<<"Phone no updated successfully. "<<endl;
                }
            }
        }
        else
        {
            cout<<"Query error "<<mysql_error(conn)<<endl;
        }
    }
    void quitJob(MYSQL *conn, string input)
    {
        cout<<endl;
        string query = "DELETE * FROM AdminInformation WHERE EmpID = '" + input + "'";
        const char *q = query.c_str();
        if(mysql_query(conn, q)==0)
        {
            MYSQL_RES *res = mysql_store_result(conn);
            if(res)
            {
                if(mysql_num_rows(res)>0)
                {
                    mysql_free_result(res);
                    cout<<"Thank you for serving us we are feeling very nostalgic. You have done tremendous work for us. You will be remembered in our organization. Best wishes for your future ."<<endl;
                }
            }
        }
        else
        {
            cout<<"Query error "<<mysql_error(conn)<<endl;
        }
    }
    void leavePermission(MYSQL *conn, string input)
    {
        int leaveDays;
        string email;
        cout<<"How many days leave you want? : ";
        cin>>leaveDays;
        cout<<"Enter your email : ";
        cin>>email;
        string query = "UPDATE AdminInformation SET LeaveDays = " + to_string(leaveDays) + " WHERE EmpID = '" + input + "'";
        if(mysql_query(conn, query.c_str())==0)
        {
            MYSQL_RES *res = mysql_store_result(conn);
            if(res)
            {
                if(mysql_num_rows(res)>0)
                {
                    mysql_free_result(res);
                    cout<<"Your application for leave will be in consideration and you will get notified on your email. "<<endl;
                }
            }
        }
        else
        {
            cout<<"Query error "<<mysql_error(conn)<<endl;
        }
    }
public:
    void userEnquiry(string input)
    {
        MYSQL *conn;
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "localhost", "root", "Nandit@9893", "bank_management", 3306, NULL, 0);
        if(conn)
        {
            string query = "SELECT Name FROM AdminInformation WHERE EmpID = " + input;
            const char *q = query.c_str();
            if(mysql_query(conn, q)==0)
            {
                MYSQL_RES *res = mysql_store_result(conn);
                if(res)
                {
                    if(mysql_num_rows(res)>0)
                    {
                        MYSQL_ROW row = mysql_fetch_row(res);
                        string name = row[0];
                        cout<<endl;
                        mysql_free_result(res);
                        cout<<"Welcome "<<name<<" to Nandit Bank"<<endl;
                    }
                }
           }
        }
        else
        {
            cout<<"Server error"<<endl;
        }
    }
    void adminChoice(string input, MYSQL *conn)
    {
        int choice = makeYourChoice();
        switch(choice)
        {
            case 1:
                {
                    updateEmailID(conn, input);
                    adminChoice(input, conn);
                }
                break;
            case 2:
                {
                    updateMobileNumber(conn, input);
                    adminChoice(input, conn);
                }
                break;
            case 3:
                {
                    leavePermission(conn, input);
                    adminChoice(input, conn);
                }
                break;
            case 4:
                {
                    quitJob(conn, input);
                    adminChoice(input, conn);
                }
                break;
            case 5:
                {
                    main();
                }
                break;
            default:
                {
                    cout<<"Invalid choice "<<endl;
                    adminChoice(input, conn);
                }
        }
    }
};





class MenuUser
{
private:
    int makeYourChoice()
    {
        cout<<endl;
        int choice;
        cout<<"1. Check Balance "<<endl;
        cout<<"2. Deposit Money "<<endl;
        cout<<"3. Withdraw Money "<<endl;
        cout<<"4. Update Mobile Number "<<endl;
        cout<<"5. Update Email ID "<<endl;
        cout<<"6. Log out "<<endl;
        cout<<"   Enter your choice : ";
        cin>>choice;
        return choice;
    }
    void checkBalance(MYSQL *conn, long long int input)
    {
        cout<<endl;
        string query = "SELECT Balance FROM UserEnquiry WHERE AadharCard = " + to_string(input) + " OR AccountNo = " + to_string(input);
        const char *q = query.c_str();
        if(mysql_query(conn, q)==0)
        {
            MYSQL_RES *res = mysql_store_result(conn);
            if(res)
            {
                if(mysql_num_rows(res)>0)
                {
                    MYSQL_ROW row = mysql_fetch_row(res);
                    string balance = row[0];
                    mysql_free_result(res);
                    cout<<"Your balance : "<<balance<<endl;
                }
            }
        }
    }
    void depositMoney(MYSQL *conn, long long int input)
    {
        cout<<endl;
        cout<<"Enter the amount you want to deposit : ";
        long long int deposit;
        cin>>deposit;
        string query = "SELECT Balance FROM UserEnquiry WHERE AadharCard = '" + to_string(input) + "' OR AccountNo = '" + to_string(input) + "'";
        const char *q = query.c_str();
        if(mysql_query(conn, q)==0)
        {
            MYSQL_RES *res = mysql_store_result(conn);
            if(res)
            {
                if(mysql_num_rows(res)>0)
                {
                    MYSQL_ROW row = mysql_fetch_row(res);
                    string balance = row[0];
                    long long int balanceInt = stoll(balance);
                    long long int newBalance = balanceInt + deposit;

                    string query1 = "UPDATE UserInformation SET Balance = " + to_string(newBalance) + " WHERE AadharCard = '" + to_string(input) + "' OR AccountNo = '" + to_string(input) + "'";
                    const char *q1 = query1.c_str();
                    if(mysql_query(conn, q1)!=0)
                    {
                        cout<<"Error updating UserInformation table"<<mysql_error(conn)<<endl;
                    }

                    string query2 = "UPDATE UserEnquiry SET Balance = " + to_string(newBalance) + " WHERE AadharCard = '" + to_string(input) + "' OR AccountNo = '" + to_string(input) + "'";
                    const char *q2 = query2.c_str();
                    if(mysql_query(conn, q2)!=0)
                    {
                        cout<<"Error updating UserEnquiry table"<<mysql_error(conn)<<endl;
                    }
                    cout<<"Money deposited successfully and New Balance : "<<newBalance<<endl;
                    mysql_free_result(res);
                }
            }
        }
        else
        {
            cout<<"Query error "<<mysql_error(conn)<<endl;
        }
    }
    void withdrawMoney(MYSQL *conn, long long int input)
    {
        cout<<endl;
        cout<<"Enter the amount you want to withdraw : ";
        long long int withdraw;
        cin>>withdraw;
        string query = "SELECT Balance FROM UserEnquiry WHERE AadharCard = '" + to_string(input) + "' OR AccountNo = '" + to_string(input) + "'";
        const char *q = query.c_str();
        if(mysql_query(conn, q)==0)
        {
            MYSQL_RES *res = mysql_store_result(conn);
            if(res)
            {
                if(mysql_num_rows(res)>0)
                {
                    MYSQL_ROW row = mysql_fetch_row(res);
                    string balance = row[0];
                    long long int balanceInt = stoll(balance);
                    long long int newBalance = balanceInt - withdraw;

                    string query1 = "UPDATE UserInformation SET Balance = " + to_string(newBalance) + " WHERE AadharCard = '" + to_string(input) + "' OR AccountNo = '" + to_string(input) + "'";
                    const char *q1 = query1.c_str();
                    if(mysql_query(conn, q1)!=0)
                    {
                        cout<<"Error updating UserInformation table"<<mysql_error(conn)<<endl;
                    }

                    string query2 = "UPDATE UserEnquiry SET Balance = " + to_string(newBalance) + " WHERE AadharCard = '" + to_string(input) + "' OR AccountNo = '" + to_string(input) + "'";
                    const char *q2 = query2.c_str();
                    if(mysql_query(conn, q2)!=0)
                    {
                        cout<<"Error updating UserEnquiry table"<<mysql_error(conn)<<endl;
                    }
                    cout<<"Money withdraw successfully and New Balance : "<<newBalance<<endl;
                    mysql_free_result(res);
                }
            }
        }
        else
        {
            cout<<"Query error "<<mysql_error(conn)<<endl;
        }
    }
    void updateMobileNumber(MYSQL *conn, long long int input)
    {
        Validation check;
        cout<<endl;
        long long int newPhoneNo = check.validatePhoneNumber("Phone No");
        string query = "UPDATE UserInformation SET PhoneNo = " + to_string(newPhoneNo) + " WHERE AadharCard = '" + to_string(input) + "' OR AccountNo = '" + to_string(input) + "'";
        const char *q = query.c_str();
        if(mysql_query(conn, q)==0)
        {
            MYSQL_RES *res = mysql_store_result(conn);
            if(res)
            {
                if(mysql_num_rows(res)>0)
                {
                    mysql_free_result(res);
                    cout<<"Phone no updated successfully. "<<endl;
                }
            }
        }
        else
        {
            cout<<"Query error "<<mysql_error(conn)<<endl;
        }
    }
    void updateEmailID(MYSQL *conn, long long int input)
    {
        Validation check;
        cout<<endl;
        string newEmail = check.validateEmail("Email");
        string query = "UPDATE UserInformation SET EmailID = " + newEmail + " WHERE AadharCard = '" + to_string(input) + "' OR AccountNo = '" + to_string(input) + "'";
        const char *q = query.c_str();
        if(mysql_query(conn, q)==0)
        {
            MYSQL_RES *res = mysql_store_result(conn);
            if(res)
            {
                if(mysql_num_rows(res)>0)
                {
                    mysql_free_result(res);
                    cout<<"EmailId updated successfully. "<<endl;
                }
            }
        }
        else
        {
            cout<<"Query error "<<mysql_error(conn)<<endl;
        }
    }
public:
    void userEnquiry(long long int input)
    {
        MYSQL *conn;
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "localhost", "root", "Nandit@9893", "bank_management", 3306, NULL, 0);
        if(conn)
        {
            string query = "SELECT Name FROM UserEnquiry WHERE EmpID = " + to_string(input);
            const char *q = query.c_str();
            if(mysql_query(conn, q)==0)
            {
                MYSQL_RES *res = mysql_store_result(conn);
                if(res)
                {
                    if(mysql_num_rows(res)>0)
                    {
                        MYSQL_ROW row = mysql_fetch_row(res);
                        string name = row[0];
                        cout<<endl;
                        mysql_free_result(res);
                        cout<<"Welcome "<<name<<" to Nandit Bank"<<endl;
                    }
                }
           }
        }
        else
        {
            cout<<"Server error"<<endl;
        }
    }
    void choice(long long int input, MYSQL *conn)
    {
        int getChoice = makeYourChoice();
        switch(getChoice)
        {
            case 1:
                {
                    checkBalance(conn, input);
                    choice(input, conn);
                }
                break;
            case 2:
                {
                    depositMoney(conn, input);
                    choice(input, conn);
                }
                break;
            case 3:
                {
                    withdrawMoney(conn, input);
                    choice(input, conn);
                }
                break;
            case 4:
                {
                    updateMobileNumber(conn, input);
                    choice(input, conn);
                }
                break;
            case 5:
                {
                    updateEmailID(conn, input);
                    choice(input, conn);
                }
                break;
            case 6:
                {
                    main();
                }
            default:
                {
                    cout<<"Invalid choice "<<endl;
                    choice(input, conn);
                }
                break;
        }
    }
};


class LogIn
{
public:
    string validateUserNamePassword(MYSQL *conn, const string &prompt, const string &tableName)
    {
        cout<<prompt<<" : "<<endl;
        string input;
        cout<<"Enter Account No./Aadhar Card : ";
        cin>>input;
        string query = "select Password from " + tableName + " where AccountNo = " + input + " or AadharCard = " + input;
        const char *q = query.c_str();
        if(mysql_query(conn, q)==0)
        {
            MYSQL_RES *res = mysql_store_result(conn);
            if(res)
            {
                if(mysql_num_rows(res)>0)
                {
                    MYSQL_ROW row = mysql_fetch_row(res);
                    string storedPassword = row[0];
                    string password;
                    cout<<"Enter Password : ";
                    cin>>password;
                    if(storedPassword==password)
                    {
                        cout<<"Login Successfull!"<<endl;
                        mysql_free_result(res);
                    }
                    else
                    {
                        cout<<"Incorrect Password."<<endl;
                        mysql_free_result(res);
                        validateUserNamePassword(conn, prompt, tableName);
                    }
                }
                else
                {
                    cout<<"Account No./Aadhar Card not found."<<endl;
                }
            }
            else
            {
                cout<<"Error : "<<mysql_error(conn)<<endl;
            }
        }
        else
        {
             cout << "Query error: " << mysql_error(conn) << endl;
        }
        return input;
    }
    string validateAdminNamePassword(MYSQL *conn, const string &prompt, const string &tableName)
    {
        cout<<prompt<<" : "<<endl;
        string input;
        cout<<"Enter EmpID : ";
        cin>>input;
        string query = "SELECT Password FROM AdminInformation WHERE EmpID = '" + input + "'";
        const char *q = query.c_str();
        if(mysql_query(conn, q)==0)
        {
            MYSQL_RES *res = mysql_store_result(conn);
            if(res)
            {
                if(mysql_num_rows(res)>0)
                {
                    MYSQL_ROW row = mysql_fetch_row(res);
                    string storedPassword = row[0];
                    string password;
                    cout<<"Enter Password : ";
                    cin>>password;
                    if(storedPassword==password)
                    {
                        cout<<"Login Successfull!"<<endl;
                        mysql_free_result(res);
                    }
                    else
                    {
                        cout<<"Incorrect Password."<<endl;
                        mysql_free_result(res);
                        validateAdminNamePassword(conn, prompt, tableName);
                    }
                }
                else
                {
                    cout<<"Account not found."<<endl;
                }
            }
            else
            {
                cout<<"Error : "<<mysql_error(conn)<<endl;
            }
        }
        else
        {
             cout << "Query error: " << mysql_error(conn) << endl;
        }
        return input;
    }
};

class Users
{
private:
    string name, fatherName, motherName, email, occupation, password, postOffice, address, district, state, gender, panCard;
    long long phoneNo, adharCard, pinCode, accountNumber;
    DOB dob;
    double balance;
    long int age;
public:
    void signUp()
    {
        cout << endl;
        Validation check;
        cout << "User Services : " << endl;
        name = check.validateString("Name");
        fatherName = check.validateString("Father's Name");
        motherName = check.validateString("Mother's Name");
        email = check.validateEmail("Email");
        phoneNo = check.validatePhoneNumber("Phone Number.");
        occupation = check.validateString("Occupation");
        password = check.validatePassword("Password");
        dob = check.validateDOB("Date of Birth");
        adharCard = check.validateAdharCard("Aadhar Card Number");
        pinCode = check.validatePinCode("Pin Code");
        postOffice = check.validateString("Post-Office");
        address = check.validateAddress("Address");
        district = check.validateString("District");
        state = check.validateString("State");
        age = check.validateAge("Age");
        gender = check.validateGender("Gender");
        panCard = check.validatePanCard("Pan Card No.");
        accountNumber = check.createAccountNumber(phoneNo, dob, adharCard, pinCode);
        cout<<"Deposit Amount : ";
        cin>>balance;
        MYSQL *conn;
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "localhost", "root", "Nandit@9893", "bank_management", 3306, NULL, 0);
        if(conn)
        {
            string query = "INSERT INTO UserInformation (Name, FathersName, MothersName, EmailID, PhoneNo, Occupation, Password, DateOfBirth, AadharCard, PinCode, PostOffice, Address, District, State, Age, AccountNo, Gender, PanCard, Balance) VALUES ('" +
                           name + "','" + fatherName + "','" + motherName + "','" + email + "','" + to_string(phoneNo) + "','" + occupation + "','" + password + "','" +
                           to_string(dob.year) + "-" + to_string(dob.month) + "-" + to_string(dob.date) + "','" + to_string(adharCard) + "','" + to_string(pinCode) + "','"
                           + postOffice + "','" + address + "','" + district + "','" + state + "','" + to_string(age) + "','" + to_string(accountNumber) + "','" + gender + "','" + panCard + "', '" + to_string(balance) + "')";
            const char *q = query.c_str();

            string queryEnquire = "INSERT INTO UserEnquiry (Name, AccountNo, AadharCard, Balance) VALUES ('" + name + "','" + to_string(accountNumber) + "','" + to_string(adharCard) + "', '" + to_string(balance) + "')";
            const char *qe = queryEnquire.c_str();
            if(mysql_query(conn, q)==0)
            {
                cout<<"Signed up successfully."<<endl;
                cout<<"Your account number : "<<accountNumber<<endl;
                cout<<"Log in for using the services : "<<endl;
                if(mysql_query(conn, qe)==0)
                {
                    cout<<endl;
                }
                else
                {
                   cout<<endl;
                }
            }
            else
            {
                cout << "Error in inserting data: " << mysql_error(conn) << endl;
            }
        }
        else
        {
            cout << "Connection failed. " << endl;
            cout << "Error: " << mysql_error(conn) << endl;
        }
        mysql_close(conn);
        main();
    }
    void logIn()
    {
        MenuUser call;
        LogIn userIn;
        cout<<endl;
        MYSQL *conn;
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "localhost", "root", "Nandit@9893", "bank_management", 3306, NULL, 0);
        if(conn)
        {
            string input = userIn.validateUserNamePassword(conn, "User Services", "UserInformation");
            call.userEnquiry(stoll(input));
            call.choice(stoll(input), conn);
        }
        else
        {
            cout<<"Connection failed. "<<endl;
        }
    }
};
class Administration
{
private:
    string name, fatherName, motherName, email, designation, password, postOffice, address, district, state, gender, panCard, empID;
    long long phoneNo, adharCard, pinCode;
    DOB dob, dateOfJoining;
    long int age;
public:
    void signUp()
    {
        cout<<endl;
        Validation check;
        cout<<"Administration Services : "<<endl;
        name = check.validateString("Name");
        fatherName = check.validateString("Father's Name");
        motherName = check.validateString("Mother's Name");
        email = check.validateEmail("Email");
        phoneNo = check.validatePhoneNumber("Phone Number.");
        designation = check.validateString("Designation");
        password = check.validatePassword("Password");
        dob = check.validateDOB("Date of Birth");
        dateOfJoining = check.validateDOB("Data of Joining");
        adharCard = check.validateAdharCard("Aadhar Card Number");
        pinCode = check.validatePinCode("Pin Code");
        postOffice = check.validateString("Post-Office");
        address = check.validateAddress("Address");
        district = check.validateString("District");
        state = check.validateString("State");
        age = check.validateAge("Age");
        gender = check.validateGender("Gender");
        panCard = check.validatePanCard("Pan Card No.");
        empID = check.createEmpId(phoneNo, adharCard, panCard);

        MYSQL *conn;
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "localhost", "root", "Nandit@9893", "bank_management", 3306, NULL, 0);
        if(conn)
        {
            string query = "INSERT INTO AdminInformation (EmpID, Name, FathersName, MothersName, EmailID, PhoneNo, Designation, Password, DateOfBirth, DateOfJoining, AadharCard, PinCode, PostOffice, Address, District, State, Age, Gender, PanCard) VALUES ('" + empID + "','" +
                           name + "','" + fatherName + "','" + motherName + "','" + email + "','" + to_string(phoneNo) + "','" + designation + "','" + password + "','" +
                           to_string(dob.year) + "-" + to_string(dob.month) + "-" + to_string(dob.date) + "','" + to_string(dateOfJoining.year) + "-" + to_string(dateOfJoining.month) + "-" + to_string(dateOfJoining.date) + "','" + to_string(adharCard) + "','"
                           + to_string(pinCode) + "','" + postOffice + "','" + address + "','" + district + "','" + state + "','" + to_string(age) + "','" + gender + "','" + panCard + "')";

            const char *q = query.c_str();
            if(mysql_query(conn, q)==0)
            {
                cout<<"Signed up successfully."<<endl;
                cout<<"Your EmpID : "<<empID<<endl;
                cout<<"Log in for using the services :"<<endl;
            }
            else
            {
                cout<<"Error in inserting data: "<<mysql_error(conn)<<endl;
            }
        }
        else
        {
            cout << "Connection failed. " << endl;
            cout << "Error: " << mysql_error(conn) << endl;
        }
        mysql_close(conn);
        main();
    }
    void logIn()
    {
        LogIn adminIn;
        MenuAdmin call;
        cout<<endl;
        MYSQL *conn;
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "localhost", "root", "Nandit@9893", "bank_management", 3306, NULL, 0);
        if(conn)
        {
            string input = adminIn.validateAdminNamePassword(conn, "Administration Services", "AdminInformation");
            call.userEnquiry(input);
            call.adminChoice(input, conn);
        }
        else
        {
            cout<<"Connection failed. "<<endl;
        }
    }
};



class Item
{
public:
    int user()
    {
        cout<<endl;
        int choice;
        cout<<"   User Services : "<<endl;
        cout<<"1. Sign up : "<<endl;
        cout<<"2. Log in : "<<endl;
        cout<<"3. Main Menu : "<<endl;
        cout<<"   Enter your choice : ";
        cin>>choice;
        return choice;
    }
    int administration()
    {
        cout<<endl;
        int choice;
        cout<<"   Administration Services : "<<endl;
        cout<<"1. Sign up : "<<endl;
        cout<<"2. Log in : "<<endl;
        cout<<"3. Main Menu : "<<endl;
        cout<<"   Enter your choice : ";
        cin>>choice;
        return choice;
    }
    int menu()
    {
        cout<<endl;
        int choice;
        cout<<"   Banking Services : "<<endl;
        cout<<"1. User Services : "<<endl;
        cout<<"2. Administration Services : "<<endl;
        cout<<"3. Exit : "<<endl;
        cout<<"   Enter your choice : ";
        cin>>choice;
        return choice;
    }
    void centerAlign(const string& text)
    {
        int consoleWidth = 160; // Adjust this based on your console width
        int padding = (consoleWidth - text.length())/2;
        cout<<setw(padding + text.length())<<text<<endl;
    }
};

int main()
{
    Item u_a;
    Users use;
    Administration admin;
    u_a.centerAlign("Welcome to Nandit Bank");
    int choice = u_a.menu();
    switch(choice)
    {
        case 1:
            {
                int userChoice = u_a.user();
                if(userChoice==1)
                {
                    use.signUp();
                }
                else if(userChoice==2)
                {
                    use.logIn();
                }
                else if(userChoice==3)
                {
                    main();
                }
                else
                {
                    cout<<"Invalid choice, choose appropriate option : "<<endl;
                }
            }
            break;
        case 2:
            {
                int adminChoice = u_a.administration();
                if(adminChoice==1)
                {
                    admin.signUp();
                }
                else if(adminChoice==2)
                {
                    admin.logIn();
                }
                else if(adminChoice==3)
                {
                    main();
                }
                else
                {
                    cout<<"Invalid choice, choose appropriate option : "<<endl;
                }
            }
            break;
        case 3:
            {
                exit(0);
            }
            break;
        default:
            {
                cout<<"Invalid choice, entered your choice again or exits : "<<endl;
            }
            break;
    }
    return 0;
}

