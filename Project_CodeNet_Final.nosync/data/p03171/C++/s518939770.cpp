#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#include <cstring>

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;
typedef long long ll;
const ll MOD = (ll)1e9 + 7;
const int N = 3000+5, inf = 1e9+5;
ll add(ll x, ll y) { x += y; if (x >= MOD) return x - MOD; return x; }
ll sub(ll x, ll y) { x -= y; if (x < 0) return x + MOD; return x; }
ll mult(ll x, ll y) { return (x * y) % MOD; }
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll a[N], dp[N][N], n;

ll f(int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    ll L = f(l + 1, r);
    ll R = f(l, r - 1);
    if ((n&1) == ((l-r+1)&1))
        return dp[l][r] = max(a[l] + L, a[r] + R);
    else
        return dp[l][r] = min(L - a[l], R - a[r]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep (i, 0, n) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    cout << f(0, n-1) << endl;
    return 0;
}