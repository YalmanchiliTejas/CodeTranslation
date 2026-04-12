#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC return 0;
using namespace std;
const int N(3003);
int64_t dp[N][N], v[N];
int n;
inline int64_t Solve(int l, int r) {
    if (l > r)
        return 0;
    if (l == r)
        return v[l];
    if (dp[l][r] != -1)
        return dp[l][r];
    dp[l][r] = max(v[l] - Solve(l + 1, r), v[r] - Solve(l, r - 1));
    return dp[l][r];
}
int main() {
    DAU
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        dp[i][i] = v[i];
    }
    cout << Solve(1, n);
    PLEC
}