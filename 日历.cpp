#include <stdio.h>
#include <stdlib.h>

int main()
{
	int y, m, d;
	printf("请输入日期（示例：2000.3.9）\n");
	scanf("%d.%d.%d", &y, &m, &d);
	Xingqi(y, m, d);
	Dijitian(y, m, d);
	return 0;
}


int Runnian(int year)//判断year年是否是闰年
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	else
		return 0;
}


int Xingqi(int year, int month, int day)//判断year年month月day日是星期几
{
	int i, s = 0, n, a[13];
	for (i = 1990; i < year; i++)
	{
		if (Runnian(i))
			n = 366;
		else
			n = 365;
		s += n; //结果为与1900年间隔的年总天数
	}

	if (Runnian(year))
		a[2] = 29;
	else
		a[2] = 28;

	for (i = 1; i <= 12; i++)
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			a[i] = 31;
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			a[i] = 30;

	for (i = 1; i < month; i++)
		s += a[i]; //加上这年过去的月份共多少天
	s += day;//加上这是本月第几天

	switch (s % 7)
	{
	case 0:printf("星期日"); break;
	case 1:printf("星期一"); break;
	case 2:printf("星期二"); break;
	case 3:printf("星期三"); break;
	case 4:printf("星期四"); break;
	case 5:printf("星期五"); break;
	case 6:printf("星期六"); break;
	}
	return 0;
}

int Dijitian(int year, int month, int day) //判断year年month月day日是这年第几天
{
	int i, s = 0, n, a[13];
	if (Runnian(year))
		a[2] = 29;
	else
		a[2] = 28;

	for (i = 1; i <= 12; i++)
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			a[i] = 31;
		else if (i == 4 || i == 6 || i == 9 || i == 11)
			a[i] = 30;

	for (i = 1; i < month; i++)
		s += a[i];//这年过去的月份共多少天
	s += day;//加上这是本月第几天
	printf("今年的第%d天\n", s);
}
