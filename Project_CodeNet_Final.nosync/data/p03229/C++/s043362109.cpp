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
    std::deque<long long> b, ans;
    auto func = [&](bool t) {
        ans.clear();
        for (int i = t; i < n - !t; i++) b.push_back(a[i]);
        ans.push_back(a[t ? 0 : n - 1]);
        bool flag = t;
        while (!b.empty()) {
            if (flag) {
                ans.push_front(b.back()), b.pop_back();
                if (!b.empty()) ans.push_back(b.back()), b.pop_back();
            }
            else {
                ans.push_front(b.front()), b.pop_front();
                if (!b.empty()) ans.push_back(b.front()), b.pop_front();
            }
            flag = !flag;
        }
        long long sum = 0;
        for (int i = 0; i < n - 1; i++) {
            sum += std::abs(ans[i] - ans[i + 1]);
        }
        return sum;
    };
    std::cout << std::max(func(true), func(false)) << std::endl;
    return 0;
}