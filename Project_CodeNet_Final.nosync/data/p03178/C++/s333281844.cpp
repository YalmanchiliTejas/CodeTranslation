#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <std::uint_fast64_t mod>
class ModInt {
    using u64 = std::uint_fast64_t;

   public:
    u64 x;
    ModInt(const int x = 0) : x(x < 0 ? (mod - (-x % mod)) % mod : x % mod) {}

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
        *this *= r.pow(p);
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

    ModInt pow(u64 n) const {
        ModInt res(1), mul(x);
        while (n > 0) {
            if (n & 1) res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }
    ModInt inv() { return (ModInt)1 / (*this); }
    int get_mod() { return mod; }

    friend std::istream &operator>>(std::istream &in, ModInt &m) {
        int a;
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

int D;
mint solve(string &s, int k = 0, bool status = 1, int sum = 0) {
    static mint dp[10010][2][100];
    static bool visited[10010][2][100] = {};
    static int max_num = 9;

    if (k == s.size()) {
        return sum == 0;
    }

    mint &res = dp[k][status][sum];
    if (visited[k][status][sum])
        return res;
    else
        res = 0, visited[k][status][sum] = true;

    int r = (status ? s[k] - '0' : max_num);

    for (int i = 0; i <= r; i++) {
        int from = sum - i;
        if (from < 0) from = D - (-from % D);
        from %= D;
        mint cnt = solve(s, k + 1, status && i == r, from);
        res += cnt;
    }
    return res;
}

int main() {
    string K;
    cin >> K >> D;
    cout << solve(K) - 1 << endl;
    return 0;
}