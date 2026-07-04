#include <iostream>
#include <string>
#include <fstream>
using namespace std;



const int MAX = 100; //our storage limit
string names[MAX];
string ids[MAX];
double grades[MAX];
int counT = 0; // number of student stored.


void addStudent()
{
    if (counT >= 100)
    {
        cout << "STORAGE FULL" << endl;
        cout << endl;
        return;
    }

    cout << "ENTER STUDENT NAME: ";
    cin.ignore();
    getline(cin, names[counT]);
    
    cout << "ENTER STUDENT ID: ";
    cin >> ids[counT];

    cout << "ENTER GRADE (0 - 100): ";
    cin >> grades[counT];

    counT++;
}

void displayAll()
    {
    if (counT == 0)
    {
        cout << "NO STUDENTS ON RECORD" << endl;
        return;
    }

    cout << "\nALL STUDENTS:\n" << endl;
    for (int i = 0; i < counT; i++)
    {
        cout << i + 1 << ". " << names[i] << " | ID: " << ids[i] << " | Grade: " << grades[i] << "%" << endl;
    } 

    }

    void searchByName()
    {
        string search;

        cout << "ENTER STUDENT NAME: ";
        cin.ignore();
        getline(cin, search);

        bool found = false;
        for ( int i = 0; i < counT; i++)

        {
            if ( names[i] == search)
            {
                cout << "FOUND: " << names[i] << " | ID: " << ids[i] <<" | GRADE: " << grades[i] << "%" << endl;
                found = true; 
            }
            if (!found)
            {
                cout << "STUDENT WITH THE ENTERRED NAME NOT FOUND." << endl;
                cout << endl;
            }
            
        }

    }



int main()
{
    int response = 0;
    cout << "<<< STUDENT RECORDS MANAGER >>> \n" << endl;

    do
    {
        cout << "\n\nMAIN MENU\n\n" << endl;
        cout << "\n1. ADD STUDENT\n2. SEARCH STUDENT BY NAME\n3. DISPLAY ALL FILES\n3. EXIT\n\n" << endl;
        cout << endl;
        cin >> response;
        cout << endl;

        switch (response)
    {
        case 1:
        {
            addStudent();
            cout << endl;
            break;
        }

        case 2: 
        {
           searchByName();
           break;

        }

        case 3: 
        {
            displayAll();
            cout << endl;
            break;
        }

        default:
        {
            cout << "PLEASE CHOOSE OPTIONS 1 - 4" << endl;
        }
    }



    } while (response != 5);
    

//save to file feature



    return 0;
}
