//
//  sortFunc.cpp
//  Lab13
//
//  Created by Sean Belingheri on 11/17/22.
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int*sortLowToHigh(int arr1[], int size1);
int main()
{
    int*arr=NULL;
    int size, i = 0;
    int*p;
    char ch;
    string temp;
    
    cout<<"Enter the array size: ";
    cin>>size;
    
    cout<<"Enter "<<size<<" values: ";
    arr=new int[size];
    do
    {
        cin>>arr[i];
        i++;
        ch = cin.get();
    } while(ch != '\n' && i < size);
    
    if(i == size && ch != '\n')
        getline(cin, temp);
    else if(i < size && ch == '\n')
    {
        for(i; i<size; i++)
            arr[i]=0;
    }
    
    p = sortLowToHigh(arr, size);
    
    cout<<"Original array: ";
    for(int b = 0; b < size; b++)
        cout<<arr[b]<<" ";
    cout<<endl<<"Sorted Array: ";
    for(int b = 0; b < size; b++)
        cout<<p[b]<<" ";
    cout<<endl;
    return 0;
}

int*sortLowToHigh(int arr1[], int size1)
{
    int*sub_arr=NULL;
    int indicator = 0;
    sub_arr=new int[size1];
    for(int i = 0; i < size1; i++)
        sub_arr[i] = arr1[i];
    
    do{
        for(int k = 0; k < size1 - 1; k++) //goes through each index in array and compares it with value to the left. If the first value is greater than the second value, this swaps them. This needs to run multiple times for the entire sequence, as this loop naturally pushes the biggest numbers to the back first.
            {
                if(sub_arr[k]>sub_arr[k+1])
                {
                    sub_arr[k+1] += sub_arr[k];
                    sub_arr[k] = sub_arr[k+1]-sub_arr[k];
                    sub_arr[k+1] -= sub_arr[k];
                }
            }
        indicator++; //the indicator makes it so the loop runs as many times as there are values in the array.
    }while(indicator < size1);
    
    return sub_arr;
}
