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

const ll inf = LONG_LONG_MAX / 2 - 1;
ll n;
vector<ll> a;
vector<vector<ll>> dp;

ll dfs(ll l, ll r) {
    if (dp[l][r] != inf) return dp[l][r];
    ll turn = n - (r - l + 1);
    if (turn % 2 == 0) {
        if (l == r) {
            dp[l][r] = a[l];
            return dp[l][r];
        }
        dp[l][r] = -inf;
        chmax(dp[l][r], dfs(l + 1, r) + a[l]);
        chmax(dp[l][r], dfs(l, r - 1) + a[r]);
    }
    else {
        if (l == r) {
            dp[l][r] = -a[l];
            return dp[l][r];
        }
        dp[l][r] = inf;
        chmin(dp[l][r], dfs(l + 1, r) - a[l]);
        chmin(dp[l][r], dfs(l, r - 1) - a[r]);
    }
    return dp[l][r];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    cin >> n;
    a.resize(n);
    rep(i, n) cin >> a[i];
    dp.resize(n, vector<ll>(n, inf));
    cout << dfs(0, n - 1) << endl;
    return 0;
}
