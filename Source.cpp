#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;
void MergeSort(int arr[], int, int);
void merge(int arr[], int, int , int );
int print(int arr[], int Size);

int main()
{
	srand((unsigned)time(0));
	int arr[30];
	for (int i = 0; i < 30; i++)
	{
		arr[i] = rand() % 30;
	}
	cout << "the array befor sorting  ";
	print(arr, 30);
	MergeSort(arr, 0, 30);
	cout << "the array befor sorting  ";
	print(arr, 30);



	return 0;
}
void MergeSort(int arr[], int l, int r)
{
	int mid = (l + r) / 2;
	if (l >= r)
		return;
	MergeSort(arr, l, mid);
	MergeSort(arr, mid + 1, r);
	merge(arr, l, mid, r);
}
void merge(int arr[], int l, int mid, int r)
{
	int n1 = (mid - l) + 1; // size of the leftsub array
	int n2 = r - mid;      // size of the rightsub array

	int L[n1], R[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	// Initial index of first subarray &  second subarray & merged subarray

	int i = 0, j = 0, k = l;

	// Merge the temp arrays back into arr[l..r]

	while (i <= n1 && j <= n2)
	{
		if (L[i] <= R[i])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of
   // L[], if there are any
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of
	// R[], if there are any
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}

}

int print(int arr[], int Size)
{
	for (int i = 0; i < Size; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
	return 0;
}