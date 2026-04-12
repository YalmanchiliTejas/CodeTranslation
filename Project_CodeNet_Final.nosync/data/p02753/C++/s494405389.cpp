/**
 *    author:  nasimnoob
**/

#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

typedef long long                       ll;
typedef unsigned long long              ull;
typedef long double                     ld;


#define      PI                         3.141592654


int main()
{
    string a,b,c;
    int n,l=0,i,k;
    cin>>a;
    k = a.size();
    for(i=0; i<k; i++)
    {
        if(a[i]==a[i+1])
            l++;
    }
    if(k-1==l)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
    }
    return 0;
}


