#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define pb push_back
#define all(x) x.begin(), x.end()
#define pi pair<int, int>
#define l first
#define r second
#define int long long

using namespace std;

const int maxn = 2e5 + 1, mod = 1e9 + 7;

int a[maxn], n;

pi solve(int md) {
    vector<pi> dp(n + 1);
    dp[0] = {0, 0};
    dp[1] = ((a[0] + md > 0) ? pi(a[0] + md, 1) : pi(0, 0));
    for (int i = 1; i < n; i++)
        dp[i + 1] = (dp[i - 1].l + a[i] + md > dp[i].l ? pi(dp[i - 1].l + a[i] + md, dp[i - 1].r + 1) : dp[i]);
    return dp[n];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = -1e12, r = 1e12;
    while (r - l > 1) {
        int md = (l + r) / 2;
        if (solve(md).r >= n / 2)
            r = md;
        else
            l = md;
    }
    auto gg = solve(r);
    cout << gg.l - (n/2) * r;
    return 0;
}
