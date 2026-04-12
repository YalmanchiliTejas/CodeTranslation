#include <iostream>
#include <algorithm>

int main() {
    long long n, k, ret = 0;
    std::cin >> n >> k;

    if (k == 0) {
        std::cout << n * n << std::endl;
        return 0;
    }

    for (auto a = k + 1; a <= n; a++) {
        ret += n / a * (a - k) + std::max(0ll, (n % a) - k + 1);
    }

    std::cout << ret << std::endl;

    return 0;
}