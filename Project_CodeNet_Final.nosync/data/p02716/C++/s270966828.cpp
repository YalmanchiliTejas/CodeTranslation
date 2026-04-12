#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
using i64 = long long;

int main() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (auto &e : a) std::cin >> e;

    std::vector<std::map<int, i64>> dp(n + 1);
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 2; k++) {
            const int c = i / 2 + k;
            for (int j = 2; j <= 4; j++) {
                const int p = i - j;
                if (p < 0) {
                    if (c == 0) dp[i][c] = 0;
                    else if (c == 1) dp[i][c] = a[i];
                } else {
                    const auto it = dp[p].find(c - 1);
                    if (it == dp[p].end()) continue;
                    if (dp[i].find(c) == dp[i].end()) dp[i][c] = a[i] + it->second;
                    else dp[i][c] = std::max(dp[i][c], a[i] + it->second);
                }
            }
        }
    }

    i64 ret = std::numeric_limits<i64>::min();
    for (int i = 0; i < n; i++) {
        const auto it = dp[i].find(n / 2);
        if (it != dp[i].end() && it->second > ret) ret = it->second;
    }

    std::cout << ret << std::endl;

    return 0;
}
