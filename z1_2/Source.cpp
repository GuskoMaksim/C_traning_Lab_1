#include <iostream>
#include <string>
using namespace std;

struct Student
{
	string F_name;
	string L_name;
	int val[3];
	int naim=1000;
};

struct Student* St;

void Show(int kol)
{
	cout.fill('-');
	cout.width(57);
	cout << "-"<<endl;
	cout.fill(' ');
	cout << "|First name:\t|Last name:\t|Ocenki:\t\t|" << endl;
	for (int i = 0; i < kol; i++)
	{
		cout << "|";
		cout.width(8);
		cout << St[i].F_name;
		cout.width(8);
		cout << "|";
		cout.width(8);
		cout << St[i].L_name;
		cout.width(8);
		cout << "|";
		for (int k = 0; k < 3; k++)
		{
			cout << St[i].val[k] << "\t";
		}
		cout << "|" << endl;
	}
	cout.fill('-');
	cout.width(57);
	cout << "-" << endl;
	cout.fill(' ');
}

void Obm(int f, int s)
{
	swap(St[f].F_name, St[s].F_name);
	swap(St[f].L_name, St[s].L_name);
	for (int i = 0; i < 3; i++)
	{
		swap(St[f].val[i], St[s].val[i]);
	}
}

void Sort(int kol)
{
	for (int k = 0; k < kol; k++)
	{
		for (int i = k + 1; i <= kol - 1; i++)
		{
			if (St[k].naim < St[i].naim)
			{
				Obm(k, i);
			}
		}
	}
}

void Set(int kol)
{
	for (int i = 0; i < kol; i++)
	{
		cout << "Enter name: ";
		cin >> St[i].F_name;
		cout << "Enter last name: ";
		cin >> St[i].L_name;
		for (int k = 0; k < 3; k++)
		{
			cout << "Enter " << k + 1 << " ocenku ";
			cin >> St[i].val[k];
			if (St[i].naim > St[i].val[k])
				St[i].naim = St[i].val[k];
		}
		cout << endl << endl;
	}
}

int main()
{
	int n;
	cout << "Enter number student" << endl;
	do
	{
		cin >> n;
	} while (n < 3);
	St = new Student[n];
	Set(n);
	Show(n);
	cout << endl << endl;
	Sort(n);
	Show(n);
	delete []St;
}