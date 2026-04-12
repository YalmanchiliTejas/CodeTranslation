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
#include <cassert>

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
using uInt = long long unsigned int;
using Double = long double;
using namespace std;
#define INF (1 << 30) - 1
#define INFl (ll)5e15
#define DEBUG 0
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 998244353


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

    constexpr Mint &pow(int rhs) noexcept {
        u64 exp = static_cast<u64>(rhs);
        Mint base(a);
        a = 1;
        while (exp) {
            if (exp % 2) {
                *this *= base;
            }
            base *= base;
            exp /= 2;
        }
        return *this;
    }

};

class Solve {
public:
    void solve() {
        Int N, S;
        cin >> N >> S;
        vector<Int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        vector<vector<Mint>> dp(S + 1, vector<Mint>(3));
        dp[0][0] = 1;


        for (int i = 0; i < N; ++i) {
            for (int j = S; j >= 0; --j) {
                if (j + A[i] <= S) {
                    Mint l = i + 1;
                    Mint r = N - i;

                    dp[j + A[i]][1] += dp[j][0] * l;
                    dp[j + A[i]][2] += dp[j][0] * l * r;

                    dp[j + A[i]][1] += dp[j][1];
                    dp[j + A[i]][2] += dp[j][1] * r;

//                    dp[j + A[i]][2] += dp[j][2];
                }
            }

//            for (int j = 0; j <= S; ++j) {
//                cout << dp[j][1].value() << " ";
//            }
//            cout << endl;
//            for (int j = 0; j <= S; ++j) {
//                cout << dp[j][2].value() << " ";
//            }
//            cout << endl;
//            cout << "-----------------" << endl;

//            if (i == 0) {
//                dp[0][0] = 0;
//            }
        }

        Mint ans = dp[S][2];
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
