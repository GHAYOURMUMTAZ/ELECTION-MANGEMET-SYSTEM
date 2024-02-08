#include<iostream>
#include"voter.h"
#include"pa.h"
#include"na.h"
using namespace std;

void main_menu() {
    int choice;

    do {
        cout << "______________________Welcome to Election Management System____________________________________" << endl;
        cout << "Press a button according to the requirement:\n"
        << "1. For Voter Management:\n"
        << "2. For Member of National Assembly Management:\n"
        << "3. For Parliamentary Management:\n"
        << "4. For Exit:\n"
        << "Enter your choice: \n"
        << "________________________________________________________________________________________________" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            menuvotter();
            break;

        case 2:
            menu_na();
            break;

        case 3:
            menu_pa();
            break;

        case 4:
            cout << "Exiting the program...\n";
           
            break;

        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4); 
}

int main() {
    main_menu();
    return 0;
}
