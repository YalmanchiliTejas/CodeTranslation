#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <vector>

const int MOD = 1e9 + 7;
const int iINF = 2147483647;
const long long int llINF = 9223372036854775807;

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vvvl = vector<vector<vector<ll>>>;

typedef pair<ll, ll> pll;
bool paircomp(const pll &a, const pll &b) {
  if (a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}
struct multi {
  ll first;
  ll second;
  ll third;
  multi(ll first, ll second, ll third)
      : first(first), second(second), third(third) {}
};
bool multicomp(const multi &a, const multi &b) {
  if (a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define RREP(i, n) for (ll i = (n)-1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define AUTO(i, m) for (auto &i : m)
#define ALL(a) (a).begin(), (a).end()
#define MAX(vec) *std::max_element(vec.begin(), vec.end())
#define MIN(vec) *std::min_element(vec.begin(), vec.end())
#define ARGMAX(vec)                                                            \
  std::distance(vec.begin(), std::max_element(vec.begin(), vec.end()))
#define ARGMIN(vec)                                                            \
  std::distance(vec.begin(), std::min_element(vec.begin(), vec.end()))
#define REV(T) greater<T>()
#define PQ(T) priority_queue<T, vector<T>, greater<T>>
#define VVL(a, b, c) vector<vector<ll>>(a, vector<ll>(b, c))
#define VVVL(a, b, c, d)                                                       \
  vector<vector<vector<ll>>>(a, vector<vector<ll>>(b, vector<ll>(c, d)))
#define SP(a) setprecision(a)
#define SQRT(a) sqrt((long double)(a))
#define DPOW(a, b) pow((long double)(a), (long double)(b))
#define UNIQUE(vec)                                                            \
  do {                                                                         \
    sort(ALL((vec)));                                                          \
    (vec).erase(std::unique(ALL((vec))), (vec).end());                         \
  } while (0)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

ll P(ll n, ll m) {
  ll ans = 1;
  for (ll i = m + 1; i <= n; i++) {
    ans *= i;
    ans %= MOD;
  }
  return ans;
}

ll MODPOW(ll n, ll m) {
  if (m == 0) {
    return 1;
  } else if (m % 2 == 0) {
    ll tmp = MODPOW(n, m / 2);
    return (tmp * tmp) % MOD;
  } else {
    return (n * MODPOW(n, m - 1)) % MOD;
  }
}
ll factorial(ll n) {
  ll ans = 1;
  for (ll i = 2; i <= n; i++) {
    ans *= i;
    ans %= MOD;
  }
  return ans;
}
ll C(ll n, ll m) { return (P(n, n - m) * MODPOW(factorial(m), MOD - 2)) % MOD; }

ll DIV(ll a, ll b) { return (a * MODPOW(b, MOD - 2)) % MOD; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N, M, K;
  cin >> N >> M >> K;
  ll ans = 0;
  ll a = C(N * M - 2, K - 2);

  REP(i, N) REP(j, M) {
    ll po = 0;
    po += (((N - 1 - i) * (N - i) * M) / 2) % MOD;
    po %= MOD;
    po += ((i * (i + 1) * M) / 2) % MOD;
    po %= MOD;
    po += (((M - 1 - j) * (M - j) * N) / 2) % MOD;
    po %= MOD;
    po += ((j * (j + 1) * N) / 2) % MOD;
    po %= MOD;
    po *= a;
    po %= MOD;
    ans += po;
    ans %= MOD;
  }
  cout << DIV(ans, 2) << endl;

  return 0;
}
