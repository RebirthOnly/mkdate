nt getYear();
	int getMonth();
	int getDay();
	void addDate(CMyDate od);
};
void CMyDate::addDate(CMyDate od)
{
	year = year + od.year;
	month = month + od.month;
	day = day + od.day;
	check();
}
CMyDate::CMyDate()
{
	year = 2019;
@ -31,12 +39,7 @@ CMyDate::CMyDate(int y, int m, int d)
	year = y;
	month = m;
	day = d;
	if (check() == 1 || check() == -1)
	{
		month = 1;
		day = 1;
		cout << "??????????????????????1" << endl;
	}
	check();

}
int CMyDate::setDate(int y, int m, int d)
@ -44,13 +47,7 @@ int CMyDate::setDate(int y, int m, int d)
	year = y;
	month = m;
	day = d;
	if (check() == 1 || check() == -1)
	{
		month = 1;
		day = 1;
		cout << "??????????????????????1" << endl;
		return -1;
	}
	check();
	return 0;

}
@ -60,21 +57,46 @@ void CMyDate::displayDate()
}
int CMyDate::check()
{
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (month > 12 || month < 1)
		return -1;
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day || day < 1)
			return 1;
	}
	else
	int flatYearDays[13] = { 31,31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[13] = { 31,31,29,31,30,31,30,31,31,30,31,30,31 };
	int temp=1;
	while (temp == 1&&month!=0&&day!=0)
	{
		if (flatYearDays[month - 1] < day || day < 1)
			return 1;
		if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		{
			if (leapYearDays[month ] < day)
			{
				day = day - leapYearDays[month ];
				month++;
				temp = 1;
			}
			else
			{
				temp = 0;
			}
		}
		else
		{
			if (flatYearDays[month ] < day )
			{
				day = day - flatYearDays[month ];
				month++;
				temp = 1;
			}
			else
			{
				temp = 0;
			}
		}
		if (month > 12)
		{
			year++;
			month = month - 12;
			temp = 1;
		}
	}
	return 0;

return 0;
}
int CMyDate::getYear()
{
@ -119,17 +141,13 @@ void CMyDate::addOneDay()
}
int main()
{
	CMyDate od;
	CMyDate od1(2020,2,29),od2(1,2,20);
	int i;
	int count = 1;
	od.setDate(2000, 1, 21);
	od.displayDate();
	while (!((od.getYear() == 2019) && (od.getMonth() == 4) && (od.getDay()) == 11))
	{
		od.addOneDay();
		count++;
	}
	cout << count << endl;
	od1.addDate(od2);
	od1.displayDate();
	od2.displayDate();
	
	return 0;
}

