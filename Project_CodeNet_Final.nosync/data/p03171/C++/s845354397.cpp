#include <bits/stdc++.h>
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;
typedef long double lld;
typedef long long ll;
const ll inf = 1e18;
const int maxn = 3005;
ll a[maxn], dp[maxn][maxn];

ll dfs(int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != inf) return dp[l][r];
    dp[l][r] = max(a[l] - dfs(l + 1, r), a[r] - dfs(l, r - 1));
    return dp[l][r];
}

int main() {
//    freopen("in.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = inf;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << dfs(1, n)<< endl;
    return 0;
}