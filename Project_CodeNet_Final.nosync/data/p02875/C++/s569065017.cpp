// #pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <random>
#include <cmath>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

const int mod = 998244353;

ll binpow(ll a, int p = mod - 2) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}

const int N = 1e7 + 1;

ll f[N], fr[N];
ll pw[N];

ll cnk(int n, int k) {
    return f[n] * fr[k] % mod * fr[n - k] % mod;
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    f[0] = fr[0] = 1;
    pw[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = f[i - 1] * i % mod;
        fr[i] = binpow(f[i]);
        pw[i] = pw[i - 1] * 2 % mod;
    }
    ll ans = binpow(3, n);
    for (int i = n / 2 + 1; i <= n; i++) {
        ll keks = cnk(n, i) * pw[n - i + 1] % mod;
        ans = (ans - keks + mod) % mod;
    }
    cout << ans << endl;
}