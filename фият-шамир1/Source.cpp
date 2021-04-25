#include <iostream>
#include <math.h>
#include <time.h>
#include <random>
#include <vector>
#include <windows.h>

using namespace std;

/*
1. числа p и q должны быть простыми и сгенерированы рандоно
2. вычисляем n = p* q ( по модулю)
3.сгенерировать S взаимно протое с n , где s лежит в промежутке от 1 до н-1
4. V=s*s (mod n)
5. сгенерировать  r взаимно протое с n , где r лежит в промежутке от  до н-1
6. x=r*r (mod n)
7. сгенерировать е или 0 или 1    если 0 то возвратить значение r, если 1 то возвратить y=r*s(mod n)

проверка


8. если e=0 то y^2=r^2 вывод - подтверждено
иначе
е=1
x*V (mod n) .... подтверждено
*/

bool isPrime(int* n)
{
    // если n > 1
    if (*n > 1)
    {
        // в цикле перебираем числа от 2 до n - 1
        for (int i = 2; i < *n; i++)
        {
            if (*n % i == 0)
            {// если n делится без остатка на i - возвращаем false (число не простое)
                return false;
                break;
            }
        }


        // если программа дошла до данного оператора, то возвращаем true (число простое) - проверка пройдена
        return true;
    }
    else // иначе возвращаем false (число не простое)
        return false;
}

void Gen_prost(int* a)
{
	srand(time(NULL));
    *a = 1 + rand() % 700;
	while (isPrime(a) == false)
	{
		*a = 1 + rand() % 700;
	}

}

void showarr(vector <int>& a) // создаем массив 
{
	// cout << "[";
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << "    ";
	}
	// cout << "]";
}

void S_gen(int* n, int* s)
{

	*s = 1 + rand() % (*n - 1);

}
// тененбаун



void main()
{
	setlocale(LC_ALL, "ru");
	int p;
	int q;
	Gen_prost(&p);
	cout << "p = " << p << endl;
	Sleep(1000);
	Gen_prost(&q);
	cout << "q = " << q << endl << endl;

    int n = abs(p * q);
	cout << "n = " << n << endl << endl;

	int s;
	S_gen(&n, &s);
	int r;
	S_gen(&n, &r);

	int V;
	V = (s * s) % n;
	cout << "Открытый ключ V =  " << V << endl;

	int x;
	x = (r * r) % n;
	cout << "Открытый ключ x =  " << x << endl;

	cout << "случайно генерируем бит e 0 или 1" << endl;
	srand(time(NULL));
	int e;
	e = rand() % 2;
	cout << "сгенерированный бит " << e;
	cout << endl;

	// Если B отправил e=0, то A возвращает y
	if (e == 0)
	{
		cout << r << "  Подтверждено" << endl;
	}
	if (e == 1)
	{
		int y;
		y = (r * s) % n;
		cout << y;
		if (((x * V) % n) == (y * y))
		{
			cout << "подтверждено" << endl;
		}
		else
		{
			cout << " не подтверждено" << endl;
		}
	}
}
	
