#include <bits/stdc++.h>
#define int long long int
#define ld long double
#define pb push_back
#define pf push_front
#define ft first
#define sc second
#define all(v) v.begin(), v.end()
using namespace std;
const int maxn = 201001, inf = 1e17;
int suf[maxn];
int dp[maxn][3];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> mas(2*n, 0);
    for (int d = 0; d < n; d++) {
        cin >> mas[d];
    }
    for (int d = n - 1; d >= 0; d--) {
        suf[d] = suf[d + 1] + mas[d];
        if (d > 0) {
            suf[d - 1] = suf[d];
            d--;
        }
    }
    if (n % 2 == 0) {
        int ans = suf[0];
        int sm = 0;
        for (int d = 0; d < n; d+=2) {
            sm += mas[d];
            ans = max(ans, sm + suf[d + 3]);
        }
        cout << ans;
        return 0;
    } else {
        for (int d = 0; d <= n + 5; d++) {
            dp[d][0] = -inf;
            dp[d][1] = -inf;
            dp[d][2] = -inf;
        }
        dp[0][0] = mas[0];
        dp[1][1] = mas[1];
        dp[2][2] = mas[2];
        for (int d = 0; d < n; d++) {
            if (d % 2 == 0) {
                dp[d + 1][0] = max(dp[d + 1][0], dp[d][0]);
                dp[d + 3][1] = max(dp[d + 3][1], dp[d][0] + mas[d + 3]);
                dp[d + 4][2] = max(dp[d + 4][2], dp[d][0] + mas[d + 4]);
            } else {
                dp[d + 1][0] = max(dp[d + 1][0], dp[d][0] + mas[d + 1]);
                dp[d + 2][1] = max(dp[d + 2][1], dp[d][0] + mas[d + 2]);
                dp[d + 3][2] = max(dp[d + 3][2], dp[d][0] + mas[d + 3]);
            }
            if (d % 2 == 1) {
                dp[d + 1][1] = max(dp[d + 1][1], dp[d][1]);
                dp[d + 3][2] = max(dp[d + 3][2], dp[d][1] + mas[d + 3]);
            } else {
                dp[d + 1][1] = max(dp[d + 1][1], dp[d][1] + mas[d + 1]);
                dp[d + 2][2] = max(dp[d + 2][2], dp[d][1] + mas[d + 2]);
            }
            if (d % 2 == 0) {
                dp[d + 1][2] = max(dp[d + 1][2], dp[d][2]);
            } else {
                dp[d + 1][2] = max(dp[d + 1][2], dp[d][2] + mas[d + 1]);
            }
        }
        int ans = dp[n - 2][0];
        ans = max(ans, dp[n - 1][1]);
        ans = max(ans, dp[n][2]);
        cout << ans;
    }
}
