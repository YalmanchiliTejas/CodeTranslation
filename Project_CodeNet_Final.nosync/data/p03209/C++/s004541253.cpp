#include <bits/stdc++.h>
using namespace std;

int64_t leftPs(int n, int64_t x) {
    int64_t sz = (1LL << (n + 2)) - 3;
    if (x == sz) return (1LL << (n + 1)) - 1;
    if (x == 1) return 0;
    if (x == sz / 2 + 1) return 1LL << n;
    if (x < sz / 2 + 1) return leftPs(n - 1, x - 1);
    if (x > sz / 2 + 1) return (1LL << n) + leftPs(n - 1, x - (sz / 2 + 1));
}

int main() {
    int n;
    int64_t x;
    cin >> n >> x;
    cout << leftPs(n, x) << '\n';
}
