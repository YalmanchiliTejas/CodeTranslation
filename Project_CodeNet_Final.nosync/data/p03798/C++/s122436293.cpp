#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repc(i, n) for (int i = 0; i <= int(n); i++)
#define rrepc(i, n) for (int i = int(n); i >= 0; i--)
#define repi(i, a, b) for (int i = int(a); i < int(b); i++)
#define repic(i, a, b) for (int i = int(a); i <= int(b); i++)
#define each(x, y) for (auto &x : y)
#define all(a) (a).begin(), (a).end()
#define bit(b) (1ll << (b))
#define uniq(v) (v).erase(unique(all(v)), (v).end())

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
template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template <typename T> inline void amax(T &x, T y) { if (x < y) x = y; }
template <typename T> inline void amin(T &x, T y) { if (x > y) x = y; }
template <typename T> inline T power(T x, i64 n, T e = 1) { T r = e; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }
template <typename T> istream& operator>>(istream &is, vector<T> &v) { each(x, v) is >> x; return is; }
template <typename T> ostream& operator<<(ostream &os, vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }
template <typename T, typename S> istream& operator>>(istream &is, pair<T, S> &p) { is >> p.first >> p.second; return is; }
template <typename T, typename S> ostream& operator<<(ostream &os, pair<T, S> &p) { cout << p.first << ' ' << p.second; return os; }

void solve() {
  int n; cin >> n;
  string s; cin >> s;

  auto inc = [&](int i) { return (i + 1) % n; };
  auto dec = [&](int i) { return (i + n - 1) % n; };

  each(p, vi32({0, 1, 2, 3})) {
    auto t = bitset<100010>(p);

    for (int i = 0; i + 3 <= n; i++) {
      if (s[i + 1] == 'o') {
        if (t[i + 1]) t[i + 2] = t[i];
        else t[i + 2] = 1 - t[i];
      } else {
        if (t[i + 1]) t[i + 2] = 1 - t[i];
        else t[i + 2] = t[i];
      }
    }

    bool f = true;
    if (s[0] == 'o') {
      if (t[0] && (t[dec(0)] != t[inc(0)])) f = false;
      if (!t[0] && (t[dec(0)] == t[inc(0)])) f = false;
    } else {
      if (t[0] && (t[dec(0)] == t[inc(0)])) f = false;
      if (!t[0] && (t[dec(0)] != t[inc(0)])) f = false;
    }
    if (s[n - 1] == 'o') {
      if (t[n - 1] && (t[dec(n - 1)] != t[inc(n - 1)])) f = false;
      if (!t[n - 1] && (t[dec(n - 1)] == t[inc(n - 1)])) f = false;
    } else {
      if (t[n - 1] && (t[dec(n - 1)] == t[inc(n - 1)])) f = false;
      if (!t[n - 1] && (t[dec(n - 1)] != t[inc(n - 1)])) f = false;
    }
    if (f) {
      rep(i, n) cout << (t[i] ? 'S' : 'W'); cout << '\n';
      return;
    }
  }

  cout << -1 << '\n';
}
