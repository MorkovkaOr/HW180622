#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define delimiter "\n----------------------------------------------------\n"

void FillRand(int arr[], const int n);
void FillRand(double arr[], const int n);
void FillRand(char arr[], const int n);
template<typename T>
void Print(T arr[], const int n);
template<typename T>
void push_back(T*& arr, int& n, T value);
template<typename T>
void push_front(T*& arr, int& n, T value);
template<typename T>
void insert(T*& arr, int& n, T value, int position);
template<typename T>
void pop_back(T*& arr, int& n);
template<typename T>
void pop_front(T*& arr, int& n);
template<typename T>
void erase(T*& arr, int& n, int position);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "¬ведите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	cout << "»сходный массив:\n";
	Print(arr, n);

	int value;
	int position;
	cout << "¬ведите добавл€емое значение: "; cin >> value;
	push_back(arr, n, value);
	Print(arr, n);

	cout << "¬ведите добавл€емое значение: "; cin >> value;
	push_front(arr, n, value);
	Print(arr, n);

	cout << "¬ведите добавл€емое значение: "; cin >> value;
	cout << "¬ведите индекс элемента: "; cin >> position;
	insert(arr, n, value, position);
	Print(arr, n);

	pop_back(arr, n);
	Print(arr, n);

	pop_front(arr, n);
	Print(arr, n);

	cout << "¬ведите индекс элемента: "; cin >> position;
	erase(arr, n, position);
	Print(arr, n);

	delete[] arr;

	cout << delimiter << endl;

	cout << "¬ведите размер массива: "; cin >> n;
	double* arrd = new double[n];

	FillRand(arrd, n);
	cout << "»сходный массив:\n";
	Print(arrd, n);
	double valued;
	cout << "¬ведите добавл€емое значение: "; cin >> valued;
	push_back(arrd, n, valued);
	Print(arrd, n);

	cout << "¬ведите добавл€емое значение: "; cin >> valued;
	push_front(arrd, n, valued);
	Print(arrd, n);

	cout << "¬ведите добавл€емое значение: "; cin >> valued;
	cout << "¬ведите индекс элемента: "; cin >> position;
	insert(arrd, n, valued, position);
	Print(arrd, n);

	pop_back(arrd, n);
	Print(arrd, n);

	pop_front(arrd, n);
	Print(arrd, n);

	cout << "¬ведите индекс элемента: "; cin >> position;
	erase(arrd, n, position);
	Print(arrd, n);

	delete[] arrd;

	cout << delimiter << endl;

	cout << "¬ведите размер массива: "; cin >> n;
	char* arrc = new char[n];

	char valuec;

	FillRand(arrc, n);
	cout << "»сходный массив:\n";
	Print(arrc, n);

	cout << "¬ведите добавл€емое значение: "; cin >> valuec;
	push_back(arrc, n, valuec);
	Print(arrc, n);

	cout << "¬ведите добавл€емое значение: "; cin >> valuec;
	push_front(arrc, n, valuec);
	Print(arrc, n);

	cout << "¬ведите добавл€емое значение: "; cin >> valuec;
	cout << "¬ведите индекс элемента: "; cin >> position;
	insert(arrc, n, valuec, position);
	Print(arrc, n);

	pop_back(arrc, n);
	Print(arrc, n);

	pop_front(arrc, n);
	Print(arrc, n);

	cout << "¬ведите индекс элемента: "; cin >> position;
	erase(arrc, n, position);
	Print(arrc, n);

	delete[] arrc;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		
		arr[i] = rand() % 100;
	}
}
void FillRand(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		
		arr[i] = (double)(rand() % 100)/10;
	}
}
void FillRand(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		
		arr[i] = rand();
	}
}
template<typename T>
void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template<typename T>
void push_back(T*& arr, int& n,T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
}
template<typename T>
void push_front(T*& arr, int& n, T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
		buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
}
template<typename T>
void insert(T*& arr, int& n, T value, int position)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	for (int i = 0; i < n-position; i++)
	{
		arr[n - i] = arr[n - 1 - i];
	}
	arr[position] = value;
	n++;
}
template<typename T>
void pop_back(T*& arr, int& n)
{
	T* buffer = new T[n - 1];
	for (int i = 0; i < n-1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
}
template<typename T>
void pop_front(T*& arr, int& n)
{
	T* buffer = new T[n - 1];
	for (int i = 1; i < n; i++)
	{
		buffer[i-1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
}
template<typename T>
void erase(T*& arr, int& n, int position)
{
	T* buffer = new T[n - 1];
	for (int i = 0,b=0; i < n-1; i++,b++)
	{
		if (i == position)
		{
			b++;
		}
		buffer[i] = arr[b];
	}
	delete[] arr;
	arr = buffer;
	n--;
}