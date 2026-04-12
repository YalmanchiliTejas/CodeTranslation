#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;
map<pair<int, int>, long long> dp;
int vt[N];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> vt[i];
    }
    dp[{-1, 0}] = dp[{0, 0}] = 0;
    long long mxdp = -1e18;
    for (int i = 1; i <= n; i++) {
        int mink = max(1, (n / 2) - (n - i + 1) / 2);
        int maxk = (i + 1) / 2;
        for (int j = mink; j <= maxk; j++) {
            for (int ni = i - 4; ni <= i - 2; ni++) {
                if (dp.count({ni, j - 1}) == 0)
                    continue;
                if (dp.count({i, j}) == 0)
                    dp[{i, j}] = dp[{ni, j - 1}] + vt[i];
                else
                    dp[{i, j}] = max(dp[{i, j}], dp[{ni, j - 1}] + vt[i]);
            }
            if (j == n / 2)
                mxdp = max(mxdp, dp[{i, j}]);
        }
    }
    cout << mxdp;
}

int main() {
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);
    solve();
}
