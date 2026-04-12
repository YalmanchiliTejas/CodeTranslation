#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MIN(a) *std::min_element((a).begin(), (a).end())
#define MAX(a) *std::max_element((a).begin(), (a).end())
#define SUM(a) std::accumulate((a).begin(), (a).end(), 0LL)
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define RREP(i, n) for (int (i) = (n)-1; (i) >= 0; (i)--)
#define FOR(i, m, n) for (int (i) = (m); (i) < (n); i++)
#define FORR(i, m, n) for (int (i) = (n)-1; (i) >= (m); i--)
#define debug(x) std::cerr << #x << " = " << x << '\n'
// #define int long long

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vl = std::vector<long long>;
using vvl = std::vector<std::vector<long long>>;
// using bint = boost::multiprecision::cpp_int;
// using rat = boost::rational<bint>;

constexpr int inf = (1 << 30) - 1;
constexpr long long INF = 1LL << 60;
constexpr double eps = 1e-9;

inline void ios_() {std::cin.tie(nullptr); std::ios::sync_with_stdio(false);}
template<typename T> inline T Div(const T& a, const T& b) {return (a + b - 1) / b;}
template<typename T> bool chmin(T& a, const T& b) {if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, const T& b) {if(a < b){a = b; return true;} return false;}

template<typename T>
inline void finish(const T& msg) {
    std::cout << msg << std::endl;
    std::exit(0);
}

template<typename T>
long long binarySearch(long long ng, long long ok, const T& fn) {
    while (std::abs(ok - ng) > 1) {
        long long mid = (ok + ng) / 2;
        if (fn(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

struct ModInt {
    long long value;
    static constexpr long long mod = 1e9+7;
    // static constexpr long long mod = 998244353;

    constexpr ModInt(long long v = 0) : value(((v % mod) + mod) % mod) {}

    constexpr ModInt pow(long long n) const {
        long long x = value, res = 1;
        while (n > 0) {
            if (n & 1) {
                res = res * x % mod;
            }
            x = x * x % mod;
            n >>= 1;
        }
        return ModInt(res);
    }

    constexpr ModInt inverse() const {
        return pow(mod - 2);
    }

    constexpr ModInt operator-() const {
        return ModInt((mod - value) % mod);
    }

    constexpr ModInt& operator+=(const ModInt& a) {
        value += a.value;
        value %= mod;
        return *this;
    }

    constexpr ModInt& operator-=(const ModInt& a) {
        value += (-a).value;
        value %= mod;
        return *this;
    }

    constexpr ModInt& operator*=(const ModInt& a) {
        value *= a.value;
        value %= mod;
        return *this;
    }

    constexpr ModInt& operator/=(const ModInt& a) {
        return (*this) *= a.inverse();
    }

    constexpr ModInt operator+(const ModInt& a) const {
        return ModInt(*this) += a;
    }

    constexpr ModInt operator-(const ModInt& a) const {
        return ModInt(*this) -= a;
    }

    constexpr ModInt operator*(const ModInt& a) const {
        return ModInt(*this) *= a;
    }

    constexpr ModInt operator/(const ModInt& a) const {
        return ModInt(*this) /= a;
    }

    constexpr bool operator==(const ModInt& a) const {
        return value == a.value;
    }

    constexpr bool operator!=(const ModInt& a) const {
        return value != a.value;
    }

    friend std::istream& operator>>(std::istream& is, ModInt& a) {
        long long v;
        is >> v;
        a = v;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const ModInt& a) {
        os << a.value;
        return os;
    }

    static ModInt factorial(int n) {
        static std::vector<ModInt> fact(1 << 18);

        if (fact.size() <= n) fact.resize(n + 1);

        if (n < 0) return 0;
        if (n == 0) return 1;
        if (fact[n] != 0) return fact[n];

        return fact[n] = factorial(n - 1) * n;
    }

    static ModInt combin(int n, int k) {
        if (n < 0 || k < 0 || n < k) return 0;
        return factorial(n) / (factorial(k) * factorial(n - k));
    }
};

using mint = ModInt;



signed main() {
    int x;
    cin >> x;
    cout << (x >= 30 ? "Yes" : "No") << endl;
    return 0;
}
