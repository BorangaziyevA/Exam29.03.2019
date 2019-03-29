#include<time.h> 
#include<iostream> 
#include<Windows.h>
#include<iomanip>
#include<locale.h>
#include<fstream>

int buf_size = 0;

int cur_size = 0;

using namespace std;

struct Animal
{
	char name[30];

	char clas[30];

	char nam[30];

	void print()
	{
		cout << name << " " << clas << " " << nam << endl;
	}


};

void add(Animal *&fs, Animal el)
{
	if (buf_size == 0)
	{
		buf_size = 4;
		fs = new Animal[buf_size];
	}
	else
	{
		if (cur_size == buf_size)
		{
			buf_size *= 2;
			Animal*tmp = new Animal[buf_size];
			for (size_t i = 0; i < cur_size; i++)
			{
				tmp[i] = fs[i];
			}
			delete[]fs;
			fs = tmp;
		}

	}
	fs[cur_size++] = el;

}

void task1()
{
	char str[30];

	cout << "Введите строку(без пробелов)" << endl;
	cin >> str;

	for (size_t i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}

	}

	for (size_t i = 0; i < strlen(str); i++)
	{
		cout << str[i];
	}
	cout << endl;
}

void Delete(int *&arr, int &n)
{
	int k = 0;

	int *tmp;

	for (size_t i = 0; i < n; i++)
	{
		if (arr[i] != 0)
		{
			k++;
		}

	}
	tmp = new int[k];

	k = 0;

	for (size_t i = 0; i < n; i++)
	{
		if (arr[i] != 0)
		{
			tmp[k] = arr[i];
			k++;
		}

	}

	delete[] arr;
	arr = tmp;

	n = k;
}

void task2()
{
	int n;

	cout << "Введите количество" << endl;
	cin >> n;

	int *arr;

	arr = new int[n];


	for (size_t i = 0; i < n; i++)
	{
		arr[i] = 0 + rand() % 5;
	}

	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	Delete(arr, n);

	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void task3()
{
	
	int n;
	cout << "Количетсво"<<endl;
	cin >> n;


	int *arr;
	arr = new int[n];

	cout << "Заполните" << endl;
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = 0 + rand() % 20;
		cout << arr[i] << " ";
	}
	cout << endl;
	int k = 0;

	for (size_t i = 1; i < n; i++)
	{
		if (arr[i] < arr[i-1])
		{
			k++;
			cout << arr[i] << " ";
		}
		
	}
	cout<< endl << "Количество таких элементов: " << k << endl;
}

bool IsPowerN(float k, float n)
{
	int flag = 1;
	do
	{
		k = k / n;
		if (k == n)
			return 1;
		else if(k < n)
		{
			return 0;
		}

	} while (flag != 0);

}

void task4()
{
	float k, n;

	cout << "Введите K" << endl;
	cin >> k;
	cout << "Введите N" << endl;
	cin >> n;
	cout << IsPowerN(k, n) << endl;;

	cout << "Введите новый N" << endl;
	cin >> n;

	int a = 0;

	int as[10];
	for (size_t i = 0; i < 10; i++)
	{
		as[i] = 10 + rand() % 100;
		cout << as[i] << " ";
	}
	cout << endl;
	for (size_t i = 0; i < 10; i++)
	{
		cout << i << "." << IsPowerN(as[i], n) << " ";
		a = a + IsPowerN(as[i], n);
	}
	cout << "Количество степеней N = " << a << endl;
}

void task5()
{
	const int M = 5;
	const int N = 5;

	int arr[M][N];

	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			arr[i][j] = 1 + rand() % 40;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	int K;
	cout << "Столбец?" << endl;
	cin >> K;

	for (size_t i = 0; i < M; i++)
	{
		cout << arr[i][K+1] << endl;;
	}

}

void Golos(char golos[30],Animal *zs)
{
	if (!strcmp(golos, zs[0].name) || !strcmp(golos, zs[0].nam))
	{
		cout << endl << "Fox....Fox..." << endl;
	}
	else if (!strcmp(golos, zs[1].name) || !strcmp(golos, zs[1].nam))
	{
		cout << endl << "Wooooooo" << endl;
	}
	else if (!strcmp(golos, zs[2].name) || !strcmp(golos, zs[2].nam))
	{
		cout << endl << "Meow Meow" << endl;
	}
	else if (!strcmp(golos, zs[3].name) || !strcmp(golos, zs[3].nam))
	{
		cout << endl << "Woof Woof" << endl;
	}
	else
		cout << "Неопределен" << endl;

	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));

	ifstream in_file("in.txt");

	Animal el;

	int task;

	int flag = 0;

	int n;

	int tmp;
	char golos[20];

	Animal* zs = 0;

	do
	{
		cout << "Task number" << endl;
		cin >> task;

		switch (task)
		{
		case 1:task1(); break;
		case 2:task2(); break;
		case 3:task3(); break;
		case 4:task4(); break;
		case 5:task5(); break;
		case 6:
			while (!in_file.eof())
			{
				in_file >> el.name;

				in_file >> el.clas;

				in_file >> el.nam;

				add(zs, el);
			}
			for (size_t i = 0; i < cur_size; i++)
			{
				zs[i].print();
			}
			cout << "Подать голос кого?" << endl;
			cin >> golos;

			Golos(golos, zs);

			break;
		}
		cout << "Continue?" << endl;
		cin >> flag;

		system("cls");

	} while (flag != 0);

	system("pause");
	return 0;
}