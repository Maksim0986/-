// Ряды.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <locale>


using namespace std;

double sumN(double, int, double&);
double sumE(double, double, int&);

int main()
{
	while ("") {
		setlocale(LC_ALL, "rus");
		cout << "1.Открыть решение задачи" << endl;
		cout << "2.Выйти из программы" << endl;
		
		int m = 0;
		cin >> m;
		
		switch (m) {
		case 1:
			
			cout << "Вычисление значений функции 1/(1+x)^3\n\n";
			double x;
			double func;
			double sum;
			int n;
			cout << "Задание 1" << endl;
			cout << "Введите значение аргумента > ";
			cin >> x;
			for (; ;) {
				switch (x > 1 || x < -1) {
				case 1:
					cout << "Неверно введен аргумент, аргумент должен находится в интервале (-1;1), введите еще раз" << endl;
					cin >> x;
					break;
				default:
					goto all;
					
					break;
					
				}
			}
			

		   all:



			cout << "Задайте число слагаемых > ";
			cin >> n;
			func = 1 / pow(1 + x, 3);
			double last;
			sum = sumN(x, n, last);
			cout << "Точное значение функции равно " << func << endl;
			cout << "Частичная сумма ряда равна " << sum << endl;
			cout << "Абсолютная погрешность равна " << fabs(func - sum) << endl;
			cout << "Последнее слагаемое равно " << last << endl;

			cout << "\nЗадание 2" << endl;
			double E;
			cout << "Введите значение аргумента > ";
			cin >> x;
			
			for (; ;) {
				switch (x > 1 || x < -1) {
				case 1:
					cout << "Неверно введен аргумент, аргумент должен находится в интервале (-1;1), введите еще раз" << endl;
					cin >> x;
					break;
				default:
					goto mnc;

					break;

				}
			}


		    mnc:

			cout << "Задайте точность вычислений > ";
			cin >> E;
			func = 1 / pow(1 + x, 3);
			sum = sumE(x, E, n);
			cout << "Точное значение функции равно " << func << endl;
			cout << "Частичная сумма ряда c заданной точностью равна " << sum << endl;
			cout << "Учтено " << n << " членов ряда" << endl;
			sum = sumE(x, E / 10, n);
			cout << "Частичная сумма ряда c точностью, большей в 10 раз, равна " << sum << endl;
			cout << "Учтено " << n << " членов ряда" << endl;
			_getch();
			break;


		case 2:
			cout << "Выход из программы" << endl;
			_getch;
			return 0;
			break;

		default:
			cout << "Вы ввели неверный пункт меню." << endl;
			_getch;
		}



 	}
	
	
	
	
	
}

double sumN(double x, int n, double& last)
{
	
	last = x;
	double sum = last;
	for (int i = 2; i < n; ++i)
	{
		double r; 
		r = -x * ((i + 1) / (i - 1));
		last *= r;
		sum += last;
	}
	return sum;
}

double sumE(double x, double E, int& n)
{
	double last;
	last = x;
	double sum = last;
	for (n = 2; fabs(last) > E; ++n)
	{
		double r; 
		r = -x * ((n + 1) / (n - 1));
		last *= r;
		sum += last;
	}
	return sum;
}
