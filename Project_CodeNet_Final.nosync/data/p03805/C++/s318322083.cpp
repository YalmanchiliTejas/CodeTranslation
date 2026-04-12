#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    auto n = std::size_t(0);
    auto m = 0;
    std::cin >> n >> m;

    auto adj = std::vector<std::vector<unsigned char>>(n, std::vector<unsigned char>(n, 0));
    for (auto i_ = 0; i_ < m; ++i_) {
        auto a = std::size_t(0);
        auto b = std::size_t(0);
        std::cin >> a >> b;
        adj[a - 1][b - 1] = 1;
        adj[b - 1][a - 1] = 1;
    }

    auto perm = std::vector<unsigned char>();
    perm.resize(n);
    std::iota(perm.begin(), perm.end(), 0);

    auto counter = 0;
    do {
        auto itr = perm.begin();
        while ((itr + 1 != perm.end()) && (adj[*itr][*(itr + 1)] != 0)) itr++;

        if (itr + 1 == perm.end()) counter++;
    } while (std::next_permutation(perm.begin() + 1, perm.end()));

    std::cout << counter << std::endl;
    return 0;
}