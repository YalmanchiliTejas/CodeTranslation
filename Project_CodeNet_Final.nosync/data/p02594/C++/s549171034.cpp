#include <iostream>

void solve() {
    int x;
    std::cin >> x;
    std::cout << (x >= 30 ? "Yes" : "No") << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}
