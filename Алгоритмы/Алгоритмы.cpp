#include <iostream>
#include <string>
using namespace std;
#include <fstream>
const char* FNAME = "Text.txt";
struct Table
{
	char key;
	string value;
};
void algo_S(Table* array, int size)
{
	int i;
	char key;
	int counter = 0;
	int entrances = 0;
	int comparisons = 0;
	cout << "\nPlease, enter the key here: ";
	cin >> key;
	cout << "Key is :" << key << endl;
	cout << "Algo reading:" << endl;

	for (i = 0; i < size; i++)
	{
		comparisons++;
		if (array[i].key == key)
		{
			comparisons++;
			counter++;

			cout << array[i].key << "\t";
			cout << array[i].value << "\n";

		}
		else comparisons++;
	}
	if (counter == 0)
	{
		comparisons++;
		cout << "Comp number: " << comparisons << endl;
		cout << "No key found" << endl;
	}
	else
		cout << "Times key has been found equals: " << counter << endl;
	comparisons++;
	cout << "Comparisons number: " << comparisons << endl;
	
}
void algo_Q(Table* array, int size)
{
	int i = 0;
	int counter = 0;
	int entrances=0;
	int comparisons=0;
	cout << "\n\n\nalgo_Q \n\nPlease, enter algo_Q key: ";
	cin >> array[size].key;


ReturnBlock:
	while (array[i].key != array[size].key)
	{
		comparisons++;
		i++;
	}
	comparisons++;
	if (i < size)
	{
		comparisons++;
		counter++;
		cout << array[i].key << "\t";
		cout << array[i].value << "\n";
		i++;
		goto ReturnBlock;
	}
	if (counter == 0)
	{
		comparisons++;
		cout << "Number of comparisons: " << comparisons << endl;
		cout << "Key not found" << endl;
	}
	else
		comparisons++;
		cout << "Times key was found : " << counter << endl;
	cout << "Comparisons number: " << comparisons << endl;
	

}
void sort(Table* array, int size)
{
	int i;
	Table temp;

	for (i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
		{
			if (int(array[j].key) < int(array[j + 1].key))
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	cout << "\n\n\nSorted Table: " << endl << endl;
	for (i = 0; i < size; i++)
	{
		cout << array[i].key << "\t";
		cout << array[i].value << "\n";
	}
}



void algo_T(Table *array, int size)
{
int i = 0;
char key;
int counter = 0;
int comparisons = 0;
array[size].key = ' ';

cout << "\n\n\nPlease, enter Algorithm T key: ";
cin >> key;

cout << "T Algotithm key is: " << key << endl;

while (array[i].key > key)
{
i++;
comparisons++;
}
while (array[i].key == key)
{

 counter++;
 comparisons++;
 cout << array[i].key << "\t";
 cout << array[i].value << "\n";
i++;
}
if (counter == 0)
{
	comparisons++;
	cout << "Number of comparisons: " << comparisons << endl;
    cout << "There is no such key in the structure" << endl;
}
else
cout << "Times key has been found equals: " << counter << endl;
comparisons++;
cout << "Comparisons: " << comparisons << endl;

} 

void algo_B(Table* array, int size)

{

	int i = 0;

	char key;


	int comparisons = 0;

	int counter = 0;

	int index_end = 0;

	int index_start = size-1;

	cout << "\n\n\nPlease, enter algorithm B key: ";

	cin >> key;

	cout << "B Algotithm key is: " << key << endl;

	while (index_end < index_start)

	{

		comparisons++;

		i = (index_start + index_end) / 2;

	

		if (key < array[i].key)

		{

			index_end = i - 1;

			comparisons++;

		}

		else if (key == array[i].key)

		{

			comparisons++;

			while (key == array[i - 1].key)

			{

				comparisons++;

				i--;

			}

			while (key == array[i].key)

			{


				counter++;

				cout << array[i].key << "\t";

				cout << array[i].value << "\n";

				i++;

			}

			cout << "Key found: " << counter << " " << "times" << endl;


			cout << "Times compared in the cycle: " << comparisons << endl;

			system("pause");

			exit(1);

		}

		else

		{

			comparisons++;

			index_start = i + 1;

		}

	}

	cout << "There is no such key in the structure" << endl;


	cout << "Comparisons: " << comparisons << endl;

}



int main()
{
	int i;
	int size = 19;


	Table* array = new Table[size];
	ifstream fin(FNAME);

	for (i = 0; i < size; i++)
	{
		fin >> array[i].key;
		cout << array[i].key << "\t";
		fin >> array[i].value;
		cout << array[i].value << "\n";
	}


	algo_S(array, size);
	algo_Q(array, size);
	sort(array, size);
	algo_T(array, size);
	algo_B(array, size);
	system("pause");
	return 0;
}