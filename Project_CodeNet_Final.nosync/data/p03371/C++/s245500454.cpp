#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    long long int a=0;
    long long int e=0;
    long long int n=0;
    long long int k=0;
    long long int m=0;
    long long int j=0;
    long long int c=0;
    long long int d=0;
    long long int b=0;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>n;
    cin>>m;
    e=min(n,m);
    j=2*c*max(n,m);
    k=e*2*c;
    if(n-m>0)
    {
        k=k+(n-m)*a;
    }
    else
    {
        k=k+(m-n)*b;
    }
    e=a*n+b*m;
    if(k<e && k<j)
    {
        cout<<k;
    }
    else if(e<k && e<j)
    {
        cout<<e;
    }
    else
    {
        cout<<j;
    }
}