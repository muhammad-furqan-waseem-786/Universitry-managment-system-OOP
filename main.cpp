#include <iostream>
#include <stdlib.h>

#include "Final.h"

using namespace std;

void deanFunction();
void HODFunction();
void departmentFunction();
void student();

int main()
{
    int choice = 0;    

    do
    {
        cout << "1. Dean" << endl;
        cout << "2. HOD" << endl;
        cout << "3. Departments Details" << endl;
        cout << "4. Student" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        while (choice < 0 || choice > 4)
        {
            cout << "Invalid Input \nEnter again : ";
            cin >> choice;
        }
        
        system("CLS");

        if(choice == 1)
        {
            deanFunction();
        }
        else if(choice ==  2)
        {
            HODFunction();
        }
        else if(choice == 3)
        {
            departmentFunction();
        }
        else if(choice == 4)
        {
            student();
        }
    }
    while (choice != 0);
    
    return 0;
}

void deanFunction()
{
    Database obj;

    int deanChoice = 0;
    int authority = 0 , employeeCode = 0 , session = 0;
    string name = "\0" , designation = "\0";

    do
    {
        cout << endl;
        cout << "1. Hire Faculty Member" << endl;
        cout << "2. Delete Faculty Member" << endl;
        cout << "3. Search Faculty Member" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> deanChoice;

        while (deanChoice < 0 || deanChoice > 3)
        {
            cout << "Invalid Input\nEnter again : ";
            cin >> deanChoice;
        }

        system("CLS");

        if(deanChoice == 1)
        {
            cout << "1. Permission granted" << endl;
            cout << "2. Permission Denied" << endl;
            cout << "Enter your choice : ";
            cin >> authority;

            while (authority < 1 || authority > 2)
            {
                cout << "Invalid Input\nEnter again : ";
                cin >> authority;
            }

            if(obj.deanAuthority(authority))
            {
                cout << "Name : ";
                cin >> name;
                cout << "Designation : ";
                cin >> designation;
                cout << "Session : ";
                cin >> session;

                while (session <= 0 || session > 2)
                {
                    cout << "There are only 2 session\nEnter 1 or 2 : ";
                    cin >> session;
                }
                
                cout << "Employee Code : ";
                cin >> employeeCode;

                obj.insertFaculty(name , designation , session , employeeCode);
            }
            else
            {
                cout << "Permission denied" << endl;
            }          
        }
        else if(deanChoice == 2)
        {
            cout << "1. Permission granted" << endl;
            cout << "2. Permission Denied" << endl;
            cout << "Enter your choice : ";
            cin >> authority;

            while (authority < 1 || authority > 2)
            {
                cout << "Invalid Input\nEnter again : ";
                cin >> authority;
            }

            if(obj.deanAuthority(authority))
            {                        
                cout << "Employee Code : ";
                cin >> employeeCode;

                obj.deleteFaculty(employeeCode);
            }
            else
            {
                cout << "Permission denied" << endl;
            }     
        }
        else if(deanChoice == 3)
        {
            cout << "Name : ";
            cin >> name;
            cout << "Employee Code : ";
            cin >> employeeCode;

            obj.searchFaculty(employeeCode , name);
        }
    } while (deanChoice != 0);
}
void HODFunction()
{
    Database obj;

    int HODChoice = 0;
    int authority = 0 , employeeCode = 0 , session = 0;
    string name = "\0" , designation = "\0";
    int department = 0;

    cout << "1. Permission granted" << endl;
    cout << "2. Permission Denied" << endl;
    cout << "Enter your choice : ";
    cin >> authority;

    while (authority < 1 || authority > 2)
    {
        cout << "Invalid Input\nEnter again : ";
        cin >> authority;
    }

    if(obj.deanAuthority(authority))
    {
        obj.readFaculty();

        cout << endl;
        cout << "Name : ";
        cin >> name;
        cout << "Designation : ";
        cin >> designation;                
        cout << "Employee Code : ";
        cin >> employeeCode;

        cout << "1. EE department" << endl;             
        cout << "2. ME department" << endl;             
        cout << "3. CE department" << endl;
        cout << "Enter your choice : ";
        cin >> department;

        while (department < 1 || department > 3)
        {
            cout << "Invalid Input\nEnter Again : ";
            cin >> department;
        }    

        if(department == 1)
        {
            obj.insertEE(name , designation , "EE" , employeeCode);
        }
        else if(department == 2)
        {
            obj.insertME(name , designation , "ME" , employeeCode);
        }
        else if(department == 3)
        {
            obj.insertCE(name , designation , "CE" , employeeCode);                    
        }

    }
    else
    {
        cout << "Permission denied " << endl;
    }           
}
void departmentFunction()
{
    Database obj;
    int department = 0;

    do
    {
        cout << endl;
        cout << "1. EE department" << endl;
        cout << "2. ME department" << endl;
        cout << "3. CE department" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> department;

        while (department < 0 || department > 3)
        {
            cout << "Invalid Input \nEnter again : ";
            cin >> department;
        }

        system("CLS");

        if(department == 1)
        {
            cout << "1. Faculty list" << endl;
            cout << "2. CLO's and PLO's" << endl;
            cout << "3. Time Table" << endl;
            cout << "4. Vision and Mission" << endl;
            cout << "0. Exit" << endl;
            cout << "Enter your choice : ";
            cin >> department;

            while (department < 0 || department > 4)
            {
                cout << "Invalid Input \nEnter again : ";
                cin >> department;
            }

            system("CLS");

            if(department == 1)
            {
                obj.readEE();
            }
            else if(department == 2)
            {
                obj.closAndPlosEE();
            }
            else if(department == 3)
            {
                obj.timeTableEE();
            }
            else if(department == 4)
            {
                obj.visionAndMission();
            }
        }
        else if(department == 2)
        {
            cout << "1. Faculty list" << endl;
            cout << "2. CLO's and PLO's" << endl;
            cout << "3. Time Table" << endl;
            cout << "4. Vision and Mission" << endl;
            cout << "0. Exit" << endl;
            cout << "Enter your choice : ";
            
            cin >> department;

            while (department < 0 || department > 4)
            {
                cout << "Invalid Input \nEnter again : ";
                cin >> department;
            }

            system("CLS");

            if(department == 1)
            {
                obj.readME();
            }
            else if(department == 2)
            {
                obj.closAndPlos();
            }
            else if(department == 3)
            {
                obj.timeTableME();
            }
            else if(department == 4)
            {
                obj.visionAndMission();
            }
        }
        else if(department == 3)
        {
            cout << "1. Faculty list" << endl;
            cout << "2. CLO's and PLO's" << endl;
            cout << "3. Time Table" << endl;
            cout << "4. Vision and Mission" << endl;
            cout << "0. Exit" << endl;
            cout << "Enter your choice : ";
            
            cin >> department;

            while (department < 0 || department > 4)
            {
                cout << "Invalid Input \nEnter again : ";
                cin >> department;
            }

            system("CLS");

            if(department == 1)
            {
                obj.readCE();
            }
            else if(department == 2)
            {
                obj.closAndPlos();
            }
            else if(department == 3)
            {
                obj.timeTableCE();
            }
            else if(department == 4)
            {
                obj.visionAndMission();
            }
        }
    } while (department != 0);
}
void student()
{
    Database obj;

    int choice = 0;
    string name;
    int rollNumber;

    do
    {
        cout << "\n1. Enter Student " << endl;
        cout << "2. Read Student" << endl;
        cout << "0. Exit " << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        while (choice < 0 || choice > 2)
        {
            cout << "Invalid Input \nEnter again : ";
            cin >> choice;
        }

        system("CLS");

        if(choice == 1)
        {
            cout << "Enter name : ";
            cin >> name;
            cout << "Enter Roll Number : ";
            cin >> rollNumber;

            obj.writeStudent(name , rollNumber);
        }
        else if (choice == 2)
        {
            obj.readStudent();
        }
        
    } while (choice != 0);
    
}