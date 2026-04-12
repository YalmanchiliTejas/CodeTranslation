#include <bits/stdc++.h>
#include <unordered_map>

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
const int MAXN = static_cast<int>(2e4) + 17;

int n, d;
string s;
ll dp[MAXN][101][2];

bool read() {
    if (!(cin >> s >> d))
        return false;

    return true;
}

ll add(ll a, ll b) { return (a += b) >= INF ? a - INF : a; }

void solve() {
    n = sz(s);
    s = "0" + s;
    dp[0][0][1] = 1;

    for (int i = 0; i < n; ++i)
        for (int nc = 0; nc < 10; ++nc)
            for (int j = 0; j < d; ++j) {
                dp[i + 1][(j + nc) % d][0] = add(dp[i + 1][(j + nc) % d][0], dp[i][j][0]);

                if (nc < s[i + 1] - '0')
                    dp[i + 1][(j + nc) % d][0] = add(dp[i + 1][(j + nc) % d][0], dp[i][j][1]);

                if (nc == s[i + 1] - '0')
                    dp[i + 1][(j + nc) % d][1] = add(dp[i + 1][(j + nc) % d][1], dp[i][j][1]);
            }

    ll res = dp[n][0][0] + dp[n][0][1] - 1;
    res = (res % INF + INF) % INF;
    cout << res << endl;
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

