#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define mod 1000000007

ll dp[3001][3001][2], help[3001][3001][2];
vector<ll> v, pre;

ll f(ll l, ll r, ll player) {
    if (l > r) return 0;
    else if (l == r) return v[l];

    if (dp[l][r][player] != -1) return dp[l][r][player];

    ll score1 = v[l] + pre[r] - pre[l] - f(l + 1, r, 1 - player);
    ll score2 = v[r] + pre[r - 1] - (l ? pre[l - 1] : 0) - f(l, r - 1, 1 - player);

    if (score1 > score2) {
        help[l][r][player] = 0;
    } else {
        help[l][r][player] = 1;
    }
    dp[l][r][player] = max(score1, score2);
    return dp[l][r][player];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    v.resize(n);
    pre.resize(n);

    memset(dp, -1, sizeof(dp));

    for (auto &i : v) {
        cin >> i;
    }

    pre[0] = v[0];
    for (ll i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + v[i];
    }

    f(0, n - 1, 0);

    if (help[0][n - 1][0] == 0) {
        cout << f(0, n - 1, 0) - f(1, n - 1, 1);
    } else {
        cout << f(0, n - 1, 0) - f(0, n - 2, 1);
    }
}
