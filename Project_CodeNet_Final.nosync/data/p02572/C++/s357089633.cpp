#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
const ll mod = 1000000000 + 7;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), acc(n+1, 0);
    rep(i, 0, n) {
        cin >> a[i];
    }
    for(ll i = n-1; i >= 0; i--){
        acc[i] = acc[i+1] + a[i];
        acc[i] %= mod;
    }
    ll ans = 0;
    rep(i, 0, n) {
        ans += (a[i] * acc[i+1]) % mod;
        ans %= mod;
    }
    cout << ans % mod << endl;
    return 0;
}