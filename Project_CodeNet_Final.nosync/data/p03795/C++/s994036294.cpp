#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int x,n,y=200;
    scanf("%d",&n);

    if(n>=15)
        x=(800*n)-(((n-(n%15))/15)*y);
    else
        x=800*n;
    printf("%d",x);
}
