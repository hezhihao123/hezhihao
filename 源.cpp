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
	string b = "ƽʱ�ɼ�Ϊ";
	string c = "ʵ��ɼ�Ϊ";
	string d = "��ĩ�ɼ�Ϊ";
	cout << "������ѧ�ţ�"<<endl;
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
	string e = " ��ֵΪ��";
	string d = " ��׼��Ϊ��";
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
	string ask = "������ָ� ͳ��/��ѯ/����/��������";
	string code="";
while(code!="��������"){

		cout << ask<<endl;
	
	cin >> code;
	
	if (code == "ͳ��")
	{
		Sort();
		for (int i = 0; i < 6; i++)
			cout << "��"<< i+1 << "��" << stu[i].name << "���ܳɼ�Ϊ"<< stu[i].grade4<<endl;
	}
	else
	{
		if (code == "��ѯ")
			find();
		else{
		
		if(code=="����")
		fenxi();
		 }
	}
} 

	return 0;
}







