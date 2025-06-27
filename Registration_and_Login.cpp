#include<iostream>
#include<fstream>
using namespace std;
class temp 
{
    string userName, Email, password;
    string searchName, searchPass, searchEmail;
    fstream file;
public:
    void login();
    void signUp();  
    void forgot();
} obj;
int main() 
{
    char choice;
    cin.ignore(); 
    cout << "\n1- Login";
    cout << "\n2- SignUp";
    cout << "\n3- Forgot Password";
    cout << "\n4- Exit";
    cout << "\nEnter your choice :: ";
    cin >> choice;
    cin.ignore();  
    switch (choice) 
    {
    case '1':
        obj.login();
        break;
    case '2':
        obj.signUp();  
        break;
    case '3':
        obj.forgot();
        break;
    case '4':
        return 0;
    default:
        cout << "Invalid Selection!";
    }
}
void temp::signUp() 
{
    cout << "\nEnter your username :: ";
    getline(cin, userName);
    cout << "Enter Your Email Address :: ";
    getline(cin, Email);
    cout << "Enter Your Password :: ";
    getline(cin, password);
    file.open("loginData.txt", ios::out | ios::app);
    file << userName << "*" << Email << "*" << password << endl;
    file.close();
}

void temp::login() 
{
    cout << "------------LOGIN-------------" << endl;
    cout << "Enter your User Name :: ";
    getline(cin, searchName);
    cout << "Enter your Password :: ";
    getline(cin, searchPass);

    bool found = false;
    file.open("loginData.txt", ios::in);
    while (getline(file, userName, '*') && getline(file, Email, '*') && getline(file, password)) {
        if (userName == searchName && password == searchPass) {
            cout << "\nAccount Login Successful";
            cout << "\nUsername :: " << userName << endl;
            cout << "Email :: " << Email << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Invalid Username or Password!" << endl;
    file.close();
}
void temp::forgot() {
    cout << "\nEnter your UserName: ";
    getline(cin, searchName);
    cout << "\nEnter your email address :: ";
    getline(cin, searchEmail);

    bool found = false;
    file.open("loginData.txt", ios::in);
    while (getline(file, userName, '*') && getline(file, Email, '*') && getline(file, password)) {
        if (userName == searchName && Email == searchEmail) {
            cout << "\nAccount Found...." << endl;
            cout << "Your Password :: " << password << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "No matching account found!" << endl;
    file.close();
}
