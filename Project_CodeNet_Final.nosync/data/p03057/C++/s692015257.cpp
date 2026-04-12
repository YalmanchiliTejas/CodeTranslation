//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <random>
#include <assert.h>
#include <memory.h>
#include <time.h>

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
#define rank qwertyuio

using namespace std;

inline bool setmin(int &x, int y) { return (y < x) ? x = y, 1 : 0; }
inline bool setmax(int &x, int y) { return (y > x) ? x = y, 1 : 0; }
inline bool setmin(ll &x, ll y) { return (y < x) ? x = y, 1 : 0; }
inline bool setmax(ll &x, ll y) { return (y > x) ? x = y, 1 : 0; }

const int N = 200000;
const int inf = (int)1e9 + 1;
const ll big = (ll)1e18 + 1;
const int P = 239;
const int P1 = 31;
const int P2 = 57;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const int MOD2 = 998244353;
const double eps = 1e-9;
const double pi = atan2(0, -1);
const int ABC = 26;

inline void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

ll bin_pow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        p >>= 1;
    }
    return res;
}

ll rev(ll x) {
    return bin_pow(x, MOD - 2);
}

ll fact[N + 1], rfact[N + 1];

void init() {
    fact[0] = 1;
    rep(i, 1, N + 1) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    rfact[N] = rev(fact[N]);
    repb(i, N - 1, -1) {
        rfact[i] = rfact[i + 1] * (i + 1) % MOD;
    }
}

ll C(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    return fact[n] * rfact[k] % MOD * rfact[n - k] % MOD;
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    cout << fixed;
    //ll TL = 0.95 * CLOCKS_PER_SEC;
    //clock_t time = clock();
    init();
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    repb(i, m - 1, -1) {
        s[i] = char('0' + (s[0] != s[i]));
    }
    int c1 = -1;
    rep(i, 0, m) {
        if (s[i] == '1') {
            c1 = i;
        }
    }
    if (c1 == -1) {
        int ans = 0;
        for (int i = 0; i * 2 <= n; i++) {
            add(ans, C(n - i, i));
            if (i >= 1) {
                add(ans, C(n - 2 - (i - 1), (i - 1)));
            }
        }
        cout << ans << "\n";
        return 0;
    }
    s = s.substr(0, c1 + 1);
    m = sz(s);
    if (n % 2 == 1) {
        cout << 0 << "\n";
        return 0;
    }
    int k = n - 1, cur = 0;
    rep(i, 0, m) {
        if (s[i] == '0') {
            cur++;
        }
        if (s[i] == '0' && (i == m - 1 || s[i + 1] == '1')) {
            if (cur % 2 == 1) {
                setmin(k, cur);
            } else if (cur == i + 1) {
                setmin(k, cur + 1);
            }
            cur = 0;
        }
    }
    //cout << k << endl;
    int dp[n + 2], pref1[n + 2];
    fill(dp, dp + n + 2, 0);
    fill(pref1, pref1 + n + 2, 0);
    dp[1] = 1;
    pref1[1] = 1;
    for (int i = 3; i <= n + 1; i += 2) {
        int last_add = max(1, i - (k + 1));
        dp[i] = pref1[i - 2] - (last_add - 2 >= 0 ? pref1[last_add - 2] : 0);
        if (dp[i] < 0) {
            dp[i] += MOD;
        }
        pref1[i] = (pref1[i - 2] + dp[i]) % MOD;
    }
    /*rep(i, 1, n + 2) {
        cout << dp[i] << " ";
    }
    cout << "\n";*/
    int ans = dp[n + 1];
    //cout << k << endl;
    for (int c = 1; c <= k; c += 2) {
        //cout << c << " " << dp[n - c] << endl;
        ans = (ans + 1LL * c * dp[n - c]) % MOD;
    }
    cout << ans << "\n";
    return 0;
}