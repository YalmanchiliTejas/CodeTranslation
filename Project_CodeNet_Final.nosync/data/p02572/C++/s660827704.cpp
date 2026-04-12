#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <limits>
#include <utility>
#include <algorithm>
#include <tuple>
#include <limits>

typedef long long ll;

const ll MOD = 1000000007;

int main(int argc, char *argv[])
{
    ll n;
    std::vector<ll> a;

    std::cin >> n;

    a.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<ll> b(n);
    b[n - 1] = a[n - 1];
    for (int i = n - 1; i > 0; i--) {
        b[i - 1] = (b[i] + a[i - 1]) % MOD;
    }

    ll sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += a[i] * b[i + 1];
        sum %= MOD;
    }

    std::cout << sum << std::endl;

    return 0;
}
