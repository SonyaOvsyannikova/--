

#include <iostream>
#include <math.h>
#include <vector>
#include <time.h>
using namespace std;

 void showarr(vector <int>& a) // создаем массив 
 {
	// cout << "[";
	 for (int i = 0; i < a.size(); i++)
	 {
		 cout << a[i] << "    ";
	 }
	// cout << "]";
 }
 bool isPrime(int lll)
 {
	 for (int i = 2; i < lll; i++) {
		 if (lll % i == 0)
			 return false;
	 }
 }

 void func()
 {
	 int n;
	 int lll = 0;
	 srand(time(NULL));
	 int p = 1 + rand() % 700; //первый пункт
	 int q = 1 + rand() % 700;
	 n = p * q;
	 cout << "модуль n число = " << abs(n) << endl;
	 while (isPrime(p) == false)
	 {
		 p = 1 + rand() % 700;

		 if (isPrime(p) == true)
		 {
			 cout << p << "verno " << endl;
			 break;
		 }
	 }
	 while (isPrime(q) == false)
	 {
		 q = 1 + rand() % 700;

		 if (isPrime(q) == true)
		 {
			 cout << q << "verno " << endl;
			 break;
		 }
	 }
	 vector<int> arr;
	 vector<int> arr1;
	 for (int i = 1; i < (n - 1); i++) // поиск на какие значения n делится без остатка число s наход в промежутке от 1 до n-1
	 {                                       // заносим в вектор
		 if (n % i == 0)
		 {
			 arr.push_back(i);
		 }
	 }
	 for (int i = 2; i < (n - 1); i++)    // заносим в вектор arr1 все числа которые не делятся ни на один элемент arr (нет общих длителей с n )
	 {
		 for (int j = 1; j < arr.size() - 1; j++)
		 {
			 if (i % arr[j] != 0)
			 {
				 if (j == arr.size() - 2)
				 {
					 arr1.push_back(i);
				 }
				 else
					 break;
			 }
		 }
	 }
	 cout << " все числа на которые n делится без остатка " << endl;
	 showarr(arr);
	 cout << endl;
	 cout << " все взаимнопростые с n числа " << endl;
	 showarr(arr1);
	 cout << endl;

	 int s;
	 cout << "выберете чисо из представленных чисел выше" << endl;
	 cin >> s;
	 int V;
	 V = (s * s) % n;
	 cout << "Открытый ключ V =  " << V << endl;

	 // случайно выбираем бит e 0 or 1
	 cout << "случайно генерируем бит e 0 или 1" << endl;
	 srand(time(NULL));
	 int e;
	 e = 1 + rand() % 1 + 0;
	 cout << "сгенерированный бит " << e;
	 cout << endl;
	 int r;
	 cout << "Выберите r из чисел, из которых вы выбирали ранее" << endl;
	 cin >> r;
	 int x = (r * r) % n;
	 cout << "одно из передаваемых сообщений  " << x << endl;
	 // Если B отправил e=0, то A возвращает y
	 if (e == 0)
	 {
		 cout << r;
	 }
	 if (e = 1)
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

int main()
{
	setlocale(LC_ALL, "ru");

	func();
	
	
	
}

