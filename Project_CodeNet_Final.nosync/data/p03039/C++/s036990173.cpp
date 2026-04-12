#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<P ,ll> P3;
typedef pair<P ,P> PP;
const ll MOD = ll(1e9)+7;
const int IINF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = int(1e5 + 5);
const double EPS = 1e-6;
const int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define ALL(v) (v).begin(), (v).end()

ll mod_power(ll x, ll n) {  //繰り返し二乗法
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    else {
        ll d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
        return d;
    }
}


ll mod_inv(ll a, ll m = MOD) {  // a^-1 mod m
    return mod_power(a, m-2);
}

ll nCk(ll n, ll k) {
    if (k == 0)
        return 1;
    else
        return nCk(n, k - 1) * (n - k + 1) % MOD * mod_inv(k) % MOD;
}

int main() {
    ll n, m, k, tmp = 0, ans = 0;
    cin >> n >> m >> k;
    // y
    for(ll i = 0; i<n; i++){
        tmp += i*(n-i);
        tmp %= MOD;
    }
    tmp *= nCk(n*m-2,k-2);
    tmp %= MOD;
    tmp *= m*m;
    ans += tmp;
    // x
    tmp = 0;
    for(ll i = 0; i<m; i++){
        tmp += i*(m-i);
        tmp %= MOD;
    }
    tmp *= nCk(n*m-2,k-2);
    tmp %= MOD;
    tmp *= n*n;
    ans += tmp;
    ans %= MOD;
    cout << ans << endl;
    return 0;
}