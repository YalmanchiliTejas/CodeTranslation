#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m,i,p,k,j,q;
    cin>>n;
    int a[n];
    for(i=0; i<n; i++)
    {
       cin>>a[i];
    }k=0;m=0;
    sort(a,a+n);
    for(i=0; i<n; i++)
    {
        k+=a[i];
        //k%=1000000007;
    }
    //k=(k*k)%10000000007;
    for(i=0; i<n; i++)
    {
        k-=a[i];
        m+=((k%1000000007)*a[i])%1000000007;
        m%=1000000007;
    }
    cout<<m;
}

