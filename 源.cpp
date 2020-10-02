#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
struct student {
	int num;
	string name;
	int grade1, grade2, grade3;
	double grade4;
};
student stu[6];
int a[6];

void getGrade4() {
	for (int i = 0; i < 6; i++)
	{
		a[i] = stu[i].grade1*0.2+stu[i].grade2*0.2+stu[i].grade3*0.6;
		stu[i].grade4= stu[i].grade1*0.2+stu[i].grade2*0.2+stu[i].grade3*0.6;
	}
}

void exchange(int x, int y) {
	student t;
	t = stu[x]; stu[x] = stu[y]; stu[y] = t;
}
void Sort() {
	for (int i = 1; i < 6; i++) {
		if (stu[i - 1].grade4 > stu[i].grade4)
			for (int o = i; o != 0; o--) {
				if (stu[o - 1].grade4 < stu[o].grade4)
					break;
				exchange(o - 1, o);
			}
	}
}

void find() {
	int num;
	string b = "平时成绩为";
	string c = "实验成绩为";
	string d = "期末成绩为";
	cout << "请输入学号："<<endl;
	cin >> num;
	for (int i = 0; i < 6; i++)
	{
		if (stu[i].num == num) {
			cout << b << stu[i].grade1 << c << stu[i].grade2 << d << stu[i].grade3<<endl;
			break;
		}

	}
}
void fenxi() {
	string e = " 均值为：";
	string d = " 标准差为：";
	double sum=0,sum2=0;
	for (int i = 0; i < sizeof(a)/4; i++) {
		sum = sum + a[i];
	}
	double b = sum / (sizeof(a)/4);
	for (int i = 0; i < sizeof(a)/4; i++) {
		sum2 = sum2 + pow((a[i] - (double)b), 2);
	}
	double c = pow(sum2 / (sizeof(a)/4),0.5);
	cout << e << b << d << c;
}
int main()
{
	int number = 0;
	ifstream input("data.txt");
	input >> number;

	for (int i = 0; i < 6; i++)
	{
		input >> stu[i].num;
		input >> stu[i].name;
		input >> stu[i].grade1;
		input >> stu[i].grade2;
		input >> stu[i].grade3;
		
	}
	input.close();
	getGrade4();
	string ask = "请输入指令： 统计/查询/分析/结束程序";
	string code="";
while(code!="结束程序"){

		cout << ask<<endl;
	
	cin >> code;
	
	if (code == "统计")
	{
		Sort();
		for (int i = 0; i < 6; i++)
			cout << "第"<< i+1 << "名" << stu[i].name << "的总成绩为"<< stu[i].grade4<<endl;
	}
	else
	{
		if (code == "查询")
			find();
		else{
		
		if(code=="分析")
		fenxi();
		 }
	}
} 

	return 0;
}







