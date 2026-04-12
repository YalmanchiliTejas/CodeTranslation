#include<iostream>
#define MOD 1000000007
using namespace std;
typedef long long int ll;

int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll p[n]={0};
    p[n-1]=a[n-1];
    for(ll i=n-2;i>0;i--)
    {
        p[i]=p[i+1]+a[i];
    }
    ll sum=0;
    for(ll i=0;i<n-1;i++)
    {
       sum+=((a[i]%MOD)*(p[i+1]%MOD))%MOD;
    }
    cout<<sum%MOD<<"\n";
}