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

int dx4[] = {1, -1, 0, 0};
int dy4[] = {0, 0, 1, -1};
int dx8[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy8[] = {1, -1, 0, 0, 1, -1, -1, 1};

// Debug
#define debug(x) cerr << (x) << " (L:" << __LINE__ << ")" << '\n'

// Loop
#define inc(i, a, n) for (ll i = (a), _##i = (n); i < _##i; ++i)
#define dec(i, a, n) for (ll i = (a), _##i = (n); i > _##i; --i)
#define rep(i, n) inc(i, 0, n)

// Stream
#define fout(n) cout << fixed << setprecision(n)
#define fasten cin.tie(0), ios::sync_with_stdio(0)

// Speed
run() { fasten, fout(10); }
#pragma GCC optimize("-O3")
#pragma GCC target("avx")

// Math
inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

signed main() {
    int N, M;
    cin >> N >> M;
    vector<vector<bool>> d(N+1, vector<bool>(N+1));
    rep(i, M) {
        int n, m;
        cin >> n >> m;
        d[n][m] = d[m][n] = true;
    }
    int a[N];
    rep(i, N) a[i] = i+1;
    ll ans = 0;
    do {
        if (a[0] != 1) continue;
        bool f = true;
        rep(i, N-1) {
            f = f && d[a[i]][a[i+1]];
        }
        if(f) ++ans;
    } while (next_permutation(a, a + N));

    cout << ans << nl;
}
