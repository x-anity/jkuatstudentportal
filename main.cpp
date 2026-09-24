#include <iostream>
using namespace std;

#include "lecturer.h"
#include "student.h"

int main()
{
    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "     JKUAT INFORMATION SYSTEM\n";
        cout << "====================================\n";

        cout << "1. Lecturer Module\n";
        cout << "2. Student Module\n";
        cout << "3. Exit\n";

        cout << "\nChoose option: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                lecturerLogin();
                break;

            case 2:
                studentLogin();
                break;

            case 3:
                cout << "\nThank you for using the system.\n";
                break;

            default:
                cout << "\nInvalid option.\n";
        }

    } while (choice != 3);

    return 0;
}