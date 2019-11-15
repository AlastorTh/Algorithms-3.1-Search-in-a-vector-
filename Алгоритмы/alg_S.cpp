#include <iostream>
#include <fstream> // читаем данные из файла
#include <string>
const char* FNAME = "Text.txt";
using namespace std;
struct table
{
	int data; // данные
	char key; //ключ
};

int main()
{
	char SKey;
	cout << " Enter a key to be searched:";
	cin >> SKey;
	cout << endl;
	int num = 0;
	int nums[20] = { 0 };
	ifstream fin(FNAME);
	if (!fin) //если нет файла с указанным именем
	{
		cout << "Error! No file found!\n";
		return 1;
	}
	if (fin.peek() == EOF) //если файл пуст
	{
		cout << "Error! File empty! \n";
		return 2;
	}
	table array[20] = { 0 };
	for (int i = 0; i < 20; i++)
	{
		fin>> array[i].key;
		fin>> array[i].data;
	}
	cout << "Original structure:" << endl;
	for (int i = 0; i < 19; i++)
	{
		cout << i + 1<< "\t";
		cout << array[i].key << "\t";
		cout << array[i].data << "\n";
	}
	cout << endl;
	int i = 1;
	do
	{
		if (array[i].key == SKey) {
			nums[num] = i;
			num++;
		}
		i++;
	} while (i <= 19);


	if (num != 0)
	{
		cout << "Key(s) found:" << endl;
		for (i = 0; i < num; i++)
		{
			cout << nums[i] + 1 << "\t";
			cout << array[nums[i]].key << "\t";
			cout << array[nums[i]].data << "\n";
		}
	}
	else
	{
		cout << "Key not found" << endl;
	}
	return 0;
}