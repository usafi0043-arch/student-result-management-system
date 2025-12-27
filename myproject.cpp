#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks;

public:
    void input() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Total Marks (out of 100): ";
        cin >> marks;
    }

    void display() {
        cout << "\nRoll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << "/100" << endl;
        cout << "Grade: " << getGrade() << endl;
    }

    char getGrade() {
        if (marks >= 80) return 'A';
        else if (marks >= 60) return 'B';
        else if (marks >= 40) return 'C';
        else return 'F';
    }

    int getRollNo() {
        return rollNo;
    }
};

int main() {
    const int MAX = 100;
    Student students[MAX];
    int count = 0, choice;

    do {
        cout << "\n--- Student Result Menu ---\n";
        cout << "1. Add Student\n2. View All\n3. Search by Roll No\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            students[count].input();
            count++;
        } else if (choice == 2) {
            for (int i = 0; i < count; i++) {
                students[i].display();
            }
        } else if (choice == 3) {
            int r;
            cout << "Enter Roll No to search: ";
            cin >> r;
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (students[i].getRollNo() == r) {
                    students[i].display();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Student not found.\n";
        } else if (choice == 4) {
            cout << "Exiting program.\n";
        } else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
