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
    std::multiset<int> s;
    for (int i = 0; i < n; i++) {
        int a; std::cin >> a;
        auto iter = s.lower_bound(a);
        if (iter == s.begin()) {
            s.insert(a);
        }
        else {
            iter--;
            s.erase(iter);
            s.insert(a);
        }
    }
    std::cout << s.size() << std::endl;
    return 0;
}
