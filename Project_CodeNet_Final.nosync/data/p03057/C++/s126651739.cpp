#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 210000;
const i64 P = 1000000000 + 7;
i64 dp[2][2][maxn];

void add(i64 &x, i64 y) {
    x += y;
    x %= P;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, l;
    string s;
    cin >> n >> l >> s;
    char c0 = s[0], c1 = c0 ^ 'R' ^ 'B';
    if (s == string(l, c0)) {
        forn(i, 2) dp[i][i][1] = 1;
        for1(i, n - 1) forn(f, 2) forn(j, 2) forn(k, 2) {
            if (j && k) continue;
            add(dp[f][k][i + 1], dp[f][j][i]);
        }
        i64 ans = 0;
        forn(f, 2) forn(j, 2) {
            if (f && j) continue;
            add(ans, dp[f][j][n]);
        }
        cout << ans << '\n';
        return 0;
    }

    if (n % 2) {
        cout << 0 << '\n';
        return 0;
    }

    vector<pair<int, char> > cl;
    pii p = {1, c0};
    for1(i, l - 1) {
        if (s[i] == p.se) ++p.fi;
        else cl.pb(p), p = {1, s[i]};
    }

//    for (auto w: cl) cerr << w.fi << ' ' << w.se << '\n';

    int ub = n;
    if (cl[0].fi % 2 == 0) ub = cl[0].fi + 1;
    for (auto w: cl) if (w.se == c0 && w.fi % 2) uin(ub, w.fi);
    ub /= 2;

    vi64 vals(n / 2 + 1), svals(n / 2 + 2);
    vals[0] = 1;
    svals[1] = 1;
    cerr << ub << '\n';
    for1(i, n / 2) {
        vals[i] = svals[i] - svals[max(i - ub - 1, 0)];
        vals[i] %= P;
//        cerr << i << ' ' << vals[i] << '\n';
        svals[i + 1] = (svals[i] + vals[i]) % P;
    }

    i64 ans = vals[n / 2];
    for1(i, ub) if (i + 1 <= n / 2) add(ans, vals[n / 2 - i - 1] * i);
    ans *= 2;
    ans %= P;
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
