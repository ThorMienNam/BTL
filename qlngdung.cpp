#include <iostream>
#include <fstream>
#include <cstring>
#include "qltv.cpp"
using namespace std;

int qladmin()
{
    char fileName[] = "user.txt";
    char userName[50], password[50], rePassword[50];
    int chuc_nang;

    fstream f;

    chonChucNang:
        cout << "1. Dang ky tai khoan\n2. Dang nhap\n0. Thoat\nLua chon: ";
        cin >> chuc_nang;
        switch (chuc_nang)
        {
        case 1:
            goto dangKy;
        case 2:
            goto dangNhap;
        case 0:
            goto thoat;
        default:
            cout << "Khong hop le\n";
            goto chonChucNang;
        }

    dangKy:
        f.open(fileName, ios::out);
        cout << "========Dang ky tai khoan=======\n";
        cout << "Nhap username (khong chua khoang trang): ";
        cin.ignore();
        cin.getline(userName,50);
        cout << "Nhap mat khau: ";
        cin.getline(password,50);
    reType:
        cout << "Nhap lai mat khau: ";
        cin.getline(rePassword,50);
        if (strcmp(password, rePassword) == 0)
        {
            if (f)
            {
                f << userName << " " << password << "\n";
                cout << "Dang ky thanh cong\n";
                f.close();
            }
            else
            {
                cout << "Khong mo duoc file\n";
            }
        }
        else
        {
            cout << "Mat khau khong khop, hay nhap lai\n";
            goto reType;
        }
        goto chonChucNang;

    dangNhap:
        cout << "======Dang nhap tai khoan ======\n";
        f.open(fileName, ios::in);
        f >> userName >> password;
        if (f)
        {
            f >> userName >> password;
            char userNameData[50], passwordData[50];
            int soLan = 2, dem = 0;
        tenDangNhap:
            cout << "Ten dang nhap: ";
            cin.ignore();
            cin.getline(userNameData,50);
            if (strcmp(userNameData, userName) != 0)
            {
                cout << "Khong ton tai tai khoan\n";
                ++dem;
                cout << "Dang nhap lai (" << dem << "/" << soLan << "): ";
                if (dem > soLan)
                {
                    goto thoat;
                }
                goto tenDangNhap;
            }
            soLan = 2;
            dem = 0;
        matKhau:
            cout << "Nhap mat khau: ";
            cin.getline(passwordData,50);
            if (strcmp(passwordData, password) != 0)
            {
                cout << "Mat khau khong dung\n";
                ++dem;
                cout << "Nhap lai mat khau (" << dem << "/" << soLan << "): ";
                if (dem > soLan)
                {
                    goto thoat;
                }
                goto matKhau;
            }
            else
            {
                cout << "Thanh cong\n";
                mainqltv();
                f.close();
            }
        }
        else
        {
            cout << "Khong tai khoan da duoc dang ky!\n";
        }
        goto chonChucNang;
    thoat:
        cout << "hen gap lai\n";
        return 0;
    }