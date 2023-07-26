//
//  main.cpp
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
    int size_row, size_column, i = 0, g = 0, coor = 1;
    char ch;
    string temp;
    
    
    
    cout<<"Enter dimensions (row, columns): ";
    cin>>size_row>>size_column;
    
    arr=new int*[size_row];
    for(int k = 0; k < size_row; k++)
        arr[k] = new int[size_column];
    
    for(g; g < size_row; g++, coor++)
    {
        cout<<"Enter coordinate "<<coor<<": ";
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
    
    cout<<"Distance is "<<setprecision(2)<<fixed<<sqrt( pow(arr[1][0]-arr[0][0], 2) + pow(arr[1][1]-arr[0][1], 2) )<<endl;
    return 0;
}
// cout << sizeof(arr)/sizeof(arr[0][0]) << endl;
