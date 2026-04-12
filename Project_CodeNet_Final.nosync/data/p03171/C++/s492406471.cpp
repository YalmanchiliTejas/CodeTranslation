#include <bits/stdc++.h>

using namespace std;

const int M = 3e3 + 3;
int n, t[M];
long long dp[M][M][2];

long long solve (int s, int e, int p) {
    if (s > e) return 0;
    long long &ret = dp[s][e][p];
    if (ret != -1) return ret;
    if (p == 0) {
        ret = max (solve(s+1, e, 1)+t[s], solve (s, e-1, 1) + t[e]);
    }
    if (p == 1) {
        ret = min (solve(s+1, e, 0)-t[s], solve (s, e-1, 0) - t[e]);
    }
    return ret;
}

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf ("%d", &t[i]);
    memset (dp, -1, sizeof dp);
    cout << solve (0, n-1, 0);
}
