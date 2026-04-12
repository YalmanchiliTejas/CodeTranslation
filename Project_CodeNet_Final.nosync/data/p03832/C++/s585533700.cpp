#include <bits/stdc++.h>
using namespace std;

struct Benri { Benri() { std::cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(12);}} benri;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vll = vector<long long>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define F first
#define S second

template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

constexpr long long MOD = 1000000007;
//constexpr long long MOD = 998244353;
//constexpr int INF = 1001001001;
constexpr ll INF = 1001001001001001001ll;
constexpr double EPS = 1e-10;
using number = long long;


template< int64_t mod >
struct mInt {
    int64_t x;

    mInt() : x(0LL) {}
    mInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
    mInt &operator+=(const mInt &p) { if ((x += p.x) >= mod) x -= mod; return *this; }
    mInt &operator-=(const mInt &p) {if ((x += mod - p.x) >= mod) x -= mod; return *this;}
    mInt &operator*=(const mInt &p) { x = (x * p.x % mod); return *this;}
    mInt &operator/=(const mInt &p) { *this *= p.inverse(); return *this;}
    mInt operator-() const { return mInt(-x); }
    mInt operator+(const mInt &p) const { return mInt(*this) += p; }
    mInt operator-(const mInt &p) const { return mInt(*this) -= p; }
    mInt operator*(const mInt &p) const { return mInt(*this) *= p; }
    mInt operator/(const mInt &p) const { return mInt(*this) /= p; }
    bool operator==(const mInt &p) const { return x == p.x; }
    bool operator!=(const mInt &p) const { return x != p.x; }
    mInt inverse() const {
        int64_t a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {t = a / b; swap(a -= t * b, b); swap(u -= t * v, v);}
        return mInt(u);
    }
    mInt pow(int64_t n) const {
        mInt ret(1), mul(x);
        while (n > 0) {if (n & 1) ret *= mul; mul *= mul; n >>= 1;}
        return ret;
    }
    friend ostream &operator<<(ostream &os, const mInt &p) {
        return os << p.x;
    }
    friend istream &operator>>(istream &is, mInt &a) {
        int64_t t; is >> t;
        a = mInt< mod >(t);
        return (is);
    }
    static int64_t get_mod() { return mod; }
};
using mint = mInt< MOD >;

template<typename T, int FAC_MAX> struct Comb {
    vector<T> fac, ifac, iv;
    Comb() {
        fac.resize(FAC_MAX, 1); ifac.resize(FAC_MAX, 1); iv.resize(FAC_MAX, 1);
        for (int i = 2; i < FAC_MAX; i++) {
            fac[i] = fac[i - 1] * i;
            iv[i] = - iv[MOD % i] * T(MOD / i) ;
            ifac[i] = ifac[i - 1] * iv[i];
        }
        //for(int i = 1; i < FAC_MAX; i++) fac[i] = fac[i - 1] * i;
        //ifac[FAC_MAX - 1] = T(1) / fac[FAC_MAX - 1];
        //for (int i = FAC_MAX - 2; i >= 1; i--) ifac[i] = ifac[i + 1] * T(i + 1);
    }
    T aPb(int a, int b) { if (b < 0 || a < b) return T(0); return fac[a] * ifac[a - b]; }
    T aCb(int a, int b) { if (b < 0 || a < b) return T(0); return fac[a] * ifac[a - b] * ifac[b]; }
    T nHk(int n, int k) {
        if (n == 0 && k == 0) return T(1); if (n <= 0 || k < 0) return 0;
        return aCb(n + k - 1, k);
    }
};

mint dp[1010][1010];


int main() {
    int n, a, b, c, d; cin >> n >> a >> b >> c >> d;

    Comb<mint, 1010> com;
    dp[a - 1][0] = 1;
    for (int i = a; i <= b; i++) rep(j, n + 1) {
        dp[i][j] = dp[i - 1][j];
        for (int k = c; k <= min(d, j / i); k++) {
            dp[i][j] += dp[i - 1][j - i * k] *
                        com.aPb(n - j + i * k, i * k) * (com.ifac[i]).pow(k) * com.ifac[k];
        }
    }

    cout << dp[b][n] << endl;

}