#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

struct Person
{
	string m_Name;//输入名字
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
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

//添加联系人
void addperson(Addressbook* abs)
{
	if (abs->m_size == MAX)
	{
		cout << "通讯录已满，无法添加新联系人" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personarray[abs->m_size].m_Name = name;

		int sex;
		cout << "请输入性别: " << endl;
		cout << "1--男生" << endl;
		cout << "2--女生" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personarray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "请重新输入：" << endl;
		}
		
		int age;
		cout << "请输入年龄: " << endl;
		cin >> age;
		abs->personarray[abs->m_size].m_age = age;

		string phone;
		cout << "请输入电话号码：" << endl;
		cin >> phone;
		abs->personarray[abs->m_size].m_Phonenum = phone;

		string addr;
		cout << "请输入住址：" << endl;
		cin >> addr;
		abs->personarray[abs->m_size].m_Addr = addr;

		abs->m_size++;

		cout << "添加成功！" << endl;

		system("pause");
		system("cls");
	}
}

//显示联系人
void Showperson(Addressbook* abs)
{
	if (abs->m_size == 0)
	{
		cout << "无联系人" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名：" << abs->personarray[i].m_Name << "\t";
			cout << "性别：" << (abs->personarray[i].m_sex==1?"男":"女") << "\t";
			cout << "年龄：" << abs->personarray[i].m_age << "\t";
			cout << "电话号码：" << abs->personarray[i].m_Phonenum << "\t";
			cout << "住址：" << abs->personarray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

//检测联系人是否存在
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
	cout << "请输入要删除的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			//数据前移
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->m_size--;
		cout << "删除成功！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "查无此人！" << endl;
		system("pause");
		system("cls");
	}
}

void findperson(Addressbook* abs)
{
	cout << "请输入想查找的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personarray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personarray[ret].m_sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personarray[ret].m_age << "\t";
		cout << "电话号码：" << abs->personarray[ret].m_Phonenum << "\t";
		cout << "住址：" << abs->personarray[ret].m_Addr << endl;
	}
	else {
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

void Modifyperson(Addressbook* abs)
{
	cout << "请输入您要修改的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "请输入姓名：" << endl;
		string name1;
		cin >> name1;
		abs->personarray[ret].m_Name = name1;

		cout << "请输入性别：" << endl;
		cout << "1--男" << endl;
		cout << "2--女" << endl;
		int sex;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personarray[ret].m_sex = sex;
				break;
			}
			cout << "请重新输入：" << endl;
		}
		
		cout << "请输入年龄：" << endl;
		int age;
		cin >> age;
		abs->personarray[ret].m_age = age;

		string phone;
		cout << "请输入电话号码：" << endl;
		cin >> phone;
		abs->personarray[ret].m_Phonenum = phone;

		string addr;
		cout << "请输入住址：" << endl;
		cin >> addr;
		abs->personarray[ret].m_Addr = addr;

		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}

void Clearperson(Addressbook* abs)
{
	if (abs->m_size == 0) {
		cout << "通讯录为空，无需清空" << endl;
	}
	else {
	cout << "您是否真的要清空联系人？" << endl;
	string infer;
	cin >> infer;
	if (infer == "yes")
	{
	abs->m_size = 0;
	cout << "通讯录已清空！" << endl;
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
	//创建通讯录
	Addressbook abs;
	//初始化联系人数量
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
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
}