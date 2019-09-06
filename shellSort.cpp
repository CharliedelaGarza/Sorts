#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#define BUBBLE 1000000
using namespace std;

int shellSort(int arr[], int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {

        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            
            arr[j] = temp;
        }
    }
    return 0;
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
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
    shellSort(arr, BUBBLE);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("%f s \n", time_taken*1000);
    
    //printArray(arr, BUBBLE);
    
    return 0;
}

