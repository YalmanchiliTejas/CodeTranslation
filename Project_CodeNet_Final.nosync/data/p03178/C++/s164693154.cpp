#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::string k;
    int d;
    const i64 mod = 1000000007;
    std::cin >> k >> d;

    std::vector<std::vector<i64>> dp(d, std::vector<i64>(2));
    for (int i = 0; i < k[0] - '0'; i++) dp[i % d][0]++;
    dp[(k[0] - '0') % d][1] = 1;
    for (unsigned i = 1; i < k.size(); i++) {
        int t = k[i] - '0';
        decltype(dp) cp(d, std::vector<i64>(2));
        for (int j = 0; j < d; j++) {
            for (int p = 0; p < 10; p++) cp[(j + p) % d][0] = (cp[(j + p) % d][0] + dp[j][0]) % mod;
            for (int p = 0; p < t; p++) cp[(j + p) % d][0] = (cp[(j + p) % d][0] + dp[j][1]) % mod;
            cp[(j + t) % d][1] = dp[j][1];
        }
        std::swap(cp, dp);
    }

    std::cout << (dp[0][0] + dp[0][1] + mod - 1) % mod << std::endl;

    return 0;
}