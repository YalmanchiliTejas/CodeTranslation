#include <stdio.h>
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int N;
    cin >>N;
        int x;
        int y ;
     x = N *800 ;
     y = ((N/15)*200) ;
    if ( N>15)
    cout <<x-y ;
     if (N==15)
    cout << x -200 ;
    if (N< 15)  
cout << x ;
    return 0;
}