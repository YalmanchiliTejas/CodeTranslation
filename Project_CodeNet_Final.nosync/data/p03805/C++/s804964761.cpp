#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"
template<class T> void chmax(T &a, const T b){ a = max(a, b); }
template<class T> void chmin(T &a, const T b){ a = min(a, b); }

ll n, m;
vector<vector<ll>> g, dp;

void dfs(ll v, ll p = -1, ll bit = 0) {
    if (bit & (1 << v)) return;
    bit |= 1 << v;
    dp[v][bit]++;
    for(auto &x : g[v]) {
        if (x == p) continue;
        dfs(x, v, bit);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    cin >> n >> m;
    g.resize(n);
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dp.resize(n, vector<ll>(1 << n, 0));
    dfs(0);
    ll ans = 0;
    rep(i, n) ans += dp[i][(1 << n) - 1];
    cout << ans << endl;
    return 0;
}
