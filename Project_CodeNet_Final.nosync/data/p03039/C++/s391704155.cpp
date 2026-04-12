#ifdef _MSC_VER
#include <__msvc_all_public_headers.hpp>
#undef min
#undef max
#else
#define NDEBUG
#include <bits/stdc++.h>
#endif

using namespace std;
using large = long long;

constexpr auto mod = 1'000'000'007;

template <large M> static large pow(const large b, const large e) {
    if (e < 0)
        return 0;
    if (e == 0)
        return 1;
    if (e == 1)
        return b;

    auto p = (e % 2 == 0 ? large{1} : b);
    return p * pow<M>(b * b % M, e / 2) % M;
}

template <large M> static large inv(const large k) { return pow<M>(k % M, M - 2); }
template <large M> static large fac(const large x) {
    if (x < 0)
        return 0;
    if (x <= 1)
        return 1;

    auto c = large{1};
    for (auto i = x; i >= 2; --i) {
        c *= i;
        c %= M;
    }
    return c;
}

template <large M = mod> static large choose(const large n, const large k) {
    // n! / (k! * (n-k)!)
    auto fn = fac<M>(n);
    auto fk = inv<M>(fac<M>(k));
    auto fnk = inv<M>(fac<M>(n - k));

    auto c = fn * fk;
    c %= M;
    c *= fnk;
    c %= M;
    return c;
}

static large solve(const large m, const large n) {
    auto sum = 0LL;
    const auto nn = n * n % mod;
    for (auto dx = 1; dx < m; dx++) {
        auto cnt = m - dx;
        auto dxsum = dx * cnt % mod;
        dxsum = (dxsum * nn) % mod;
        sum += dxsum;
        sum %= mod;
    }
    return sum;
}

int main() {
    large n, m, k;
    cin >> n >> m >> k;

    auto sum = solve(m, n) + solve(n, m);
    sum %= mod;
    sum *= choose(m * n - 2, k - 2);
    sum %= mod;
    cout << sum << endl;
    return 0;
}
