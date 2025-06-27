#include<bits/stdc++.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    long long creditnum;
    do
    {
       cout<<"Enter credit card number: ";
       cin>>creditnum; 
    } while (creditnum <= 0);
    long long pcc = creditnum;
    int sum = 0;
    int count1 = 0;
    long long divisor = 10;
    char types[20];
    //1st condition
    while(pcc > 0)
    {
        int lastdigit = pcc % 10;
        sum = sum + lastdigit;
        pcc = pcc / 100;
    }
    // 2nd condition: Double every second digit from right to left and sum the digits
pcc = creditnum / 10;
while (pcc > 0)
{
    int digit = (pcc % 10) * 2;
    if (digit > 9)
        digit = (digit % 10) + (digit / 10); // sum of digits
    sum += digit;
    pcc /= 100;
}
    //length of card nuber
    pcc = creditnum;
    while(pcc != 0)
    {
        pcc = pcc / 10;
        count1++;
    }
    for(int i = 0; i < count1 - 2; i++)
    {
        divisor = divisor * 10;
    }
    int firstdigit = creditnum / divisor;
    int firsttwo = creditnum / (divisor / 10);
    if(sum%10==0) //if divisible then valid
    {
        if(firstdigit == 4 && (count1 == 13 || count1 == 16))
        {
            cout<<"VALID \n";
            cout<<"CARD TYPE:";
            strcpy(types, "VISTA");
        }
        else if((firsttwo == 34 || firsttwo == 37) && count1 == 16)
        {
            cout<<"VALID \n";
            cout<<"CARD TYPE:";
            strcpy(types, "AMERICAN EXPRESS");
        }
        else if((50 < firsttwo && firsttwo < 56) && count1 == 16)
        {
            cout<<"VALID \n";
            cout<<"CARD TYPE:";
            strcpy(types, "MASTERCARD");
        }
        else
        {
            cout<<"VALID ID \n";
            strcpy(types, "OTHER CARD TYPE");
        }
    }
    else
    {
        strcpy(types, "INVALID");
    }
    cout<< types;
    return 0;
}