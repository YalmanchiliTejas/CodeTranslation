//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <math.h>
#include <memory>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = int64_t;
using ull = uint64_t;
constexpr ll LL_MAX = numeric_limits<ll>::max();
constexpr ull ULL_MAX = numeric_limits<ull>::max();

template<typename T>
vector<T> make_vec_nd(T init, ll size) {
    return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, ll size, Args... rest) {
    auto inner = make_vec_nd(init, rest...);
    return vector<decltype(inner)>(size, inner);
}

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (a)-1; i >= (b); i--)

struct Mod {
    static uint64_t PRIME;
    uint64_t value = 0;
    Mod()
    : value(0) {}
    Mod(ll v) {
        if (v >= 0) {
            value = v % PRIME;
        } else {
            value = PRIME - (-v) % PRIME;
        }
    }
    Mod operator+(const Mod& rhs) const { return Mod(*this) += rhs; }
    Mod& operator+=(const Mod& rhs) {
        value += rhs.value;
        if (value >= PRIME) {
            value -= PRIME;
        }
        return *this;
    }
    Mod operator-(const Mod& rhs) const { return Mod(*this) -= rhs; }
    Mod& operator-=(const Mod& rhs) {
        if (value < rhs.value) {
            value += PRIME;
        }
        value -= rhs.value;
        return *this;
    }
    Mod operator*(const Mod& rhs) const { return Mod(*this) *= rhs; }
    Mod& operator*=(const Mod& rhs) {
        value = (value * rhs.value) % PRIME;
        return *this;
    }
    Mod inv() const { return power(*this, PRIME - 2); }
    Mod operator/(const Mod& rhs) const { return Mod(*this) /= rhs; }
    Mod& operator/=(const Mod& rhs) {
        *this *= rhs.inv();
        return *this;
    }
    static Mod power(Mod rhs, ll exp) {
        Mod ans = 1;
        while (exp > 0) {
            if (exp % 2) {
                ans *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return ans;
    }
};
uint64_t Mod::PRIME = 1000000007;

vector<Mod> fact;

Mod binom(ll n, ll r) {
    if (!(0 <= n && 0 <= r && r <= n)) {
        return 0;
    } else {
        return fact[n] / fact[r] / fact[n-r];
    }
}

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    fact.resize(max(N*M-2, max(N+1, M+1))+1,1);
    rep(n,1,fact.size()) {
        fact[n] = fact[n-1] * n;
    }
    Mod ans = 0;
    rep(i,0,2) {
        ans += Mod(M) * Mod(M) * binom(N+1, 3) * binom(N*M-2, K-2);
        swap(N,M);
    }
    cout << ans.value << endl;
}

