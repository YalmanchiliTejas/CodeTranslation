#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
using namespace std;
ll mod=1e9+7;
int main() {
    fast();
    // ll t;
    // cin>>t;
    // while(t--)			
    // {
         
    // }
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    ll pref[n];
    pref[0]=0;
    for(int i=1;i<n;i++)
    {
        pref[i]=(pref[i-1]%mod+a[i-1]%mod)%mod;
    }
    ll ans=0;
    for(int i=1;i<n;i++)
    {
        ll temp=(a[i]%mod*pref[i]%mod)%mod;
        ans=(ans%mod+temp%mod)%mod;
    }
    cout<<ans<<endl;
}