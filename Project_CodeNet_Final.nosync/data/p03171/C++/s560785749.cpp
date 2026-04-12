#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

using ll = long long;

const int N = 3005;

ll dp[N][N];
ll a[N];
int n;

void solve() {
    // dp[L][R]: the max value the first player can achieve with interval L, R
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int L = n - 1; L >= 0; --L) {
        for (int R = L; R < n; ++R) {
            if (L == R) dp[L][R] = a[L];
            dp[L][R] = max(a[L] - dp[L+1][R], a[R] - dp[L][R-1]);
        }
    }
    printf("%lld\n", dp[0][n - 1]);
}

int main() {
    while (~scanf("%d", &n)) {
        solve();
    }
    return 0;
}
