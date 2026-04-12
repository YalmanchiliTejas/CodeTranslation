//header
#ifdef LOCAL
    #include "cxx-prettyprint-master/prettyprint.hpp"
    #define debug(x) cout << x << endl
#else
    #define debug(...) 42
#endif
    #pragma GCC optimize("Ofast")
    #include <bits/stdc++.h>
    //types
    using namespace std;
    using ll = long long;
    using ul = unsigned long long;
    using ld = long double;
    typedef pair < ll , ll > Pl;        
    typedef pair < int, int > Pi;
    typedef vector<ll> vl;
    typedef vector<int> vi;
    template< typename T >
    using mat = vector< vector< T > >;
    template< int mod >
    struct modint {
        int x;

        modint() : x(0) {}

        modint(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

        modint &operator+=(const modint &p) {
            if((x += p.x) >= mod) x -= mod;
            return *this;
        }

        modint &operator-=(const modint &p) {
            if((x += mod - p.x) >= mod) x -= mod;
            return *this;
        }

        modint &operator*=(const modint &p) {
            x = (int) (1LL * x * p.x % mod);
            return *this;
        }

        modint &operator/=(const modint &p) {
            *this *= p.inverse();
            return *this;
        }

        modint operator-() const { return modint(-x); }

        modint operator+(const modint &p) const { return modint(*this) += p; }

        modint operator-(const modint &p) const { return modint(*this) -= p; }

        modint operator*(const modint &p) const { return modint(*this) *= p; }

        modint operator/(const modint &p) const { return modint(*this) /= p; }

        bool operator==(const modint &p) const { return x == p.x; }

        bool operator!=(const modint &p) const { return x != p.x; }

        modint inverse() const {
            int a = x, b = mod, u = 1, v = 0, t;
            while(b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
            }
            return modint(u);
        }

        modint pow(int64_t n) const {
            modint ret(1), mul(x);
            while(n > 0) {
            if(n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
            }
            return ret;
        }

        friend ostream &operator<<(ostream &os, const modint &p) {
            return os << p.x;
        }

        friend istream &operator>>(istream &is, modint &a) {
            int64_t t;
            is >> t;
            a = modint< mod >(t);
            return (is);
        }

        static int get_mod() { return mod; }
    };
    //abreviations
    #define all(x) (x).begin(), (x).end()
    #define rall(x) (x).rbegin(), (x).rend()
    #define rep_(i, a_, b_, a, b, ...) for (int i = (a), max_i = (b); i < max_i; i++)
    #define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
    #define SZ(x) ((int)(x).size())
    #define pb(x) push_back(x)
    #define eb(x) emplace_back(x)
    #define mp make_pair
    #define print(x) cout << x << endl
    #define vsum(x) accumulate(x, 0LL)
    #define vmax(a) *max_element(all(a))
    #define vmin(a) *min_element(all(a))
    //functions
    ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
    ll lcm(ll a, ll b) { return a/gcd(a, b)*b;}
    template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
    template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
    template< typename T >
    T mypow(T x, ll n) {
        T ret = 1;
        while(n > 0) {
            if(n & 1) (ret *= x);
            (x *= x);
            n >>= 1;
        }
        return ret;
    }
    ll modpow(ll x, ll n, const ll mod) {
        ll ret = 1;
        while(n > 0) {
            if(n & 1) (ret *= x);
            (x *= x);
            n >>= 1;
            x%=mod;
            ret%=mod;
        }
        return ret;
    }
    uint64_t my_rand(void) {
        static uint64_t x = 88172645463325252ULL;
        x = x ^ (x << 13); x = x ^ (x >> 7);
        return x = x ^ (x << 17);
    }
    //graph template
    template< typename T >
    struct edge {
        int src, to;
        T cost;

        edge(int to, T cost) : src(-1), to(to), cost(cost) {}

        edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

        edge &operator=(const int &x) {
            to = x;
            return *this;
        }
        operator int() const { return to; }
    };
    template< typename T >
    using Edges = vector< edge< T > >;
    template< typename T >
    using WeightedGraph = vector< Edges< T > >;
    using UnWeightedGraph = vector< vector< int > >;

//constant
#define INF 4001002003004005006LL
#define inf 1000000005
#define mod 1000000007LL
//#define endl '\n'
typedef modint<mod> mint;
const long double eps = 0.001;
const long double PI  = 3.141592653589793;

//library
template< typename T >
struct FormalPowerSeries : vector< T > {
  using vector< T >::vector;
  using P = FormalPowerSeries;

  using MULT = function< P(P, P) >;

  static MULT &get_mult() {
    static MULT mult = nullptr;
    return mult;
  }

  static void set_fft(MULT f) {
    get_mult() = f;
  }

  void shrink() {
    while(this->size() && this->back() == T(0)) this->pop_back();
  }

  P operator+(const P &r) const { return P(*this) += r; }

  P operator+(const T &v) const { return P(*this) += v; }

  P operator-(const P &r) const { return P(*this) -= r; }

  P operator-(const T &v) const { return P(*this) -= v; }

  P operator*(const P &r) const { return P(*this) *= r; }

  P operator*(const T &v) const { return P(*this) *= v; }

  P operator/(const P &r) const { return P(*this) /= r; }

  P operator%(const P &r) const { return P(*this) %= r; }

  P &operator+=(const P &r) {
    if(r.size() > this->size()) this->resize(r.size());
    for(int i = 0; i < r.size(); i++) (*this)[i] += r[i];
    return *this;
  }

  P &operator+=(const T &r) {
    if(this->empty()) this->resize(1);
    (*this)[0] += r;
    return *this;
  }

  P &operator-=(const P &r) {
    if(r.size() > this->size()) this->resize(r.size());
    for(int i = 0; i < r.size(); i++) (*this)[i] -= r[i];
    shrink();
    return *this;
  }

  P &operator-=(const T &r) {
    if(this->empty()) this->resize(1);
    (*this)[0] -= r;
    shrink();
    return *this;
  }

  P &operator*=(const T &v) {
    const int n = (int) this->size();
    for(int k = 0; k < n; k++) (*this)[k] *= v;
    return *this;
  }

  P &operator*=(const P &r) {
    if(this->empty() || r.empty()) {
      this->clear();
      return *this;
    }
    assert(get_mult() != nullptr);
    return *this = get_mult()(*this, r);
  }

  P &operator%=(const P &r) {
    return *this -= *this / r * r;
  }

  P operator-() const {
    P ret(this->size());
    for(int i = 0; i < this->size(); i++) ret[i] = -(*this)[i];
    return ret;
  }

  P &operator/=(const P &r) {
    if(this->size() < r.size()) {
      this->clear();
      return *this;
    }
    int n = this->size() - r.size() + 1;
    return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);
  }

  P pre(int sz) const {
    return P(begin(*this), begin(*this) + min((int) this->size(), sz));
  }

  P operator>>(int sz) const {
    if(this->size() <= sz) return {};
    P ret(*this);
    ret.erase(ret.begin(), ret.begin() + sz);
    return ret;
  }

  P operator<<(int sz) const {
    P ret(*this);
    ret.insert(ret.begin(), sz, T(0));
    return ret;
  }

  P rev(int deg = -1) const {
    P ret(*this);
    if(deg != -1) ret.resize(deg, T(0));
    reverse(begin(ret), end(ret));
    return ret;
  }

  P diff() const {
    const int n = (int) this->size();
    P ret(max(0, n - 1));
    for(int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * T(i);
    return ret;
  }

  P integral() const {
    const int n = (int) this->size();
    P ret(n + 1);
    ret[0] = T(0);
    for(int i = 0; i < n; i++) ret[i + 1] = (*this)[i] / T(i + 1);
    return ret;
  }

  // F(0) must not be 0
  P inv(int deg = -1) const {
    assert(((*this)[0]) != T(0));
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    P ret({T(1) / (*this)[0]});
    for(int i = 1; i < deg; i <<= 1) {
      ret = (ret + ret - ret * ret * pre(i << 1)).pre(i << 1);
    }
    return ret.pre(deg);
  }

  // F(0) must be 1
  P log(int deg = -1) const {
    assert((*this)[0] == 1);
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    return (this->diff() * this->inv(deg)).pre(deg - 1).integral();
  }

  P sqrt(int deg = -1) const {
    const int n = (int) this->size();
    if(deg == -1) deg = n;

    if((*this)[0] == T(0)) {
      for(int i = 1; i < n; i++) {
        if((*this)[i] != T(0)) {
          if(i & 1) return {};
          if(deg - i / 2 <= 0) break;
          auto ret = (*this >> i).sqrt(deg - i / 2) << (i / 2);
          if(ret.size() < deg) ret.resize(deg, T(0));
          return ret;
        }
      }
      return P(deg, 0);
    }

    P ret({T(1)});
    T inv2 = T(1) / T(2);
    for(int i = 1; i < deg; i <<= 1) {
      ret = (ret + pre(i << 1) * ret.inv(i << 1)) * inv2;
    }
    return ret.pre(deg);
  }

  // F(0) must be 0
  P exp(int deg = -1) const {
    assert((*this)[0] == T(0));
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    P ret({T(1)});
    for(int i = 1; i < deg; i <<= 1) {
      ret = (ret * (pre(i << 1) + T(1) - ret.log(i << 1))).pre(i << 1);
    }
    return ret.pre(deg);
  }

  P pow(int64_t k, int deg = -1) const {
    const int n = (int) this->size();
    if(deg == -1) deg = n;
    for(int i = 0; i < n; i++) {
      if((*this)[i] != T(0)) {
        T rev = T(1) / (*this)[i];
        P C(*this * rev);
        P D(n - i);
        for(int j = i; j < n; j++) D[j - i] = C[j];
        D = (D.log() * k).exp() * (*this)[i].pow(k);
        P E(deg);
        if(i * k > deg) return E;
        auto S = i * k;
        for(int j = 0; j + S < deg && j < D.size(); j++) E[j + S] = D[j];
        return E;
      }
    }
    return *this;
  }


  T eval(T x) const {
    T r = 0, w = 1;
    for(auto &v : *this) {
      r += w * v;
      w *= x;
    }
    return r;
  }
};
/* how to use
// you can use ntt instead.
ArbitraryModConvolution<mint> arb;
using FPS = FormalPowerSeries< mint >;
auto mult = [&](const FPS::P &a, const FPS::P &b) {
    auto ret = arb.multiply(a, b);
    return FPS::P(ret.begin(), ret.end());
};
FPS::set_fft(mult);
//example
FormalPowerSeries< mint > X(K + 1);
*/

namespace FastFourierTransform {
    using real = double;

    struct C {
        real x, y;

        C() : x(0), y(0) {}

        C(real x, real y) : x(x), y(y) {}

        inline C operator+(const C &c) const { return C(x + c.x, y + c.y); }

        inline C operator-(const C &c) const { return C(x - c.x, y - c.y); }

        inline C operator*(const C &c) const { return C(x * c.x - y * c.y, x * c.y + y * c.x); }

        inline C conj() const { return C(x, -y); }
    };

    const real PI = acosl(-1);
    int base = 1;
    vector< C > rts = { {0, 0},
                                        {1, 0} };
    vector< int > rev = {0, 1};


    void ensure_base(int nbase) {
        if(nbase <= base) return;
        rev.resize(1 << nbase);
        rts.resize(1 << nbase);
        for(int i = 0; i < (1 << nbase); i++) {
            rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
        }
        while(base < nbase) {
            real angle = PI * 2.0 / (1 << (base + 1));
            for(int i = 1 << (base - 1); i < (1 << base); i++) {
                rts[i << 1] = rts[i];
                real angle_i = angle * (2 * i + 1 - (1 << base));
                rts[(i << 1) + 1] = C(cos(angle_i), sin(angle_i));
            }
            ++base;
        }
    }

    void fft(vector< C > &a, int n) {
        assert((n & (n - 1)) == 0);
        int zeros = __builtin_ctz(n);
        ensure_base(zeros);
        int shift = base - zeros;
        for(int i = 0; i < n; i++) {
            if(i < (rev[i] >> shift)) {
                swap(a[i], a[rev[i] >> shift]);
            }
        }
        for(int k = 1; k < n; k <<= 1) {
            for(int i = 0; i < n; i += 2 * k) {
                for(int j = 0; j < k; j++) {
                    C z = a[i + j + k] * rts[j + k];
                    a[i + j + k] = a[i + j] - z;
                    a[i + j] = a[i + j] + z;
                }
            }
        }
    }

    vector< int64_t > multiply(const vector< int > &a, const vector< int > &b) {
        int need = (int) a.size() + (int) b.size() - 1;
        int nbase = 1;
        while((1 << nbase) < need) nbase++;
        ensure_base(nbase);
        int sz = 1 << nbase;
        vector< C > fa(sz);
        for(int i = 0; i < sz; i++) {
            int x = (i < (int) a.size() ? a[i] : 0);
            int y = (i < (int) b.size() ? b[i] : 0);
            fa[i] = C(x, y);
        }
        fft(fa, sz);
        C r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);
        for(int i = 0; i <= (sz >> 1); i++) {
            int j = (sz - i) & (sz - 1);
            C z = (fa[j] * fa[j] - (fa[i] * fa[i]).conj()) * r;
            fa[j] = (fa[i] * fa[i] - (fa[j] * fa[j]).conj()) * r;
            fa[i] = z;
        }
        for(int i = 0; i < (sz >> 1); i++) {
            C A0 = (fa[i] + fa[i + (sz >> 1)]) * t;
            C A1 = (fa[i] - fa[i + (sz >> 1)]) * t * rts[(sz >> 1) + i];
            fa[i] = A0 + A1 * s;
        }
        fft(fa, sz >> 1);
        vector< int64_t > ret(need);
        for(int i = 0; i < need; i++) {
            ret[i] = llround(i & 1 ? fa[i >> 1].y : fa[i >> 1].x);
        }
        return ret;
    }
};
template< typename T >
struct ArbitraryModConvolution {
    using real = FastFourierTransform::real;
    using C = FastFourierTransform::C;

    ArbitraryModConvolution() = default;

    vector< T > multiply(const vector< T > &a, const vector< T > &b, int need = -1) {
        if(need == -1) need = a.size() + b.size() - 1;
        int nbase = 0;
        while((1 << nbase) < need) nbase++;
        FastFourierTransform::ensure_base(nbase);
        int sz = 1 << nbase;
        vector< C > fa(sz);
        for(int i = 0; i < a.size(); i++) {
            fa[i] = C(a[i].x & ((1 << 15) - 1), a[i].x >> 15);
        }
        fft(fa, sz);
        vector< C > fb(sz);
        if(a == b) {
            fb = fa;
        } else {
            for(int i = 0; i < b.size(); i++) {
                fb[i] = C(b[i].x & ((1 << 15) - 1), b[i].x >> 15);
            }
            fft(fb, sz);
        }
        real ratio = 0.25 / sz;
        C r2(0, -1), r3(ratio, 0), r4(0, -ratio), r5(0, 1);
        for(int i = 0; i <= (sz >> 1); i++) {
            int j = (sz - i) & (sz - 1);
            C a1 = (fa[i] + fa[j].conj());
            C a2 = (fa[i] - fa[j].conj()) * r2;
            C b1 = (fb[i] + fb[j].conj()) * r3;
            C b2 = (fb[i] - fb[j].conj()) * r4;
            if(i != j) {
                C c1 = (fa[j] + fa[i].conj());
                C c2 = (fa[j] - fa[i].conj()) * r2;
                C d1 = (fb[j] + fb[i].conj()) * r3;
                C d2 = (fb[j] - fb[i].conj()) * r4;
                fa[i] = c1 * d1 + c2 * d2 * r5;
                fb[i] = c1 * d2 + c2 * d1;
            }
            fa[j] = a1 * b1 + a2 * b2 * r5;
            fb[j] = a1 * b2 + a2 * b1;
        }
        fft(fa, sz);
        fft(fb, sz);
        vector< T > ret(need);
        for(int i = 0; i < need; i++) {
            int64_t aa = llround(fa[i].x);
            int64_t bb = llround(fb[i].x);
            int64_t cc = llround(fa[i].y);
            aa = T(aa).x, bb = T(bb).x, cc = T(cc).x;
            ret[i] = aa + (bb << 15) + (cc << 30);
        }
        return ret;
    }
};
const int mx = 100000;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(20);
    ArbitraryModConvolution<mint> arb;
    using FPS = FormalPowerSeries< mint >;
    auto mult = [&](const FPS::P &a, const FPS::P &b) {
        auto ret = arb.multiply(a, b);
        return FPS::P(ret.begin(), ret.end());
    };
    FPS::set_fft(mult);
    int n, a, b, c, d; cin>>n>>a>>b>>c>>d;
    FormalPowerSeries<mint> F(n+1);
    F[0] = 1;
    vector<mint> fact(n+1, 1);
    rep(i, 1, n+1)fact[i] = fact[i-1]*i;
    rep(i, a, b+1){
        FormalPowerSeries<mint> G(n+1);
        G[0] = 1;
        rep(j, c, d+1){
            if(j*i>n)break;
            G[j*i] = (mint)1/mypow<mint>(fact[i], j)/fact[j];
        }
        F*=G;
        F.resize(n+1);
    }
    cout << F[n]*fact[n] << endl;
} 