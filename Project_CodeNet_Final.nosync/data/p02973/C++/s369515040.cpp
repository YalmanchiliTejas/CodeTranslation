#include <set>
#include <iostream>
#include <functional>

int main() {
    int n;
    std::cin >> n;
    long long first;
    std::cin >> first;
    int ans = 1;
    std::multiset<long long, std::greater<long long>> set;
    set.insert(first);

    for (int i = 1; i < n; ++i) {
        long long next;
        std::cin >> next;
        auto it = set.upper_bound(next);
        if (it == set.end()) {
            ans++;
        } else {
            set.erase(it);
        }
        set.insert(next);
    }

    std::cout << set.size();
}
