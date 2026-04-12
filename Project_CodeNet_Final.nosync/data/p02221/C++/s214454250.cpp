#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <functional>
#include <cassert>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<int> ps(1 << n);
    for (auto& p : ps) std::cin >> p;

    auto tab = vec(n + 1, vec(1 << n, 0));
    for (int i = 0; i < (1 << n); ++i) tab[0][i] = ps[i];

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i + (1 << k) < (1 << n); ++i) {
            int x = tab[k][i],
                y = tab[k][i + (1 << k)];
            if (x > y) std::swap(x, y);

            int win = (s[y - x - 1] == '0' ? x : y);
            tab[k + 1][i] = win;
        }
    }

    std::function<int(int, int, int)>
        dfs = [&](int l, int r, int k) {
            if (k == 0) {
                return (l == 1 ? tab[k][(1 << n) - 1] : tab[k][0]);
            }

            int x, y;
            if (l < r) {
                int rem = (1 << (k - 1)) - l;
                x = dfs(l, rem, k - 1);
                y = tab[k - 1][rem];
            } else {
                x = tab[k - 1][(1 << n) - l];
                y = dfs(l - (1 << (k - 1)), r, k - 1);
            }

            if (x > y) std::swap(x, y);
            return (s[y - x - 1] == '0' ? x : y);
        };

    for (int i = 0; i < (1 << n); ++i) {
        int l = (1 << n) - i,
            r = i;

        std::cout << dfs(l, r, n) << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}

