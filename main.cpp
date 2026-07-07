#include <iostream>
#include <string>

using namespace std;

float getTotalHoursWorked();

float calculateRegularPay(float totalHours);

float calculateOvertimePay(float totalHours);

float calculateTotalWages(float regularPay, float overtimePay);


void displayInformation(string farmerName, float totalHours, float regularPay, float overtimePay, float totalWages);

int main()
{
    float totalHoursWorked, regularPay, overtimePay, totalWages;

    string farmerName;

    int numberOfFarmers;

    cout<<"FARM WAGE CALCULATOR"<<endl;

    cout<<"Enter the number of farm workers to process: ";
    cin>>numberOfFarmers;
    cin.ignore();

    for (int farmerCount = 1; farmerCount <= numberOfFarmers; farmerCount++)
    {
         cout<<"Processing for Farm Worker "<<farmerCount<<endl;

         cout<<"Enter the name of the farm worker (type 'quit' to end the program): ";
         getline(cin, farmerName);

         if (farmerName == "quit"){
            cout<<"Program terminated by the user....Bye"<<endl;
            break;
         }

         // Call all the Functions

         totalHoursWorked = getTotalHoursWorked();

         regularPay = calculateRegularPay(totalHoursWorked);

         overtimePay = calculateOvertimePay(totalHoursWorked);

         totalWages = calculateTotalWages(regularPay, overtimePay);

         displayInformation(farmerName, totalHoursWorked, regularPay, overtimePay, totalWages);


    }

    return 0;
}

float getTotalHoursWorked(){
    float totalhours;
    cout<<"Enter the total hours worked: ";
    cin >> totalhours;
    while (totalhours < 0)
        {
            cout << "Invalid input....hours cannot be negative" << endl;
            cout << "Enter the total hours worked again: ";
            cin >> totalhours;
        }
    cin.ignore();
    return totalhours;
}

 float calculateRegularPay(float totalHours)
{
    float regularPay;
    if (totalHours <= 40)
        regularPay = totalHours * 10;
    else
        regularPay = 40 * 10;

    return regularPay;
}

float calculateOvertimePay(float totalHours)
{
    float overtimePay;
    if (totalHours <= 40)
        overtimePay = 0;
    else
        overtimePay = (totalHours - 40) * 15;

    return overtimePay;
}

float calculateTotalWages(float regularPay, float overtimePay){
    float totalWage = regularPay + overtimePay;
    return totalWage;
}

void displayInformation(string farmerName, float totalHours, float regularPay, float overtimePay, float totalWages){
    cout<<"Farmer Name: "<<farmerName<<endl;
    cout<<"Total hours worked: "<<totalHours<<"hrs"<<endl;
    cout<<"Regular Pay: GHC"<<regularPay<<endl;
    cout<<"Overtime Pay: GHC"<<overtimePay<<endl;
    cout<<"Total Wage: GHC"<<totalWages<<endl;
}
