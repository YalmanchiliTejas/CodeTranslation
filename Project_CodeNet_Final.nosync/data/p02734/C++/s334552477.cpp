#include <bits/stdc++.h>
using i64 = long long;

int main() {
    constexpr i64 mod = 998244353;
    int n, s;
    std::cin >> n >> s;
    std::vector<int> a(n);
    for (auto &e : a) std::cin >> e;

    i64 ret = 0;
    std::vector<i64> dp(3001);
    for (int i = 0; i < n; i++) {
        auto next(dp);
        next[a[i]] = (next[a[i]] + i + 1) % mod;
        for (int j = 1; j + a[i] <= s; j++) {
            next[j + a[i]] = (next[j + a[i]] + dp[j]) % mod;
        }
        ret = (ret + next[s]) % mod;
        std::swap(dp, next);
    }

    std::cout << ret << std::endl;

    return 0;
}
