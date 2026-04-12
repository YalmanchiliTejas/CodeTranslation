#include <algorithm>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, s, t) for (int i = s; i < t; i++)
#define ALL(obj) obj.begin(), obj.end()
#define fcout cout << fixed << setprecision(10)
const int iINF = 1e9;
const long long llINF = 1e18;
const int MOD = 1e9 + 7;
template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

template <int MOD>
struct ModInt {
    long long val;
    constexpr ModInt(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr ModInt operator-() const noexcept { return val ? MOD - val : 0; }
    constexpr ModInt operator+(const ModInt& r) const noexcept { return ModInt(*this) += r; }
    constexpr ModInt operator-(const ModInt& r) const noexcept { return ModInt(*this) -= r; }
    constexpr ModInt operator*(const ModInt& r) const noexcept { return ModInt(*this) *= r; }
    constexpr ModInt operator/(const ModInt& r) const noexcept { return ModInt(*this) /= r; }
    constexpr ModInt& operator+=(const ModInt& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr ModInt& operator-=(const ModInt& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr ModInt& operator*=(const ModInt& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr ModInt& operator/=(const ModInt& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator==(const ModInt& r) const noexcept { return this->val == r.val; }
    constexpr bool operator!=(const ModInt& r) const noexcept { return this->val != r.val; }
    friend constexpr ostream& operator<<(ostream& os, const ModInt<MOD>& x) noexcept { return os << x.val; }

    friend constexpr istream& operator>>(istream& is, ModInt<MOD>& x) noexcept { return is >> x.val; }
    friend constexpr ModInt<MOD> modpow(const ModInt<MOD>& a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};

using mint = ModInt<MOD>;

long long modPow(long long x, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

long long extGCD(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    long long d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

template <typename T>
map<T, int> compress(vector<T> x) {
    map<T, int> res;
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    for (int i = 0; i < x.size(); i++) {
        res[x[i]] = i;
    }

    return res;
}

template <typename T>
int former(const vector<T>& v, T x) {
    return upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
}

template <typename T>
int latter(const vector<T>& v, T x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

template <typename T>
using Vec = vector<T>;
template <typename T>
using VVec = vector<vector<T>>;
using LL = long long;
int main() {
    int N;
    cin >> N;
    Vec<LL> A(N);
    REP(i, N) cin >> A[i];
    multiset<LL> s;
    REP(i, N) {
        auto itr = s.lower_bound(A[i]);
        if (itr != s.begin()) s.erase(--itr);
        s.insert(A[i]);
    }
    cout << s.size() << endl;
    return 0;
}