#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
using namespace std;
const int Max_voters = 100;
struct Areadetails {
    string area;
    int block_no;
    string PA_Number;
    string NA_Number;
};
struct voterdetail {
    long int cnic;
    string nationality;
    string pollingboth;
    int family_no;
    Areadetails area1;
};
void addvoter_details(voterdetail vote[], int& current_index);
void view_voter(voterdetail vote[], const int current_index);
void search_voter(voterdetail vote[], const int current_index);
void write_filevoter(voterdetail vote[],const int current_index);
void read_filevoter(voterdetail vote[], int& current_index);
void update(voterdetail vote[], int current_index);
void menuvotter();


void addvoter_details(voterdetail vote[], int& current_index) {

    int input_cnic;
    if (current_index < Max_voters) {
        cout << "Please enter your nationality: " << endl;
        cin >> vote[current_index].nationality;

        if (vote[current_index].nationality != "pak" && vote[current_index].nationality != "PAK") {
            cout << "Sorry, you are not eligible for voting as your nationality is not Pakistani." << endl;
            return;
        }

        cout << "polling both " << endl;
        cin >> vote[current_index].pollingboth;

        cout << "Please enter your CNIC: ";
        cin >> input_cnic; for (int i = 0; i < current_index; i++) {
            if (input_cnic == vote[i].cnic) {
                cout << "You are already registered." << endl;
                return;
            }
        }

        vote[current_index].cnic = input_cnic;


        cout << "Enter your family registration number: ";
        cin >> vote[current_index].family_no;

        int choices_area;
        cout << "Enter your area detail:\n1 for Federal\n2 for Punjab\n.3 for KPK\n4 for Sindh\n.5 for Balochistan" << endl;
        cin >> choices_area;

        switch (choices_area) {
        case 1:
            vote[current_index].area1.area = "Federal";
            break;
        case 2:
            vote[current_index].area1.area = "Punjab";
            break;
        case 3:
            vote[current_index].area1.area = "KPK";
            break;
        case 4:
            vote[current_index].area1.area = "Sindh";
            break;
        case 5:
            vote[current_index].area1.area = "Balochistan";
            break;
        default:
            cout << "Invalid choice. Please select a valid option." << endl;
            return;
        }

        cout << "Enter block number: ";
        cin >> vote[current_index].area1.block_no;

        cout << "Enter Provisional Assembly number for your region (in format PA_000): ";
        do {
            cin >> vote[current_index].area1.PA_Number;

            if (vote[current_index].area1.PA_Number.size() != 6 &&
                vote[current_index].area1.PA_Number.substr(0, 3) != "PA_" ||
                !isdigit(vote[current_index].area1.PA_Number[3]) ||
                !isdigit(vote[current_index].area1.PA_Number[4]) ||
                !isdigit(vote[current_index].area1.PA_Number[5]))
            {
                cout << "Invalid format. Please enter according to requirements." << endl;
            }
            else { 
                break; 
            }
        } while (true);

        cout << "Enter national assembly number for your region (in format NA_000): ";
        do {
            cin >> vote[current_index].area1.NA_Number;

            if (vote[current_index].area1.NA_Number.size() != 6 ||
                vote[current_index].area1.NA_Number.substr(0, 3) != "NA_" ||
                !isdigit(vote[current_index].area1.NA_Number[3]) ||
                !isdigit(vote[current_index].area1.NA_Number[4]) ||
                !isdigit(vote[current_index].area1.NA_Number[5]))
            {
                cout << "Invalid format. Please enter according to requirements." << endl;
            }
            else {
                break;
            }
        } while (true);


        current_index++;





    }
    else {
        cout << "votting done sucessfully" << endl;

    }

}
void view_voter(voterdetail voters[], const int current_index) {
    cout << "Details of all candidates:" << endl;
    cout << setw(12) << "Nationality" << setw(15) << "polling both" << setw(15) << "CNIC"
        << setw(25) << "Family Registration No" << setw(15) << "Area"
        << setw(15) << "Block No" << setw(15) << "PA Number"
        << setw(15) << "NA Number" << endl;

    for (int i = 0; i < current_index; i++) {
        cout << "Candidate details for candidate " << i + 1 << ":" << endl;
        cout << setw(12) << voters[i].nationality << setw(15) << voters[i].pollingboth
            << setw(15) << voters[i].cnic << setw(25) << voters[i].family_no
            << setw(15) << voters[i].area1.area << setw(15) << voters[i].area1.block_no
            << setw(15) << voters[i].area1.PA_Number << setw(15) << voters[i].area1.NA_Number << endl;
        cout << "*-----------------------------------*" << endl;
    }
}

void search_voter(voterdetail voters[], const int current_index) {
    int search_id;
    cout << "Please enter your ID to get information about your voting: ";
    cin >> search_id;

    cout << setw(12) << "Nationality" << setw(15) << "pollingboth" << setw(15) << "CNIC"
        << setw(25) << "Family Registration No" << setw(15) << "Area"
        << setw(15) << "Block No" << setw(15) << "PA Number"
        << setw(15) << "NA Number" << endl;

    int i;
    for (i = 0; i < current_index; i++) {
        if (search_id == voters[i].cnic) {
            cout << setw(12) << voters[i].nationality << setw(15) << voters[i].pollingboth
                << setw(15) << voters[i].cnic << setw(25) << voters[i].family_no
                << setw(15) << voters[i].area1.area << setw(15) << voters[i].area1.block_no
                << setw(15) << voters[i].area1.PA_Number << setw(15) << voters[i].area1.NA_Number << endl;
            break;
        }
    }

    if (i == current_index) {
        cout << "This candidate doesn't exist." << endl;
    }
}
void update(voterdetail vote[], int current_index)
{
    int cnic;
    bool edited = false;
    int i = 0;

    cout << "Enter your cnic for update voter data: " << endl;
    cin >> cnic;

    for (i = 0; i < current_index; i++) {
        if (cnic == vote[i].cnic) {
            edited = true;
            break;
        }
    }

    if (edited) {
        addvoter_details(vote, i);
        cout << "record sucess fully updated" << endl;
    }
    else {
        cout << cnic << " : ID doesn't exist" << endl;
    }
}


void write_filevoter(voterdetail vote[],  const int current_index) {
    ofstream fout;
    fout.open("voterdetails.txt");

    try {


        if (!fout.is_open()) {
            throw runtime_error("Failed to open the file for writing");
        }


        for (int i = 0; i < current_index; i++) {
            fout << setw(15) << vote[i].nationality << setw(15) << vote[i].pollingboth
                << setw(15) << vote[i].cnic << setw(15) << vote[i].family_no
                << setw(15) << vote[i].area1.area << setw(15) << vote[i].area1.block_no
                << setw(15) << vote[i].area1.PA_Number << setw(15) << vote[i].area1.NA_Number << endl;
        }

        fout.close();
        cout << "Data has been successfully written to 'voterdetails.txt'" << endl;
    }
    catch (runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void read_filevoter(voterdetail vote[], int& current_index) {
    ifstream fin;
    fin.open("voterdetails.txt");

    try {
        if (!fin.is_open()) {
            throw runtime_error("File  does not exist.");
        }

        while (fin >> vote[current_index].nationality >> vote[current_index].pollingboth >> vote[current_index].cnic >>
            vote[current_index].family_no >> vote[current_index].area1.area >>
            vote[current_index].area1.block_no >> vote[current_index].area1.PA_Number >>
            vote[current_index].area1.NA_Number) {
            current_index++;
        }

        fin.close();
        cout << "Data has been successfully read from 'voterdetails.txt'" << endl;
    }
    catch (runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
}
void menuvotter() {
    int choices;
    voterdetail vote[Max_voters];
    int current_index = 0;
    read_filevoter(vote, current_index);

    try {

        do {
            cout << "Enter choice:\n"
                << "1. Add voter details:\n"
                << "2. View candidate details:\n"
                << "3. Search for a candidate:\n"
                << "4. Update voter details:\n"
                << "5. Exit\n";
            cin >> choices;

            switch (choices) {
            case 1:
                addvoter_details(vote, current_index);
                break;
            case 2:
                view_voter(vote, current_index);
                break;
            case 3:
                search_voter(vote, current_index);
                break;


            case 4:
                cout << "update votter info" << endl;
                update(vote, current_index);
                break;
            case 5:
                cout << "Exiting program...\n";
                write_filevoter(vote, current_index);
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
            }
        } while (choices != 5);
    }
    catch (exception& e) {
        cout << "exception caught"<<e.what() << endl;
    }
}
