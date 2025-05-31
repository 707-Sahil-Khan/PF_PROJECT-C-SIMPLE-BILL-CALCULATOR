#include<iostream>
#include<windows.h>
#include<fstream>

using namespace std;

int main(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);  // Green text
    
    
    
    
    
    long int Bill, Wmeter, First_Floor, Ground_Floor;
    int ToPay, P1, P2, Tax;
    int Reading;
    long int LateRead;
    int LateDays;
    long int AvgLatePerDay;
    int NumOfLateDays;
    long int LateWmeter;
    long int LastWhiteLate;
    long int FinalLateReading;
    long int CurBill;
    long int BlueFinal;
    
    ofstream out("bill_report.txt");

    cout << "\n\t======================================\n";
    cout << "\t     Electricity Bill Calculator\n";
    cout << "\t======================================\n";
    
    cout<<"\n\tChoose One Option\n\t 1 for Late Reading \n\t 2 for Normal Reading"<<endl;
    cin>>Reading;
    if(Reading == 1){
    	cout<<"\n\tEnter the Current reading (White): "<<endl;
    	cin>>LateRead;
    	cout<<"\n\tEnter the Last reading(White):  "<<endl;
    	cin>>LastWhiteLate;
    	FinalLateReading=LateRead-LastWhiteLate;
    	cout<<"\n\tEnter Days:"<<endl;
    	cin>>LateDays;
    	AvgLatePerDay=FinalLateReading/LateDays;
    	cout<<"\n\tAverage use per day:"<<AvgLatePerDay<<endl;
    	cout<<"\n\t number of days to calculate for: "<<endl;
    	cin>>NumOfLateDays;
    	LateWmeter=AvgLatePerDay*NumOfLateDays;
    	cout << "\n\t Enter the Last reading from Bill: ";
        cin >> Bill;
        cout<< "\n\t Enter the Current reading from Bill: ";
        cin>>CurBill;
        cout<<"\n\t New Reading is: "<<endl;
        BlueFinal=CurBill-Bill;
        cout<<BlueFinal;
        First_Floor=LateWmeter;
        Ground_Floor = BlueFinal - First_Floor;
        cout << "\n\t--------------------------------------\n";
        cout << "\tFirst Floor consumption is: " << First_Floor << " units\n";
        cout << "\tGround Floor consumption is: " << Ground_Floor << " units\n";
        cout << "\n\tEnter total Cash (Rs): ";
        cin >> ToPay;
         P1 = (First_Floor * 100) / BlueFinal;
    P2 = (Ground_Floor * 100) / BlueFinal;

    float FirstCash = ((float)First_Floor / BlueFinal) * ToPay;
    float GroundCash = ((float)Ground_Floor / BlueFinal) * ToPay;

    cout << "\n\t--------------------------------------\n";
    cout << "\tPercent Split:\n";
    cout << "\tFirst Floor: " << P1 << "%\n";
    cout << "\tGround Floor: " << P2 << "%\n";

    cout << "\n\tBill Split:\n";
    cout << "\tFirst Floor has to pay: Rs." << FirstCash << endl;
    cout << "\tGround Floor has to pay: Rs." << GroundCash << endl;

    cout << "\n\tPlease enter Taxes (if any): Rs. ";
    cin >> Tax;

    int Taxes = Tax / 2;

    cout << "\n\tTax per floor: Rs." << Taxes << endl;

    cout << "\n\t=========== Final Payment ===========\n";
    cout << "\tFirst Floor Total: Rs." << FirstCash + Taxes << endl;
    cout << "\tGround Floor Total: Rs." << GroundCash + Taxes << endl;
    cout << "\t======================================\n";
     // Reset text color
    SetConsoleTextAttribute(hConsole, 7);

    // Write to file
    out << "===== GAS Bill Report =====\n";
    out << "Total Bill Units: " << BlueFinal << "\n";
    out << "White Meter Reading (First Floor): " << LateWmeter << "\n";
    out << "First Floor Units: " << First_Floor << "\n";
    out << "Ground Floor Units: " << Ground_Floor << "\n";
    out << "Total Cash: Rs. " << ToPay << "\n\n";

    out << "First Floor Percentage: " << P1 << "%\n";
    out << "Ground Floor Percentage: " << P2 << "%\n";
    out << "First Floor Bill: Rs. " << FirstCash << "\n";
    out << "Ground Floor Bill: Rs. " << GroundCash << "\n";
    out << "Tax per Floor: Rs. " << Taxes << "\n\n";
    out << "=== Final Payable ===\n";
    out << "First Floor: Rs. " << FirstCash + Taxes << "\n";
    out << "Ground Floor: Rs. " << GroundCash + Taxes << "\n";

    out.close();

    cout << "\n\t? Report saved to 'bill_report.txt'\n";

    // ?? Auto-open the file
    ShellExecute(0, "open", "bill_report.txt", NULL, NULL, SW_SHOWNORMAL);

	}
	
	else {
    long int prevBill, currBill;
    long int prevWhite, currWhite;

    cout << "\n\t Enter previous reading from Bill: ";
    cin >> prevBill;
    cout << "\n\t Enter current reading from Bill: ";
    cin >> currBill;

    cout << "\n\t Enter previous reading from (White) Meter: ";
    cin >> prevWhite;
    cout << "\n\t Enter current reading from (White) Meter: ";
    cin >> currWhite;

    // Validation
    if (currBill < prevBill || currWhite < prevWhite) {
        cout << "\n\tError: Current reading cannot be less than previous reading.\n";
        return 1;
    }

    long int billConsumption = currBill - prevBill;
    long int whiteConsumption = currWhite - prevWhite;

    First_Floor = whiteConsumption;
    Ground_Floor = billConsumption - whiteConsumption;

    cout << "\n\t--------------------------------------\n";
    cout << "\tFirst Floor consumption is: " << First_Floor << " units\n";
    cout << "\tGround Floor consumption is: " << Ground_Floor << " units\n";

    cout << "\n\tEnter total Cash (Rs): ";
    cin >> ToPay;

    P1 = (First_Floor * 100) / billConsumption;
    P2 = (Ground_Floor * 100) / billConsumption;

    float FirstCash = ((float)First_Floor / billConsumption) * ToPay;
    float GroundCash = ((float)Ground_Floor / billConsumption) * ToPay;

    cout << "\n\t--------------------------------------\n";
    cout << "\tPercent Split:\n";
    cout << "\tFirst Floor: " << P1 << "%\n";
    cout << "\tGround Floor: " << P2 << "%\n";

    cout << "\n\tBill Split:\n";
    cout << "\tFirst Floor has to pay: Rs." << FirstCash << endl;
    cout << "\tGround Floor has to pay: Rs." << GroundCash << endl;

    cout << "\n\tPlease enter Taxes (if any): Rs. ";
    cin >> Tax;

    int Taxes = Tax / 2;

    cout << "\n\tTax per floor: Rs." << Taxes << endl;

    cout << "\n\t=========== Final Payment ===========\n";
    cout << "\tFirst Floor Total: Rs." << FirstCash + Taxes << endl;
    cout << "\tGround Floor Total: Rs." << GroundCash + Taxes << endl;
    cout << "\t======================================\n";

    // Write to file
    out << "===== GAS Bill Report =====\n";
    out << "Total Bill Units: " << billConsumption << "\n";
    out << "White Meter Reading (First Floor): " << whiteConsumption << "\n";
    out << "First Floor Units: " << First_Floor << "\n";
    out << "Ground Floor Units: " << Ground_Floor << "\n";
    out << "Total Cash: Rs. " << ToPay << "\n\n";

    out << "First Floor Percentage: " << P1 << "%\n";
    out << "Ground Floor Percentage: " << P2 << "%\n";
    out << "First Floor Bill: Rs. " << FirstCash << "\n";
    out << "Ground Floor Bill: Rs. " << GroundCash << "\n";
    out << "Tax per Floor: Rs. " << Taxes << "\n\n";
    out << "=== Final Payable ===\n";
    out << "First Floor: Rs. " << FirstCash + Taxes << "\n";
    out << "Ground Floor: Rs. " << GroundCash + Taxes << "\n";

    cout << "\n\t? Report saved to 'bill_report.txt'\n";

    // Auto-open the file
    ShellExecute(0, "open", "bill_report.txt", NULL, NULL, SW_SHOWNORMAL);
}

return 0;
}
