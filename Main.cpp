#include<iostream>
using namespace std;

class MyArray
{
private:
	int* arr;
	int N;

public:
	MyArray()
	{
		N = 1;
		arr = new int[N];
		for (int i = 0; i < N; i++)
			arr[i] = 0;
	}
	MyArray(int n)
	{
		N = n;
		arr = new int[N];
	}

	MyArray(const MyArray& source)
	{
		N = source.N;
		arr = new int[N];
		for (int i = 0; i < N; i++)
			arr[i] = source.arr[i];
	}

	~MyArray()
	{
		delete[] arr;
	}

	int getSize()
	{
		return N;
	}

	void printMyArray()
	{
		for (int i = 0; i < N; i++)
			cout << arr[i] << "  ";
		cout << endl;
	}

	void setElements()
	{
		for (int i = 0; i < N; i++)
			cin >> arr[i];
	}

	void sortMyArray()
	{
		int temp;
		for (int i = 0; i < N; i++)
		{
			temp = arr[i];
			for (int j = i; j < N; j++)
				if (temp > arr[j])
				{
					temp = arr[j]; 
					arr[j] = arr[i];
					arr[i] = temp;
				}
		}
	}

	int maxElement()
	{
		sortMyArray();
		return arr[N - 1];
	}

	int minElement()
	{
		sortMyArray();
		return arr[0];
	}
};

int main()
{
	setlocale(LC_CTYPE, "rus");
	int n;
	cout << "N: ";
	cin >> n;
	MyArray array(n);
	cout << "Set " << n << " elements: ";
	array.setElements();
	cout << "Array: ";
	array.printMyArray();
	array.sortMyArray();
	cout << "Sorted array: ";
	array.printMyArray();
	cout << "Max = " << array.maxElement() << " Min = " << array.minElement() << endl;

	return 0;
}