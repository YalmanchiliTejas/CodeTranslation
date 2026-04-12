#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define FOR(i, x, y) for (ll i = x; i < y; i++)
#define MOD 1000000007
typedef long long ll;
using namespace std;

ll dp[10001][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    ll d;
    cin >> s >> d;
    dp[0][0] = 1;
    FOR(i, 1, s.size()) {
        FOR(j, 0, d) {
            dp[i][j] = 0;
            FOR(k, 0, 10) {
                dp[i][j] = (dp[i][j] + dp[i - 1][(j - k + 100 * d) % d]) % MOD;
            }
        }
    }
    ll ans = dp[s.size() - 1][0] - 1;
    ll pref = 0;
    FOR(j, 1, s[0] - '0') {
        ans = (ans + dp[s.size() - 1][(100000 * d - (pref + j)) % d]) % MOD;
    }
    pref += (s[0] - '0');
    FOR(i, 1, s.size()) {
        FOR(j, 0, s[i] - '0') {
            ans = (ans + dp[s.size() - i - 1][(100000 * d - (pref + j)) % d]) %
                  MOD;
        }
        pref += (s[i] - '0');
    }
    ans += (pref % d == 0);
    cout << ans << '\n';
    return 0;
}