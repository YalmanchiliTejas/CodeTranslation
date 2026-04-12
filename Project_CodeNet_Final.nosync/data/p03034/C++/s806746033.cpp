#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int n;
    std::cin >> n;
    std::vector<i64> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    i64 ret = 0;
    for (int d = 1; d < n; d++) {
        i64 c = 0;
        int l = 0, r = n - 1;
        while (1) {
            l += d;
            r -= d;
            if ((l >= r && r % d == 0) || r < d || l >= n - 1) break;
            c += s[l] + s[r];
            ret = std::max(ret, c);
        }
    }
    std::cout << ret << std::endl;

    return 0;
}
