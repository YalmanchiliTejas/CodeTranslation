#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    string s;
    cin >> s;
    ll k;
    cin >> k;
    ll n = len(s);
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(k + 1, vector<ll>(2, 0)));
    dp[0][0][0] = 1;
    rep(i, n) {
        ll v = (s[i] != '0') ? 1 : 0;
        reps(j, v, k + 1) dp[i + 1][j][0] = dp[i][j - v][0];
        v = s[i] - '0';
        rep(j, k + 1) {
            if (j == 0) {
                dp[i + 1][j][1] += dp[i][j][1];
                if (v > 0) dp[i + 1][j][1] += dp[i][j][0];
            }
            else {
                dp[i + 1][j][1] += dp[i][j][1] + dp[i][j - 1][1] * 9;
                if (v > 0) dp[i + 1][j][1] += dp[i][j][0] + dp[i][j - 1][0] * (v - 1);
            }
        }
    }
    cout << (dp[n][k][0] + dp[n][k][1]) << endl;
    return 0;
}
