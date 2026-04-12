#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

template <std::int_fast64_t Modulus>
class ModInt {
    using i64 = std::int_fast64_t;

private:
    i64 m_value;

public:
    constexpr ModInt(const i64 x = 0) noexcept : m_value(x % Modulus) {
        if (m_value < 0) m_value += Modulus;
    }

    constexpr const i64& value() const noexcept { return m_value; }

    constexpr ModInt& operator+=(const ModInt rhs) noexcept {
        m_value += rhs.m_value;
        if (m_value >= Modulus) {
            m_value -= Modulus;
        }
        return *this;
    }
    constexpr ModInt& operator-=(const ModInt rhs) noexcept {
        if (m_value < rhs.m_value) {
            m_value += Modulus;
        }
        m_value -= rhs.m_value;
        return *this;
    }
    constexpr ModInt& operator*=(const ModInt rhs) noexcept {
        m_value = m_value * rhs.m_value % Modulus;
        return *this;
    }
    constexpr ModInt& operator/=(ModInt rhs) noexcept {
        i64 exp = Modulus - 2;
        while (exp) {
            if (exp & 1) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp >>= 1;
        }
        return *this;
    }

    constexpr ModInt& operator++() noexcept {
        *this += 1;
        return *this;
    }
    constexpr ModInt operator++(int) noexcept {
        ModInt res = *this;
        *this += 1;
        return res;
    }
    constexpr ModInt& operator--() noexcept {
        *this -= 1;
        return *this;
    }
    constexpr ModInt operator--(int) noexcept {
        ModInt res = *this;
        *this -= 1;
        return res;
    }

    constexpr ModInt pow(i64 k) const noexcept {
        ModInt res = 1;
        ModInt tmp = *this;
        for (; k > 0; k >>= 1) {
            if (k & 1) res *= tmp;
            tmp *= tmp;
        }
        return res;
    }

    constexpr ModInt inv() const noexcept {
        i64 q = m_value;
        i64 b = Modulus, u = 1, v = 0;
        while (b) {
            i64 t = q / b;
            q -= t * b;
            swap(q, b);
            u -= t * v;
            swap(u, v);
        }
        u %= Modulus;
        if (u < 0) u += Modulus;
        return u;
    }

    friend constexpr ModInt operator+(const ModInt& lhs, const ModInt& rhs) noexcept {
        return ModInt<Modulus>(lhs) += rhs;
    }
    friend constexpr ModInt operator-(const ModInt& lhs, const ModInt& rhs) noexcept {
        return ModInt<Modulus>(lhs) -= rhs;
    }
    friend constexpr ModInt operator*(const ModInt& lhs, const ModInt& rhs) noexcept {
        return ModInt<Modulus>(lhs) *= rhs;
    }
    friend constexpr ModInt operator/(const ModInt& lhs, const ModInt& rhs) noexcept {
        return ModInt<Modulus>(lhs) /= rhs;
    }

    friend constexpr ModInt operator<(const ModInt& lhs, const ModInt& rhs) noexcept {
        return lhs.m_value < rhs.m_value;
    }
    friend constexpr ModInt operator>(const ModInt& lhs, const ModInt& rhs) noexcept {
        return lhs.m_value > rhs.m_value;
    }
    friend constexpr ModInt operator<=(const ModInt& lhs, const ModInt& rhs) noexcept {
        return lhs.m_value <= rhs.m_value;
    }
    friend constexpr ModInt operator>=(const ModInt& lhs, const ModInt& rhs) noexcept {
        return lhs.m_value >= rhs.m_value;
    }

    friend constexpr ModInt operator==(const ModInt& lhs, const ModInt& rhs) noexcept {
        return lhs.m_value == rhs.m_value;
    }
    friend constexpr ModInt operator!=(const ModInt& lhs, const ModInt& rhs) noexcept {
        return lhs.m_value != rhs.m_value;
    }

    friend std::istream& operator>>(std::istream& is, ModInt& rhs) {
        i64 a;
        is >> a;
        rhs = a;
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const ModInt& rhs) {
        os << rhs.m_value;
        return os;
    }
};

template <std::int_fast64_t Modulus>
class ModComb {
    using i64 = int_fast64_t;
    using Vl = std::vector<i64>;

private:
    Vl fac, inv, finv;

public:
    ModComb(i64 n) : fac(n + 1), inv(n + 1), finv(n + 1) {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (i64 i = 2; i < n + 1; ++i) {
            fac[i] = fac[i - 1] * i % Modulus;
            inv[i] = Modulus - inv[Modulus % i] * (Modulus / i) % Modulus;
            finv[i] = finv[i - 1] * inv[i] % Modulus;
        }
    }

    ModInt<Modulus> comb(i64 n, i64 k) {
        ModInt<Modulus> res;
        if (n < k)
            res = 0;
        else if (n < 0 || k < 0)
            res = 0;
        else
            res = fac[n] * (finv[n - k] * finv[k] % Modulus) % Modulus;
        return res;
    }

    ModInt<Modulus> get_fac(i64 n) { return ModInt<Modulus>(fac[n]); }
    ModInt<Modulus> get_finv(i64 n) { return ModInt<Modulus>(finv[n]); }
};


constexpr ll MOD = 1e9 + 7;
using Mint = ModInt<MOD>;

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif

    ll N, M, K;
    cin >> N >> M >> K;

    Mint ans = 0;
    ModComb<MOD> mc(200000);
    Mint cmb = mc.comb(N * M - 2, K - 2);

    for (ll d = 0; d < N; d++) {
        ans += d * cmb * (N - d) * M * M;
    }
    for (ll d = 0; d < M; d++) {
        ans += d * cmb * (M - d) * N * N;
    }

    cout << ans << "\n";

    return 0;
}