#include <cstring>
#include <iostream>
using namespace std;
int main() {
    int N, S; cin >> N >> S;
    int a[N]; for (int i = 0; i < N; i++) cin >> a[i];
    long long dp[S+1];
    memset(dp, 0, sizeof dp);
    long long ans = 0;
    const int M = 998244353;
    for (int r = 0; r < N; r++) {
        for (int t = S-a[r]; t >= 0; t--)
            (dp[t+a[r]] += dp[t]) %= M;
        if (a[r] <= S) dp[a[r]] += r+1;
        ans += dp[S];
        ans %= M;
    }

    cout << ans % M << endl;
}
