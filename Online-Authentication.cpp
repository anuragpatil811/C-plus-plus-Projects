#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string login;
    string user;
    int login_times;
    string password_login;
    string password;
    string command;
    cout<<"WELCOME----TO----LOGIN-----TO----VERIFY-----DETAILS"<<endl;
    cout<<"\n";
    cin >> command;
    while(command != "exit")
    {
        if(command == "register")
        {
         cout<<"\n\n"<<endl;
         cout<<"Registration"<<"------------------"<<endl;
         cout<<"register:";
         cin>>user;
         cout<<"password:";
         cin>>password;
         cout<<"\n\n";
         cout<<"Registered Successfully !"<<endl;
         cout<<"\n\n";
         cout<<"exit/login/register"<<endl<<"Command:";
         cin>>command;
         login_times = 3;
         while(login_times > 0)
         {
            cout<<"\n\n";
            cout<<"Login"<<endl<<"_______";
            cout<<"\n";

            cout<< "login:";
            cin>>login;
            cout<<"Password:";
            cin>>password_login;
            //Checking Phase:
            if(login == user && password_login == password)
            {
                cout<<"loged in successfully !"<<endl;
                cout<<"welcome"<<" "<<user<<"!";
                break;
            }
            else if(login != user && password_login == password)
            {
                cout<<"username is incorrect!"<<endl;
                login_times--;
            }
            else if(login == user && password_login != password)
            {
                cout<<"password is incorrect!"<<endl;
                login_times--;
            }
            else
            {
                cout<<"Everything is incorrect!"<<endl;
            }
         }
        }
    }
}