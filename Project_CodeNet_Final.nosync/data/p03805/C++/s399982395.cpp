#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <complex>
#include <iomanip>
#include <cassert>
#include <random>


int main() {
    int n, m; std::cin >> n >> m;
    std::vector<std::vector<int>> edg(n);
    for (int i = 0; i < m; i++) {
        int a, b; std::cin >> a >> b;
        a--; b--;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    auto dfs = [&](auto &self, int pos, int s) {
        if (s == (1 << n) - 1) return 1;
        int ret = 0;
        for (int c : edg[pos]) {
            if ((s >> c) & 1) continue;
            ret += self(self, c, s | (1 << c));
        }
        return ret;
    };
    std::cout << dfs(dfs, 0, 1) << std::endl;
    return 0;
}
