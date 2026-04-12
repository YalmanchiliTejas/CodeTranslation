#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N = 2e5 + 5;
int n;
ll arr[N], dp[N][3];
int lst;
ll solve(int idx, int state) {
    if (idx >= n)
        return 0;
    ll &ret = dp[idx][state];
    if (ret != -1)
        return ret;
    ret = -1e18;
    if (state < 2)
        ret = solve(idx + 1, state + 1);
    if (idx != n - 1 || state)
        ret = max(ret, arr[idx] + solve(idx + 2, state));
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof dp);
    if (n % 2 == 1)
        cout << solve(0, 0);
    else
        cout << solve(0, 1);
    return  0;
}