#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 3005;

int a[MAXN];
long long dp[MAXN][MAXN];
bool used[MAXN][MAXN];
int n;

long long solve(int l, int r) {
    if (l > r) return 0;
    if (used[l][r]) return dp[l][r];

    long long& ans = dp[l][r];
    if ((r - l) % 2 ==  (n - 1) % 2) {
        ans = max(a[l] + solve(l + 1, r), a[r] + solve(l, r - 1));
    } else {
        ans = min(-a[l] + solve(l + 1, r), -a[r] + solve(l, r - 1));
    }
    used[l][r] = true;
    return ans;
}

int main(void) {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &a[i]);
    }
    long long ans = solve(0, n - 1);
    printf("%lld\n", ans);

    return 0;
}
