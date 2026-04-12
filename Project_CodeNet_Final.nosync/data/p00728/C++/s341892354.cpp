#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<int> vec;
    while (true) {
        vec.clear();

        int n;
        std::cin >> n;

        if (n == 0)
            break;
        
        vec.resize(n);
        for (auto&& e : vec)
            std::cin >> e;
        
        std::sort(vec.begin(), vec.end());
        std::cout << std::accumulate(vec.begin() + 1, vec.end() - 1, 0) / (n - 2) << std::endl;
    }
}
