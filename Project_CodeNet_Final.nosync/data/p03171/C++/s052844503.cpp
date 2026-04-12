#include <bits/stdc++.h>

using namespace std;

int n;
int v[3010];

long long dp[3010][3010][2];

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> v[i];


    auto f = [&](auto &Self, int i, int j, int flag) -> long long {
        if(i > j) return 0;
        auto &ans = dp[i][j][flag];
        if(ans != -1) return ans;
        ans = flag ? -1e18 : 1e18;

        if(flag) {
            ans = max(ans, Self(Self, i + 1, j, !flag) + v[i]);
            ans = max(ans, Self(Self, i, j - 1, !flag) + v[j]);
        } else {
            ans = min(ans, Self(Self, i + 1, j, !flag) - v[i]);
            ans = min(ans, Self(Self, i, j - 1, !flag) - v[j]);
        }
        return ans;
    };
    
    cout << f(f, 0, n - 1, 1) << "\n";
    //cout << dp[0][n - 1][1] << "\n";
    return 0;
}
