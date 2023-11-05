#include <iostream>
#include <fstream>
#include "functions.h"

using namespace std;
int acc_verification = 0, pass_updated = 0;
struct Pieces {
    string size, color, price;
    int quantity;
};

void changePass(int x) {
    string username, id, newUsername, password, pass, newPassword;
    cout << "Enter Previous Username & Password" << endl;
    cout << "Enter Username: ";
    getline(cin, username);
    cout << "Enter Password: ";
    getline(cin, password);
    system("clear");
    ifstream passChange("Owner.txt");
    while (passChange >> id >> pass) {
        if (username == id && password == pass) {
            cout << "Enter New Username & Password." << endl;
            cout << "Enter Username: ";
            getline(cin, newUsername);
            cout << "Enter Password: ";
            getline(cin, newPassword);
            system("clear");
            ofstream updated("Owner.txt");
            updated << newUsername << endl;
            updated << newPassword << endl;
            updated.close();
            cout << "\t\t\tUsername & Password Changed Successfully!!!" << endl;

        } else {
            cout << "Wrong Username or Password, Kindly Enter Correct Credentials" << endl;
            changePass(1);
        }
        passChange.close();

    }
}


void owner_regis() {
    string username, password;
    cout << "Change Username & Password" << endl;
    cout << "Enter Username: ";
    getline(cin, username);
    cout << "Enter Password: ";
    getline(cin, password);
    ofstream user_pass_change("Owner.txt");
    user_pass_change << username << endl;
    user_pass_change << password << endl;
    user_pass_change.close();
}

void owner(int x) {
    int passUpdate;
    string username, password, id, pass;
    ifstream owner_detail1("Owner.txt");
    while (owner_detail1 >> id >> pass) {
        if (id == "QWERTY" && pass == "1234") {
            cout << "\tEnter Your Username & Password !!! ( Default Username: QWERTY & Password: 1234 )\n\n";
        } else {
            cout << "\tEnter 0 TO Login Using Updated Username & Password or Enter 1 To Change Username & Password : ";
            cin >> passUpdate;
            cin.ignore();
            pass_updated = 1;
        }
    }
    if (passUpdate == 0) {
        cout << "Username:";
        getline(cin, username);
        cout << "Password:";
        getline(cin, password);
        ifstream owner_detail("Owner.txt");
        while (owner_detail >> id >> pass) {
            if (id == username && pass == password) {
                system("clear");
                acc_verification = 1;
                cout << "\t\t\tLogin successful !!!" << endl;
            } else {
                system("clear");
                cout << "\t\t\tWrong Username or Password." << endl;
                owner(1);
            }
        }
        if (acc_verification == 1 && pass_updated == 0) {
            owner_regis();
        }
    } else { changePass(1); }
}

void worker(int x) {
    string username, password, id1, pass1;
    cout << "\tEnter Your Username & Password\n\n";
    cout << "Username:";
    getline(cin, username);
    cout << "Password:";
    getline(cin, password);
    ifstream worker_detail("Worker.txt");
    while (worker_detail >> id1 >> pass1) {
        if (id1 == username && pass1 == password) {
            system("clear");
            cout << "\t\t\tLogin successful !!!" << endl;
        } else {
            system("clear");
            cout << "\t\t\tWrong Username or Password." << endl;
            worker(1);
        }
    }

}

void piecesInfo() {
    int listings;
    cout << "Enter the Number of Listings You Want to Enter" << endl;
    cin >> listings;
    system("clear");
    Pieces p1[1000];
    ofstream listInput("Listings.txt");
//    listInput.open();
    for (int i = 0; i < listings; i++) {
        cout << "Enter The Size of Listing # " << i + 1 << " :";
        cin >> p1[i].size;
        listInput << p1[i].size << "\t";
        cout << "Enter The Color of Listing # " << i + 1 << " :";
        cin >> p1[i].color;
        listInput << p1[i].color << "\t";

        cout << "Enter The Price of Listing # " << i + 1 << " :";
        cin >> p1[i].price;
        listInput << p1[i].price << "\t";

        cout << "Enter The Quantity of Listing # " << i + 1 << " :";
        cin >> p1[i].quantity;
        listInput << p1[i].quantity << "\n";

        cout << endl;
    }
    listInput.close();
}

void addHours() {
    string names;
    int numOfWorkers, arr[1000];
    cout << "\t\t\tAdd the Names of Workers First !!!" << endl << endl;
    cout <<"Enter The Number of Workers you Want To Enter." << endl;
    cin >> numOfWorkers;
    cin.ignore();
    system("clear");
    ofstream workingHours("Workers_Name.txt");
    cout <<"\t\t\tEnter The Names of Workers One By One.";
    for(int i=0; i<numOfWorkers; i++){
        cout <<"Enter The Name of Worker # " <<i+1 <<": ";
        getline(cin, names);
        workingHours << names << endl;

    }


}
