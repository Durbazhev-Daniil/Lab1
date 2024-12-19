#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;
int n;
double x, s;
double factorial(int n)
{
	if (n == 1)//условие выхода из рекурсии
		return 1;
	return factorial(n - 1) * n;
}
double rec(double x, int n)
{
	if (n == 0) //условие выхода из рекурсии
		return x;
	return (cos(n * x)) / factorial(n) + rec(x, n - 1);
}
int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Введите натуральное значение n и любое значение x через пробел ";
	cin >> n >> x;
	while (n < 1)
	{
		cout << "Вы ввели не натуральное значение n " << endl;
		cout << "Введите НОРМАЛЬНОЕ натуральное значение n и любое значение x через пробел ";
		cin >> n >> x;
	}
	s = rec(x, n - 1);
	cout << "S = " << s << endl;
	return 0;
}