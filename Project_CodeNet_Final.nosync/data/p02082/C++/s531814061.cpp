#include <iostream>

int main() {
    int s, t, p, q, m, y;
    std::cin >> s >> t >> p >> q >> m >> y;
    std::cout << (s ^ t ^ y) << std::endl;
    return 0;
}

