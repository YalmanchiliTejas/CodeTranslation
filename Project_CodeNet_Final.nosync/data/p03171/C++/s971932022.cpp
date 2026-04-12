#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (ll i = 0; i < (ll) (n); ++i)
#define sz(a) static_cast<int>((a).size())
#define pb emplace_back
#define mp make_pair
#define endl '\n'
#define f first
#define s second

#ifdef SEREZHKA
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename T>
void _dbg(const char* _s, T _h) { cerr << _s << " = " << _h << "\n"; }

template<typename T, typename... Ts>
void _dbg(const char*_s, T _h, Ts... _t) {
    int _b = 0;
    
    while (((_b += *_s == '(') -= *_s == ')') != 0 || *_s != ',')
        cerr << *_s++;
    
    cerr << " = " << _h << ",";
    _dbg(_s + 1, _t...);
}

using ll = long long;

const ll INF = static_cast<ll>(1e9) + 7ll;
const ll LINF = INF * INF;
const int MAXN = static_cast<int>(3e3) + 17;

int n;
int a[MAXN];
bool used[MAXN][MAXN];
pair<ll, ll> dp[MAXN][MAXN];

bool read() {
    if (!(cin >> n))
        return false;

    forn (i, n)
        cin >> a[i];

    return true;
}

void dfs(int l, int r, int t) {
    if (used[l][r])
        return ;

    used[l][r] = true;

    if (l == r) {
        if (t == 0)
            dp[l][r] = mp(a[l], 0);
        else
            dp[l][r] = mp(0, a[l]);

        return ;
    }

    dfs(l + 1, r, t ^ 1);
    dfs(l, r - 1, t ^ 1);

    if (t == 0) {
        if (a[l] + dp[l + 1][r].f - dp[l + 1][r].s > a[r] + dp[l][r - 1].f - dp[l][r - 1].s)
            dp[l][r] = mp(a[l] + dp[l + 1][r].f, dp[l + 1][r].s);
        else
            dp[l][r] = mp(a[r] + dp[l][r - 1].f, dp[l][r - 1].s);
    } else {
        if (dp[l + 1][r].f - dp[l + 1][r].s - a[l] < dp[l][r - 1].f - dp[l][r - 1].s - a[r])
            dp[l][r] = mp(dp[l + 1][r].f, a[l] + dp[l + 1][r].s);
        else
            dp[l][r] = mp(dp[l][r - 1].f, a[r] + dp[l][r - 1].s);
    }
}

void solve() {
    dfs(0, n - 1, 0);
    cout << dp[0][n - 1].f - dp[0][n - 1].s << endl;
}

int main() {
    cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    
#ifdef SEREZHKA
    freopen("file.in", "r", stdin);
#endif
    
    while (read())
        solve();
    
    return 0;
}

