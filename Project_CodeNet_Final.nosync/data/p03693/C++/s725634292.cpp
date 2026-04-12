#include <bits/stdc++.h>

int main() {
    int r, g, b;
    std::cin >> r >> g >> b;

    if ((100 * r + 10 * g + b) % 4 == 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}
