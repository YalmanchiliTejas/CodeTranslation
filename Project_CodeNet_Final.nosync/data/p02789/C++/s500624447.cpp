#include <iostream>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::cout << (n == m ? "Yes" : "No") << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}
