#include <iostream>
#include <string>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    const auto d = 100*a + 10*b + c;
    const auto ret = (d % 4 == 0) ? "YES" : "NO";

    std::cout << ret << std::endl;
}
