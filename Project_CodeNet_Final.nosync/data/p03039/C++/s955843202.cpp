#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e18

template <std::uint_fast64_t mod>
class ModInt {
    using u64 = std::uint_fast64_t;

   public:
    u64 x;
    ModInt(const ll x = 0) : x(x < 0 ? (mod - (-x % mod)) % mod : x % mod) {}

    ModInt operator+(const ModInt r) { return ModInt(*this) += r; }
    ModInt operator*(const ModInt r) { return ModInt(*this) *= r; }
    ModInt operator-(const ModInt r) { return ModInt(*this) -= r; }
    ModInt operator/(const ModInt r) { return ModInt(*this) /= r; }
    ModInt operator-() { return ModInt(mod - x); }

    ModInt &operator+=(const ModInt r) {
        x += r.x;
        if (x >= mod) x -= mod;
        return *this;
    }
    ModInt &operator-=(const ModInt r) {
        if (x < r.x) x += mod;
        x -= r.x;
        return *this;
    }
    ModInt &operator*=(const ModInt r) {
        x *= r.x;
        if (x >= mod) x %= mod;
        return *this;
    }
    ModInt &operator/=(ModInt r) {
        if (!(x % r.x)) {
            x /= r.x;
            return *this;
        }
        u64 p = mod - 2;
        while (p > 0) {
            if (p & 1) *this *= r;
            r *= r;
            p >>= 1;
        }
        return *this;
    }
    ModInt &operator++(int) { return (*this) += 1; }
    ModInt &operator++() { return (*this) += 1; }
    ModInt &operator--(int) { return (*this) -= 1; }
    ModInt &operator--() { return (*this) -= 1; }

    bool operator<(const ModInt r) { return x < r.x; }
    bool operator>(const ModInt r) { return x > r.x; }
    bool operator<=(const ModInt r) { return x <= r.x; }
    bool operator>=(const ModInt r) { return x >= r.x; }
    bool operator==(const ModInt r) { return x == r.x; }
    bool operator!=(const ModInt r) { return x != r.x; }

    ModInt inv() { return (ModInt)1 / (*this); }
    int get_mod() { return mod; }

    friend std::istream &operator>>(std::istream &in, ModInt &m) {
        ll a;
        in >> a;
        if (a < 0) a = mod - (-a % mod);
        if (a >= mod) a %= mod;
        m.x = a;
        return in;
    }
    friend std::ostream &operator<<(std::ostream &out, const ModInt &m) {
        out << m.x;
        return out;
    }
};
constexpr std::uint_fast64_t mod = 1e9 + 7;
using mint = ModInt<mod>;

template <typename T>
T fact(std::uint_fast32_t n) {
    static vector<T> factorial(1, 1);

    if (n < factorial.size())
        return factorial[n];
    else
        for (T i = factorial.size(); i <= n; i++) {
            factorial.push_back(factorial.back() * i);
        }
    return factorial[n];
}
template <typename T>
T invfact(std::uint_fast32_t n) {
    static vector<T> ifactorial(1, 1);

    if (n < ifactorial.size())
        return ifactorial[n];
    else
        for (T i = ifactorial.size(); i <= n; i++) {
            ifactorial.push_back(ifactorial.back() / i);
        }
    return ifactorial[n];
}
template <typename T>
T comb(std::uint_fast32_t a, std::uint_fast32_t b, bool small = false) {
    if (a == 0 && b == 0) return 1;
    if (a < b || a < 0) return 0;
    if (small) return fact<T>(a) / fact<T>(a - b) / fact<T>(b);
    if (!small) return fact<T>(a) * invfact<T>(a - b) * invfact<T>(b);
}

int main() {
    mint H, W;
    ll K;
    cin >> H >> W >> K;
    mint ans = 0;
    ans += H * H * comb<mint>((H * W - 2).x, K - 2) * W * (W * W - 1) / 6;
    ans += W * W * comb<mint>((H * W - 2).x, K - 2) * H * (H * H - 1) / 6;
    cout << ans << endl;
    return 0;
}