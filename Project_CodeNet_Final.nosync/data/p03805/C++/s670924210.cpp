#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(var, begin, end) for (int var = (begin); var <= (end); var++)
#define RFOR(var, begin, end) for (int var = (begin); var >= (end); var--)
#define REP(var, length) FOR(var, 0, length - 1)
#define RREP(var, length) RFOR(var, length - 1, 0)
#define EACH(value, var) for (auto value : var)
#define SORT(var) sort(var.begin(), var.end())
#define REVERSE(var) reverse(var.begin(), var.end())
#define RSORT(var) \
  SORT(var);       \
  REVERSE(var)
#define OPTIMIZE_STDIO         \
  ios::sync_with_stdio(false); \
  cin.tie(0);                  \
  cout.precision(10);          \
  cout << fixed
#define endl '\n'

const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
struct mint {
  ll x;
  mint() : x(0) {
  }
  mint(ll x) : x((x % MOD + MOD) % MOD) {
  }
  mint& operator+=(const mint& r) {
    if ((x += r.x) >= MOD) {
      x -= MOD;
    }
    return *this;
  }
  mint& operator-=(const mint& r) {
    if ((x -= r.x) < 0) {
      x += MOD;
    }
    return *this;
  }
  mint& operator*=(const mint& r) {
    if ((x *= r.x) > MOD) {
      x %= MOD;
    }
    return *this;
  }
  mint& operator++() {
    if ((++x) >= MOD) {
      x -= MOD;
    }
    return *this;
  }
  mint operator++(int) {
    mint ret = x;
    if ((++x) >= MOD) {
      x -= MOD;
    }
    return ret;
  }
  mint& operator--() {
    if ((--x) < 0) {
      x += MOD;
    }
    return *this;
  }
  mint operator--(int) {
    mint ret = x;
    if ((--x) < 0) {
      x += MOD;
    }
    return ret;
  }
  mint operator+(const mint& r) {
    mint ret;
    return ret = x + r.x;
  }
  mint operator-(const mint& r) {
    mint ret;
    return ret = x - r.x;
  }
  mint operator*(const mint& r) {
    mint ret;
    return ret = x * r.x;
  }
  mint operator-() {
    return mint() - *this;
  }
  bool operator<(const mint& a) {
    return x < a.x;
  }
  bool operator>(const mint& a) {
    return x > a.x;
  }
  bool operator<=(const mint& a) {
    return x <= a.x;
  }
  bool operator>=(const mint& a) {
    return x >= a.x;
  }
  bool operator==(const mint& a) {
    return x == a.x;
  }
  bool operator!=(const mint& a) {
    return x != a.x;
  }
};
ostream& operator<<(ostream& os, const mint& r) {
  os << r.x;
  return os;
}
ostream& operator>>(ostream& os, const mint& r) {
  os >> r.x;
  return os;
}

void solve(istream& cin, ostream& cout) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> G(n);
  REP(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  vector<int> v(n);
  REP(i, n) v[i] = i;
  int ans = 0;
  do {
    if (v[0] != 0) continue;
    bool visited_all = true;
    REP(i, n - 1) {
      bool visited = false;
      int u = v[i];
      for (int nu : G[u]) {
        if (nu == v[i + 1]) visited = true;
      }
      if (!visited) visited_all = false;
    }
    if (visited_all) ans++;
  } while (next_permutation(v.begin(), v.end()));
  cout << ans << endl;
}

#ifndef TEST
int main() {
  OPTIMIZE_STDIO;
  solve(cin, cout);
  return 0;
}
#endif
