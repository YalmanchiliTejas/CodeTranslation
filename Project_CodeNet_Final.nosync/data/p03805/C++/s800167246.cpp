
#include <vector>
#include <algorithm>
#include <cstdint>
#include <iostream>

using std::vector;
using std::uint64_t;

const unsigned int NMAX = 8;
constexpr unsigned int MMAX = NMAX * (NMAX - 1) / 2;

uint64_t search(vector<vector<unsigned int>>& e, vector<unsigned int>& stack, const unsigned int max) {
    unsigned int root = stack.back();
    if (stack.size() == max) {
        return 1;
    }

    uint64_t sum = 0;
    for (unsigned int v : e[root]) {
        if (std::find(stack.begin(), stack.end(), v) != stack.end()) {
            continue;
        }
        stack.push_back(v);
        sum += search(e, stack, max);
        stack.pop_back();
    }

    return sum;
}

int main() {
    unsigned int n, m;
    
    std::cin >> n >> m;

    vector<vector<unsigned int>> e;
    e.reserve(n);
    for (int i = 0; i < n; i++) {
        vector<unsigned int> tmp;
        e.emplace_back(tmp);
    }
    for (int i = 0; i < m; i++) {
        unsigned int src, dst;
        std::cin >> src >> dst;
        src -= 1; dst -= 1;
        e[src].push_back(dst);
        e[dst].push_back(src);
    }
    
    vector<unsigned int> stack;
    stack.push_back(0);
    unsigned int ans = search(e, stack, n);
    std::cout << ans << std::endl;
}