#include <bits/stdc++.h>

int main() {
    long long n, ret;
    std::cin >> n;
    std::vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::sort(a.begin(), a.end());
    std::reverse(a.begin(), a.end());
    while (a[0] >= n) {
        long long sub = 0;
        for (int i = 0; i < n; i++) {
            auto c = a[i] - (n - 1);
            b[i] = c / n + (c % n > 0);
            sub += b[i];
            a[i] -= n * b[i];
        }
        for (int i = 0; i < n; i++) a[i] += sub - b[i];
        ret += sub;
        std::sort(a.begin(), a.end());
        std::reverse(a.begin(), a.end());
    }

    std::cout << ret << std::endl;

    return 0;
}