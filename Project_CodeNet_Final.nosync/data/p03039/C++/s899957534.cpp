#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repi(i, a, b) for (int i = int(a); i < int(b); i++)
#define each(x, y) for (auto &x : y)
#define all(a) (a).begin(), (a).end()
#define bit(b) (1ll << (b))
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define rsort(v) sort(all(v)); reverse(all(v))

using namespace std;

using i32 = int;
using i64 = long long;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;
using vf80 = vector<f80>;
using vstr = vector<string>;

inline void yes() { cout << "Yes" << '\n'; exit(0); }
inline void no() { cout << "No" << '\n'; exit(0); }
inline i64 gcd(i64 a, i64 b) { if (min(a, b) == 0) return max(a, b); if (a % b == 0) return b; return gcd(b, a % b); }
inline i64 lcm(i64 a, i64 b) { return a / gcd(a, b) * b; }
void solve(); int main() { ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(16); solve(); return 0; }
template<typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template<typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template<typename T> inline void amax(T &x, T y) { if (x < y) x = y; }
template<typename T> inline void amin(T &x, T y) { if (x > y) x = y; }
template<typename T> inline T power(T x, i64 n) { T r = 1; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }
template<typename T> istream& operator>>(istream &is, vector<T> &v) { for (auto &x : v) is >> x; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }

template<int mod>
struct ModInt {
  int x;
  ModInt(): x(0) {}
  ModInt(i64 a) { x = a % mod; if (x < 0) x += mod; }
  ModInt &operator+=(ModInt that) { x = (x + that.x) % mod; return *this; }
  ModInt &operator-=(ModInt that) { x = (x + mod - that.x) % mod; return *this; }
  ModInt &operator*=(ModInt that) { x = (i64) x * that.x % mod; return *this; }
  ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
  ModInt operator-() { return ModInt(-this->x); }
  friend ostream& operator<<(ostream &os, ModInt m) { return os << m.x; }
  ModInt inverse() {
    int a = x, b = mod, u = 1, v = 0;
    while (b) { int t = a / b; a -= t * b; u -= t * v; swap(a, b); swap(u, v); }
    return ModInt(u);
  }
  #define op(o, p) ModInt operator o(ModInt that) { return ModInt(*this) p that; }
    op(+, +=) op(-, -=) op(*, *=) op(/, /=)
  #undef op
  #define op(o) bool operator o(ModInt that) const { return x o that.x; }
    op(==) op(!=) op(<) op(<=) op(>) op(>=)
  #undef op
};

using mint = ModInt<1000000007>;

template<typename T>
struct ModCalc {
  vector<T> fac, finv;
  ModCalc(int max) {
    fac = vector<T>(max + 1);
    finv = vector<T>(max + 1);
    fac[0] = 1;
    reps(i, max) fac[i] = fac[i - 1] * i;
    finv[max] = (T) 1 / fac[max];
    rreps(i, max) finv[i - 1] = finv[i] * i;
  }
  T com(int a, int b) {
    if (a < 0) return 0;
    if (b < 0 || b > a) return 0;
    return fac[a] * finv[a - b] * finv[b];
  }
};

using mcalc = ModCalc<mint>;
auto mc = mcalc(200010);

void solve() {
  i64 N, M, K;
  cin >> N >> M >> K;
  vector<vector<mint>> brd(N, vector<mint>(M, 0));
  rep(i, N) rep(j, M) {
    i64 x = i + 1, y = j + 1;
    i64 w = N - (x - 1);
    i64 t = y * (y + 1) * (x - 1) / 2 + (y - 0) * (x - 2) * (x - 1) / 2
          + y * (y - 1) * w / 2 + (y - 1) * (w - 1) * (w - 0) / 2;
    brd[i][j] = t;
  }
  mint ans = 0;
  rep(i, N) rep(j, M) ans += brd[i][j];
  cout << ans * mc.com(N * M - 2, K - 2) << '\n';
}
