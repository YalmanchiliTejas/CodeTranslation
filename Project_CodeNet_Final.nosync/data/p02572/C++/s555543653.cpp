#include<iostream>
#define m 1000000007
using namespace std;
int main()
{
    long long n,i,j;
    cin>>n;
    long long a[n],c[n],sum=0;
    for(i=0;i<n;i++)
        cin>>a[i];
    c[0]=a[0];
    for(i=1;i<n;i++)
        c[i]=(c[i-1]+a[i])%m;
    for(i=n-1;i>0;i--)
    {
        sum=(sum+(c[i-1]*a[i])%m)%m;
    }
    cout<<sum<<endl;
}
