#pragma GCC target("avx2,avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//using i128 = __int128_t;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
constexpr char ln = '\n';
constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
template<class T1, class T2> inline bool chmax(T1 &a, T2 b) {if (a < b) {a = b; return true;} return false;}
template<class T1, class T2> inline bool chmin(T1 &a, T2 b) {if (a > b) {a = b; return true;} return false;}
inline int topbit(int x) {return x == 0 ? -1 : 31-__builtin_clz(x);}
inline int topbit(long long x) {return x == 0 ? -1 : 63-__builtin_clzll(x);}
inline int botbit(int x) {return x == 0 ? 32 : __builtin_ctz(x);}
inline int botbit(long long x) {return x == 0 ? 64 : __builtin_ctzll(x);}
inline int popcount(int x) {return __builtin_popcount(x);}
inline int popcount(long long x) {return __builtin_popcountll(x);}
inline void print() {cout << "\n";}
template<class T>
inline void print(const vector<T> &v) {
    for (auto itr = v.begin(); itr != v.end(); ++itr) cout << *itr << " ";
    print();
}
template<class T, class... Args>
inline void print(const T &x, const Args &... args) {
    cout << x << " ";
    print(args...);
}
#ifdef MINATO_LOCAL
#define dump(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;
inline void debug() {cerr << endl;}
template<class T>
inline void debug(const vector<T> &v) {
    for (auto itr = v.begin(); itr != v.end(); ++itr) cerr << *itr << " ";
    debug();
}
template<class T, class... Args>
inline void debug(const T &x, const Args &... args) {
    cerr << x << " ";
    debug(args...);
}
#else
#define dump(x) void(0)
inline void debug() {}
template<class T> inline void debug(const vector<T> &v) {}
template<class T, class... Args> inline void debug(const T &x, const Args &... args) {}
#endif
struct Fast_ios {Fast_ios() {cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20);};} fast_ios;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <uint_fast64_t Modulus> 
struct ModInt {
    using u64 = uint_fast64_t;

    u64 a;

    constexpr ModInt(const long long x = 0) noexcept : a(x >= 0 ? x % Modulus : (Modulus - (-x) % Modulus) % Modulus) {}
    constexpr u64 &value() noexcept {return a;}
    constexpr const u64 &value() const noexcept {return a;}
    constexpr ModInt operator+(const ModInt rhs) const noexcept {return ModInt(*this) += rhs;}
    constexpr ModInt operator-(const ModInt rhs) const noexcept {return ModInt(*this) -= rhs;}
    constexpr ModInt operator*(const ModInt rhs) const noexcept {return ModInt(*this) *= rhs;}
    constexpr ModInt operator/(const ModInt rhs) const noexcept {return ModInt(*this) /= rhs;}
    constexpr ModInt operator^(const long long rhs) const noexcept {return ModInt(*this) ^= rhs;}
    constexpr bool operator==(const ModInt &rhs) const noexcept {return a == rhs.a;}
    constexpr bool operator!=(const ModInt &rhs) const noexcept {return a != rhs.a;}
    constexpr ModInt &operator+=(const ModInt rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) {
            a -= Modulus;
        }
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt rhs) noexcept {
        if (a < rhs.a) {
            a += Modulus;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr ModInt &operator/=(ModInt rhs) noexcept {
        u64 exp = Modulus - 2;
        while (exp) {
            if (exp&1) *this *= rhs;
            exp >>= 1;
            rhs *= rhs;
        }
        return *this;
    }
    constexpr ModInt &operator^=(long long exp) noexcept {
        ModInt rhs = a;
        a = 1;
        while (exp) {
            if (exp&1) *this *= rhs;
            exp >>= 1;
            rhs *= rhs;
        }
        return *this;
    }

    friend ostream &operator<<(ostream& os, const ModInt& rhs) noexcept {return os << rhs.a;}
    friend istream &operator>>(istream& is, ModInt& rhs) noexcept {long long a; is >> a; rhs = a; return is;}
};

using mint = ModInt<MOD>;
int main() {
    int N; cin >> N;
    vector<mint> A(N);
    rep(i,N) cin >> A[i];

    mint ans = accumulate(all(A),mint(0));
    ans *= ans;
    rep(i,N) ans -= A[i]*A[i];
    ans /= 2;
    cout << ans << ln;
}