#include <cstdlib>
#include <iostream>
using namespace std; 
  
  
void printArray(int a[], int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << a[i] << " "; 
	}
	cout << endl;
}
  
// Standard Lomuto partition function 
int partition(int arr[], int low, int high) 
{ 
    int pivot = arr[high]; 
    int i = (low - 1); 
    for (int j = low; j <= high - 1; j++) { 
        if (arr[j] <= pivot) { 
            i++; 
            cout << "Swapping " << arr[i] << " and " << arr[j] << endl; 
            swap(arr[i], arr[j]);
            printArray(arr,7);
        } 
    } 
    cout << "Swapping " << arr[i+1] << " and " << arr[high] << endl; 
    printArray(arr,7);
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 
  
// Implementation of QuickSelect 
int kthSmallest(int a[], int left, int right, int k) 
{ 
	int size = right + 1;
	cout << "Original Array: ";
	printArray(a, size); 
    while (left <= right) { 
		
		cout << "---------------------------------------------------" << endl; 
		cout << "Left: " << left << " Right: " << right << endl;
		
        // Partition a[left..right] around a pivot 
        // and find the position of the pivot 
        int pivotIndex = partition(a, left, right); 
		
		
		cout << "PivotIndex: " << pivotIndex << endl;
		cout << "Array after partition: ";
		printArray(a, size);
        // If pivot itself is the k-th smallest element 
        if (pivotIndex == k - 1) 
            return a[pivotIndex]; 
  
        // If there are more than k-1 elements on 
        // left of pivot, then k-th smallest must be 
        // on left side. 
        else if (pivotIndex > k - 1) 
            right = pivotIndex - 1; 
  
        // Else k-th smallest is on right side. 
        else
            left = pivotIndex + 1; 
    } 
    return -1; 
} 
  
// Driver program to test above methods 
int main() 
{ 
    int arr[] = { 10, 5, 4, 11, 8, 6, 26 }; 
    //int arr[] = {0,1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 5; 
    int ans = kthSmallest(arr, 0, n - 1, k);
    cout << "K-th smallest element is " << ans << endl; 
    return 0; 
} 