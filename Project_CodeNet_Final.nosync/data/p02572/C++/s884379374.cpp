#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> a(n);

    ll p = 0;
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++){
        p += a[i];
        p += mod;
        p %= mod;
    }
    ll ans = 0;
    for(ll i = 0; i < n-1; i++){
        p -= a[i];
        p += mod;
        p %= mod;
        ans += (a[i]*p)%mod;
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}