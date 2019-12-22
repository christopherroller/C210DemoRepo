#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <string>
#include <vector>
using namespace std;

class Account
{
	public:	
		Account();
		void SetInitialInvestmentAmount(double t_initialInvestmentAmount);
		void SetMonthlyDeposit(double t_monthlyDeposit);
		void SetAnnualInterest(double t_annualInterest);
		void SetNumberOfYears(int t_numberOfYears);
		bool GetUserInput();
		double GetInitialInvestmentAmount();
		double GetMonthlyDeposit();
		double GetAnnualInterest();
		int GetNumberOfYears();
		void FormatAndDisplayReports();
		void CalculateAccountAmounts();
	private:
		double m_initialInvestmentAmount;
		double m_monthlyDeposit;
		double m_annualInterest;
		int m_numberofYears;
		//these will track our overall account totals and interest totals. No need to store the value explicitly as it's available via the sum;
		vector<double> m_yearEndBalance;
		vector<double> m_yearEndInterestEarned;
		vector<double> m_yearEndBalanceNoDeposit;
		vector<double> m_yearEndInterestEarnedNoDeposit;
};

#endif // ACCOUNT_H_
