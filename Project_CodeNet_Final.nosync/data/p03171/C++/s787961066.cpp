#include <bits/stdc++.h>

using namespace std;

const int N = 3001;
using ll = long long;
ll dp[N][N][2];
int a[N];

ll solve(int l, int r, int player) {
    if (l > r) {
        return 0;
    }
    ll& ans = dp[l][r][2];
    if (ans != -1) {
        return ans;
    }
    ans = -1e18;
    if (player == 0) {
        ans = max(solve(l + 1, r, 1) + a[l], solve(l, r - 1, 1) + a[r]);
    } else {
        ans = min(solve(l + 1, r, 0) - a[l], solve(l, r - 1, 0) - a[r]);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof dp);
    cout << solve(1, n, 0);
    return 0;
}
