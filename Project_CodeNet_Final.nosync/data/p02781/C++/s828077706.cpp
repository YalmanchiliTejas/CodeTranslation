#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    string s;
    int k;
    cin >> s >> k;
    while (s[0] == '0') s.erase(s.begin());
    int dp[s.size()][k + 1][10][2];
    for (int i = 0; i < s.size(); ++i) for (int j = 0; j <= k; ++j) for (int id = 0; id < 10; ++id) for (int id2 = 0; id2 < 2; ++id2) dp[i][j][id][id2] = 0;
    dp[0][0][0][0] = 1;
    for (int i = 1; i < (s[0] - '0'); ++i) dp[0][1][i][0] = 1;
    dp[0][1][s[0] - '0'][1] = 1;
    for (int i = 1; i < s.size(); ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int id = 0; id < 10; ++id) {
                for (int ind = 0; ind < 2; ++ind) {
                    for (int id2 = 0; id2 < 10; ++id2) {
                        if (id2 != 0 && j < k) {
                            //cout << i << ' ' << j << ' ' << id << ' ' << id2 << '\n';
                            if (ind == 0 || (s[i] - '0') >= id2) {
                                if (ind && (s[i] - '0') == id2) dp[i][j + 1][id2][ind] += dp[i - 1][j][id][ind];
                                else dp[i][j + 1][id2][0] += dp[i - 1][j][id][ind];
                            }
                            continue;
                        }
                        if (id2 != 0) continue;
                        if (ind && s[i] == '0') dp[i][j][id2][1] += dp[i - 1][j][id][ind];
                        else dp[i][j][id2][0] += dp[i - 1][j][id][ind];
                    }
                }
            }
        }
    }
    /*for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int id = 0; id < 10; ++id) cout << i << ' ' << j << ' ' << id << ' ' << dp[i][j][id].first << ' ' << dp[i][j][id].second << '\n';
        }
    }*/
    int ans = 0;
    for (int i = 0; i < 10; ++i) ans += dp[s.size() - 1][k][i][0] + dp[s.size() - 1][k][i][1];
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
