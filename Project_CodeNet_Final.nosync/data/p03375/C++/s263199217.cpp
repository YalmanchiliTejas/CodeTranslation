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


struct modint {
    ll val;

    static ll &mod() {
        static ll mod_ = 0;
        return mod_;
    }
    static void set_mod(const ll x) { mod() = x; }
    static ll M() {return mod(); }
    static ll get_mod() { return mod(); }

    modint() : val(0LL) {}
    modint(const ll x) : val(x) {
        val = x % M();
        while (val < 0) val += M();
    }

    modint& operator+=(const modint a) { val += a.val; if (val >= M()) val -= M(); return *this; }
    modint& operator-=(const modint a) { val -= a.val; if (val < 0) val += M(); return *this; }
    modint& operator*=(const modint a) { val = val * a.val % M(); return *this; }
    modint& operator/=(const modint a) { val = val * a.inverse().val % M(); return *this;}
    modint& operator=(const int& x) {
        val = x % M();
        while (val < 0) val += M();
        return *this;
    }
    modint operator+(const modint a) const { return modint(*this) += a; }
    modint operator-(const modint a) const { return modint(*this) -= a; }
    modint operator*(const modint a) const { return modint(*this) *= a; }
    modint operator/(const modint a) const { return modint(*this) /= a; }
    modint operator-() const { return {M() - val}; }
    modint inverse() const {
        ll u = 1, v = 0, s = 0, t = 1, m = M(), x = val;
        while (x) {ll q = M() / x; swap(s -= q * u, u); swap(t -= q * v, v); swap(m -= q * x, x); }
        if (s < 0) s += M();
        return modint(s);
    }
    modint pow(ll n) {
        ll u = 1, xx = val;
        while (n > 0) { if (n & 1) u = u * xx % M(); xx = xx * xx % M(); n >>= 1; }
        return modint(u);
    }
    friend ostream &operator<<(ostream &os, const modint &p) {
        return os << p.val;
    }
    friend istream &operator>>(istream &is, modint &a) {
        ll t;
        is >> t;
        a = modint(t);
        return (is);
    }
};
using mint = modint;


template<typename T, int FAC_MAX> struct Comb {
    vector<T> fac, ifac, iv;
    Comb() {
        fac.resize(FAC_MAX, 1); ifac.resize(FAC_MAX, 1); iv.resize(FAC_MAX, 1);
        ll mod = fac[0].get_mod();
        for (ll i = 2; i < FAC_MAX; i++) {
            fac[i] = fac[i - 1] * i;
            iv[i] = - iv[mod % i] * T(mod / i) ;
            ifac[i] = ifac[i - 1] * iv[i];
        }
    }
    T aPb(int a, int b) { if (b < 0 || a < b) return T(0); return fac[a] * ifac[a - b]; }
    T aCb(int a, int b) { if (b < 0 || a < b) return T(0); return fac[a] * ifac[a - b] * ifac[b]; }
    T nHk(int n, int k) {
        if (n == 0 && k == 0) return T(1); if (n <= 0 || k < 0) return 0;
        return aCb(n + k - 1, k);
    }
};

template<class T> struct Stirling {
    vector<vector<T>> S;
    Stirling(int MAX) : S(MAX, vector<T>(MAX, 0)) {
        S[0][0] = 1;
        for (int n = 1; n < MAX; ++n) {
            for (int k = 1; k <= n; ++k) {
                S[n][k] = S[n - 1][k - 1] + S[n - 1][k] * k;
            }
        }
    }
    T get(int n, int k) {
        if (n < 0 || k < 0 || n < k) return 0;
        return S[n][k];
    }
};


const int MAX = 3100;
int main() {
    ll N, M; cin >> N >> M;
    mint::set_mod(M);

    Comb<mint, MAX> bc;
    Stirling<mint> sl(MAX);

    vector<mint> two(MAX * MAX, 0), dtwo(MAX, 0);
    two[0] = 1, dtwo[0] = 2;
    for (int i = 1; i < MAX; ++i) dtwo[i] = dtwo[i - 1] * dtwo[i - 1];
    for (int i = 1; i < MAX * MAX; ++i) two[i] = two[i - 1] * 2;

    mint res = 0;
    for (int n = 0; n <= N; ++n) {
        //cout << "n : " << n << endl;
        mint add = 0;
        for (int k = 0; k <= n; ++k) {
            mint jiyudo = two[(N - n) * k] * dtwo[N - n];
            mint core = sl.get(n, k) + sl.get(n, k + 1) * (k + 1);
            //cout << core << " " << jiyudo << endl;
            add += core * jiyudo;
        }
        mint choose = bc.aCb(N, n);
        //cout << choose << endl;
        add *= choose;
        if (n % 2 == 0) res += add;
        else res -= add;
        //cout << "res : " << res << endl;
    }
    cout << res << endl;
}

