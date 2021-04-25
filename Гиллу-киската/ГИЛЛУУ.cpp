#include <iostream>
#include <math.h>
#include <time.h>
#include <random>
#include <vector>
#include <windows.h>
/*
����
1)�������� p, q
2) V>=3 ��������� ��� 
*/
using namespace std;

bool isPrime(int* n)
{
	// ���� n > 1
	if (*n > 1)
	{
		// � ����� ���������� ����� �� 2 �� n - 1
		for (int i = 2; i < *n; i++)
		{
			if (*n % i == 0)
			{// ���� n ������� ��� ������� �� i - ���������� false (����� �� �������)
				return false;
				break;
			}
		}


		// ���� ��������� ����� �� ������� ���������, �� ���������� true (����� �������) - �������� ��������
		return true;
	}
	else // ����� ���������� false (����� �� �������)
		return false;
}

void Gen_prost(int* a)
{
	srand(time(NULL));
	*a = 1 + rand() % 700;
	while (isPrime(a) == false)
	{
		*a = 1 + rand() % 20;
	}

}

void showarr(vector <int>& a) // ������� ������ 
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

// ��������� �������� ����� V

void V_gen(int* a)
{
	srand(time(NULL));
	*a = 1 + rand() % 700;
	while (isPrime(a) == false)
	{
		*a = 1 + rand() % 20;
	}
}

// ������ �� �� �

void f_n(int& p, int& q)
{
	int f;
	f = (p - 1) * (q - 1);
	cout << " ���������� f(n) =  " << f << endl;

}

// ������� ������

int phi(int& n)
{
	long long result = n;
	for (int i = 2; (i * i) <= n; ++i)
	{
		if (n % i == 0)
		{
			while (n % i == 0)
			{
				n /= i;
				result -= result / i;
			}
		}
		if (n > 1)
		{
			result -= result / n;
		}
	}
	return result;
}



// �������� S �������� �������

void S_v(int& v, int& f, int& n)
{
	int s;
	s = pow(v, (-1));
	s %=(phi(n));
	cout << " s = " << s << endl;
}




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

	

	int v;
	V_gen(&v);
	cout << "V = " << v << endl;
	Sleep(1000);
	

	int f = 0;
	f_n(p, q);

	phi(n);
	S_v(v, f, n);

	system("pause");
/*	int s;
	S_gen(&n, &s);
	int r;
	S_gen(&n, &r);
	*/
}
