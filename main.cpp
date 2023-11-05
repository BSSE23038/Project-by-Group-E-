#include <iostream>
#include "functions.h"
using namespace std;

int main ()
{
    int identity;
    cout <<"\t\t\tWelcome To 'Textile Nexus'.\n\n\n";
    cout <<"\tEnter Your Identity.\n";
    cout<<"\t\t\n1 For Owner.\n2 For Worker.\n3 For Customer.\n";
    cin >> identity;
    cin.ignore();
    if(identity==1){
        int functions_of_owner;
        system("clear");
        cout <<"\t\t\t\tIdentity Successfully Matched.\n" << endl;
        owner(identity);
        cout<<"Enter 1 For Adding Pieces' Information\n";
        cout<<"Enter 2 For Adding Working Hours of Workers\n";
        cout<<"Enter 3 To Find  Working Hours of Any Worker\n";
        cin >> functions_of_owner;
        if(functions_of_owner==1){
            system("clear");
            piecesInfo();
        }
        else if (functions_of_owner==2){
            system("clear");
            addHours();
        }

    }
    else if(identity==2){
        system("clear");
        cout <<"\t\t\t\tIdentity Successfully Matched." << endl;
        worker(identity);

    }
    else if(identity==3){
        cout <<"\t\t\t\tIdentity Successfully Matched." << endl;

    }
    else if(identity<1||identity>3){
        cout <<"\t\t\t\tInvalid Identity." << endl;
        }
}