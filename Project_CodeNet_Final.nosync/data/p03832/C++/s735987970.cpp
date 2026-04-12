#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>
#include <cstring>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

typedef long long int ll;
using ll = long long int;
using ull = long long unsigned int;
using Int = long long int;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//edit
class Mint {
    using u64 = std::uint_fast64_t;
    u64 Modulus = MOD;

public:
    u64 a;

    constexpr Mint(const u64 x = 0) noexcept : a(x % Modulus) {}

    constexpr u64 &value() noexcept { return a; }

    constexpr const u64 &value() const noexcept { return a; }

    constexpr Mint operator+(const Mint rhs) const noexcept {
        return Mint(*this) += rhs;
    }

    constexpr Mint operator-(const Mint rhs) const noexcept {
        return Mint(*this) -= rhs;
    }

    constexpr Mint operator*(const Mint rhs) const noexcept {
        return Mint(*this) *= rhs;
    }

    constexpr Mint operator/(const Mint rhs) const noexcept {
        return Mint(*this) /= rhs;
    }

    constexpr Mint &operator+=(const Mint rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) {
            a -= Modulus;
        }
        return *this;
    }

    constexpr Mint &operator-=(const Mint rhs) noexcept {
        if (a < rhs.a) {
            a += Modulus;
        }
        a -= rhs.a;
        return *this;
    }

    constexpr Mint &operator*=(const Mint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }

    constexpr Mint &operator/=(Mint rhs) noexcept {
        u64 exp = Modulus - 2;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }

    constexpr Mint pow(int rhs) noexcept {
        Mint ret(1);
        Mint base(a);
        u64 exp = static_cast<u64>(rhs);
        while (exp) {
            if (exp % 2) {
                ret *= base;
            }
            base *= base;
            exp /= 2;
        }
        return ret;
    }

};


class Combination {
public:
    vector<Mint> fact;
    vector<Mint> ifact;

    Combination(int n) {
        fact.resize(static_cast<unsigned long>(n + 1));
        ifact.resize(static_cast<unsigned long>(n + 1));

        fact[0] = ifact[0] = Mint(1);
        for (int i = 1; i <= n; ++i) {
            fact[i] = fact[i - 1] * Mint(i);
            ifact[i] = Mint(1) / fact[i];
        }
    }

    Mint nPk(Int n, Int k) {
        return fact[n] * ifact[n - k];
    }

    Mint nCk(Int n, Int k) {
        return fact[n] * ifact[n - k] * ifact[k];
    }

    Mint nHk(Int n, Int k) {
        return nCk(n + k, n);
    }
};

Combination cmb(1001);

class Solve {
public:
    void solve() {
        Int N, A, B, C, D;
        cin >> N >> A >> B >> C >> D;
        vector<vector<Mint>> dp(N + 1, vector<Mint>(N + 1));
        dp[0][0] = 1;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= N; ++j) {
                dp[i + 1][j] += dp[i][j];
                for (Int k = C; k <= D && j + k * (i + 1) <= N; ++k) {
                    if (i + 1 < A) continue;
                    dp[i + 1][j + k * (i + 1)] += dp[i][j] * cmb.nPk(N - j, k * (i + 1))
                                                  * cmb.ifact[i + 1].pow(k) * cmb.ifact[k];
                }
            }
        }

//        Mint ans = dp[B][N] - dp[A - 1][N];
        Mint ans = dp[B][N];
        cout << ans.value() << endl;


    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}
