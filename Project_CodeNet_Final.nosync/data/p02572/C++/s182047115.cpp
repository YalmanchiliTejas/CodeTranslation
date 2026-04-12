#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define REPr(i, n) for(int i = (n)-1; i >= 0; --i)
#define FORq(i, m, n) for(int i = (m); i <= (n); ++i)
#define FORqr(i, m, n) for(int i = (n); i >= (m); --i)
#define MP make_pair
#define SIN(x, S) (S.count(x) != 0)
#define M0(x) memset(x, 0, sizeof(x))
#define FILL(x, y) memset(x, y, sizeof(x))
#define MM(x) memset(x, -1, sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define DB(x) cerr << #x << " = " << x << endl
#define DB2(x, y)                                                              \
    cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define DEBUG                                                                  \
    int x12345;                                                                \
    cin >> x12345;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef long long ll;
typedef long long integer;
const long long MOD = 1e9 + 7;
///////////////////////////////////////////////
// for template
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
///////////////////////////////////////////////

template <int MOD> struct Fp {
    long long val;

    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if(val < 0)
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
        if(val >= MOD)
            val = val % MOD;

        if(val < 0)
            val += MOD * ((-val + MOD - 1) / MOD);

        return *this;
    }

    constexpr Fp &operator-=(const Fp &r) noexcept {
        val -= r.val;
        if(val < 0)
            val += MOD * ((-val + MOD - 1) / MOD);
        val = val % MOD;
        return *this;
    }

    constexpr Fp &operator*=(const Fp &r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }

    constexpr Fp &operator/=(const Fp &r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while(b) {
            long long t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        val = val * u % MOD;
        if(val < 0)
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
        if(n == 0)
            return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if(n & 1)
            t = t * a;
        return t;
    }
};

using mint = Fp<MOD>;

/// 🍈( '-' 🍈 |AC|
int main() {
    int N; cin >> N;
    vector<mint> A(N),B(N);
    REP(i,N){
        cin >> A[i];
    }
    REPr(i, N){
        if (i == N - 1){
            B[i] = A[i];
            continue;
        }
        B[i] = A[i] + B[i + 1];
    }

    mint ans = 0;

    REP(i, N - 1){
        ans = ans + A[i] * B[i + 1];
    }
    cout << ans << endl;
}