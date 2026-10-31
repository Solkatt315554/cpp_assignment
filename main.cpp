#include <iostream>
#include <fstream> 
#include <sstream>   
#include <string>
using namespace std;

// Define maximum
const int MAX_SIZE = 100;

// Declare parallel arrays
string itemID[MAX_SIZE];
string fullName[MAX_SIZE];
string jobTitle[MAX_SIZE];
string department[MAX_SIZE];
string gender[MAX_SIZE];
int age[MAX_SIZE];
string hireDate[MAX_SIZE];
double monthlySalary[MAX_SIZE];

int employeeCount = 0; 

void loadEmployeeData(string filename);
void showMenu();

// Main Function 
int main() 
{
    cout << "[System] Program is starting..." << endl;

    //  Load data from employee.txt automatically at startup
    loadEmployeeData("employee.txt");

    //Launch the interactive main menu
    showMenu();

    return 0;
}

// load employee data from text file
void loadEmployeeData(string filename) 
{
    ifstream file(filename);
    
    if (!file.is_open()) 
    {
        cout << "Error: Unable to open file " << filename << ". NOT the same folder as the program!" << endl;
        return;
    }

    string line;
    
    getline(file, line);

    employeeCount = 0; 

    while (getline(file, line)) 
    {
        if (line.empty()) continue; 

        if (!line.empty() && line.back() == '\r') 
        {
            line.pop_back();
        }

        stringstream ss(line);
        string tempAge, tempSalary;

        try 
        {
            getline(ss, itemID[employeeCount], '\t');
            getline(ss, fullName[employeeCount], '\t');
            getline(ss, jobTitle[employeeCount], '\t');
            getline(ss, department[employeeCount], '\t');
            getline(ss, gender[employeeCount], '\t');
            
            getline(ss, tempAge, '\t');
            if (!tempAge.empty()) 
            {
                age[employeeCount] = stoi(tempAge);
            }

            getline(ss, hireDate[employeeCount], '\t');
            
            getline(ss, tempSalary, '\t');
            if (!tempSalary.empty()) 
            {
                monthlySalary[employeeCount] = stod(tempSalary);
            }

            employeeCount++;
        } 
        catch (const exception & e) 
        {
            cout << "Error parsing line " << employeeCount + 1 << ": " << e.what() << endl;
        }
    }

    file.close();
    cout << "[System] Successfully loaded " << employeeCount << " employee records!" << endl;
}


// Main Menu Function
void showMenu() 
{
    int choice;
    
    do {
        // Display the menu interface
        cout << "\n========================================" << endl;
        cout << "       EMPLOYEE MANAGEMENT SYSTEM       " << endl;
        cout << "========================================" << endl;
        cout << "1. Display Employee Table" << endl;
        cout << "2. Add New Employee" << endl;
        cout << "3. Search Employee" << endl;
        cout << "4. Delete Employee" << endl;
        cout << "5. Update Employee Details" << endl;
        cout << "6. Generate Statistics & Histograms" << endl;
        cout << "7. Exit Program" << endl;
        cout << "========================================" << endl;
        cout << "Please enter your choice (1-7): ";
        
        cin >> choice;

        if (cin.fail()) 
        {
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            cout << "Invalid input! Please enter a valid number." << endl;
            continue;
        }

        switch (choice) 
        {
            case 1:
                cout << "\n[Executing] Display Table..." << endl;
                break;
                
            case 2:
                cout << "\n[Executing] Add Employee..." << endl;
                break;
                
            case 3:
                cout << "\n[Executing] Search Employee..." << endl;
                break;
                
            case 4:
                cout << "\n[Executing] Delete Employee..." << endl;
                break;
                
            case 5:
                cout << "\n[Executing] Update Employee..." << endl;
                break;
                
            case 6:
                cout << "\n[Executing] Generate Statistics..." << endl;
                break;
                
            case 7:
                cout << "Exiting program. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Please choose between 1 and 7." << endl;
        }

    } while (choice != 7); 
}
