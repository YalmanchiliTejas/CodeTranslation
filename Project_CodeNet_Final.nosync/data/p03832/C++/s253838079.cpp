#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repc(i, n) for (int i = 0; i <= int(n); i++)
#define rrepc(i, n) for (int i = int(n); i >= 0; i--)
#define repi(i, a, b) for (int i = int(a); i < int(b); i++)
#define repic(i, a, b) for (int i = int(a); i <= int(b); i++)
#define all(a) (a).begin(), (a).end()
#define bit32(x) (1 << (x))
#define bit64(x) (1ll << (x))
#define sz(v) ((int) v.size())

using namespace std;

using i64 = long long;
using f80 = long double;
using vi32 = vector<int>;
using vi64 = vector<i64>;
using vf80 = vector<f80>;
using vstr = vector<string>;

void yes() { cout << "Yes" << endl; exit(0); }
void no() { cout << "No" << endl; exit(0); }
template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template <typename T> void amax(T &x, T y) { x = max(x, y); }
template <typename T> void amin(T &x, T y) { x = min(x, y); }
template <typename T> T exp(T x, i64 n, T e = 1) { T r = e; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }
template <typename T> istream& operator>>(istream &is, vector<T> &v) { for (auto &x : v) is >> x; return is; }
template <typename T> ostream& operator<<(ostream &os, vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }
void solve(); int main() { ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(16); solve(); return 0; }

template <typename T, typename U>
vector<U> make_vector(T&& n, U&& val) {
  return vector<U>(forward<T>(n), forward<U>(val));
}
template <typename T, typename... Args>
decltype(auto) make_vector(T&& n, Args&&... args) {
  return vector<decltype(make_vector(forward<Args>(args)...))>(forward<T>(n), make_vector(forward<Args>(args)...));
}

const int INF = 1001001001;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

template <int mod>
struct ModInt {
  int x;
  ModInt(): x(0) {}
  ModInt(long long a) { x = a % mod; if (x < 0) x += mod; }
  ModInt &operator+=(ModInt that) { x = (x + that.x) % mod; return *this; }
  ModInt &operator-=(ModInt that) { x = (x + mod - that.x) % mod; return *this; }
  ModInt &operator*=(ModInt that) { x = (long long) x * that.x % mod; return *this; }
  ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
  ModInt inverse() {
    int a = x, b = mod, u = 1, v = 0;
    while (b) { int t = a / b; a -= t * b; u -= t * v; swap(a, b); swap(u, v); }
    return ModInt(u);
  }
  #define op(o, p) ModInt operator o(ModInt that) { return ModInt(*this) p that; }
    op(+, +=) op(-, -=) op(*, *=) op(/, /=)
  #undef op
  friend ostream& operator<<(ostream &os, ModInt m) { return os << m.x; }
};

using mint = ModInt<1000000007>;

template <typename T>
struct ModCalc {
  vector<T> facc;
  vector<T> finv;
  ModCalc(int max) {
    facc.resize(max + 1);
    finv.resize(max + 1);
    facc[0] = 1;
    for (int i = 0; i < max; i++) {
      facc[i + 1] = facc[i] * (i + 1);
    }
    finv[max] = (T) 1 / facc[max];
    for (int i = max; i > 0; i--) {
      finv[i - 1] = finv[i] * i;
    }
  }
  T com(int a, int b) {
    if (a < 0 || b < 0 || b > a) return 0;
    return facc[a] * finv[a - b] * finv[b];
  }
};

using mcalc = ModCalc<mint>;
auto mc = mcalc(1000);

void solve() {
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  auto memo = make_vector(b + 1, n + 1, (mint) 0);
  repc(i, b) repc(j, n) {
    memo[i][j].x = -1;
  }
  auto f = [&](auto f, int i, int r) -> mint {
    if (i == b + 1) {
      if (r == 0) return (mint) 1;
      if (r != 0) return (mint) 0;
    }
    if (memo[i][r].x != -1) {
      return memo[i][r];
    }
    mint ret = 0;
    ret += f(f, i + 1, r);
    repic(k, c, d) {
      if (r < i * k) {
        break;
      }
      mint t = mc.facc[r] / (mc.facc[r - i * k] * exp(mc.facc[i], k) * mc.facc[k]);
      ret += f(f, i + 1, r - i * k) * t;
    }
    return memo[i][r] = ret;
  };
  mint ans = f(f, a, n);
  cout << ans << endl;
}
