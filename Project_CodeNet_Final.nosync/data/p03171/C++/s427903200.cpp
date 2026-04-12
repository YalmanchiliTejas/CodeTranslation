#include <bits/stdc++.h>
#define ll long long
#define lsb(x) (x & -x)

using namespace std;

const ll INF = 3000000000005;

void rundp(int i, int j, vector<vector<ll>> &dp, int n, const vector<ll> &v) {
    if(dp[i][j] != -INF)
        return;
    if(i + j == n) {
        dp[i][j] = 0;
        return;
    }

    rundp(i + 1, j, dp, n, v);
    rundp(i, j + 1, dp, n, v);

    dp[i][j] = max(v[i + 1] - dp[i + 1][j], v[n - j] - dp[i][j + 1]);
}

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);
    //freopen("a.in", "r", stdin);

    int n;
    cin >> n;
    vector<ll> v(n + 1, 0);
    for(int i = 1; i <= n; i ++)
        cin >> v[i];

    vector<vector<ll>> dp(n + 2, vector<ll> (n + 2, -INF));
    rundp(0, 0, dp, n, v);

    cout << dp[0][0];

    return 0;
}
