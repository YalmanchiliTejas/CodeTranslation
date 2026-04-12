#include <bits/stdc++.h>
using namespace std;
void Main();

using i8  = int8_t;   /* -128 ~ 127 */
using u8  = uint8_t;  /* 0 ~ 255 */
using i16 = int16_t;  /* -32,768 ~ 32,767 */
using u16 = uint16_t; /* 0 ~ 65,535 */
using i32 = int32_t;  /* -2,147,483,648 ~ 2,147,483,647 */
using u32 = uint32_t; /* 0 ~ 4,294,967,295 */
using i64 = int64_t;  /* -9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807 */
using u64 = uint64_t; /* 0 ~ 18,446,744,073,709,551,615 */
using f32 = float;    /* (-3.4 * 10^38) ~ (3.4 * 10^38) */
using f64 = double;   /* (-1.7 * 10^308) ~ (1.7 * 10^308) */
using f80 = __float80;
template <class T> using Vec = vector<T>;
constexpr i64 INF = 1010000000000000017;
constexpr i64 MOD = 1e9 + 7;
constexpr f64 EPS = 1e-12;
constexpr f64 PI = 3.14159265358979323846;
#define ALL(v) v.begin(), v.end()
#define YN(a, b, c) ((c)? a : b)
#define GCD(a, b) __gcd(a, b) /* 最大公約数 */
#define LCM(a, b) a / __gcd(a, b) * b /* 最小公倍数 */

template<u32 MOD> struct Fp {
    i64 val;
    constexpr Fp(i64 v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }

    constexpr u64 getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        i64 a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            i64 t = a / b;
            a -= t * b; swap(a ,b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, i64 n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};

using mi64 = Fp<MOD>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}

void Main() {
    i32 N;
    cin >> N;
    Vec<i64> A(N);
    Vec<i64> S(N + 1, 0);
    i64 s = 0;
    for (i32 i = 0; i < N; i++) {
        i64 t; cin >> t;
        A[i] = t;
        s += t;
    }
    S[0] = s;
    for (i32 i = 1; i <= N; i++) {
        S[i] = S[i - 1] - A[i - 1];
    }
    mi64 sum = 0;
    for (i32 i = 0; i < N; i++) {
        sum += mi64(A[i]) * mi64(S[i + 1]);
    }
    cout << sum << endl;
}
