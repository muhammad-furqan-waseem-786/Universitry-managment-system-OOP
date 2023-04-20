#include <iostream>
#include <fstream>

using namespace std;

class HOD
{
    public:

    bool HODAuthority(int input);
};

class Dean
{
    public:

    bool deanAuthority(int input);
};

class EE
{
    private:

    ifstream read;
    ofstream write;
    string name , designation , reader;
    int session , employeeCode , counter; 

    public:

    void insertEE(string name , string designation , string department , int employeeCode);
    void readEE();
    void deleteEE(int code);
    void closAndPlosEE();
    void timeTableEE();
    int numberOfLinesEE();
    void visionAndMission();
};

class ME
{
    private:

    ifstream read;
    ofstream write;
    string name , designation , reader;
    int session , employeeCode , counter; 

    public:

    void insertME(string name , string designation , string department , int employeeCode);
    void readME();
    void deleteME(int code);
    void closAndPlos();
    void timeTableME();
    int numberOfLinesME();
};

class CE
{
    private:

    ifstream read;
    ofstream write;
    string name , designation , reader;
    int employeeCode , counter; 

    public:

    void insertCE(string name , string designation , string department , int employeeCode);
    void readCE();
    void deleteCE(int code);
    int numberOfLinesCE();
    void timeTableCE();
};

class Student
{
    private:

    ifstream read;
    ofstream write;

    string name , readFile;
    int rollNumber , counter;

    public:

    void readStudent();
    void writeStudent(string pName , int pRollNumber);
    int numberOfLinesStudent();
};

class Database : public HOD , public Dean , public EE , public CE , public ME , public Student
{
    private:

    ifstream read;
    ofstream write;
    string name , designation , readFromFile;
    int session , employeeCode , counter; 

    public:

    Database();
    void insertFaculty(string n , string d , int s  , int c);
    void readFaculty();
    void deleteFaculty(int code);
    void searchFaculty(int code , string pName);
    int numberOfLines();
    void facultyLoad();
};

Database::Database()
{
    name = designation = readFromFile = "\0";
    session = employeeCode = counter = 0;
}
void Database::insertFaculty(string n , string d , int s  , int c)
{
    write.open("Faculty.txt" , ios::app);

    write << n << endl;
    write << d << endl;
    write << s << endl;
    write << c << endl;

    write.close();
}
void Database::readFaculty()
{
    int store = numberOfLines() / 4;

    cout << endl;
    cout << "Name \t   Designaetion \t Session \t Employee Code" << endl;
    read.open("Faculty.txt");

    for(int i = 1 ; i <= store ; i++)
    {
        read >> name;
        read >> designation;
        read >> session;
        read >> employeeCode;

        cout << name << "\t\t" << designation << "\t             " << session << "  \t   \t" << employeeCode << endl;
    }
    read.close();
}
void Database::deleteFaculty(int code)
{
    EE objEE;
    ME objME;
    CE objCE;

    int store = numberOfLines() / 4;

    read.open("Faculty.txt");
    write.open("temp.txt" , ios::app);

    for(int i = 1 ; i<= store ; i++)
    {
        read >> name;
        read >> designation;
        read >> session;
        read >> employeeCode;

        if(employeeCode == code)
        {
            cout << "Record of employee " << code << " is deleted" << endl;
            cout << "Name : " << name << endl;
            cout << "Designaton : " << designation << endl;
            cout << "Session : " << session << endl;
            cout << "Employee Code : " << employeeCode << endl << endl;

            objEE.deleteEE(employeeCode);
            objCE.deleteCE(employeeCode);
            objME.deleteME(employeeCode);
        }
        else
        {
            write << name << endl;
            write << designation << endl;
            write << session << endl;
            write << employeeCode << endl;
        }
    }

    write.close();
    read.close();

    remove("Faculty.txt");
    rename("temp.txt" , "Faculty.txt");
}
void Database::searchFaculty(int code , string pName)
{
    int store = numberOfLines() / 4;

    read.open("Faculty.txt");

    for(int i = 1 ; i <= store ; i++)
    {
        read >> name;
        read >> designation;
        read >> session;
        read >> employeeCode;

        if(code == employeeCode && pName == name)
        {
            cout << endl;
            cout << "<-------------Information------------->" << endl;
            cout << "Name : " << name << endl;
            cout << "Designaton : " << designation << endl;
            cout << "Session : " << session << endl;
            cout << "Employee Code : " << employeeCode << endl;
            cout << "<------------------------------------->" << endl;

            return;
        }
    }
    read.close();
}
int Database::numberOfLines()
{
    counter = 0;

    read.open("Faculty.txt");

    while(getline(read , readFromFile))
    {
        counter++;
    }

    read.close();

    return counter;
}

bool Dean::deanAuthority(int input)
{
    if (input == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool HOD::HODAuthority(int input)
{
    if (input == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void EE::insertEE(string name , string designation , string department , int employeeCode)
{
    write.open("EE.txt" , ios::app);

    write << name << endl;
    write << designation << endl;
    write << employeeCode << endl;

    write.close();
}
void EE::readEE()
{
    int store = numberOfLinesEE() / 3;

    cout << "Name \t   Designaetion \t Employee Code" << endl;
    read.open("EE.txt");

    for(int i = 1 ; i <= store ; i++)
    {
        read >> name;
        read >> designation;
        read >> employeeCode;

        cout << name << "\t\t" << designation << "\t    " << employeeCode << endl;
    }
    read.close();
}
void EE::closAndPlosEE()
{
    char reading;
    
    read.open("EECLOPLO.txt");

    while (!read.eof())
    {
        read.get(reading);
        cout << reading;
    }
    
    read.close();
}
int EE::numberOfLinesEE()
{
    counter = 0;

    read.open("EE.txt");

    while(getline(read , reader))
    {
        counter++;
    }

    read.close();

    return counter;
}
void EE::deleteEE(int code)
{
    int store = numberOfLinesEE() / 3;

    read.open("EE.txt");
    write.open("temp1.txt" , ios::app);

    for(int i = 1 ; i<= store ; i++)
    {
        read >> name;
        read >> designation;
        read >> employeeCode;

        if(employeeCode == code)
        {
            cout << "<---------------------------------------------->" << endl;
            cout << "Deleted from EE record" << endl;

            cout << "Name : " << name << endl;
            cout << "Designaton : " << designation << endl;
            cout << "Employee Code : " << employeeCode << endl;
        }
        else
        {
            write << name << endl;
            write << designation << endl;
            write << employeeCode << endl;
        }
    }

    write.close();
    read.close();

    remove("EE.txt");
    rename("temp1.txt" , "EE.txt");
}
void EE::timeTableEE()
{
    char reading;

    read.open("EEtimetable.txt");

    while (!read.eof())
    {
        read.get(reading);
        cout << reading;
    }

    read.close();
}
void EE::visionAndMission()
{
    char reading , reading1;

    cout << "<----------VISION---------->" << endl;

    read.open("Vision.txt");

    while(!read.eof())
    {
        read.get(reading);

        cout << reading;
    }

    read.close();

    cout << endl << endl;

    cout << "<----------MISSION---------->" << endl;

    read.open("Mission.txt");

    while(!read.eof())
    {
        read.get(reading1);

        cout << reading1;
    }

    read.close();

    cout << endl << endl;
}
void ME::insertME(string name , string designation , string department , int employeeCode)
{
    write.open("ME.txt" , ios::app);

    write << name << endl;
    write << designation << endl;
    write << employeeCode << endl;

    write.close();
}
void ME::readME()
{
    int store = numberOfLinesME() / 3;

    cout << "Name \t   Designaetion \t Employee Code" << endl;
    read.open("ME.txt");

    for(int i = 1 ; i <= store ; i++)
    {
        read >> name;
        read >> designation;
        read >> employeeCode;

        cout << name << "\t\t" << designation << "\t" << employeeCode << endl;
    }
    read.close();
}
void ME::deleteME(int code)
{
    int store = numberOfLinesME() / 3;

    read.open("ME.txt");
    write.open("temp2.txt" , ios::app);

    for(int i = 1 ; i<= store ; i++)
    {
        read >> name;
        read >> designation;
        read >> employeeCode;

        if(employeeCode == code)
        {
            cout << "<---------------------------------------------->" << endl;
            cout << "Deleted from ME record" << endl;

            cout << "Name : " << name << endl;
            cout << "Designaton : " << designation << endl;
            cout << "Employee Code : " << employeeCode << endl;
        }
        else
        {
            write << name << endl;
            write << designation << endl;
            write << employeeCode << endl;
        }
    }

    write.close();
    read.close();

    remove("ME.txt");
    rename("temp2.txt" , "ME.txt");
}
void ME::closAndPlos()
{
    char reading;

    read.open("CECLOPLO.txt");

    while (!read.eof())
    {
        read.get(reading);
        cout << reading;
    }

    read.close();
}
int ME::numberOfLinesME()
{
    counter = 0;

    read.open("ME.txt");

    while(getline(read , reader))
    {
        counter++;
    }

    read.close();

    return counter;
}
void ME::timeTableME()
{
    char reading;

    read.open("MEtimetable.txt");

    while (!read.eof())
    {
        read.get(reading);

        cout << reading;
    }

    read.close();
    
}
void CE::insertCE(string name , string designation , string department , int employeeCode)
{
    write.open("CE.txt" , ios::app);

    write << name << endl;
    write << designation << endl;
    write << employeeCode << endl;

    write.close();
}
void CE::readCE()
{
    int store = numberOfLinesCE() / 3;

    cout << "Name \t   Designaetion \t Employee Code" << endl;
    read.open("CE.txt");

    for(int i = 1 ; i <= store ; i++)
    {
        read >> name;
        read >> designation;
        read >> employeeCode;

        cout << name << "\t\t" << designation << "\t" << employeeCode << endl;
    }
    read.close();
}
void CE::deleteCE(int code)
{
    int store = numberOfLinesCE() / 3;

    read.open("CE.txt");
    write.open("temp3.txt" , ios::app);

    for(int i = 1 ; i<= store ; i++)
    {
        read >> name;
        read >> designation;
        read >> employeeCode;

        if(employeeCode == code)
        {
            cout << "<---------------------------------------------->" << endl;
            cout << "Deleted from CE record" << endl;

            cout << "Name : " << name << endl;
            cout << "Designaton : " << designation << endl;
            cout << "Employee Code : " << employeeCode << endl;
        }
        else
        {
            write << name << endl;
            write << designation << endl;
            write << employeeCode << endl;
        }
    }

    write.close();
    read.close();

    remove("CE.txt");
    rename("temp3.txt" , "CE.txt");
}
int CE::numberOfLinesCE()
{
    counter = 0;

    read.open("CE.txt");

    while(getline(read , reader))
    {
        counter++;
    }

    read.close();

    return counter;
}
void CE::timeTableCE()
{
    char reading;

    read.open("CEtimetable.txt");

    while (!read.eof())
    {
        read.get(reading);
        cout << reading;
    }

    read.close();
}

int Student::numberOfLinesStudent()
{
    counter = 0;

    read.open("Student.txt");

    while (getline(read,readFile))
    {
        counter++;
    }

    read.close();  

    return counter;  
}

void Student::readStudent()
{
    int store = numberOfLinesStudent()/2;

    cout << "Roll Number \t Name" << endl;

    read.open("Student.txt");

    for(int i = 1 ; i <= store ; i++)
    {
        read >> name;
        read >> rollNumber;

        cout << rollNumber << " \t\t " << name << endl;
    }

    read.close();
}

void Student::writeStudent(string pName , int pRollNumber)
{
    write.open("Student.txt" , ios::app);

    write << pName << endl;
    write << pRollNumber << endl;

    write.close();
}