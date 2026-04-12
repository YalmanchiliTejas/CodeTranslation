#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long dp[N] = {};
long long arr[N] = {};
long long per[N] = {};
long long DP(int x) {
    if (~dp[x]) return dp[x];
    if (x & 1)
        return dp[x] = max(arr[x] + DP(x - 2), arr[x - 1] + DP(x - 3));
    else
        return dp[x] = max(arr[x] + DP(x - 2), arr[x - 1] + per[x - 2]);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        per[i] = per[i - 1] + arr[i] * (i & 1);
    fill(dp, dp + n + 1, -1);
    dp[0] = 0;
    dp[1] = 0;
    cout << DP(n) << '\n';
    return 0;
}