#include <iostream>
#include <windows.h>
#include <conio.h>
#include <math.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	long double e, x, ln, poga, pogo; // e - эпсилон, ln - точное значение, poga - абсолютная погрешность, pogo - относительная погрешность
	int i = 3; // i - общий член для продолжения последовательности

	cout << "Расчитываем приближённое значение ln((1 + x) / (1 - x)) с точностью E" << endl;
	cout << "Введите точность вычислений E: ";
	cin >> e;
	cout << "Введите x: ";
	cin >> x;
	while (x < 0 || x >= 1)
	{
		cout << "Попробуйте ещё раз!" << endl;
		cout << "Введите x: ";
		cin >> x;
	}

	long double elem = 2 * x, s = 2 * x;
	//cout << "elem0 = " << elem << endl;

	while (fabs(elem) >= e)
	{
		elem = 2 * pow(x, i) / i;
		//cout << "elem" << i - 1 << " = " << elem << endl;
		s += elem;
		//cout << "s = " << s << endl;
		i += 2;
	}

	ln = log((1 + x) / (1 - x));
	poga = ln - s;
	pogo = poga / ln * 100;
	cout << "Приближённое значение = " << s << endl;
	cout << "Точное значение = " << ln << endl;
	cout << "Абсолютная погрешность = " << poga << endl;
	cout << "Относительная погрешность = " << pogo << '%' << endl;

	_getch();
	return 0;
}