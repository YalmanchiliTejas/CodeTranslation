// Author: Vamsi Krishna Reddy Satti
// With love for Competitive Programming!
 
// #pragma GCC optimize ("Ofast,unroll-loops,-ffloat-store")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

string to_string(const string& s) { return '"' + s + '"'; }
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cout << " " << to_string(H);
    debug_out(T...);
}
#ifdef LOCAL
    #define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) 3
#endif
 
#define cin_exception cin.exceptions(cin.failbit);
#define cout_precision cout.setf(ios::fixed); cout.precision(15);
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using ld = long double; using vi = vector<int>;
using ll = int_fast64_t; using ull = uint_fast64_t;
using vl = vector<ll>; using vul = vector<ull>;

// -----------------------------------------------------------------------------

const int N = 3e3 + 5, S = N;
const int MOD = 998244353;
int n, s;
int dp[N][S][3];

void solve() {
    cin >> n >> s;
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        int pi = i - 1;
        for (int j = 0; j <= s; ++j) {
            dp[i][j][0] = (ll(0) + dp[i][j][0] + dp[pi][j][0]) % MOD;
            dp[i][j][1] = (ll(0) + dp[i][j][1] + dp[pi][j][0] + dp[pi][j][1]) % MOD;
            dp[i][j][2] = (ll(0) + dp[i][j][2] + dp[pi][j][0] + dp[pi][j][1] + dp[pi][j][2]) % MOD;
            if (j + a > s) continue;
            dp[i][j + a][1] = (ll(0) + dp[i][j + a][1] + dp[pi][j][0] + dp[pi][j][1]) % MOD;
            dp[i][j + a][2] = (ll(0) + dp[i][j + a][2] + dp[pi][j][0] + dp[pi][j][1]) % MOD;
        }
    }
    cout << dp[n][s][2] << '\n';
}

// -----------------------------------------------------------------------------

int main() {
    fast_io;
#ifdef LOCAL
    cin_exception;
#endif
    int t = 1;
    // cin >> t;
    // preprocess();
    for (int i = 1; i <= t; ++i) {
        solve();
    }
}
