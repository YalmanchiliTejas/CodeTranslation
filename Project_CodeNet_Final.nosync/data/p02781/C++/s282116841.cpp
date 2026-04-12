#include <bits/stdc++.h>
using i64 = long long;

std::string s;
i64 dp[101][10][2];

i64 rec(int d, int r, int f) {
    if (d < 0) return r == 0;
    if (r == 0) return 1;
    if (dp[d][r][f] >= 0) return dp[d][r][f];

    i64 ret = rec(d - 1, r, f || s[d] != '0');
    for (int i = 1; i < 10; i++) {
        if (f) ret += rec(d - 1, r - 1, f);
        else if (i < s[d] - '0') ret += rec(d - 1, r - 1, 1);
        else if (i == s[d] - '0') ret += rec(d - 1, r - 1, f);
    }

    return dp[d][r][f] = ret;
}

int main() {
    int k;
    std::cin >> s >> k;

    std::reverse(s.begin(), s.end());

    for (int i = 0; i <= 100; i++) for (int j = 0; j < 10; j++) dp[i][j][0] = dp[i][j][1] = -1;

    i64 ret = rec(s.size() - 1, k, 0);
    std::cout << ret << std::endl;

    return 0;
}
