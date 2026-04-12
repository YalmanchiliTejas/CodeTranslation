#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define ddrep(i, n) for (int i = n; i > 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define ssrep(i, s, t) for (int i = s; i <= t; ++i)

#define rng(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#define chmax(x, y) (x = max(x, y))
#define chmin(x, y) (x = min(x, y))

using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using ld = long double;

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  rep(i, (int)v.size()) {
    if (i)
      os << ",";
    os << v[i];
  }
  os << "}";
  return os;
}

template <typename T, size_t S> void printArray(const T (&array)[S]) {
  for (auto val : array)
    std::cout << val << ", ";
  std::cout << "\n";
}

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

vector<ll> tt, pat;

ll dfs(ll lv, ll remain) {
  if (remain == 0) return 0;

  ll ret = 0;

  remain--; // B

  // lv-1
  if (tt[lv-1] <= remain) remain -= tt[lv-1], ret += pat[lv-1];
  else ret += dfs(lv-1, remain), remain = 0;

  if (remain > 0) remain--, ret++; // P

  // lv-1
  if (tt[lv-1] <= remain) remain -= tt[lv-1], ret += pat[lv-1];
  else ret += dfs(lv-1, remain), remain = 0;

  remain--; // B

  return ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << std::setprecision(10);

  ll n, x; std::cin >> n >> x;
  tt.resize(n+1), pat.resize(n+1);
  tt[0] = 1;
  rrep(i, n) tt[i] = tt[i-1] + 3 + tt[i-1];
  pat[0] = 1;
  rrep(i, n) pat[i] = pat[i-1] + 1 + pat[i-1];
  std::cout << dfs(n, x) << "\n";
}
