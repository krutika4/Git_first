// C++ implementation of QuickSort Algorithm

#include <iostream> 
#include <vector>
using namespace std;

//Last element of the array is taken as pivot
int partition (vector<int>& arr, int low, int high) 
{ 
	int pivot = arr[high]; 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high- 1; j++) 
	{ 
		if (arr[j] <= pivot) 
		{ 
			i++; 
			swap(arr[i], arr[j]); 
		} 
	} 
	swap(arr[i + 1], arr[high]); 
	return (i + 1); 
} 

//low: starting index of the array
//high: last index of the array
void quickSort(vector<int>& arr, int low, int high) 
{ 
	if (low < high) 
	{ 
		int index = partition(arr, low, high); //partition index
		quickSort(arr, low, index - 1); 
		quickSort(arr, index + 1, high); 
	} 
} 

//Function to print the array
void printArray(vector<int>& arr, int size) 
{ 
	for(int i=0; i<size; i++) 
		cout<<arr[i]<<" "; 
} 

// Main function 
int main() 
{ 
	vector<int> arr = {100, 34, 342, 23, 233, 65, 76, 45}; 
	cout<<"Array before sorting: ";
	printArray(arr, arr.size());
	quickSort(arr, 0, arr.size()-1); 
	cout<<"\nSorted array: "; 
	printArray(arr, arr.size()); 
	return 0; 
} 
 

/*Output:
Array before sorting: 100, 34, 342, 23, 233, 65, 76, 45
Sorted array: 23, 34, 45, 65, 76, 100, 233, 342