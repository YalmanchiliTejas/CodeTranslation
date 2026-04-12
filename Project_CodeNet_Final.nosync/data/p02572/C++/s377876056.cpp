#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    ll suf[n];
    for(int i=0;i<n;i++)
        suf[i]=0;
    suf[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        suf[i]=(a[i]+suf[i+1])%mod;
    }
    ll ans=0;
    for(int i=0;i<n-1;i++)
    {
        ans=(ans%mod+(a[i]%mod*suf[i+1]%mod)%mod)%mod;
    }
    cout<<ans<<endl;
}