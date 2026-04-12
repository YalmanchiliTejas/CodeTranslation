#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll = int64_t;

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

string s;
int K, N;

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

ll com(ll n, ll r) {
  if (r < 0 && n > r) return 0;
  if (r == 1) return n;
  else if (r == 2) return n * (n-1) / 2;
  else return n * (n-1) * (n-2) / 6;
}
ll pow(ll n, ll k) {
  ll ret = 1;
  rep(i, k) ret *= n;
  return ret;
}

ll solve(int i, int k, bool smaller) {
  if (k == 0) return 1;
  if (i == N) return 0;
  if (smaller) return com(N-i, k) * pow(9, k);
  else if (s[i] == '0') return solve(i+1, k, false);
  else {
    ll zero, middle, lowwer;
    zero = solve(i+1, k, true);
    middle = solve(i+1, k-1, true) * (s[i] - '1');
    lowwer = solve(i+1, k-1, false);
    return zero + middle + lowwer;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << std::setprecision(10);

  std::cin >> s >> K;
  N = s.size();
  ll ans = solve(0, K, false);
  std::cout << ans << "\n";
}
