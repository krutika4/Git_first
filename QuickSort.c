/* C implementation of QuickSort Algorithm*/
#include<stdio.h> 

// Function to swap two elements 
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

//Last element of the array is taken as pivot
int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high- 1; j++) 
	{ 
		if (arr[j] <= pivot) 
		{ 
			i++; 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

//low: starting index of the array
//high: last index of the array
void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		int index = partition(arr, low, high); //partition index
		quickSort(arr, low, index - 1); 
		quickSort(arr, index + 1, high); 
	} 
} 

//Function to print the array
void printArray(int arr[], int size) 
{ 
	for (int i=0; i<size; i++) 
		printf("%d ", arr[i]); 
} 

// Main function 
int main() 
{ 
	int arr[] = {100, 34, 342, 23, 233, 65, 76, 45}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printf("Array before sorting: ");
	printArray(arr, n);
	quickSort(arr, 0, n-1); 
	printf("\nSorted array: "); 
	printArray(arr, n); 
	return 0; 
} 
 

/*Output:
Array before sorting: 100, 34, 342, 23, 233, 65, 76, 45
Sorted array: 23, 34, 45, 65, 76, 100, 233, 342