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

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

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
        *this *= rhs.inv();
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

    constexpr ModInt inv() const noexcept {
        i64 q = m_value;
        i64 b = Modulus, u = 1, v = 0;
        while (b) {
            i64 t = q / b;
            q -= t * b;
            std::swap(q, b);
            u -= t * v;
            std::swap(u, v);
        }
        u %= Modulus;
        if (u < 0) u += Modulus;
        return u;
    }

    constexpr ModInt pow(i64 k) const noexcept {
        ModInt res = 1;
        ModInt tmp;
        if (k < 0) {
            tmp = (*this).inv();
            k = -k;
        }
        else {
            tmp = *this;
        }
        for (; k > 0; k >>= 1) {
            if (k & 1) res *= tmp;
            tmp *= tmp;
        }
        return res;
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

    friend constexpr bool operator<(const ModInt& lhs, const ModInt& rhs) noexcept {
        return lhs.m_value < rhs.m_value;
    }
    friend constexpr bool operator>(const ModInt& lhs, const ModInt& rhs) noexcept {
        return lhs.m_value > rhs.m_value;
    }
    friend constexpr bool operator<=(const ModInt& lhs, const ModInt& rhs) noexcept {
        return lhs.m_value <= rhs.m_value;
    }
    friend constexpr bool operator>=(const ModInt& lhs, const ModInt& rhs) noexcept {
        return lhs.m_value >= rhs.m_value;
    }

    friend constexpr bool operator==(const ModInt& lhs, const ModInt& rhs) noexcept {
        return lhs.m_value == rhs.m_value;
    }
    friend constexpr bool operator!=(const ModInt& lhs, const ModInt& rhs) noexcept {
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

constexpr ll MOD = 998244353;
using Mint = ModInt<MOD>;

Mint dp[3010][3010];

void solve() {
    ll N, S;
    cin >> N >> S;
    Vl A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (ll i = 0; i < N; i++) {
        dp[i + 1][A[i]] += i + 1;
        for (ll j = 1; j <= S; j++) {
            if (j - A[i] >= 0) {
                dp[i + 1][j] += dp[i][j - A[i]];
            }
            dp[i + 1][j] += dp[i][j];
        }
    }

    Mint ans = 0;
    for (ll i = 1; i <= N; i++) {
        ans += dp[i][S];
    }
    cout << ans << "\n";
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif
#ifdef FILEOUTPUT
    ofstream ofs("./in_out/output.txt");
    cout.rdbuf(ofs.rdbuf());
#endif
    solve();
    cout << flush;
    return 0;
}