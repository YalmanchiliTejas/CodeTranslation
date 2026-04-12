#include <iostream>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

using lint = long long;

void solve() {
    lint n;
    int x, m;
    std::cin >> n >> x >> m;

    auto to = vec(40, vec(m, -1));
    auto sum = vec(40, vec(m, 0LL));
    for (lint i = 0; i < m; ++i) {
        to[0][i] = (i * i) % m;
        sum[0][i] = i;
    }

    for (int k = 0; k + 1 < 40; ++k) {
        for (int i = 0; i < m; ++i) {
            to[k + 1][i] = to[k][to[k][i]];
            sum[k + 1][i] = sum[k][i] + sum[k][to[k][i]];
        }
    }

    lint ans = 0;
    for (int k = 0; k < 40; ++k) {
        if ((~n >> k) & 1) continue;
        ans += sum[k][x];
        x = to[k][x];
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}
