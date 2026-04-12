#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c;
    std::cin >> a >> b >> c;
    int r = 100 * a + 10 * b + c;
    std::cout << (((r % 4) == 0) ? "YES" : "NO") << std::endl;
}
