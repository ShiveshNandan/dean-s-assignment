#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int divide(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (arr[i] <= pivot){
            i++;
        }

        while (arr[j] > pivot){
            j--;
        }

        if (i < j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
void QuickSort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = divide(arr, low, high); 
        QuickSort(arr, low, mid - 1);  
        QuickSort(arr, mid + 1, high);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    QuickSort(arr,0,n-1); 
    cout << "Sorted array: ";
    for (int i=0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
