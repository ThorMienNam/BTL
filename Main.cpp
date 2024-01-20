#include<iostream>
#include<fstream>
#include<cstring>
#include "qlngdung.cpp"
using namespace std;

int main()
{
    int chon;
    while (true){
        cout << "*************************MENU**************************\n";
        cout << "**  1. Su dung khong can admin                       **\n";
        cout << "**  2. Yeu cau su dung admin                         **\n";
        cout << "*******************************************************\n";
        menu:
        cout << "chon chuc nang ban muon\n";
        cin>>chon;
    switch (chon)
    {
        case 1:
            qltvnormal();
            system("cls");
            break;
        case 2:
            qladmin();
            system("cls");
            break;
        case 0:
            break;
        default:
            cout << "\nKhong co chuc nang nay!";
            cout << "\nHay chon chuc nang trong hop menu.";
            goto menu;
            break;
    }
    }
}   