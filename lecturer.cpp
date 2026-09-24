#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "lecturer.h"

void lecturerLogin()
{
    string username, password;

    cout << "\n===== LECTURER LOGIN =====\n";

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    if (username == "lecturer" && password == "1234")
    {
        cout << "\nLogin successful!\n";
        lecturerMenu();
    }
    else
    {
        cout << "\nInvalid username or password.\n";
    }
}

void lecturerMenu()
{
    int choice;

    do
    {
        cout << "\n==============================\n";
        cout << "       LECTURER MODULE\n";
        cout << "==============================\n";

        cout << "1. View Units\n";
        cout << "2. Add Notes\n";
        cout << "3. Add Assignment\n";
        cout << "4. Add CAT\n";
        cout << "5. Add Exam\n";
        cout << "6. Enter Student Marks\n";
        cout << "7. View Student Marks\n";
        cout << "8. Logout\n";

        cout << "Choose option: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "\nUnits taught:\n";
                cout << "BIT2101 - Programming\n";
                cout << "BIT2102 - Database Systems\n";
                cout << "BIT2103 - Computer Networks\n";
                break;

            case 2:
                cout << "\nNotes uploaded successfully.\n";
                break;

            case 3:
                cout << "\nAssignment added successfully.\n";
                break;

            case 4:
                cout << "\nCAT added successfully.\n";
                break;

            case 5:
                cout << "\nExam added successfully.\n";
                break;

            case 6:
                enterMarks();
                break;

            case 7:
                viewMarks();
                break;

            case 8:
                cout << "\nLogging out...\n";
                break;

            default:
                cout << "\nInvalid option.\n";
        }

    } while (choice != 8);
}
void enterMarks()
{
    string regNo;
    string unitCode;

    double assignment;
    double cat;
    double exam;

    cout << "\n===== ENTER STUDENT MARKS =====\n";

    cout << "Student Registration Number: ";
    cin >> regNo;

    cout << "Unit Code: ";
    cin >> unitCode;

    cout << "Assignment Mark: ";
    cin >> assignment;

    cout << "CAT Mark: ";
    cin >> cat;

    cout << "Exam Mark: ";
    cin >> exam;

    // Open marks file in append mode
    ofstream file("database/marks.txt", ios::app);

    if (!file)
    {
        cout << "Error opening database file.\n";
        return;
    }

    file << regNo << "|"
         << unitCode << "|"
         << assignment << "|"
         << cat << "|"
         << exam << endl;

    file.close();

    cout << "\nMarks saved successfully!\n";

    cout << "Total: "
         << assignment + cat + exam
         << "/100\n";
}