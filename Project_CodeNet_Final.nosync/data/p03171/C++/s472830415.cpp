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

ll f(ll l, ll r, bool taro) {
    if (dp[l][r] != INF) {
        return dp[l][r];
    }
    if (abs(l - r) == 0) {
        return dp[l][r] =  0;
    } else if (abs(l - r) == 1) {
        if (taro) {
            return dp[l][r] =  A[l];
        } else {
            return dp[l][r] =  -A[l];
        }
    }
    ll res = 0;
    if (taro) {
        res = max(f(l + 1, r, false) + A[l], f(l, r - 1, false) + A[r - 1]);
    } else {
        res = min(f(l + 1, r, true) - A[l], f(l, r - 1, true) - A[r - 1]);
    }
    return dp[l][r] = res;
}

void solve() {
    cin >> N;
    A.resize(N);
    rep(i, N) cin >> A[i];
    dp.assign(N, vector<ll>(N + 1, INF));
    cout << f(0, N, true) << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
