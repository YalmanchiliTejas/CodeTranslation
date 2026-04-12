#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll INF = 1ll << 62;

int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int& n : nums)
        cin >> n;

    int marg = 1 + N % 2;

    vector<array<ll, 3>> dp(N);
    for (auto& a : dp)
        a.fill((-INF));
    for (int i = 0; i <= marg; i++)
        dp[i][marg - i] = nums[i];
    for (int i = 2; i < N; i++) {
        for (int j = 0; j <= marg; j++) {
            for (int k = 0; j + k <= marg; k++) {
                if (i - 2 - k >= 0)
                    dp[i][j] = max(dp[i][j], dp[i - 2 - k][j + k] + nums[i]);
            }
        }
    }
    ll ans = -INF;
    for (int i = N - 1 - marg; i < N; i++) {
        ans = max(ans, dp[i][N - 1 - i]);
    }
    cout << ans << endl;
}
