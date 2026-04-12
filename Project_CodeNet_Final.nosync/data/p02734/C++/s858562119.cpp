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
constexpr std::uint_fast64_t mod = 998244353;
using mint = ModInt<mod>;

int main() {
    int N, S;
    cin >> N >> S;
    vector<int> A(N + 1);
    for (int i = 0; i < N; i++) cin >> A[i + 1];

    vector<vector<mint>> dp(N + 1, vector<mint>(S + 1, 0));
    mint ans = 0;
    for (int i = 1; i <= N; i++) {
        dp[i - 1][0]++;
        for (int x = 0; x <= S; x++) {
            if (dp[i - 1][x] > 0) {
                dp[i][x] += dp[i - 1][x];
                if (x + A[i] <= S) dp[i][x + A[i]] += dp[i - 1][x];
            }
        }
    }
    for (int i = 1; i <= N; i++) ans += dp[i][S];
    cout << ans << endl;
    return 0;
}