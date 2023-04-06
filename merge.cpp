#include <iostream>
using namespace std;

void Merge(int arr[], int mid, int low, int high)
{
    int i, j, k, arr2[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high){
        if (arr[i] < arr[j]){
            arr2[k] = arr[i];
            i++;
            k++;
        }
        else{
            arr2[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid){
        arr2[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high){
        arr2[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i <= high; i++){
        arr[i] = arr2[i];
    }
}

void MergeSort(int arr[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        Merge(arr, mid, low, high);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    MergeSort(arr,0,n-1);   
    cout << "Sorted array: ";
    for (int i=0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
