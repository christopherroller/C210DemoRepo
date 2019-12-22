
/*
	Project Two
	Christopher Roller
	12/1/2019

*/


#include <iostream>
#include <conio.h>
#include "Account.h"

int main()
{
	bool cont = true;
	while (cont) {
		Account account;	

		bool goodData = false;
		while (!goodData) {
			goodData = account.GetUserInput();
			if (goodData == false) {
				system("CLS");
				cout << "There was an error with one or more of your values." << endl;
				cout << "Please check your inputs and try again." << endl;
			}
		}		

		cout << "Press any key to continue..." << endl;
		_getch();
		system("CLS");
		account.CalculateAccountAmounts();
		account.FormatAndDisplayReports();

		cout << "Continue...(y/n)?" << endl;
		char c;
		cin >> c;
		if (c == 'n' || c == 'N') {
			cont = false;
			cout << "Thanks for using Airgead Banking Application.";

		}
	}

}
