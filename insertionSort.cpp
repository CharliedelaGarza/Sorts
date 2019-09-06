

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUBBLE 1000

using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[BUBBLE];
    clock_t t;
    int i, num;
    for (i = 0; i < BUBBLE; i ++)
    {
        num = rand() % BUBBLE + 1;
        arr[i] = num;
    }
    t = clock();
    insertionSort(arr, BUBBLE);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("%f ms \n", time_taken*1000);
    //printArray(arr, BUBBLE);
    
    return 0;
}


