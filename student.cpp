#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "student.h"

string loggedInStudent;

void studentLogin()
{
    string username;
    string password;

    cout << "\n===== STUDENT LOGIN =====\n";

    cout << "Registration Number: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    if (username == "2024/001" && password == "1234")
    {
        loggedInStudent = username;

        cout << "\nLogin successful!\n";

        studentMenu();
    }
    else
    {
        cout << "\nInvalid registration number or password.\n";
    }
}
void studentMenu()
{
    int choice;

    do
    {
        cout << "\n==============================\n";
        cout << "        STUDENT MODULE\n";
        cout << "==============================\n";

        cout << "1. Register Unit\n";
        cout << "2. View Registered Units\n";
        cout << "3. Access LMS\n";
        cout << "4. View Notes\n";
        cout << "5. View Assignments\n";
        cout << "6. View CATs\n";
        cout << "7. View Grades\n";
        cout << "8. Logout\n";

        cout << "Choose option: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                registerUnit();
                break;

            case 2:
                viewRegisteredUnits();
                break;

            case 3:
                cout << "\nWelcome to the LMS.\n";
                break;

            case 4:
                cout << "\nYour unit notes are available here.\n";
                break;

            case 5:
                cout << "\nYour assignments are available here.\n";
                break;

            case 6:
                cout << "\nYour CATs are available here.\n";
                break;

            case 7:
                viewGrades();
                break;

            case 8:
                cout << "\nLogging out...\n";
                break;

            default:
                cout << "\nInvalid option.\n";
        }

    } while (choice != 8);
}
void viewGrades()
{
    ifstream file("database/marks.txt");

    if (!file)
    {
        cout << "Unable to open marks database.\n";
        return;
    }

    string line;

    cout << "\n====================================\n";
    cout << "           MY GRADES\n";
    cout << "====================================\n";

    while (getline(file, line))
    {
        string regNo;
        string unitCode;
        string assignmentStr;
        string catStr;
        string examStr;

        size_t pos;

        // Registration number
        pos = line.find("|");
        regNo = line.substr(0, pos);
        line.erase(0, pos + 1);

        // Unit code
        pos = line.find("|");
        unitCode = line.substr(0, pos);
        line.erase(0, pos + 1);

        // Assignment
        pos = line.find("|");
        assignmentStr = line.substr(0, pos);
        line.erase(0, pos + 1);

        // CAT
        pos = line.find("|");
        catStr = line.substr(0, pos);
        line.erase(0, pos + 1);

        // Exam
        examStr = line;

        if (regNo == loggedInStudent)
        {
            double assignment = stod(assignmentStr);
            double cat = stod(catStr);
            double exam = stod(examStr);

            double total = assignment + cat + exam;

            cout << "\nUnit: " << unitCode;
            cout << "\nAssignment: " << assignment;
            cout << "\nCAT: " << cat;
            cout << "\nExam: " << exam;
            cout << "\nTotal: " << total << "/100\n";
        }
    }

    file.close();
}