#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[50],b[50];
ll f(ll n,ll x)
{
    return n>0?x<=a[n-1]+1?f(n-1,x-1):b[n-1]+1+f(n-1,x-2-a[n-1]):x<=0?0:1;
}

int main()
{
    ll n,x;
    scanf("%lld%lld",&n,&x);
    a[0]=1;
    b[0]=1;
    for(int i=1;i<n;i++)
    {
        a[i]=a[i-1]*2+3;
        b[i]=b[i-1]*2+1;
    }
    printf("%lld\n",f(n,x));
}
