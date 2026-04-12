#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;
int main(){

    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i=0; i<n; i++) cin >> a[i];

    ll sum=0;
    ll ans=0;
    rep(i,n-1){
        sum=(sum+a[i])%mod;
        ans=(ans+sum*a[i+1])%mod;
    } 
    cout << ans << endl;
    
    return 0;
}