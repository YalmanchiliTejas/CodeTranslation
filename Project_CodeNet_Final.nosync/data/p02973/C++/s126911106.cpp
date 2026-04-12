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
    int n; std::cin >> n;
    std::vector<int> dp(n + 2, 1e9 + 2);
    dp[0] = -1e9 - 2;
    for (int i = 0; i < n; i++) {
        int a; std::cin >> a;
        auto iter = std::upper_bound(dp.begin(), dp.end(), -a);
        *iter = -a;
    }
    std::cout << std::lower_bound(dp.begin(), dp.end(), 1e9 + 2)
        - dp.begin() - 1 << std::endl;
    return 0;
}
