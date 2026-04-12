#include <algorithm>
#include <iostream>
int main(int argc, char const* argv[]) {
    int a, b, c, x, y;
    std::cin >> a >> b >> c >> x >> y;
    int nz = 0;
    if (c * 2 < a + b) {
        nz += std::min(x, y);
    }

    if (c * 2 < a) {
        nz += std::max(x - nz, 0);
    }

    if (c * 2 < b) {
        nz += std::max(y - nz, 0);
    }
    std::cout << a * std::min(std::max(0, x - nz), x) + b * std::min(std::max(0, y - nz), y) + c * nz * 2 << std::endl;
    return 0;
}
