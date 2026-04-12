#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int n;
    std::cin >> n;
    int max = 0, ret = 0;
    for (int i = 0; i < n; i++) {
        int h;
        std::cin >> h;
        if (h >= max) ret++;
        max = std::max(max, h);
    }
    std::cout << ret << std::endl;

    return 0;
}
