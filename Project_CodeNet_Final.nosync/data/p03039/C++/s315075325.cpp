#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
typedef long long ll;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

template <uint_fast64_t MOD> class ModInt {
    using u64 = uint_fast64_t;

  public:
    u64 a;

    constexpr ModInt(const u64 x = 0) noexcept : a(x % MOD) {}
    constexpr u64 &value() noexcept { return a; }
    constexpr const u64 &value() const noexcept { return a; }
    constexpr ModInt operator+(const ModInt rhs) const noexcept {
        return ModInt(*this) += rhs;
    }
    constexpr ModInt operator-(const ModInt rhs) const noexcept {
        return ModInt(*this) -= rhs;
    }
    constexpr ModInt operator*(const ModInt rhs) const noexcept {
        return ModInt(*this) *= rhs;
    }
    constexpr ModInt operator/(const ModInt rhs) const noexcept {
        return ModInt(*this) /= rhs;
    }
    constexpr ModInt &operator+=(const ModInt rhs) noexcept {
        a += rhs.a;
        if(a >= MOD) {
            a -= MOD;
        }
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt rhs) noexcept {
        if(a < rhs.a) {
            a += MOD;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt rhs) noexcept {
        a = a * rhs.a % MOD;
        return *this;
    }
    constexpr ModInt &operator/=(ModInt rhs) noexcept {
        u64 exp = MOD - 2;
        while(exp) {
            if(exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }
    constexpr bool operator==(const ModInt rhs) noexcept {
        return this->a == rhs.a;
    }
    constexpr bool operator!=(const ModInt rhs) noexcept {
        return this->a != rhs.a;
    }
    friend constexpr ostream &operator<<(ostream &os,
                                         const ModInt<MOD> &x) noexcept {
        return os << x.a;
    }
    friend constexpr istream &operator>>(istream &is, ModInt<MOD> &x) noexcept {
        return is >> x.a;
    }
};

//二項係数（nCk mod.p;1<=k<=n<=1e7,pは素数）
template <class T> struct Combination {
    const int MOD = 1000000007;
    vector<T> fac, finv, inv;
    Combination(const int MAX) : fac(MAX), finv(MAX), inv(MAX) {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for(int i = 2; i < MAX; i++) {
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }
    T comb(int n, int k) {
        if(n < k)
            return 0;
        if(n < 0 || k < 0)
            return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }
};

int main() {
    using mint = ModInt<MOD>;
    ll N, M, K;
    cin >> N >> M >> K;
    Combination<ll> C(N * M);
    mint sum = 0;
    for(int i = 1; i < N; i++) {
        sum += mint(i) * mint(N - i) * mint(M * M);
    }
    for(int j = 1; j < M; j++) {
        sum += mint(j) * mint(M - j) * mint(N * N);
    }
    cout << sum * mint(C.comb(N * M - 2, K - 2)) << endl;
    return 0;
}