#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;
#define forn(i,p,n); for(long long i=p;i<n;++i)
#define rofn(i,p,n); for(long long i=p;i>n;--i)
#define pb push_back
#define vi vector
#define ump unordered_map
void solve(){
    ll n;
    cin >> n;
    vi<ll> a(n);
    ll sum= 0;
    ll mod = 1e9+7;
    forn(i,0,n){
        cin >> a[i];
        sum += a[i];
    }
    ll ans = 0;
    forn(i,0,n){
        sum -= a[i];
        ll x = sum%mod;
        ll y = a[i]%mod;
        x = (x*y)%mod;
        ans += (x)%mod;
    }
    cout<<ans%mod;
}
 
int main()
{
    fast;
    //int test;
    //cin >> test;
    //while(test--){
        solve();
    //}
}