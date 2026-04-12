#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

/**
 * For DEBUG
 * https://github.com/ta7uw/cpp-pyprint
 */
#include "cpp-pyprint/pyprint.h"

#endif

ll N;
vector<ll> A;
vector<vector<ll>> dp;

ll dfs(ll l, ll r) {
    if (dp[l][r] != INF) {
        return dp[l][r];
    }
    bool taro = N % 2 ? (r - l) % 2 : (r - l) % 2 == 0;
    if (r - l == 1) {
        return taro ? A[l] : -A[l];
    }
    ll res = 0;
    if (taro) {
        res = max(dfs(l, r - 1) + A[r - 1], dfs(l + 1, r) + A[l]);
    } else {
        res = min(dfs(l, r - 1) - A[r - 1], dfs(l + 1, r) - A[l]);
    }
    return dp[l][r] = res;
}

void solve() {
    cin >> N;
    A.resize(N);
    rep(i, N) cin >> A[i];
    dp.resize(N + 1, vector<ll>(N + 1, INF));
    cout << dfs(0, N) << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
