#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll mod = 1e9+7;

int main(void)
{
    ll n, ans=0;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    rep(i,n){
        sum -= a[i];
        ans += ( (a[i]%mod) * (sum%mod) ) % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}