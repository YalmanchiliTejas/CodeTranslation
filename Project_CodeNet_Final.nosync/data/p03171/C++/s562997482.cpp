#include <bits/stdc++.h>
using i64 = long long;

constexpr i64 inf = std::numeric_limits<i64>::max();

i64 dp[3030][3030];
i64 a[3030];

i64 rec2(int, int);

i64 rec1(int l, int r) {
    if (r - l == 1) return a[l];
    if (dp[l][r] != inf) return dp[l][r];
    return dp[l][r] = std::max(a[l] + rec2(l + 1, r), a[r - 1] + rec2(l, r - 1));
}

i64 rec2(int l, int r) {
    if (r - l == 1) return -a[l];
    if (dp[l][r] != inf) return dp[l][r];
    return dp[l][r] = std::min(-a[l] + rec1(l + 1, r), -a[r - 1] + rec1(l, r - 1));
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (auto &el : dp) for (auto &e : el) e = inf;

    std::cout << rec1(0, n) << std::endl;

    return 0;
}