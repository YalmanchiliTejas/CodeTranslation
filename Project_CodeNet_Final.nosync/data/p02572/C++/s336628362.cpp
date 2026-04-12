#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) int((a).size())

int main()
{
    ll i,j,n;
    cin>>n;
    vector<ll> a(n);
    for(i=0;i<n;i++) cin>>a[i];
    ll ans = 0;
    ll mod = 1e9+7;
    vector<ll> suf(n,0);
    suf[n-1] = a[n-1]%mod;
    for(i=n-2;i>=0;i--) suf[i] = (suf[i+1] + a[i])%mod;
    for(i=0;i<n-1;i++)
    {
        ll cur = (a[i]*suf[i+1])%mod;
        ans = (ans + cur)%mod;
    }
    cout<<ans<<"\n";
}
