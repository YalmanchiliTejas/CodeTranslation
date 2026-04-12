#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//long long int h[200000],d[200000];
//int i,n,m,j,k,l=0;
long long int a[200000];
int main()
{
    long long  int i,n,m,j,k=0,l;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    while(k!=-1)
    {
        if(a[n]==n-1)
        {
            printf("%lld",k);
            break;
        }
        l=a[n]/n;
        a[n]%=n;
        for(i=1;i<n;i++)
        {
            a[i]+=l;
        }
        k+=l;
        sort(a+1,a+1+n);
    }
    return 0;
}
