#include <iostream>

using namespace std;
#pragma once
class ezDate
{
public:
	ezDate();
	~ezDate();
	void setYear(int y);
	void setMonth(int m);
	void setDay(int d);
	int getYear();
	int getMonth();
	int getDay();
	void incrementDay();
	void printDate();
private:
	int year;
	int month;
	int day;
};

