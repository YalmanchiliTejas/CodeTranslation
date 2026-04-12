#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 998244353

using namespace std;
using ll = long long;
using ldb = long double;

ll modmul(ll a, ll b) {
    ll res = (a % DIV) * (b % DIV);
    return res % DIV;
}

ll modeadd(ll a, ll b) {
    ll res = (a % DIV) + (b % DIV);
    return res % DIV;
}
int main() {
    ll N, S; cin >> N >> S;
    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(S + 1, vector<ll>(3)));
    vector<int> a(N); for (int i = 0; i < N; i++) cin >> a[i];
    dp[0][0][0] = 1;
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j <= S; j++) {
            dp[i + 1][j][0] += dp[i][j][0];
            dp[i + 1][j][0] %= DIV;
            if (j + a[i] < S) {
                dp[i + 1][j + a[i]][1] += modmul(i + 1, dp[i][j][0]);
                dp[i + 1][j + a[i]][1] %= DIV;
            }
            else if (j + a[i] == S) {
                dp[i + 1][j + a[i]][2] += modmul(modmul(i + 1, N - i), dp[i][j][0]);
                dp[i + 1][j + a[i]][2] %= DIV;
            }

            dp[i + 1][j][1] += dp[i][j][1];
            if (j + a[i] < S) {
                dp[i + 1][j + a[i]][1] += dp[i][j][1];
                dp[i + 1][j + a[i]][1] %= DIV;
            }
            else if (j + a[i] == S) {
                dp[i + 1][j + a[i]][2] += modmul(N - i, dp[i][j][1]);
                dp[i + 1][j + a[i]][2] %= DIV;
            }

            dp[i + 1][j][2] += dp[i][j][2];
            dp[i + 1][j][2] %= DIV;

        }
    }
    cout << dp[N][S][2] << endl;
}
