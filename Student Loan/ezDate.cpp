#include "ezDate.h"



ezDate::ezDate()
{
}


ezDate::~ezDate()
{
}

void ezDate::setYear(int y)
{
	year = y;
}

void ezDate::setMonth(int m)
{
	month = m;
}

void ezDate::setDay(int d)
{
	day = d;
}

int ezDate::getYear()
{
	return year;
}

int ezDate::getMonth()
{
	return month;
}

int ezDate::getDay()
{
	return day;
}

void ezDate::incrementDay()
{
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day == 30)
		{
			month++;
			day = 1;
		}
		else
		{
			day++;
		}
	}
	else if (month == 2)
	{
		if (year % 4 == 0)
		{
			if (day == 29)
			{
				month++;
				day = 1;
			}
			else
			{
				day++;
			}
		}
		else
		{
			if (day == 28)
			{
				month++;
				day = 1;
			}
			else
			{
				day++;
			}
		}
	}
	else
	{
		if (day == 31)
		{
			if (month == 12)
			{
				month = 1;
				day = 1;
				year++;
			}
			else
			{
				month++;
				day = 1;
			}
		}
		else
		{
			day++;
		}
	}
}

void ezDate::printDate()
{
	switch (month)
	{
	case 1:
		cout << "January ";
		break;
	case 2:
		cout << "February ";
		break;
	case 3:
		cout << "March ";
		break;
	case 4:
		cout << "April ";
		break;
	case 5:
		cout << "May ";
		break;
	case 6:
		cout << "June ";
		break;
	case 7:
		cout << "July ";
		break;
	case 8:
		cout << "August ";
		break;
	case 9:
		cout << "September ";
		break;
	case 10:
		cout << "October ";
		break;
	case 11:
		cout << "November ";
		break;
	case 12:
		cout << "December ";
		break;
	}

	cout << day << " ";
	cout << year;
}
