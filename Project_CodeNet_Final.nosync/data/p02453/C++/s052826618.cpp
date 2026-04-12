#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> v(N);
    for (auto& e : v) std::cin >> e;

    int Q;
    std::cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int k;
        std::cin >> k;
        std::cout << (std::lower_bound(v.begin(), v.end(), k) - v.begin()) << std::endl;
    }
}

