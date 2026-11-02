#include <iostream>
#include <fstream> 
#include <sstream>   
#include <string>
using namespace std;

// Define maximum
const int MAX_SIZE =100;

// Declare parallel arrays
string itemID[MAX_SIZE];
string fullName[MAX_SIZE];
string jobTitle[MAX_SIZE];
string department[MAX_SIZE];
string gender[MAX_SIZE];
int age[MAX_SIZE];
string hireDate[MAX_SIZE];
double monthlySalary[MAX_SIZE];
int count =0; 

int readEmployeeData(string filename);
void showMenu();

// Main Function 
int main() 
{
    cout << "[System] Program is starting......" <<endl ;

    //  Read data from employee.txt 
    readEmployeeData("employee.txt");

    //Launch the interactive main menu
    showMenu();

    return 0;
}

// Read employee data from text file
int readEmployeeData(string filename) 
{
    ifstream inputFile(filename);
    
    if (!inputFile) 
    {
        cout << "[System] Error opening the file "<<filename << ". "<<endl ;
        cout <<"[Cue] Check if it is in the same folder as the program." <<endl;
        
        return 1;
    }

    string line;
    getline(inputFile, line);

    while (getline(inputFile, line)) 
    {
        if (line.empty()) continue; 

        if (!line.empty()&& line.back()== '\r') 
            line.pop_back() ;

        stringstream ss(line);
        string tempAge,tempSalary ;

        try 
        {
            getline(ss,itemID[count],'\t');
            getline(ss,fullName[count], '\t');
            getline(ss,jobTitle[count], '\t');
            getline(ss,department[count], '\t');
            getline(ss, gender[count],'\t');
            
            getline(ss,tempAge,'\t');
            age[count] = stoi(tempAge);

            getline(ss,hireDate[count], '\t');
            
            getline(ss, tempSalary,'\t');
            monthlySalary[count] =stod(tempSalary);

            count++;
        } 
        catch (const exception &e ) 
        {
            cout<< "[System] Error line is "<<count +1 <<": "<< e.what() <<endl ;
        }
    
    
    }

    inputFile.close();
    
    cout << "[System] Successfully loaded "<<count <<" employee records!" <<endl;

    return 0;

}



// Main Menu Function
void showMenu() 
{
    int choice;
    
    do {
        cout << "\n========================================" <<endl;
        cout << "       EMPLOYEE MANAGEMENT SYSTEM       " <<endl ;
        cout << "========================================" <<endl ;
        cout << "1. Display Employee Table"<<endl ;
        cout << "2. Add New Employee"<<endl;
        cout << "3. Search Employee" <<endl ;
        cout << "4. Delete Employee"<<endl ;
        cout << "5. Update Employee Details" <<endl ;
        cout << "6. Generate Statistics & Histograms"<<endl;
        cout << "7. Exit Program"<<endl;
        cout << "========================================"<<endl;
        cout << "Please enter your choice (1-7): ";
        
        cin >> choice;

        if (!cin) 
        {
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            cout <<"Invalid input! Please enter a valid number."<<endl ;
            continue;
        }

        switch (choice) 
        {
            case 1:
                cout <<"\n Display Table......"<<endl;
                break;
                
            case 2:
                cout <<"\nAdd Employee......" <<endl ;
                break;
                
            case 3:
                cout << "\nSearch Employee......"<<endl;
                break;
                
            case 4:
                cout <<"\nDelete Employee......"<<endl;
                break ;
                
            case 5:
                cout <<"\n Update Employee......" <<endl;
                break;
                
            case 6:
                cout<<"\n Generate Statistics......"<<endl ;
                break ;
                
            case 7:
                cout <<"Exiting program. See you next time." <<endl;
                break ;
                
            default:
                cout << "Invalid choice! Please choose between 1 and 7." <<endl;
        }

    } while(choice!= 7); 
}
