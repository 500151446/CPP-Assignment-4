#include <iostream>

using namespace std;

struct Employee {
    int ID;
    string FirstName;
    string LastName;
    float HoursWorked;
    float HourlyRate;
};

Employee* GetEmployeeInfo(int num)
{
    Employee* pEmployee = new Employee;
    cout << "\nEnter the ID for Employee " << num << ": ";
    cin >> pEmployee->ID;
    cout << "Enter the First Name for Employee " << num << ": ";
    cin >> pEmployee->FirstName;
    cout << "Enter the Last Name for Employee " << num << ": ";
    cin >> pEmployee->LastName;
    cout << "Enter the Hours Worked for Employee " << num << ": ";
    cin >> pEmployee->HoursWorked;
    cout << "Enter the Hourly Rate for Employee " << num << ": ";
    cin >> pEmployee->HourlyRate;

    return pEmployee;
}

float DisplayReport(Employee employee)
{
    float weeklyPay = employee.HoursWorked * employee.HourlyRate;
    cout << employee.ID << ". " << employee.FirstName << employee.LastName << ": $" << weeklyPay << "\n";
    return weeklyPay;
}

int main()
{
    int numberOfEmployees;
    cout << "Enter the number of employees: ";
    cin >> numberOfEmployees;
    

    Employee* employees = new Employee[numberOfEmployees];

    for (int i = 0; i < numberOfEmployees; i++)
    {
        employees[i] = *GetEmployeeInfo(i + 1);
    }

    cout << "\nPay Report\n----------\n";

    float payTotal = 0;
    for (int i = 0; i < numberOfEmployees; i++)
    {
        payTotal = payTotal + DisplayReport(employees[i]);
    }

    cout << "\nTotal Pay: $" << payTotal;
}