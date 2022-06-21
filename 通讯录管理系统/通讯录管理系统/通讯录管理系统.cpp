#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

struct Person
{
	string m_Name;//��������
	int m_sex;
	int m_age;
	string m_Phonenum;
	string m_Addr;
};

struct Addressbook
{
	struct Person personarray[MAX];
	int m_size;
};

void ShowMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1�������ϵ�� *****" << endl;
	cout << "***** 2����ʾ��ϵ�� *****" << endl;
	cout << "***** 3��ɾ����ϵ�� *****" << endl;
	cout << "***** 4��������ϵ�� *****" << endl;
	cout << "***** 5���޸���ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 0���˳�ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
}

//�����ϵ��
void addperson(Addressbook* abs)
{
	if (abs->m_size == MAX)
	{
		cout << "ͨѶ¼�������޷��������ϵ��" << endl;
		return;
	}
	else
	{
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personarray[abs->m_size].m_Name = name;

		int sex;
		cout << "�������Ա�: " << endl;
		cout << "1--����" << endl;
		cout << "2--Ů��" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personarray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "���������룺" << endl;
		}
		
		int age;
		cout << "����������: " << endl;
		cin >> age;
		abs->personarray[abs->m_size].m_age = age;

		string phone;
		cout << "������绰���룺" << endl;
		cin >> phone;
		abs->personarray[abs->m_size].m_Phonenum = phone;

		string addr;
		cout << "������סַ��" << endl;
		cin >> addr;
		abs->personarray[abs->m_size].m_Addr = addr;

		abs->m_size++;

		cout << "��ӳɹ���" << endl;

		system("pause");
		system("cls");
	}
}

//��ʾ��ϵ��
void Showperson(Addressbook* abs)
{
	if (abs->m_size == 0)
	{
		cout << "����ϵ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������" << abs->personarray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personarray[i].m_sex==1?"��":"Ů") << "\t";
			cout << "���䣺" << abs->personarray[i].m_age << "\t";
			cout << "�绰���룺" << abs->personarray[i].m_Phonenum << "\t";
			cout << "סַ��" << abs->personarray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//�����ϵ���Ƿ����
int isExist(Addressbook* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personarray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

void Deleteperson(Addressbook* abs)
{
	cout << "������Ҫɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			//����ǰ��
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->m_size--;
		cout << "ɾ���ɹ���" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
		system("pause");
		system("cls");
	}
}

void findperson(Addressbook* abs)
{
	cout << "����������ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personarray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->personarray[ret].m_sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personarray[ret].m_age << "\t";
		cout << "�绰���룺" << abs->personarray[ret].m_Phonenum << "\t";
		cout << "סַ��" << abs->personarray[ret].m_Addr << endl;
	}
	else {
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}

void Modifyperson(Addressbook* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������������" << endl;
		string name1;
		cin >> name1;
		abs->personarray[ret].m_Name = name1;

		cout << "�������Ա�" << endl;
		cout << "1--��" << endl;
		cout << "2--Ů" << endl;
		int sex;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personarray[ret].m_sex = sex;
				break;
			}
			cout << "���������룺" << endl;
		}
		
		cout << "���������䣺" << endl;
		int age;
		cin >> age;
		abs->personarray[ret].m_age = age;

		string phone;
		cout << "������绰���룺" << endl;
		cin >> phone;
		abs->personarray[ret].m_Phonenum = phone;

		string addr;
		cout << "������סַ��" << endl;
		cin >> addr;
		abs->personarray[ret].m_Addr = addr;

		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}

void Clearperson(Addressbook* abs)
{
	if (abs->m_size == 0) {
		cout << "ͨѶ¼Ϊ�գ��������" << endl;
	}
	else {
	cout << "���Ƿ����Ҫ�����ϵ�ˣ�" << endl;
	string infer;
	cin >> infer;
	if (infer == "yes")
	{
	abs->m_size = 0;
	cout << "ͨѶ¼����գ�" << endl;
	}
	else {
	system("pause");
	system("cls");
	return;
	}
	}

	system("pause");
	system("cls");
}

int main()
{
	//����ͨѶ¼
	Addressbook abs;
	//��ʼ����ϵ������
	abs.m_size = 0;

	int select;
	while (true)
	{
		ShowMenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addperson(&abs);
			break;
		case 2:
			Showperson(&abs);
			break;
		case 3:
			Deleteperson(&abs);
			break;
		case 4:
			findperson(&abs);
			break;
		case 5:
			Modifyperson(&abs);
			break;
		case 6:
			Clearperson(&abs);
			break;
		case 0: 
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
}