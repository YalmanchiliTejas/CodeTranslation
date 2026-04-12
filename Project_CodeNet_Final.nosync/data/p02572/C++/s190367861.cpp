#include <iostream>
using i64 = long long;

int main() {
    constexpr i64 mod = 1000000007;
    int n;
    std::cin >> n;

    i64 ret = 0, s = 0;
    for (int i = 0; i < n; i++) {
        i64 a;
        std::cin >> a;
        ret = (ret + a * s) % mod;
        s = (s + a) % mod;
    }

    std::cout << ret << std::endl;

    return 0;
}
