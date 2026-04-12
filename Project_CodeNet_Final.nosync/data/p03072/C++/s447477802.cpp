#include <iostream>
#include <algorithm>
int main() {
    int n;
    std::cin >> n;
    int h0 = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int h1;
        std::cin >> h1;
        if (h0 <= h1) {
            h0 = h1;
            ans++;
        }
    }
    std::cout << ans;
}