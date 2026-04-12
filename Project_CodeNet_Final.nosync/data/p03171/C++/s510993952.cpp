#include <bits/stdc++.h>
#include "bits/stdc++.h"

using namespace std;

#define int long long

#ifndef bhupixb
    #define var(...)
    #define stl(...)
#endif

#define rep(i,a,b) for (int i = a; i <= (int)b; ++i)
#define f first
#define s second

#define single_test

const int maxn = 3003;

int a[maxn];
int dp[maxn][maxn][2];
bool vis[maxn][maxn][2];

int go(int l, int r, bool turn) {
    if (l > r) return 0;
    int &ref = dp[l][r][turn];
    if (vis[l][r][turn]) {
        return ref;
    }
    vis[l][r][turn] = true;
    int ans;
    if (turn == false) {
        ans = a[l] + go(l + 1, r, 1);
        ans = max(ans, a[r] + go(l, r - 1, 1));
    }
    else {
        ans = -a[l] + go(l + 1, r, 0);
        ans = min(ans, -a[r] + go(l, r - 1, 0));
    }
    return ref = ans;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << go(0, n - 1, 0) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    #ifndef single_test
        cin >> t;
    #endif
    for (int i = 1; i <= t; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}