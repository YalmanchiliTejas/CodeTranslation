#include <bits/stdc++.h>


using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define reps(i,n) for (int i = 1; i <= (int)(n); ++i)
#define repd(i,n) for (int i = (int)(n - 1); i >= 0; --i)
#define repds(i,n) for (int i = (int)(n); i > 0; --i)
#define loop(i,x,n) for (int i = (int)(x); i < (n); ++i)
#define loops(i,x,n) for (int i = (int)(x); i <= (n); ++i)
#define loopd(i,x,n) for (int i = (int)(x); i > (n); --i)
#define loopds(i,x,n) for (int i = (int)(x); i >= (n); --i)
#define itrep(i,s) for (auto i = begin(s); i != end(s); ++i)
#define itrepd(i,s) for (auto i = --end(s); i != begin(s); --i)
#define all(f,x,...) [&](decltype(x)& whole) { return (f)(begin(whole), end(whole), ##__VA_ARGS__); }(x)
#define rall(f,x,...) [&](decltype(x)& whole) { return (f)(rbegin(whole), rend(whole), ##__VA_ARGS__); }(x)
using ll = long long;
using ld = long double;
constexpr ll inf = static_cast<ll>(1e17);
constexpr int iinf = static_cast<int>(1e9);
constexpr double dinf = 1e10;
constexpr ld ldinf = 1e17;
ll mod = static_cast<ll>(1e9 + 7);
std::ostream& endn(std::ostream& os) { return os.put(os.widen('\n')); }
template<class T> constexpr int sz(const T& a) { return (int)a.size(); }
template<class T, class ... Args> constexpr void mins(T& a, Args... args) { a = min<T>({ a, args... }); }
template<class T, class... Args> constexpr void maxs(T& a, Args... args) { a = max<T>({ a,args... }); }

template<class T>
struct ModInt {
    T x;
    ModInt(T x = 0) :x(x% mod) {}
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

class Comb
{
public:
    Comb() :fac(0), finv(0) {}
    Comb(int n) :fac(n + 1), finv(n + 1)
    {
        fac[0] = 1;
        for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i;
        finv[n] = fac[n].inv();
        for (int i = n; i >= 1; --i) finv[i - 1] = finv[i] * i;
    }

    void resize(int size) { *this = { size }; }

    mint C(int n, int k) {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k]);
    }
    mint P(int n, int k) {
        if (k < 0) return 0;
        return C(n, k) * fac[k];
    }
    // n!
    mint Fac(int n) {
        if (n < 0) return 0;
        return fac[n];
    }
    // 1/(n!)
    mint InvFac(int n) {
        if (n < 0) return 0;
        return finv[n];
    }

private:
    std::vector<mint> fac;
    std::vector<mint> finv;
};

int n, a, b, c, d;
Comb com;
mint dp[1005][1005];
void solve() {
    cin >> n >> a >> b >> c >> d;

    com.resize(n);
    dp[a][n] = 1;
    loop(i, a, b + 1) {
        mint res = com.InvFac(i).pow((ll)c - 1);
        rep(j, n + 1) {
            dp[i + 1][j] += dp[i][j];
            mint res2 = res;
            loop(k, c, d + 1) {
                if (i * k > j) break;
                dp[i + 1][j - i * k] += dp[i][j] * com.P(j, k * i) * com.InvFac(k) * (res2 *= com.InvFac(i));
            }
        }
    }

    cout << dp[b + 1][0].x << endn;

}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);

    solve();

    cout << flush;

    return 0;
}
