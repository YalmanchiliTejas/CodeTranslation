#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const long long MOD = 1000000007;

long long pow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

long long comb(long long a, long long b) {
    long long x = 1, y = 1;
    for (long long i = 0; i < b; i++) {
        x *= a - i;
        y *= i + 1;
        x %= MOD;
        y %= MOD;
    }
    return (x * pow(y, MOD-2)) % MOD;
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll ans = 0;
    rep(i, n) {
        ans += (ll)i * (n-i) % MOD * pow(m, 2);
        ans %= MOD;
    }
    rep(i, m) {
        ans += (ll)i * (m-i) % MOD * pow(n, 2);
        ans %= MOD;
    }
    ll s = n * m;
    ans *= comb(s-2, k-2);
    ans %= MOD;
    cout << ans << endl;
    return 0;
}