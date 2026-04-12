// Author: Shusuke Ueda
// AtCoder Beginner Contest 134 - Problem E

#include <iostream>
#include <vector>
#include <set>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& e: a) {
        std::cin >> e;
    }

    std::multiset<int> s;
    for (auto e: a) {
        auto it = s.lower_bound(e);
        if (it == s.begin()) {
            s.insert(e);
        } else {
            it--;
            s.erase(it);
            s.insert(e);
        }
    }

    std::cout << s.size() << std::endl;

    return 0;
}