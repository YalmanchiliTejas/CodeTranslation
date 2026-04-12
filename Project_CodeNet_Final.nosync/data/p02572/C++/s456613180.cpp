#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
void solve()
{
 ll n,i;
    cin>>n;
    vector<ll>a(n),suf(n);
    for(ll &x:a)cin>>x;
    suf[n-1]=a[n-1]%mod;
    for(i=n-2;i>=0;i--)
        suf[i]=(suf[i+1]+a[i])%mod;
    
    ll ans=0;
    for(i=0;i<n-1;i++)
        ans=(ans+a[i]%mod*suf[i+1]%mod)%mod;
    
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;
  //  cin>>t;
    while(t--)
        solve();
}