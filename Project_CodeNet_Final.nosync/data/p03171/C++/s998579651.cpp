#pragma GCC optimize ("O3")
#pragma GCC target ("tune=native")
#pragma GCC target ("avx")

#include <bits/stdc++.h>

// 汎用マクロ
#define ALL_OF(x) (x).begin(), (x).end()
#define REP(i,n) for (long long i=0, i##_len=(n); i<i##_len; i++)
#define RANGE(i,is,ie) for (long long i=(is), i##_end=(ie); i<=i##_end; i++)
#define UNIQUE(v) (v).erase(unique((v).begin(), (v).end()), (v).end())
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0; }
template<class T> bool chmin(T &a, const T &b) {if (a > b) {a = b; return 1;} return 0; }
#define INF 0x7FFFFFFF
#define LINF 0x7FFFFFFFFFFFFFFFLL
#define Yes(q) (q ? "Yes" : "No")
#define YES(q) (q ? "YES" : "NO")
#define DUMP(q) cerr << "[DEBUG] " #q ": " << (q) << " at " __FILE__ ":" << __LINE__ << endl
#define DUMPALL(q) cerr << "[DEBUG] " #q ": ["; REP(dumpall_i, (q).size()) { cerr << q[dumpall_i] << (dumpall_i == (q).size() - 1 ? "" : ", "); } cerr << "] at " __FILE__ ":" << __LINE__ << endl

// gcc拡張マクロ
#define gcd __gcd
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll

// エイリアス
using  ll = long long;
using ull = unsigned long long;
using  ld = long double;
using namespace std;

// モジュール


// 処理内容
int main() {

    int n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];

    // dp[l][r][i] := [l, r)が残ってるときの X - Y
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    REP(i, n+1) {
        REP(j, n+1) {
            dp[i][j] = (n - j + i) % 2 ? LINF : -LINF;
        }
        dp[i][i] = 0;
    }

    for (ll rem = 0; rem < n; rem++) {
        for (ll l = 0; l <= n - rem; l++) {
            ll r = l + rem;

            if ((n - rem) % 2) { // taro
                if (l > 0) chmax(dp[l-1][r], dp[l][r] + a[l-1]);
                if (r < n) chmax(dp[l][r+1], dp[l][r] + a[r]);
            } else { // jiro
                if (l > 0) chmin(dp[l-1][r], dp[l][r] - a[l-1]);
                if (r < n) chmin(dp[l][r+1], dp[l][r] - a[r]);
            }

        }
    }
    
    cout << dp[0][n] << endl;
    
    
}