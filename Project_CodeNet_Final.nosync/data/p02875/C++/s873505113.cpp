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

const int maxn = 11000000;
const i64 P = 998244353;
i64 fact[maxn], tcaf[maxn];

i64 deg(i64 x, i64 d) {
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        d /= 2;
        (x *= x) %= P;
    }
    return y;
}

i64 cnk(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * tcaf[k] % P * tcaf[n - k] % P;
}

map<string, int> memo;

bool can(string s) {
    if (s == "") return true;
    if (memo.count(s)) return memo[s];
    forn(i, s.size() - 1) {
        if (s[i] == 'A' && s[i + 1] == 'B') continue;
        if (s[i] == 'B' && s[i + 1] == 'A') continue;
        string t;
        forn(j, s.size()) if (j != i && j != i + 1) t += s[j];
        if (can(t)) return memo[s] = 1;
    }
    return memo[s] = 0;
}

int n;
i64 cnt[2];

void rec(string &s) {
    if (s.size() == n) {
        ++cnt[can(s)];
        if (!can(s)) cerr << s << '\n';
        return;
    }
    forn(i, 3) {
        s += (char)('A' + i);
        rec(s);
        s.resize(s.size() - 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n;
    fact[0] = 1;
    for1(i, n) fact[i] = fact[i - 1] * i % P;
    forn(i, n + 1) tcaf[i] = deg(fact[i], -1);

    i64 ans = 0;
    fore(i, n / 2 + 1, n) (ans += cnk(n, i) * deg(2, n - i)) %= P;
    (ans *= 2) %= P;
    cout << (deg(3, n) - ans + P) % P << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
