#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <conio.h.>
#include <iomanip>
using namespace std;
// Một quyển sách có các thông tin sau
struct book_information
{
    char isbn[9];//Mã số.
    char title[35];//Tên sách.
    char author[20];//Tác giả.
    char subject[23];//Chủ đề hay loại sách.
    char publisher[21];//Nhà xuất bản.
    int date;//ngày xuất bản.
    int pages;//Số trang.
    int copies;//Số bản coppy trong thư viện hay còn được gọi là số lượng sách đang có trong thư viện.
};
typedef book_information bi;

// tao line cho dep
void printLine(int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "_";
    }
    cout << endl;}

//Thêm sách vào thư viện
void inputbook(book_information &x)
{
    cout<<"Ma sach:\n";cin>>x.isbn;
    cout<<"Ten sach:\n";fflush(stdin); gets(x.title);
    cout<<"Ten tac gia:\n";fflush(stdin); gets(x.author);
    cout<<"Chu de cua sach (Loai sach):\n";fflush(stdin); gets(x.subject);
    cout<<"Nha xuat ban:\n";fflush(stdin); gets(x.publisher);
    cout<<"Nam xuat ban:\n"; cin>>x.date;
    cout<<"So trang sach:\n"; cin>>x.pages;
    cout<<"So luong sach co trong thu vien (so ban coppy in thu vien):\n"; cin>>x.copies;
}

//
void input(bi a[],int n)
{
    printLine(40);
    printf("\n Nhap sach thu %d:\n", n + 1);
    inputbook(a[n]);
    printLine(40);
}

// Xuat hien sach
void outputbook(bi a[],int n)
{
    printLine(147);                    
    cout<<setw(5) << left <<"stt";
    cout<<setw(9) << left <<"ma so";
    cout<<setw(35) << left <<"Ten Sach";
    cout<<setw(20) << left <<"Tac Gia";
    cout<<setw(23) << left <<"Chu De";
    cout<<setw(21) << left <<"Nha Xuat Ban";
    cout<<setw(15) << left <<"Ngay xuat ban";
    cout<<setw(9) << left <<"So Trang";
    cout<<right <<"So Ban copy\n";

    for (int i=0;i<n;i++){
        cout<<"\n";
        cout<<setw(5) << left  << i+1;
        cout<<setw(9) << left  <<a[i].isbn;
        cout<<setw(35) << left  <<a[i].title;
        cout<<setw(20) << left  <<a[i].author;
        cout<<setw(23) << left  <<a[i].subject;
        cout<<setw(21) << left  <<a[i].publisher;
        cout<<setw(15) << left  <<a[i].date;
        cout<<setw(9) << left  <<a[i].pages;
        cout<< right  <<a[i].copies;
    }
    printLine(147);
}

//Xoa sach
int deletebook(bi a[], char isbn[], int n) {
    int found = 0;
    char masosach[8];
    for(int i = 0; i < n; i++) {
        strcpy(masosach,a[i].isbn);
        if (strstr(strupr(masosach), strupr(isbn))) {
            found = 1;
            printLine(40);
            for (int j = i; j < n; j++) {
                a[j] = a[j+1];
            }
            cout << "\n Da xoa sach co maso = " << isbn;
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n Sach co ID = %d khong ton tai.", isbn);
        return 0;
    } else {
        return 1;
    }
}

//Tim kiem theo ten
void lookupforname(bi a[], char ten[], int n) {
    bi arrayFound[100];
    char tensach[35];
    int found = 0;
    for(int i = 0; i < n; i++) {
        strcpy(tensach, a[i].title);
        if(strstr(strupr(tensach), strupr(ten))) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    outputbook(arrayFound, found);
}

//Tim kiem theo tac gia
void lookupforauthor(bi a[], char tg[], int n) {
    bi arrayFound[100];
    char tentacgia[20];
    int found = 0;
    for(int i = 0; i < n; i++) {
        strcpy(tentacgia, a[i].author);
        if(strstr(strupr(tentacgia), strupr(tg))) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    outputbook(arrayFound, found);
}

//tim kiem theo chu de sach
void lookupforsubject(bi a[],char cd[], int n){
    bi arrayFound[100];
    char chudesach[23];
    int found = 0;
    for(int i = 0; i < n; i++) {
        strcpy(chudesach, a[i].subject);
        if(strstr(strupr(chudesach), strupr(cd))) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    outputbook(arrayFound, found);
}

//tim kiem theo nha xuat ban
void lookupforpuplish(bi a[],char nxb[], int n){
    bi arrayFound[100];
    char nhaxuatban[21];
    int found = 0;
    for(int i = 0; i < n; i++) {
        strcpy(nhaxuatban, a[i].subject);
        if(strstr(strupr(nhaxuatban), strupr(nxb))) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    outputbook(arrayFound, found);
}

//thao tac xu ly trong thu vien cho nguoi dung
void pressAnyKey() {
    cout << "\n\nBam phim bat ky de tiep tuc...";
    getch(); 
    system("cls");
}

//Cap nhat thong tin cho sach
void updatettbook(bi &x) {
    cout<<"Ten sach:\n ";fflush(stdin); gets(x.title);
    cout<<"Ten tac gia:\n ";fflush(stdin); gets(x.author);
    cout<<"Chu de cua sach (Loai sach):\n ";fflush(stdin); gets(x.subject);
    cout<<"Nha xuat ban:\n ";fflush(stdin); gets(x.publisher);
    cout<<"Nam xuat ban:\n "; cin>>x.date;
    cout<<"So trang sach:\n "; cin>>x.pages;
    cout<<"So luong sach co trong thu vien (so ban coppy in thu vien):\n "; cin>>x.copies;
}

void updatebook(bi a[], char maso[], int n) {
    char masosach[14];
    int found = 0;
    for(int i = 0; i < n; i++) {
        strcpy(masosach, a[i].isbn);
        if(strstr(strupr(masosach), strupr(maso))){
            found = 1;
            printLine(40);
            cout << "\n Cap nhat sach co ma so = " << maso ;
            updatettbook(a[i]);
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n Sach co ma so = %d khong ton tai.", maso);
    }
}

//Doc file va ghi file
int docFile(bi a[], char fileName[]) {
    FILE * fp;
    int i = 0;
    fp = fopen (fileName, "r");
    cout << "Chuan bi doc file: "; puts(fileName);
    while (fscanf(fp, "%9s%35s%20s%23s%21s%15d%9d%5d\n", &a[i].isbn, &a[i].title, &a[i].author, &a[i].subject, &a[i].publisher, &a[i].date, &a[i].pages, &a[i].copies) != EOF) {
       i++;
    }
    cout << " So loai sach co san trong file la: " << i << endl;
    cout << endl;
    fclose (fp);
    return i;
}

//ghi file
void ghiFile(bi a[], int n, char fileName[]) {
    FILE * fp;
    fp = fopen (fileName,"w");
    for(int i = 0;i < n;i++){
         fprintf(fp, "%9s%35s%20s%23s%21s%15d%9d%5d\n", a[i].isbn, a[i].title, a[i].author, a[i].subject, a[i].publisher, a[i].date, a[i].pages, a[i].copies);
    }
    fclose(fp);
}

int mainqltv()
{
    char fileName[] = "quanlythuvien.txt";
    book_information a[100];
    int key;
    int number =0;
    int max=0;
    number = docFile(a, fileName);

    while (true)
    {
        cout << "*************************MENU**************************\n";
        cout << "**  1. Them sach vao thu vien                        **\n";
        cout << "**  2. Hien thi danh sach thu vien.                  **\n";
        cout << "**  3. Xoa sach theo ID sach                         **\n";
        cout << "**  4. Tim kiem sach theo ten                        **\n";
        cout << "**  5. Tim kiem sach theo ten tac gia                **\n";
        cout << "**  6. Tim kiem sach theo chu de sach                **\n";
        cout << "**  7. Tim kiem theo nha xuat ban sach               **\n";
        cout << "**  8. Cap nhat thong tin cho sach                   **\n";
        cout << "**  9. Ghi danh sach vao file                        **\n";
        cout << "**  0. Thoat menu admin                              **\n";
        cout << "*******************************************************\n";
        cout << "Nhap tuy chon: ";
        cin>>key;
        switch (key)
        {
        case 1:
            cout<<"Them sach vao thu vien";
            input(a,number);
            number++;
            pressAnyKey();
            break;
        case 2:
            if (number>0)
            {
                cout<<"Hien thi sach da them vao thu vien";
                outputbook(a,number);
                break;
            }else cout<<"Thu vien dang rong!!!\n";
            pressAnyKey();
            break;
        case 3:
            if(number > 0) {
                    char isbn[12];
                    cout << "\n4. Xoa sach.";
                    cout << "\n Nhap masach: "; cin >> isbn;
                    if (deletebook(a, isbn, number) == 1) {
                        printf("\nSach co maso = %d da bi xoa.", &isbn);
                        number--;
                    }
                }else{
                    cout << "\nDanh sach thu vien dang trong!";
                }
                pressAnyKey();
            break;
        case 4:
                if(number > 0) {
                    cout << "\n Tim kiem sach theo ten.";
                    char strTen[30];
                    cout << "\nNhap ten de tim kiem: "; fflush(stdin); gets(strTen);
                    lookupforname(a, strTen, number);
                }else{
                    cout << "\nDanh sach thu vien trong!";
                }
                pressAnyKey();
            break;
        case 5:
                if(number > 0) {
                    cout << "\nTim kiem theo ten tac gia";
                    char strTg[30];
                    cout << "\nNhap ten tac gia can tim kiem: "; fflush(stdin); gets(strTg);
                    lookupforauthor(a, strTg, number);
                }else{
                    cout << "\nDanh sach thu vien trong!";
                }
                pressAnyKey();
            break;
        case 6:
                if(number > 0) {
                    cout << "\nTim kiem theo chu de";
                    char strcd[30];
                    cout << "\nNhap ten chu de sach can tim kiem: "; fflush(stdin); gets(strcd);
                    lookupforsubject(a, strcd, number);
                }else{
                    cout << "\nDanh sach thu vien trong!";
                }
                pressAnyKey();
            break;
        case 7:
                if(number > 0) {
                    cout << "\nTim kiem theo nha xuat ban";
                    char strnxb[30];
                    cout << "\nNhap nha xuat ban sach can tim kiem: "; fflush(stdin); gets(strnxb);
                    lookupforpuplish(a, strnxb, number);
                }else{
                    cout << "\nDanh sach thu vien trong!";
                }
                pressAnyKey();
            break;
        case 8:
            if(number > 0) {
                    char maso[12];
                    cout << "\nCap nhat sach. ";
                    cout << "\n Nhap ma so: "; cin >> maso;
                    updatebook(a, maso, number);
                }else{
                    cout << "\nSanh sach sinh vien trong!";
                }
                pressAnyKey();
            break;
        case 9:
                if(number > 0){
                    cout << "\nGhi danh sach vao file.";
                    ghiFile(a, number, fileName);
                }else{
                    cout << "\nDang sach trong!";
                }
                printf("\nGhi danh sach vao file %s thanh cong!", fileName);
                pressAnyKey();
            break;
        case 0:
            cout<<"Ban chon thoat truong trinh danh cho user admin!!\n";
            getch();
            return 0;
        default:
                cout << "\nKhong co chuc nang nay!";
                cout << "\nHay chon chuc nang trong hop menu.";
                pressAnyKey();
                break;
        }
    }
}

int qltvnormal()
{
    char fileName[] = "quanlythuvien.txt";
    book_information a[100];
    int key;
    int number =0;
    int idcount =0;
    number = docFile(a, fileName);
    
    while (true)
    {
        cout << "*************************MENU**************************\n";
        cout << "**  1. Hien thi danh sach thu vien.                  **\n";
        cout << "**  2. Tim kiem sach theo ten                        **\n";
        cout << "**  3. Tim kiem sach theo ten tac gia                **\n";
        cout << "**  4. Tim kiem sach theo chu de sach                **\n";
        cout << "**  5. Tim kiem theo nha xuat ban sach               **\n";
        cout << "**  0. Thoat menu                                    **\n";
        cout << "*******************************************************\n";
        cout << "Nhap tuy chon: ";
        cin>>key;
        switch (key)
        {
        case 1:
            if (number>0)
            {
                cout<<"Hien thi sach da them vao thu vien";
                outputbook(a,number);
                break;
            }else cout<<"Thu vien dang rong!!!\n";
            break;
        case 2:
                if(number > 0) {
                    cout << "\n2. Tim kiem sach theo ten.";
                    char strTen[30];
                    cout << "\nNhap ten de tim kiem: "; fflush(stdin); gets(strTen);
                    lookupforname(a, strTen, number);
                }else{
                    cout << "\nDanh sach thu vien trong!";
                }
                pressAnyKey();
            break;
        case 3:
                if(number > 0) {
                    cout << "\n3.Tim kiem theo ten tac gia";
                    char strTg[30];
                    cout << "\nNhap ten tac gia can tim kiem: "; fflush(stdin); gets(strTg);
                    lookupforauthor(a, strTg, number);
                }else{
                    cout << "\nDanh sach thu vien trong!";
                }
                pressAnyKey();
            break;
        case 4:
                if(number > 0) {
                    cout << "\n4.Tim kiem theo chu de";
                    char strcd[30];
                    cout << "\nNhap ten chu de sach can tim kiem: "; fflush(stdin); gets(strcd);
                    lookupforsubject(a, strcd, number);
                }else{
                    cout << "\nDanh sach thu vien trong!";
                }
                pressAnyKey();
            break;
        case 5:
                if(number > 0) {
                    cout << "\n5.Tim kiem theo nha xuat ban";
                    char strnxb[30];
                    cout << "\nNhap nha xuat ban sach can tim kiem: "; fflush(stdin); gets(strnxb);
                    lookupforpuplish(a, strnxb, number);
                }else{
                    cout << "\nDanh sach thu vien trong!";
                }
                pressAnyKey();
            break;
        case 0:
            cout<<"Ban chon thoat truong trinh danh cho user!!\n";
            getch();
            return 0;
        default:
                cout << "\nKhong co chuc nang nay!";
                cout << "\nHay chon chuc nang trong hop menu.";
                pressAnyKey();
                break;
        }
    }
}