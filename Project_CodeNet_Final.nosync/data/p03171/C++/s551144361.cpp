#include <bits/stdc++.h>

using namespace std;

int n, score[3005];
long long dp[3005][3005];

long long solve(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l > r) return 0;

    int turn = l + n - 1 - r;

    if ((turn & 1) == 0) {
        return dp[l][r] = max(solve(l + 1, r) + score[l], solve(l, r - 1) + score[r]);
    }
    else {
        return dp[l][r] = min(solve(l + 1, r) - score[l], solve(l, r - 1) - score[r]);
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &score[i]);

    memset(dp, -1, sizeof(dp));

    printf("%lld\n", solve(0, n - 1));
}
