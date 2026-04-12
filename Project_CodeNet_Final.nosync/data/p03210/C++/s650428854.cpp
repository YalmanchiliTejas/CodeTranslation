#include <stdio.h>
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<complex>
#include<vector>
#include <climits>

using namespace std;


int main(void)
{
    int x;
    scanf("%d",&x);

    if(x==3 or x==5 or x==7)
    {
        cout << "YES" << "\n";
    }
    else
    {
        cout << "NO" << "\n";
    }

    return 0;
}