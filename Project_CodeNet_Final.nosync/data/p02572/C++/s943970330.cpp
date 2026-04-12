#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
    ll n, ans=0, sum=0;
    cin>>n;
    ll a[n];
    for(ll i=0; i<n; i++) cin>>a[i];
    for(ll i=n-2; i>=0; i--){
        ll x = a[i];
        sum = (sum + a[i+1]) % mod;
        ll prc = x * sum % mod;
        ans = (ans + prc) % mod;
    }
    cout<<ans;
}