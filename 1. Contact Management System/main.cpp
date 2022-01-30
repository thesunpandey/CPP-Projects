// including all header files
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;


// Global Variable
string fName, lName, phone_Num;

void addContact();
void searchContact();
void help();
void self_exit();
bool check_digits(string);
bool checkNumbers(string);

int main(){
    short int choice;
    system("cls"); //Clearing the Screen
    // 0 for background Color(Black)
    // A for text color(Green)
    system("Color 0A");
    cout << "\n\n\n\t\t\t Contact Management";
    cout << "\n\n\t1. Add Contact\n\t2. Search Contact\n\t3. Help\n\t4. Exit \n\t> ";
    cin >> choice;
    switch(choice){
        case 1:
            addContact();
            break;
        case 2:
            searchContact();
            break;
        case 3:
            help();
            break;
        case 4:
            self_exit();
        default:
            cout << "\n\n\tInvalid Input!";
            cout << "\n\n\tPress any key to continue";
            getch();
            main();
    }
    return 0;
}

void addContact(){
    ofstream phone("number.txt", ios::app);
    system("cls");
    cout << "\n\n\tEnter First Name: ";
    cin >> fName;
    cout << "\n\tEnter last Name: ";
    cin >> lName;
    cout << "\n\tEnter 10-digit Phone Number : ";
    cin >> phone_Num;
    if(check_digits(phone_Num)){
        if(checkNumbers(phone_Num)){
            if(phone.is_open()){
                phone << fName << " " << lName << " " << phone_Num << endl;
                cout << "\n\t Contact Save Successfully!";
            }
            else{
                cout << "\n\tError Opening File !";
            }
        }
        else{
            cout << "\n\tA phone number must contains number only!";
        }
    }
    else{
        cout << "\n\t Phone Number must contains 10 digits";
    }
    phone.close();
}
void searchContact(){
    bool found = false;
    ifstream myfile("number.txt");
    string keyword;
    cout << "\n\tEnter name to search : ";
    cin >> keyword;
    while(myfile >> fName >> lName >> phone_Num){
        if(keyword == fName || keyword == lName){
            system("cls");
            cout << "\n\n\n\tContact Details found...";
            cout << "\n\n\tFirst Name : " << fName;
            cout << "\n\tLast Name : " << lName;
            cout << "\n\tPhone Number : " << phone_Num;
            found = true;
            break;
        }
    }
    if(!found){
        cout << "\n\tNo such contact found";
    }
}
void help(){
    cout << "This displays help";
}
void self_exit(){
    system("cls");
    cout << "\n\n\n\t\tThank You for using !";
    exit(1);
}

bool check_digits(string phoneNum){
       if(phoneNum.length()==10){
           return true;
       }
       return false;
}

bool checkNumbers(string phoneNum){
    bool check = true;
    for(int i=0; i<phoneNum.length(); i++){
        if(!(int(phoneNum[i])>=48 && int(phoneNum[i])<=57)){
            check =  false;
            break;
        }
   }
   if(check){
       return true;
   }
   else{
       return false;
   }
}