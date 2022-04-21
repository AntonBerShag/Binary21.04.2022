#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#define chui(s) (unsigned int)(s)

int tobinary(char num);
string tobinary(short num);
string tobinary(int num);
int tohex(string binStr);
void fillArr(int arr[], int length, int min, int max);

int main() {
	setlocale(LC_ALL, "Russian");

	// битовые операции
	/*unsigned int n = 5 << 3;
	cout << "5 << 3 = " << n << endl;

	n = 35 >> 3;
	cout << "35 >> 3 = " << n << endl;

	unsigned char s = 100;
	unsigned char ds = ~s;
	cout << "~" << chui(s) << " = " << chui(ds) << endl;

	s = 154;
	ds = 171;
	cout << chui(s) << " & " << chui(ds) << " = " << chui(s & ds) << endl;

	s = 152;
	ds = 43;
	cout << chui(s) << " | " << chui(ds) << " = " << chui(s | ds) << endl;

	s = 152;
	ds = 43;
	cout << chui(s) << " ^ " << chui(ds) << " = " << chui(s ^ ds) << endl;*/

	//Задача 1
	/*cout << "Задача 1\n";
	char z11 = 70;         //1000110
	short z12 = 15000;     //0011101010011000
	int z13 = 123124123;   //00000111010101101011100110011011
	cout << "char " << chui(z11) << " = " << tobinary(z11) << endl;
	cout << "short " << z12 << " = " << tobinary(z12) << endl;
	cout << "int " << z13 << " = " << tobinary(z13) << endl;*/

	//Задача 2
	/*cout << "Задача 2\nВведите двоичный код:\n";
	string binStr;
	cin >> binStr;

	try {
		cout << tohex(binStr) << "\n\n";
	}
	catch (const invalid_argument& ex) {
		cout << "Ошибка: " << ex.what() << endl;
	}*/

	//Задача 4
	cout << "Задача 4\nВведиет длину массива: ";
	int size;
	cin >> size;
	int* dArr = new int[size];
	cout << "Введите начало и конец диапазона:\n";
	int a, b;
	cin >> a >> b;

	try {
		fillArr(dArr, size, a, b);
		cout << "Изначальный массив\n[";
		for (int i = 0; i < size; i++)
			cout << dArr[i] << " ,";
		cout << "\b\b]\n";
	}
	catch (const range_error& ex) {
		cout << "Ошибка диапазона: " << ex.what() << endl;
	}
	catch (const underflow_error& ex) {
		cout << "Ошибка длины: " << ex.what() << endl;
	}

	return 0;
}

//Задача 4
void fillArr(int arr[], int length, int min, int max) {
	if (min > max)
		throw range_error("min more then max");
	if (length <= 0)
		throw underflow_error("not positive length");
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (max - min) - min;
}

//Задача 2
int tohex(string binStr) {
	for (int i = 0; i < binStr.length(); i++)
		if (binStr[i] != '0' && binStr[i] != '1')
			throw invalid_argument("not ninary");
	int res = 0;
	for (int i = binStr.length() - 1; i >= 0; i--) 
		res += (int)(binStr[binStr.length() - i - 1] - '0') * pow(2, i);
	return res;
}

//Задача 1
string tobinary(int num) {
	string res;//хранит в себе двоичное число
	for (int i = 31; i >= 0; i--)
		res += to_string(num >> i & 1);
	return res;
}
string tobinary(short num) {
	string res;//хранит в себе двоичное число
	for (int i = 15; i >= 0; i--)
		res += to_string(num >> i & 1);
	return res;
}
int tobinary(char num) {
	int res = 0;//хранит в себе двоичное число
	for (int i = 7; i >= 0; i--)
		res += (num >> i & 1) * pow(10, i);
	return res;
}