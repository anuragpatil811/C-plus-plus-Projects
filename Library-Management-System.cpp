#include<iostream>
#include<fstream>
using namespace std;
class temp
{
string id, name, author, search;
fstream file;
public:
   void addBook();
   void showAll();
   void extractBook();
}obj;
int main()
{
    char choice;
    cout<<"----------------------------";
    cout<<"1-Show all books";
    cout<<"2-Extract books";
    cout<<"3-Add books(ADMIN)";
    cout<<"4-Exit";
    cout<<"Enter your choice ::";
    cout<<"----------------------------";
     cout<<"Enter your choice ::";
     cin>>choice;
     switch(choice)
     {
        case '1':
             cin.ignore();
             obj.showAll();
          break;
        case '2':
               cin.ignore();
               obj.extractBook();
          break;
        case '3':
             cin.ignore();
             obj.addBook();
          break;
        case '4':
          return 0;

          break;
        default:
            cout<<"Invalid choice....";

     }
    return 0;
}
void temp :: addBook()
{
    cout<<"\nEnter Book ID ::";
    getline(cin, id);
    cout<<"Enter Book name ::";
    getline(cin, name);
    cout<<"Enter Book's Author name ::";
    getline(cin, author);
    file.open("bookData.txt", ios :: out | ios :: app);
    file<<id<<"*"<<name<<"*"<<author<<endl;
    file.close();
}
void temp :: showAll()
{
    file.open("bookData.txt", ios :: in);
    getline(file, id, '*');
    getline(file, name, '*');
    getline(file, author, '\n');
    while (!file.eof())
    {
      cout<<"\n\n";
      cout<<"\t\t Book Id \t\t\t Book Name \t\t\t Author's Name";
      while(!file.eof())
      {
        cout<<"\t\t"<<id<<"\t\t\t"<<name<<"\t\t\t"<<author<<endl;
          getline(file, id, '*');
    getline(file, name, '*');
    getline(file, author, '\n');
      }
      file.close();
    }   
}
void temp :: extractBook()
{
      showAll();
      cout<<"Enter Book ID ::";
      getline(cin, search);
    file.open("bookData.txt", ios :: in);
    getline(file, id, '*');
    getline(file, name, '*');
    getline(file, author, '\n');
    cout<<"\n\n";
    cout<<"\t\t Book ID \t\t\t Author's Name"<<endl;
    while(!file.eof())
    {
      if(search == id)
      {
        cout<<"\t\t Book Id \t\t\t Book Name \t\t\t Author's Name";
        cout<<"Book Extracted Successfully...";
      }
    getline(file, id, '*');
    getline(file, name, '*');
    getline(file, author, '\n');
    }
    file.close();
}