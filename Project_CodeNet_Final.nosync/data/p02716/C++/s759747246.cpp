#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
#define FOR(i, a, n) for(ll i=(ll)a; i<(ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
struct FastIO {FastIO() { cin.tie(0); ios::sync_with_stdio(0); }}fastiofastio;
constexpr ll INF = 1LL<<60;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];

    if(n%2==0) {
        ll sum0 = 0, sum1 = 0;
        for(ll i=0; i<n; i+=2) {
            sum0 += a[i];
            sum1 += a[i+1];
        }
        vector<vector<ll>> dp(n, vector<ll>(2, -INF));
        dp[0][0] = a[0];
        dp[1][1] = a[1];
        REP(i, n) REP(j, 2) {
            if(i>=2) chmax(dp[i][j], dp[i-2][j] + a[i]);
            if(i>=3 && j>=1) chmax(dp[i][j], dp[i-3][j-1] + a[i]);
        }
        cout << max({sum0, sum1, dp[n-2][1], dp[n-1][1]}) << endl;
    } else {
        ll sum0 = 0;
        for(ll i=1; i<n; i+=2) sum0 += a[i];
        ll sum1 = 0, mi = INF;
        for(ll i=0; i<n; i+=2) sum1 += a[i], chmin(mi, a[i]);
        sum1 -= mi;
        vector<vector<ll>> dp(n, vector<ll>(3, -INF));
        dp[0][0] = a[0];
        dp[1][1] = a[1];
        REP(i, n) REP(j, 3) {
            if(i>=2) chmax(dp[i][j], dp[i-2][j] + a[i]);
            if(i>=3 && j>=1) chmax(dp[i][j], dp[i-3][j-1] + a[i]);
        }
        cout << max({sum0, sum1, dp[n-1][2], dp[n-2][2]}) << endl;
    }

    return 0;
}