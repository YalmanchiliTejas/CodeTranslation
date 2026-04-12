//#include "atcoder/all"
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <vector>

const int MOD = 1e9 + 7;
const int iINF = 2147483647 / 2;
const long long int llINF = 9223372036854775807 / 2;

using namespace std;
// using namespace atcoder;
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
#define VV(T, a, b, c) vector<vector<T>>(a, vector<T>(b, c))
#define VVVL(a, b, c, d)                                                       \
  vector<vector<vector<ll>>>(a, vector<vector<ll>>(b, vector<ll>(c, d)))
#define VVV(T, a, b, c, d)                                                     \
  vector<vector<vector<T>>>(a, vector<vector<T>>(b, vector<T>(c, d)))
#define SP(a) fixed << setprecision(a)
#define SQRT(a) sqrt((long double)(a))
#define DPOW(a, b) pow((long double)(a), (long double)(b))
#define UNIQUE(vec)                                                            \
  do {                                                                         \
    sort(ALL((vec)));                                                          \
    (vec).erase(std::unique(ALL((vec))), (vec).end());                         \
  } while (0)

ll POW(ll n, ll m) {
  if (m == 0) {
    return 1;
  } else if (m % 2 == 0) {
    ll tmp = POW(n, m / 2);
    return (tmp * tmp);
  } else {
    return (n * POW(n, m - 1));
  }
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N, X, M;
  cin >> N >> X >> M;

  if (X == 0) {
    cout << 0 << endl;
    return 0;
  }

  map<ll, ll> MAP;
  map<ll, ll> PO;
  MAP[X] = 0;
  ll last = -1;

  ll cost = X;
  PO[0] = X;
  REP(i, M) {
    X = (X * X) % M;
    // cout << X << endl;
    if (MAP.count(X) == 0) {
      MAP[X] = i + 1;
      cost += X;
      PO[i + 1] = cost;
    } else {
      // cout << i << "," << MAP[X] << endl;
      last = i + 1;
      break;
    }
    if (i == N - 2) {
      cout << cost << endl;
      return 0;
    }
  }
  ll loop_first = MAP[X];
  //////////////
  ll loop_count = 0;
  ll loop_cost = 0;
  ll now = X;
  // cout << now << endl;
  REP(i, M) {
    now = (now * now) % M;

    loop_count++;
    loop_cost += now;
    if (now == X)
      break;
  }
  // cout << loop_cost << "," << loop_count << "," << loop_first << endl;

  // cout << PO[loop_first] << endl;

  ll ans = loop_cost * ((N - loop_first - 1) / loop_count);
  ans += PO[loop_first];
  ll rest = (N - loop_first - 1) % loop_count;

  // cout << rest << endl;

  REP(i, rest) {
    X = (X * X) % M;
    ans += X;
  }

  cout << ans << endl;

  return 0;
}
