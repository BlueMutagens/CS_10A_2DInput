//
//  input2D.cpp
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

int main()
{
    int**arr=NULL;
    int size_row, size_column, i = 0, g = 0;
    char ch;
    string temp;
    
    
    
    cout<<"Enter 2D array dimensions: ";
    cin>>size_row>>size_column;
    
    arr=new int*[size_row];
    for(int k = 0; k < size_row; k++)
        arr[k] = new int[size_column];
    
    cout<<"Enter array values:"<<endl;
    for(g; g < size_row; g++)
    {
        i = 0;
        do
        {
            cin>>arr[g][i];
            i++;
            ch = cin.get();
        } while(ch != '\n' && i < size_column);

        if(i == size_column && ch != '\n')
            getline(cin, temp);
        else if(i < size_column && ch == '\n')
        {
            for(i; i < size_column; i++)
                arr[g][i]=0;
        }
    }
    
    cout<<"Reversed Output:"<<endl;
    for(int y = size_row-1; y >= 0; y--)
    {
        for(int v = size_column-1; v >= 0; v--)
            cout<<arr[y][v]<<" ";
        cout<<endl;
    }
    return 0;
}
