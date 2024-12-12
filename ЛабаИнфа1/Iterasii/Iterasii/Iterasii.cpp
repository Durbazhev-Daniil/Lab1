#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

const double epsilon = 0.0001;
const double e = 2.7182818;
double a, b, x0, x1;

double f(double x)
{
	return (0.1 * (pow(x, 2)) - x * log(x));//вычисление значения основной функции
}

double phy(double x)
{
	return pow(e, 0.1 * x);//вычисление значения дополнительной функции x = phy(x)
}

double pr_phy(double x)
{
	return pow(e, 0.1 * x) * 0.1;//вычисление значения производной от дополнительной функции
}

int main()
{
	setlocale(LC_ALL, "Russian");

	a = 1;// левый конец отрезка
	b = 2;// правый конец отрезка

	if (abs(pr_phy(a)) < 1 || abs(pr_phy(b)) < 1) // проверка на сходимость
	{
		x0 = b;
		x1 = phy(x0);

		cout << x0 << endl;
		cout << x1 << endl;

		int k = 2;//счётчик

		while (abs(x1 - x0) > epsilon)
		{
			x0 = x1;
			x1 = phy(x0);

			cout << x1 << endl;

			k = k + 1;
		}
		cout << "Корень: " << x1 << endl;
		cout << "Количество шагов: " << k << endl;
	}
	else
		cout << "Корня не существует";
	return 0;
}