// #include <bits/stdc++.h>
#include <iostream> // cin, cout, string
#include <algorithm> // sort, min, max
#include <vector>
#include <utility> // pair, swap
#include <functional>
#include <iomanip> // setprecision
#include <map>
#include <set> // multiset
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <stack>
#include <queue> // priority_queue
#include <deque>
#include <bitset>
#include <complex>

using namespace std;

// #define int long long

using ll = long long;
using ld = long double;

// template<class T1, class T2> using P = pair<T1, T2>;
template<class T> using vec = vector<T>;
template<typename T> using func = function<T>;

using pii = pair<int, int>;
using ppi = pair<pii, int>;
using pip = pair<int, pii>;
using ppp = pair<pii, pii>;

using vi = vec<int>;
using vvi = vec<vi>; // Graph
using vp = vec<pii>;

constexpr int IINF =  0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
// constexpr int INF = sizeof(int) == sizeof(long long) ? LINF : IINF;
constexpr ll MOD = 1e9+7;

#define for_(i, a, b) for(int i = (a);i < (b);++i)
#define rfor_(i, a, b) for(int i = (b)-1;i >= (a);--i)

#define rep(i, n) for_(i, 0, n)
#define rrep(i, n) rfor_(i, 0, n)

#define pb push_back
#define mp make_pair
#define mt make_tuple
// eb(*,*) = pb(mp(*,*))
#define eb emplace_back
#define ft first
#define sd second

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a).size()
#define rev(a) reverse(all(a))
// #define sum(...) accumulate(range(__VA_ARGS__), 0LL)

#define endl '\n'
#define dec(n) fixed << setprecision(n)
#define zfl(n)  setfill(‘0’) << setw(n)
#define debug(x) cerr << #x << ": " << (x) << endl

template<typename T> T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

template<typename T> istream &operator>>(istream &is, vector<T> &v) { for(auto&& x : v) is >> x; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &v) { for(int i=0; i<(int)v.size(); ++i) cout << v[i] << ( i+1 != (int)v.size() ? " " : "" ); return os; }

template<typename A, typename B> istream &operator>>(istream &is, pair<A, B> &p) { is >> p.first; is >> p.second; return is; }
template<typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p) { os << p.first << " " << p.second; return os; }

const int limit = 100007;

template<typename T> T extgcd(const T &a, const T &b, T &x, T &y) { // ax + by = gcd(a. b)
  if (b==0) {
    x = 1;
    y = 0;
    return a;
  }
  T d = extgcd(b, a % b, y, x);
  y -= a/b * x;
  return d;
}

template<typename T=long long, const T P=(T)MOD> // P : prime
class Zp {
  private:
    T n;
    template<typename U> void set(const U &m) { n = (m % mod + mod) % mod; }
    void set(const Zp &m) { n = m.get(); }
  public:
    static const T mod;
    template<typename U> static Zp inv(const U &m) {
      T a = m, b = mod, u = 1, v = 0; // u = pow(a, mod-2), extgcd(a, b, u, v)
      while (b) {
        T t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
      }
      assert( a == 1 ); // gcd(a, b) == 1
      return Zp(u);
    }
    static Zp inv(const Zp &m) { return inv(m.get()); }
    Zp() : n(0) {}
    Zp(const Zp &m) : n(m.get()) {}
    template<typename U> Zp(U m) { set(m); }
    T get() const { return n; }
    T abs() const { return 2*n > mod ? n-mod : n; }
    Zp &operator=(const Zp &m) { set(m); return *this; }
    template<typename U> Zp &operator=(const U &m) { set(m); return *this; }
    template<typename U> Zp &operator+=(const U &m) { set(n+m); return *this; }
    Zp &operator+=(const Zp &m) { set(n+m.get()); return *this; }
    template<typename U> Zp &operator-=(const U &m) { set(n-m); return *this; }
    Zp &operator-=(const Zp &m) { set(n-m.get()); return *this; }
    template<typename U> Zp &operator*=(const U &m) { set(n * (m % mod)); return *this; }
    Zp &operator*=(const Zp &m) { set(n * m.get()); return *this; }
    template<typename U> Zp &operator/=(const U &m) { set(n * inv(m % mod)); return *this; }
    Zp &operator/=(const Zp &m) { set(n * inv(m.get())); return *this; }
    template<typename U> Zp pow(U e) const {
      if(e==0) return Zp(1);
      else if(e < 0) return inv(pow(-e));
      else {
        Zp a = *this, r = 1;
        while (e > 0) {
          if (e & 1) r *= a;
          a *= a;
          e >>= 1;
        }
        return r;
      }
    }
    //template<typename U> Zp operator^(U e) const { return pow(e); }
    operator T() const { return n; }
};
template<typename T, T P> const T Zp<T, P>::mod = P;
template<typename T, T P> const Zp<T, P> operator+(const Zp<T, P> &n, const Zp<T, P> &m) { return Zp<T, P>(n) += m; }
template<typename T, T P, typename U> const Zp<T, P> operator+(const Zp<T, P> &n, const U &m) { return Zp<T, P>(n) += m; }
template<typename T, T P, typename U> const Zp<T, P> operator+(const U &n, const Zp<T, P> &m) { return Zp<T, P>(n) += m; }
template<typename T, T P> const Zp<T, P> operator-(const Zp<T, P> &n, const Zp<T, P> &m) { return Zp<T, P>(n) -= m; }
template<typename T, T P, typename U> const Zp<T, P> operator-(const Zp<T, P> &n, const U &m) { return Zp<T, P>(n) -= m; }
template<typename T, T P, typename U> const Zp<T, P> operator-(const U &n, const Zp<T, P> &m) { return Zp<T, P>(n) -= m; }
template<typename T, T P> const Zp<T, P> operator*(const Zp<T, P> &n, const Zp<T, P> &m) { return Zp<T, P>(n) *= m; }
template<typename T, T P, typename U> const Zp<T, P> operator*(const Zp<T, P> &n, const U &m) { return Zp<T, P>(n) *= m; }
template<typename T, T P, typename U> const Zp<T, P> operator*(const U &n, const Zp<T, P> &m) { return Zp<T, P>(n) *= m; }
template<typename T, T P> const Zp<T, P> operator/(const Zp<T, P> &n, const Zp<T, P> &m) { return Zp<T, P>(n) /= m; }
template<typename T, T P, typename U> const Zp<T, P> operator/(const Zp<T, P> &n, const U &m) { return Zp<T, P>(n) /= m; }
template<typename T, T P, typename U> const Zp<T, P> operator/(const U &n, const Zp<T, P> &m) { return Zp<T, P>(n) /= m; }
template<typename T, T P> istream &operator>>(istream &is, Zp<T, P> &n) { T m; is >> m; n = m; return is; }
template<typename T, T P> ostream &operator<<(ostream &os, const Zp<T, P> &n) { os << n.get(); return os; }

template<typename T=long long, const T P=(T)MOD>
class COM {
  private:
  int m;
  vector<Zp<T, P>> fac, finv, inv;
  void init(const int &n) {
    if(m >= n) return ;
    fac.resize(n+1);
    inv.resize(n+1);
    finv.resize(n+1);
    for (int i = m+1; i <= n; i++){
      fac[i] = fac[i - 1] * i;
      inv[i] = P - inv[P % i] * (P / i);
      finv[i] = finv[i - 1] * inv[i];
    }
    m = n;
  }
  public:
  COM() : m(1), fac(2, 1), finv(2, 1), inv(2, 1) {}
  COM(const int &n) : m(1), fac(2, 1), finv(2, 1), inv(2, 1) { init(n); }
  Zp<T, P> operator()(const int &n, const int &k) {
    if (n < k) return Zp<T, P>(0);
    if (n < 0 || k < 0) return Zp<T, P>(0);
    init(n);
    return fac[n] * (finv[k] * finv[n - k]);
  }
};

using Mod = Zp<>;

int N, M, K;
COM<> com;

signed main() {
  cin.tie(0);cout.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> M >> K;

  Mod ans = 0;

  rep(d, N) ans += com(N*M-2, K-2) * (N-d) * M * M * d;
  rep(d, M) ans += com(N*M-2, K-2) * (M-d) * N * N * d;

  cout << ans << endl;

  return 0;
}
