#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Special { ��, ��, ��, Բ, �� };

string s_special[] = { "��������� �����",
					   "�����������",
					   "���������� �� ��������",
					   "Գ���� �� �����������",
					   "������� ��������" };

struct student
{
	string prizv;
	int kurs;
	Special specialization;
	int phisuka;
	int matematic;
	union
	{
		int programing;
		int chuslo_metod;
		int pedahohica;
	};
};

void Create(student* s, const int kilkist);
void Print(student* s, const int kilkist);
int find_studend(student* s, const int kilkist);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int kil_student;
	cout << "ʳ������ ��������: "; cin >> kil_student;
	cout << endl;
	student* s = new student[kil_student];

	Create(s, kil_student);
	cout << endl;
	Print(s, kil_student);
	cout << endl;

	cout << "������� ��������, �� ������� ��� ����� (�� ������� � ������): " << setprecision(2) << find_studend(s, kil_student) << "%" << endl << endl;

	cout << "������� ��������, �� �������� � ������ ������ '5' ��� '4': " << endl;
	if (find_studend(s, kil_student));
	else
		cout << "������� ��������, �� �������� � ������ ������ '5' ��� '4' �� ���������: " << endl << endl;

	delete[] s;
}

void Create(student* s, const int kilkist)
{
	int kurs, special;
	for (int i = 0; i < kilkist; i++)
	{
		cout << "������� � " << i + 1 << endl;

		cin.get();
		cin.sync();

		cout << "  �������: "; getline(cin, s[i].prizv);
		cout << "  ����: "; cin >> s[i].kurs;
		cout << "  ������������ (0 - ��������� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������): "; cin >> special;
		s[i].specialization = (Special)special;
		cout << "  ������ � ������: "; cin >> s[i].phisuka;
		cout << "  ������ � ����������: "; cin >> s[i].matematic;
		switch (special)
		{
		case 0:
			cout << "  ������ � �������������: "; cin >> s[i].programing;
			break;
		case 1:
			cout << "  ������ � ��������� ������: "; cin >> s[i].chuslo_metod;
			break;
		case 2:
		case 3:
		case 4:
			cout << "  ������ � ���������: "; cin >> s[i].pedahohica;
			break;
		default:
			cout << "�� ����� ��������� ��������! " << endl;
		}
		cout << endl;
	}
}

void Print(student* s, const int kilkist)
{
	cout << "============================================================================================================================"
		<< endl;
	cout << "| �  | �������     | ���� | ������������           | Գ���� | ����������  | ������������� | ������� ������ | ��������� |"
		<< endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < kilkist; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " "
			<< "| " << setw(13) << left << s[i].prizv
			<< "| " << setw(3) << right << s[i].kurs << "  "
			<< "| " << setw(23) << left << s_special[s[i].specialization] << " "
			<< "| " << setw(4) << right << s[i].phisuka << "   "
			<< "| " << setw(6) << right << s[i].matematic << "      ";
		switch (s[i].specialization)
		{
		case 0:
			cout << "| " << setw(7) << right << s[i].programing << "       |" << setw(18) << "|" << setw(13) << "|" << endl;
			break;
		case 1:
			cout << "| " << setw(15) << "|" << setw(10) << right << s[i].chuslo_metod << "       |" << setw(13) << "|" << endl;
			break;
		case 2:
		case 3:
		case 4:
			cout << "| " << setw(15) << "|" << setw(18) << "|" << right << setw(7) << s[i].pedahohica << "     |" << endl;
			break;
		}
	}
	cout << "============================================================================================================================" << endl;
}


int find_studend(student* s, const int kilkist)
{
	int l = 0;
	for (int i = 0; i < kilkist; i++)
		if (s[i].phisuka > 3)
		{
			cout << "� " << i + 1 << " " << s[i].prizv << " --- � ������ " << s[i].phisuka << endl;
			l = 1;
		}

	return l;
}
