#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int const maxn = 3030;

int a[maxn];
ll dp[maxn][maxn];

ll solve(int l, int r) {
    if (l == r) {
        return a[l];
    }

    ll& d = dp[l][r];

    if (d != -1) {
        return d;
    }

    d = max(a[l] - solve(l+1, r), a[r] - solve(l, r-1));

    return d;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(0, n-1) << "\n";
}