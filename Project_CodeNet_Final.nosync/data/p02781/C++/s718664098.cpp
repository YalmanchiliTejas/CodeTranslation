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
    ll k;
    cin >> s >> k;
    ll n = len(s);
    // dp[pos][smaller][cnt]
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(2, vector<ll>(k + 1, 0)));
    dp[0][0][0] = 1;
    rep(i, n) {
        ll v = (s[i] != '0') ? 1 : 0;
        reps(j, v, k + 1) {
            dp[i + 1][0][j] = dp[i][0][j - v];
        }
        v = s[i] - '0';
        rep(j, k + 1) {
            if (j == 0) {
                dp[i + 1][1][j] += dp[i][1][j];
                if (v > 0) dp[i + 1][1][j] += dp[i][0][j];
            }
            else {
                dp[i + 1][1][j] += dp[i][1][j] + dp[i][1][j - 1] * 9;
                if (v > 0) dp[i + 1][1][j] += dp[i][0][j] + dp[i][0][j - 1] * (v - 1);
            }
        }
    }
    cout << (dp[n][0][k] + dp[n][1][k]) << endl;
    return 0;
}
