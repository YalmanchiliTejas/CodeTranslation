#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main() {
    int n;
    cin>>n;
    vector<ll> v(n);
    ll s=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        s+=v[i];
        s = s%mod;
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        s = (s%mod - v[i] + mod)%mod;
        ans = (ans+((s%mod)*v[i])%mod)%mod;
    }
    cout<<ans;
}
