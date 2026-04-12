#include <bits/stdc++.h>

#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define reps(i,n) for (int i = 1; i <= (int)(n); ++i)
#define repd(i,n) for (int i = (int)(n - 1); i >= 0; --i)
#define repds(i,n) for (int i = (int)(n); i > 0; --i)
#define loop(i,x,n) for (int i = (int)(x); i < (n); ++i)
#define loops(i,x,n) for (int i = (int)(x); i <= (n); ++i)
#define loopd(i,x,n) for (int i = (int)(x); i > (n); --i)
#define loopds(i,x,n) for (int i = (int)(x); i >= (n); --i)
#define itrep(i,a) for (auto i = begin(a); i != end(a); ++i)
#define itrepd(i,a) for (auto i = rbegin(a); i != rend(a); ++i)
#define all(f,x,...) [&](decltype(x)& whole) { return (f)(begin(whole), end(whole), ##__VA_ARGS__); }(x)
using namespace std;
using ll = long long;
using ld = long double;
constexpr ll inf = static_cast<ll>(1e18);
constexpr int iinf = static_cast<int>(1e9);
constexpr double dinf = 1e10;
constexpr ld ldinf = 1e18;
ll mod = static_cast<ll>(1e9 + 7);
template<class T> constexpr int sz(const T& a) { return (int)a.size(); }
template<class T> constexpr T pow2(const T a) { return a * a; }
template<class T, class ... Args> constexpr void mins(T& a, Args... args) { a = min<T>({ a, args... }); }
template<class T, class... Args> constexpr void maxs(T& a, Args... args) { a = max<T>({ a,args... }); }
template<class A, int N, class T>
void fillArray(A(&array)[N], const T& val) { std::fill((T*)array, (T*)(array + N), val); }

template<class T>
struct ModInt {
    T x;
    ModInt(T x = 0) :x((x + mod) % mod) {}
    ModInt& operator+=(const ModInt a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    ModInt& operator-=(const ModInt a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    ModInt& operator*=(const ModInt a) {
        (x *= a.x) %= mod;
        return *this;
    }
    ModInt operator+(const ModInt a) const {
        ModInt res(*this);
        return res += a;
    }
    ModInt operator-(const ModInt a) const {
        ModInt res(*this);
        return res -= a;
    }
    ModInt operator*(const ModInt a) const {
        ModInt res(*this);
        return res *= a;
    }
    ModInt pow(T t) const {
        if (!t) return 1;
        ModInt a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }
    ModInt inv() const {
        return pow(mod - 2);
    }
    ModInt& operator/=(const ModInt a) {
        return (*this) *= a.inv();
    }
    ModInt operator/(const ModInt a) const {
        ModInt res(*this);
        return res /= a;
    }
};
using mint = ModInt<long long>;


string s;
int d;
mint dp[10005][105][2];
void solve() {
    cin >> s >> d;
    dp[0][0][0] = 1;
    rep(i, sz(s)) rep(j, d + 1) rep(k, 10) {
        if (k < s[i] - '0') dp[i + 1][(j + k) % d][1] += dp[i][j][0];
        else if (k == s[i] - '0') dp[i + 1][(j + k) % d][0] += dp[i][j][0];
        dp[i + 1][(j + k) % d][1] += dp[i][j][1];
    }
    cout << (dp[sz(s)][0][0] + dp[sz(s)][0][1] - mint(1)).x << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
