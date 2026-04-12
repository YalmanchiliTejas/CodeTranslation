#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr int mod = 1e9 + 7;

template <class T> inline bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <class T> inline bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    int d;
    cin >> s >> d;
    int n = s.size();
    int dp[2][2][100] = {};

    dp[0][0][0] = 1;
    rep(i, n) rep(j, d) {
        rep(k, 10)(dp[i + 1 & 1][1][(j + k) % d] += dp[i & 1][1][j]) %= mod;
        rep(k, s[i] - '0')(dp[i + 1 & 1][1][(j + k) % d] += dp[i & 1][0][j]) %=
            mod;
        (dp[i + 1 & 1][0][(j + s[i] - '0') % d] += dp[i & 1][0][j]) %= mod;
        dp[i & 1][0][j] = dp[i & 1][1][j] = 0;
    }

    cout << (dp[n & 1][0][0] + dp[n & 1][1][0] - 1 + mod) % mod << endl;

    return 0;
}