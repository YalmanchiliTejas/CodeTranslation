#include <bits/stdc++.h>

// ====================================================================
const int MOD = 1e9 + 7;
int add(int a, int b) {int ret = (a % MOD) + (b % MOD); if (ret >= MOD)ret -= MOD; return ret;}
int sub(int a, int b) {int ret = ((a % MOD) - (b % MOD)); if (ret < 0)ret += MOD; return ret;}
int mul(int a, int b) {return (1LL * (a % MOD) * (b % MOD)) % MOD;}
// ====================================================================

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);
    std::vector<int> sum(n + 1);

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        sum[i] = add(sum[i - 1], a[i]);
    }

    int ans = 0;

    for (int i = 1; i < n; i++) {
        ans = add(ans, mul(sub(sum[n], sum[i]), a[i]));
    }

    std::cout << ans;

    return 0;
}

