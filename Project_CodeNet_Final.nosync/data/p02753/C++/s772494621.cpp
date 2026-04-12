#include <iostream>

void solve() {
    char prev;
    std::cin >> prev;
    for (int i = 0; i < 2; ++i) {
        char c;
        std::cin >> c;
        if (c != prev) {
            std::cout << "Yes" << std::endl;
            return;
        }
        prev = c;
    }
    std::cout << "No" << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}
