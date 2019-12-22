#include <iostream>
#include <vector>
#include <iomanip>
#include <string> 
using namespace std;

#include "Account.h"

Account::Account() {
	m_annualInterest = 0.0;
	m_numberofYears = 0;
	m_initialInvestmentAmount = 0.0;
	m_monthlyDeposit = 0.0;
}

void Account::SetAnnualInterest(double t_annualInterest) {
	if (t_annualInterest >= 0) {
		m_annualInterest = t_annualInterest / 100.0;
	}
	else {
		m_annualInterest = 0;
	}
}

void Account::SetInitialInvestmentAmount(double t_initialInvestmentAmount) {
	if (t_initialInvestmentAmount >= 0) {
		m_initialInvestmentAmount = t_initialInvestmentAmount;
	}
	else {
		m_initialInvestmentAmount = 0;
	}
}


void Account::SetMonthlyDeposit(double t_monthlyDeposit) {
	if (t_monthlyDeposit >= 0) {
		m_monthlyDeposit = t_monthlyDeposit;
	}
	else {
		m_monthlyDeposit = 0;
	}
}

void Account::SetNumberOfYears(int t_numberOfYears) {
	if (t_numberOfYears >= 0) {
		m_numberofYears = t_numberOfYears;
	}
	else {
		m_numberofYears = 0;
	}
}

double Account::GetInitialInvestmentAmount() {
	return m_initialInvestmentAmount;
}

double Account::GetAnnualInterest() {
	return m_annualInterest;
}

double Account::GetMonthlyDeposit() {
	return m_monthlyDeposit;
}

int Account::GetNumberOfYears() {
	return m_numberofYears;
}


void Account::FormatAndDisplayReports()
{
	cout.width(70);
	cout << setfill(' ') <<"Balance and Interest With Additionaly Monthly Desposits        " << endl;
	cout << setfill('=') << setw(70) << "" << endl;
	cout << "    Year       Year End Balance           Year End Interest Earned" << endl;
	cout << setfill('-') << setw(70) << "" << endl;
	for (int x = 0 ; x < m_yearEndBalance.size(); x++) {
		cout << (x > 8 ? "      " : "       ") << x + 1 << "               " << fixed  << setprecision(2) << "$" << m_yearEndBalance.at(x) << "                               $" << m_yearEndInterestEarned.at(x) << "     " << endl;
	}
	cout << endl;

	cout << setfill(' ') <<"Balance and Interest Without Additionaly Monthly Desposits     " << endl;
	cout << setfill('=') << setw(70) << "" << endl;
	cout << "    Year       Year End Balance           Year End Interest Earned" << endl;
	cout << setfill('-') << setw(70) << "" << endl;
	for (int x = 0; x < m_yearEndBalanceNoDeposit.size(); x++) {
		cout << (x > 8 ? "      " : "       ") << x + 1 << "               " << fixed << setprecision(2) << "$" << m_yearEndBalanceNoDeposit.at(x) << "                               $" << m_yearEndInterestEarnedNoDeposit.at(x) << "     " << endl;
	}

}


bool Account::GetUserInput() {
	bool correctData = true;
	cout << "***********************************" << endl;
	cout << "************ Data Input ***********" << endl;
	cout << "Initial Investment Amount: $"; 

	double invAmount;	
	cin >> invAmount;
	if (invAmount >= 0) {
		Account::SetInitialInvestmentAmount(invAmount);
	}
	else {
		correctData = false;
	}

	cout << "Monthly Deposit: $";
	double monthlyDeposit;
	cin >> monthlyDeposit;
	if (monthlyDeposit >= 0) {
		Account::SetMonthlyDeposit(monthlyDeposit);
	}
	else {
		correctData = false;
	}

	cout << "Annual Interest: %";
	double annualInterest;
	cin >> annualInterest;
	if (annualInterest >= 0) {
		Account::SetAnnualInterest(annualInterest);
	}
	else {
		correctData = false;
	}


	cout << "Number of Years: ";
	int numOfYears;
	cin >> numOfYears;
	if (numOfYears >= 1) {
		Account::SetNumberOfYears(numOfYears);
	}
	else {
		correctData = false;
	}

	return correctData;
}

void Account::CalculateAccountAmounts()
{
	vector<double> yearEndBalance(m_numberofYears);
	vector<double> yearEndInterestEarned(m_numberofYears);
	vector<double> yearEndBalanceNoMonthlyDeposit(m_numberofYears);
	vector<double> yearEndInterestEarnedNoMonthlyDeposit(m_numberofYears);

	int months = m_numberofYears * 12;
	double startingAmount = m_initialInvestmentAmount;
	double monthlyDeposit = m_monthlyDeposit;
	double monthlyInterestRate = m_annualInterest / 12.0;
	double currentAmount = startingAmount;
	double currentAmountNoDeposit = startingAmount;
	double yearlyInterestEarned = 0.0;
	double yearlyInterestEarnedNoDeposit = 0.0;

	for (int x = 1; x <= months; x ++) {
		double interestEarnedThisMonth = (currentAmount + monthlyDeposit) * monthlyInterestRate;
		double interestEarnedThisMonthNoDeposit = currentAmountNoDeposit * monthlyInterestRate;
		
		yearlyInterestEarned = yearlyInterestEarned + interestEarnedThisMonth;
		yearlyInterestEarnedNoDeposit = yearlyInterestEarnedNoDeposit + interestEarnedThisMonthNoDeposit;

		currentAmount = currentAmount + monthlyDeposit + interestEarnedThisMonth;
		currentAmountNoDeposit = currentAmountNoDeposit + interestEarnedThisMonthNoDeposit;
		// a the year mark
		if (x % 12 == 0) {
			yearEndBalance.at((x / 12) - 1) = currentAmount;
			yearEndInterestEarned.at((x / 12) - 1) = yearlyInterestEarned;

			yearEndBalanceNoMonthlyDeposit.at((x / 12) - 1) = currentAmountNoDeposit;
			yearEndInterestEarnedNoMonthlyDeposit.at((x / 12) - 1) = yearlyInterestEarnedNoDeposit;
			//reset yearly interest earned
			yearlyInterestEarned = 0;
			yearlyInterestEarnedNoDeposit = 0;
		}
	}

	//set calculated vectors to class parameter
	m_yearEndBalance = yearEndBalance;
	m_yearEndInterestEarned = yearEndInterestEarned;
	m_yearEndBalanceNoDeposit = yearEndBalanceNoMonthlyDeposit;
   m_yearEndInterestEarnedNoDeposit = yearEndInterestEarnedNoMonthlyDeposit;
}
