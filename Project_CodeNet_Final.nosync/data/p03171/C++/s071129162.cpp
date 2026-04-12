
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 3000;
int n, arr[maxn];
ll dp[maxn][maxn][2];

ll dfs(int s, int e, int t) {
    if (s > e) return 0;
    if (dp[s][e][t] != 0x3f3f3f3f3f3f3f3f) return dp[s][e][t];
    ll ans;
    if (!t) {
        ans = max(arr[s] + dfs(s + 1, e, !t), arr[e] + dfs(s, e - 1, !t));
    } else {
        ans = min(-arr[s] + dfs(s + 1, e, !t), -arr[e] + dfs(s, e - 1, !t));
    }
    return dp[s][e][t] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0x3f, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    ll ans = dfs(0, n - 1, 0);
    cout << ans << endl;

    return 0;
}

