#include <iostream>
#include <math.h>
#include <time.h>
#include <random>
#include <vector>
#include <windows.h>

using namespace std;

/*
1. ����� p � q ������ ���� �������� � ������������� �������
2. ��������� n = p* q ( �� ������)
3.������������� S ������� ������ � n , ��� s ����� � ���������� �� 1 �� �-1
4. V=s*s (mod n)
5. �������������  r ������� ������ � n , ��� r ����� � ���������� ��  �� �-1
6. x=r*r (mod n)
7. ������������� � ��� 0 ��� 1    ���� 0 �� ���������� �������� r, ���� 1 �� ���������� y=r*s(mod n)

��������


8. ���� e=0 �� y^2=r^2 ����� - ������������
�����
�=1
x*V (mod n) .... ������������
*/

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
		*a = 1 + rand() % 700;
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
// ���������



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
	cout << "�������� ���� V =  " << V << endl;

	int x;
	x = (r * r) % n;
	cout << "�������� ���� x =  " << x << endl;

	cout << "�������� ���������� ��� e 0 ��� 1" << endl;
	srand(time(NULL));
	int e;
	e = rand() % 2;
	cout << "��������������� ��� " << e;
	cout << endl;

	// ���� B �������� e=0, �� A ���������� y
	if (e == 0)
	{
		cout << r << "  ������������" << endl;
	}
	if (e == 1)
	{
		int y;
		y = (r * s) % n;
		cout << y;
		if (((x * V) % n) == (y * y))
		{
			cout << "������������" << endl;
		}
		else
		{
			cout << " �� ������������" << endl;
		}
	}
}
	
