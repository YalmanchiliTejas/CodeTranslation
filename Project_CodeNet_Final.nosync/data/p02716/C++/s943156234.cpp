#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    ll dp[n][5][2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            dp[i][j][0] = dp[i][j][1] = -INFLL;
        }
    }
    dp[0][2][0] = 0;
    dp[0][3][1] = a[0];
    vector<int> d = {-2, -1, 0, 1, 2};
    for (int i = 1; i < n; i++) {
        for (int j1 = 0; j1 < 5; j1++) {
            /// i / 2 + d[j1] + (0, 1)
            int delta = (i / 2 + d[j1]) - (i + 1) / 2;
            if (delta >= -2 && delta <= 2) dp[i][delta + 2][0] = max({dp[i][delta + 2][0], dp[i - 1][j1][0], dp[i - 1][j1][1]});
            delta++;
            if (delta < -2 || delta > 2) continue;
            dp[i][delta + 2][1] = max(dp[i][delta + 2][1], dp[i - 1][j1][0] + a[i]);
        }
    }
    cout << max(dp[n - 1][2][0], dp[n - 1][2][1]);
    return 0;
}

