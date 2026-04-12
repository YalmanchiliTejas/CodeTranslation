#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

namespace chrono = std::chrono;
using namespace std::literals;

[[gnu::constructor]]
void fast_iostream() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);
}

int main() {
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    for (long long b = 1; b <= n; ++b) {
        long long cur = (n / b) * std::max(0LL, b - k) + std::max(0LL, n % b + (k != 0) - k);
        ans += cur;
    }
    cout << ans << endl;
}
