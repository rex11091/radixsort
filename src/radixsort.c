#include "radixsort.h"
#include "stdio.h"
#include "stdlib.h"


int getHighest(int arr[], int n) {
    int high = arr[0];
    int i;
    for (i = 1; i < n; i++)
        if (arr[i] > high)
            high = arr[i];
    return high;
}


void rearrangeSort(int arr[],int n, int divider)
{
    int output[n]; // to output array after sort
    int i, count[10] = { 0 };

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
    count[(arr[i] / divider) % 10]++;
    //for (i = 0; i < n; i++)
    //    printf("%d ", count[i]);

    for (i = 1; i < 10; i++)
    count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--){
    output[count[(arr[i] / divider) % 10] - 1] = arr[i];
    count[(arr[i] / divider) % 10]--;
    }

for (i = 0; i < n; i++)
    arr[i] = output[i];
}

void radixsort(int arr[], int n) {
    int m = getHighest(arr, n);
    int divider;

    for(divider=1 ; m/divider >0 ; divider *=10)
      rearrangeSort(arr, n, divider);

}
//print the array
void print(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
