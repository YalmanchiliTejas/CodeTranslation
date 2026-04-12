#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

template <int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0)
            v += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator-() const noexcept { return val ? MOD - val : 0; }
    constexpr Fp operator+(const Fp &r) const noexcept {
        return Fp(*this) += r;
    }
    constexpr Fp operator-(const Fp &r) const noexcept {
        return Fp(*this) -= r;
    }
    constexpr Fp operator*(const Fp &r) const noexcept {
        return Fp(*this) *= r;
    }
    constexpr Fp operator/(const Fp &r) const noexcept {
        return Fp(*this) /= r;
    }
    constexpr Fp &operator+=(const Fp &r) noexcept {
        val += r.val;
        if (val >= MOD)
            val -= MOD;
        return *this;
    }
    constexpr Fp &operator-=(const Fp &r) noexcept {
        val -= r.val;
        if (val < 0)
            val += MOD;
        return *this;
    }
    constexpr Fp &operator*=(const Fp &r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp &operator/=(const Fp &r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0)
            val += MOD;
        return *this;
    }
    constexpr bool operator==(const Fp &r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator!=(const Fp &r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream &operator<<(ostream &os,
                                         const Fp<MOD> &x) noexcept {
        return os << x.val;
    }
    friend constexpr istream &operator>>(istream &is, Fp<MOD> &x) noexcept {
        return is >> x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0)
            return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1)
            t = t * a;
        return t;
    }
};

const int MOD = 1000000007;
using mint = Fp<MOD>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<mint> A(N), sum(N);
    rep(i, N) {
        cin >> A[i];
        sum[i] = A[i];
    }

    rep(i, N - 1) { sum[i + 1] += sum[i]; }

    mint ans = 0;
    rep(i, N) { ans += A[i] * (sum[N - 1] - sum[i]); }

    cout << ans << endl;
}