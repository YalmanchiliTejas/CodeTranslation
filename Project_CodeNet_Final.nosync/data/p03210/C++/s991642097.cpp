#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <algorithm>

using ll = long long;

int main() {
    int X;
    std::cin >> X;
    if (X == 3 || X == 5 || X == 7) {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}
