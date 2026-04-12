#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
int main()
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    ll res=0,val=0;
    for(int i=0;i<n;i++)
    {
        val=(val+a[i])%mod;
    }
    ll cur=0;
    for(int i=0;i<n;i++)
    {
        cur=(cur+a[i])%mod;
        res=(res+(a[i]*(val-cur))%mod+mod)%mod;
    }
    cout<<res;
    return 0;
}
