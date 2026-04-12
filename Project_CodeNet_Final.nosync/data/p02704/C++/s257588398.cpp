#include <iostream>
#include <vector>

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
#define bit32(x) (1 << (x))
#define bit64(x) (1ll << (x))
#define sz(v) ((int) v.size())

using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using f80 = long double;
using vi32 = vector<int>;
using vi64 = vector<i64>;
using vf80 = vector<f80>;
using vstr = vector<string>;

inline unsigned long long xorshift() {
  static unsigned long long x = 88172645463325252ull;
  x = x ^ (x << 7);
  return x = x ^ (x >> 9);
}

template <typename T> istream& operator>>(istream &is, vector<T> &v) { each(x, v) is >> x; return is; }

int n = 500;
vector<u64> s, t, u, v;

int f(u64 x, int k) {
  return (x >> k) & 1ull;
}

int main() {
  cin >> n;
  s.resize(n);
  t.resize(n);
  u.resize(n);
  v.resize(n);
  cin >> s >> t >> u >> v;
  vector<vector<u64>> ans(n, vector<u64>(n));
  rep(i, 64) {
    bool ok = true;
    rep(_, 100) {
      auto temp = ans;
      rep(j, n) rep(k, n) {
        if (s[j] == 1 && f(u[j], i) == 0) {
          if (t[k] == 0 && f(v[k], i) == 1) {
            cout << -1 << endl;
            exit(0);
          }
        }
        if (s[j] == 0 && f(u[j], i) == 1) {
          if (t[k] == 1 && f(v[k], i) == 0) {
            cout << -1 << endl;
            exit(0);
          }
          temp[j][k] |= 1ull << i;
        }
        if (s[j] == 1 && f(u[j], i) == 1) {
          if (t[k] == 1 && f(v[k], i) == 1) {
            temp[j][k] |= 1ull << i;
          }
          if (t[k] == 0 && f(v[k], i) == 1) {
            temp[j][k] |= 1ull << i;
          }
          if (t[k] == 0 && f(v[k], i) == 0) {
            if (xorshift() % 2) {
              temp[j][k] |= 1ull << i;
            }
          }
        }
        if (s[j] == 0 && f(u[j], i) == 0) {
          if (t[k] == 0 && f(v[k], i) == 1) {
            temp[j][k] |= 1ull << i;
          }
          if (t[k] == 1 && f(v[k], i) == 1) {
            if (xorshift() % 2) {
              temp[j][k] |= 1ull << i;
            }
          }
        }
      }
      ok = true;
      rep(j, n) {
        int sum = f(temp[j][0], i);
        reps(k, n - 1) {
          if (s[j] == 0) {
            sum &= f(temp[j][k], i);
          } else {
            sum |= f(temp[j][k], i);
          }
        }
        if (sum != f(u[j], i)) {
          ok = false;
        }
      }
      rep(k, n) {
        int sum = f(temp[0][k], i);
        reps(j, n - 1) {
          if (t[k] == 0) {
            sum &= f(temp[j][k], i);
          } else {
            sum |= f(temp[j][k], i);
          }
        }
        if (sum != f(v[k], i)) {
          ok = false;
        }
      }
      if (ok) {
        ans = temp;
        break;
      }
    }
    if (!ok) {
      cout << -1 << endl;
      exit(0);
    }
  }
  rep(i, n) rep(j, n) {
    cout << ans[i][j];
    cout << (j == n - 1 ? '\n' : ' ');
  }
}