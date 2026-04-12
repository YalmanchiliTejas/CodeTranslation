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
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::sort(a.begin(), a.end());
    if (~n & 1) {
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long s = i < n / 2 ? -2 : 2;
            if (i == n / 2 - 1 || i == n / 2) s /= 2;
            ans += s*a[i];
        }
        std::cout << ans << std::endl;
    }
    else {
        long long u = 0;
        for (int i = 0; i < n; i++) {
            long long s = i < n / 2 ? -2 : 2;
            if (i == n / 2 || i == n / 2 + 1) s /= 2;
            u += s*a[i];
        }
        long long v = 0;
        for (int i = 0; i < n; i++) {
            long long s = i <= n / 2 ? -2 : 2;
            if (i == n / 2 || i == n / 2 - 1) s /= 2;
            v += s*a[i];
        }
        std::cout << std::max(u, v) << std::endl;
    }
    return 0;
}
