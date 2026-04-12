#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

const int MOD = 1e9 + 7;
const int iINF = 1000000000;
const long long int llINF = 1000000000000000000;

using namespace std;
using ll = long long int;
using edge = struct {
  int to;
  int cost;
};
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define AUTO(i, m) for (auto i = (m).begin(); i != (m).end(); ++i)
#define ALL(a) (a).begin(), (a).end()
#define MAX(vec) *std::max_element(vec.begin(), vec.end());
#define MIN(vec) *std::min_element(vec.begin(), vec.end());
#define MAXI(vec)                                                              \
  std::distance(vec.begin(), *std::max_element(vec.begin(), vec.end()));
#define MINI(vec)                                                              \
  std::distance(vec.begin(), *std::min_element(vec.begin(), vec.end()));
#define BIT(n, num) std::bitset<(n)>((num)).to_string()
#define MATMUL(a, b, c)                                                        \
  REP(i, a.size())                                                             \
  REP(j, b[0].size()) REP(k, a[0].size()) c[i][j] += a[i][k] * b[k][j];
#define CLA2(a) REP(i, a.size()) REP(j, a[0].size()) a[i][j] = 0;
#define REV(T) greater<T>()

ll pow_(ll a, ll n) {
  ll x = 1;
  while (n > 0) {
    if (n & 1)
      x = (x * a) % MOD;
    a = (a * a) % MOD;
    n >>= 1;
  }
  return x;
}

vector<ll> divisor(ll n) {
  vector<ll> ret;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i * i != n)
        ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

map<ll, int> prime_factor(ll n) {
  map<ll, int> ret;
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if (n != 1)
    ret[n] = 1;
  return ret;
}

ll factorial(int n) {
  ll ans = 1;
  for (int i = 2; i <= n; i++) {
    ans *= i;
    ans %= MOD;
  }
  return ans;
}
ll P(int n, int m) {
  ll ans = 1;
  for (int i = m + 1; i <= n; i++) {
    ans *= i;
    ans %= MOD;
  }
  return ans;
}
ll power(int n, int m) {
  if (m == 0) {
    return 1;
  } else if (m % 2 == 0) {
    ll tmp = power(n, m / 2);
    return (tmp * tmp) % MOD;
  } else {
    return (n * power(n, m - 1)) % MOD;
  }
}
ll C(int n, int m) {
  return (P(n, n - m) * power(factorial(m), MOD - 2)) % MOD;
}
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

ll mo[52] = {};
ll ful[52] = {};

ll po(ll X, ll N) {
  ll c = 0;
  if (N < 0)
    return 0;
  if (mo[N] == X && ful[N] != 0) {
    return ful[N];
  }

  ll yo = mo[N] >> 1;
  if (X > yo) {
    c++;
    c += (po(X - yo - 1, N - 1) + po(yo - 1, N - 1));
  } else {
    c += po(X - 1, N - 1);
  }
  if (mo[N] == X)
    ful[N] = c;
  return c;
}

int main() {
  for (int i = 0; i <= 51; i++) {
    mo[i] = ((ll)1 << (i + 2)) - 3;
    ful[i] = 0;
  }

  ll N, X;
  vector<ll> A;
  cin >> N >> X;
  cout << po(X, N)<<endl;

  return 0;
}
