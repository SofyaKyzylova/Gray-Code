// LR1_KyzylovaS_GrayCode.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>

using namespace std;

bool** gray;
int n, m;   
int i, j;
int* mnojestvo = new int[n];

int Mnojestvo(int* mnojestvo, int& n) 	
{
	while (true)
	{
		cout << " Введите количество элементов множества: ";
		cin >> n;
		cout << endl;

		if (n <= 0)
		{
			cout << " Введено неверное число!" << endl;
			continue;
		}

		if (n > 10)
		{
			cout << " Введенное число слишком велико! Попробуйте еще раз." << endl;
			continue;
		}

		else
		{
			cout << " Сгенерированное множество: ";
			srand(time(0));
			for (i = 0; i < n; i++)
			{
				mnojestvo[i] = rand() % 10;
				cout << mnojestvo[i] << " ";
			}
			cout << endl << endl;
			break;
		}
	}
	return 0;
}

void Quantity(int& m, int n)  
{
	m = pow(2, n);
	cout << " Количество подмножеств в заданном множестве: " << m << endl << endl;
}

void Gray(int m, int n) 
{
	gray = new bool* [m];
	for (i = 0; i < m; i++)
		gray[i] = new bool[n];
}

void Gray_Code(int m, int n) 
{
	if (n == 1)
	{
		gray[0][0] = 0;
		gray[1][0] = 1;
		return;
	}
	else
	{
		for (i = 0; i < m / 2; i++)
		{
			gray[i][n - 1] = 0; 
			gray[m - i - 1][n - 1] = 1; 
		}

		Gray_Code(m / 2, n - 1);

		for (i = m / 2; i < m; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				gray[i][j] = gray[m - i - 1][j];  
			}
		}

	}
}

void Print_GreyCode() 
{
	cout << " Код Грея:" << endl << endl;

	for (i = 0; i < m; i++)
	{
		cout << " Y [" << i << "]  ";

		for (j = 0; j < n; j++)
		{
			cout << gray[i][j] << " ";
		}

		cout << "   { ";
		for (j = 0; j < n; j++)
		{
			if (gray[i][j] == 1)
				cout << mnojestvo[j] << " ";
		}
		cout << "}";

		if (i == m / 2 - 1)
		{
			cout << endl;
			for (int k = 0; k < 2 * n; k++)
			{
				cout << "--"; 
			}
		}
		cout << endl;
	}
	cout << endl << endl;
}

void Delete_Gray() 
{
	for (i = 0; i < m; i++)
		delete[]gray[i];
	delete[]gray;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Mnojestvo(mnojestvo, n);
	Quantity(m, n);

	Gray(m, n);
	Gray_Code(m, n);
	Print_GreyCode();

	Delete_Gray();

	system("pause");

	return 0;
}
