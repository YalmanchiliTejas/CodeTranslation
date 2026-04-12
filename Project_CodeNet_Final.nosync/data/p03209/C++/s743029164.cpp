#include <bits/stdc++.h>
using i64 = long long;

i64 s[60];

i64 calc(i64 l, i64 j) {
    if (!j) return 0;
    if (!l) return 1;
    if (j <= (s[l] - 1) / 2) return calc(l - 1, j - 1);
    if (j == (s[l] - 1) / 2 + 1) return calc(l - 1, s[l - 1]) + 1;
    if (j == s[l]) return 2 * calc(l - 1, s[l - 1]) + 1;
    return calc(l - 1, s[l - 1]) + calc(l - 1, j - s[l - 1] - 2) + 1;
}

int main() {
    i64 n, x;
    std::cin >> n >> x;
    s[0] = 1;
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] * 2 + 3;
    }
    std::cout << calc(n, x) << std::endl;

    return 0;
}