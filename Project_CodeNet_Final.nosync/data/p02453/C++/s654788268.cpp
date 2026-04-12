#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main(void) {
    int n;
    std::cin >> n;

    std::vector<int> vec{};
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        vec.push_back(a);
    }

    int q;
    std::cin >> q;

    for (int j = 0; j < q; ++j) {
        int k;
        std::cin >> k;

        int location = std::distance(
            vec.begin(), std::lower_bound(vec.begin(), vec.end(), k));
        std::cout << location << std::endl;
    }
}
