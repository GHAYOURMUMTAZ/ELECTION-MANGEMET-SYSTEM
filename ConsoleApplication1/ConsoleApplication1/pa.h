#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
struct assembly_candidatepa {
    string constituency_no;
    long int  cnic_no;
    string constituency_name;
    string party_name;
    string revolutionary_symbol;
    int age;

};
const int max_candidatepa = 100;

void add_candidatepa(assembly_candidatepa candidate[], int& current_index);
void view_candidatepa(assembly_candidatepa candidate[], const int current_index);
void searchpa(assembly_candidatepa candidate[], const int current_index);
void write_to_filepa(assembly_candidatepa candidate[], const int current_index);
void read_from_filepa(assembly_candidatepa candidate[], int& current_index);
void menu_pa();


void add_candidatepa(assembly_candidatepa candidate[], int& current_index) {
    int age;
   
    if (current_index < max_candidatepa) {
        do {
            cout << "Please enter the constituency number ('PA_000'): ";
            cin >> candidate[current_index].constituency_no;

            if (candidate[current_index].constituency_no.size() != 6 ||
                candidate[current_index].constituency_no.substr(0, 3) != "PA_" ||
                !isdigit(candidate[current_index].constituency_no[3]) ||
                !isdigit(candidate[current_index].constituency_no[4]) ||
                !isdigit(candidate[current_index].constituency_no[5]))
            {
                cout << "Invalid format. Please enter according to the requirements ('PA_000').\n";
            }
            else {
                break;
            }
        } while (true);

        cout << "Please enter your CNIC number: ";
        cin >> candidate[current_index].cnic_no;

        cout << "Please enter your constituency name: ";
        cin >> candidate[current_index].constituency_name;

        cout << "Please enter your revolutionary symbol: ";
        cin >> candidate[current_index].revolutionary_symbol;

        cout << "Please enter your party name: ";
        cin >> candidate[current_index].party_name;

        cout << "Please enter your age: ";
        cin >> age;

        if (age < 25) {
            cout << "You are not eligible for voting according to the constitution of Pakistan." << endl;
            return;
        }

        else { candidate[current_index].age = age; }

        current_index++;
        cout << "Candidate details added successfully." << endl;


    }
    else {
        cout << "Maximum candidates reached. Cannot add more candidates." << endl;
    }
}
void view_candidatepa(assembly_candidatepa candidate[], const int current_index) {
    cout << "Details of all candidates:" << endl;
    cout << setw(15) << "Constituency No" << setw(15) << "CNIC No"
        << setw(20) << "Constituency Name" << setw(36) << "Revolutionary Symbol"
        << setw(20) << "Party Name" << setw(10) << "Age" << endl;

    for (int i = 0; i < current_index; i++) {
        cout << setw(15) << candidate[i].constituency_no << setw(15) << candidate[i].cnic_no
            << setw(20) << candidate[i].constituency_name << setw(36) << candidate[i].revolutionary_symbol
            << setw(20) << candidate[i].party_name << setw(10) << candidate[i].age << endl;
    }
}
void searchpa(assembly_candidatepa candidate[], const int current_index) {
    string input_constituency;
    cout << "Please enter a constituency number to get data of a member: ";
    cin >> input_constituency;

    bool found = false;

    cout << "Details of candidates with constituency number " << input_constituency << ":" << endl;
    cout << setw(15) << "Constituency No" << setw(15) << "CNIC No"
        << setw(20) << "Constituency Name" << setw(20) << "Revolutionary Symbol"
        << setw(20) << "Party Name" << setw(10) << "Age" << endl;

    for (int i = 0; i < current_index; i++) {
        if (input_constituency == candidate[i].constituency_no) {
            cout << setw(15) << candidate[i].constituency_no << setw(15) << candidate[i].cnic_no
                << setw(20) << candidate[i].constituency_name << setw(20) << candidate[i].revolutionary_symbol
                << setw(20) << candidate[i].party_name << setw(10) << candidate[i].age << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No candidates found with constituency number " << input_constituency << "." << endl;
    }
}

void write_to_filepa(assembly_candidatepa candidate[], const  int current_index) {
    try {
        ofstream fout("pa.txt");

        if (!fout.is_open()) {
            throw runtime_error("Error opening file for writing.");
        }

        for (int i = 0; i < current_index; i++) {
            fout << candidate[i].constituency_no << " "
                << candidate[i].cnic_no << " "
                << candidate[i].constituency_name << " "
                << candidate[i].revolutionary_symbol << " "
                << candidate[i].party_name << " "
                << candidate[i].age << "\n";
        }

        fout.close();
        cout << "Data has been successfully written to 'pa.txt'" << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void read_from_filepa(assembly_candidatepa candidate[], int& current_index) {
    current_index = 0;
    try {
        ifstream fin("pa.txt", ios::app);

        if (!fin.is_open()) {
            throw runtime_error("File  does not exist.");
        }

        while (fin >> candidate[current_index].constituency_no
            >> candidate[current_index].cnic_no
            >> candidate[current_index].constituency_name
            >> candidate[current_index].revolutionary_symbol
            >> candidate[current_index].party_name
            >> candidate[current_index].age) {
            current_index++;
        }

        fin.close();
        cout << "Data has been successfully read from file" << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}
void menu_pa() {
    cout << "________ Welcome to Parliamentary Assembly Candidate Management System ________" << endl;
    assembly_candidatepa candidate[max_candidatepa];
    int current_index = 0;
    read_from_filepa(candidate, current_index);

    int choice;
    try {

        do {
            cout << "Menu:\n";
            cout << "1. Add Candidate :\n"
                << "2. View Candidates :\n"
                << "3. Search Candidate :\n"
                << "4. Exit:\n";

            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                add_candidatepa(candidate, current_index);
                break;

            case 2:


                view_candidatepa(candidate, current_index);
                break;

            case 3:
                searchpa(candidate, current_index);
                break;

            case 4:
                cout << "Exiting program and saving to file...\n";
                write_to_filepa(candidate, current_index);
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
            }

        } while (choice != 4);
    }
    catch (exception& e)
    {
        cout << "exception caught" <<e.what()<< endl;
    }
}

