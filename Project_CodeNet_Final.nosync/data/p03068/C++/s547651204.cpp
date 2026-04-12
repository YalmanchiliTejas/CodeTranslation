#include <bits/stdc++.h>
using namespace std;

// Define
using ll = int64_t;
using ul = uint64_t;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll INF = LONG_MAX;
const ul MAX = ULONG_MAX;
const char nl = '\n';

#define elif else if
#define def inline auto
#define run __attribute__((constructor)) def _

// Debug
#define debug(x) cerr << (x) << " (L:" << __LINE__ << ")" << '\n'

// Loop
#define inc(i, a, n) for (ll i = (a), _##i = (n); i < _##i; ++i)
#define dec(i, a, n) for (ll i = (a), _##i = (n); i > _##i; --i)
#define rep(i, n) inc(i, 0, n)
#define be(c) begin(c), end(c)

// Stream
#define fout(n) cout << fixed << setprecision(n)
#define fasten cin.tie(0), ios::sync_with_stdio(0)

// Speed
run() { fasten, fout(10); }
#pragma GCC optimize("-O3")
#pragma GCC target("avx")

signed main() {
    int n, k;
    string ss;
    cin >> n >> ss >> k;
    char s = ss[k-1];
    rep(i, n) {
        if(ss[i] != s) ss[i] = '*';
    }
    cout << ss << nl;
}
