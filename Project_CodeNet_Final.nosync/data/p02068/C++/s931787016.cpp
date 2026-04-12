#include <iostream>
#include <vector>
#include <set>

using Int = long long int;
using std::vector;

int main() {
    int n;
    std::cin >> n;
    vector<Int> a(n);
    for (auto& x : a) std::cin >> x;

    std::set<Int> primes;
    for (auto x : a) {
        for (Int p = 2; p * p <= x; ++p) {
            if (x % p != 0) continue;
            primes.insert(p);
            while (x % p == 0) x /= p;
        }
        if (x > 1) primes.insert(x);
    }

    Int ans = 0;
    for (auto p : primes) {
        Int sum = 0;
        for (auto x : a) {
            if (x % p == 0) sum += x;
        }
        ans = std::max(ans, sum);
    }

    std::cout << ans << std::endl;
    return 0;
}

