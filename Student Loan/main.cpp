#include <iostream>
#include <iomanip>
#include <ctime>
#include "ezDate.h"

using namespace std;

int main()
{
	time_t t = time(0);
	struct tm now;
	localtime_s(&now, &t);

	ezDate today;
	today.setMonth(now.tm_mon + 1);
	today.setDay(now.tm_mday);
	today.setYear(now.tm_year + 1900);

	float currently_owed;
	float yearly_interest_rate;
	float daily_interest_rate;
	float monthly_payment;
	float payment_day;
	
	cout << fixed;
	cout << setprecision(2);

	cout << "\n\n";
	cout << "Federal Loan Calculator\n";
	cout << "\n\tby John Entrieri";
	cout << "\n\n\n\n";
	
	cout << "Amount Owed at this Moment: $";
	cin >> currently_owed;

	cout << "\nFixed Interest Rate: ";
	cin >> yearly_interest_rate;

	daily_interest_rate = yearly_interest_rate / 365;
	cout << setprecision(4);
	cout << "\nDaily Interest Rate: " << daily_interest_rate << "%\n";

	cout << "\nAmount you'd like to pay monthly: $";
	cin >> monthly_payment;

	cout << "\nDay of the month you'll make each payment: ";
	cin >> payment_day;

	cout << "\n\n-----------------------------------------------------";

	cout << setprecision(2);
	cout << "\n\nToday, ";
	today.printDate();
	cout << ", $" << currently_owed << " is owed with an Annual Interest Rate of ";
	cout << yearly_interest_rate << "%\n$" << monthly_payment << " will be paid on the ";
	cout << setprecision(0);
	cout << payment_day << " of very month.\n\n";

	system("PAUSE");

	float days_interest;
	float total_paid = 0;
	ezDate date_counter = today;
	float amount_owed = currently_owed;
	float day_start_amount = amount_owed;

	cout << setprecision(2);
	while (amount_owed > 0)
	{
		date_counter.printDate();
		cout << "\t" << amount_owed;

		if (date_counter.getDay() == payment_day)
		{
			if (amount_owed >= monthly_payment)
			{
				cout << "\t" << monthly_payment;
				amount_owed -= monthly_payment;
				total_paid += monthly_payment;
			}
			else
			{
				cout << "\t" << amount_owed;
				total_paid += amount_owed;
				amount_owed = 0;				
				break;
			}
		}
		else
		{
			cout << "\t0.00";
		}

		days_interest = amount_owed*(daily_interest_rate/100);

		cout << "\t" << days_interest;

		amount_owed += days_interest;

		cout << "\t" << amount_owed;
		cout << "\n";

		date_counter.incrementDay();
	}
	cout << "\n\n-----------------------------------------------------";
	cout << "\n\n\nYou'll be finished paying ";
	date_counter.printDate();

	cout << "\n\nYou paid a total of $" << total_paid;
	cout << "\n\nYou initally owed $" << currently_owed;
	cout << "\n\nYou paid $" << total_paid - currently_owed << " in interest.\n";

	system("PAUSE");
	return 0;
}