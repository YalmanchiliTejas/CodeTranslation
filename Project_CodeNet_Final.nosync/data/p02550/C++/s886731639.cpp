#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (ll)(n); ++i)
#define rrep(i, j, n) for (int i = (int)(n)-1; j <= i; --i)

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& a) {
  os << "{";
  for (size_t i = 0; i < a.size(); ++i) os << (i > 0 ? "," : "") << a[i];
  return os << "}";
}

[[maybe_unused]] constexpr ll MOD = 1000000007;
[[maybe_unused]] constexpr int INF = 0x3f3f3f3f;
[[maybe_unused]] constexpr ll INFL = 0x3f3f3f3f3f3f3f3fLL;

int main() {
  ll n, x, m;
  cin >> n >> x >> m;
  vector<bool> used(m * 2);
  vector<ll> one_cycle;

  int start = 0;
  ll now = x;
  rep(i, 0, n) {
    used[now] = true;
    one_cycle.push_back(now);
    now = now * now % m;
    if (used[now]) {
      rep(j, 0, one_cycle.size()) if (one_cycle[j] == now) {
        start = j;
        break;
      }
      break;
    }
  }

  ll s1 = 0, s2 = 0, loop = (int)one_cycle.size() - start;
  rep(i, 0, start) s1 += one_cycle[i];
  rep(i, start, one_cycle.size()) s2 += one_cycle[i];
  ll ans = s1 + (n - start) / loop * s2;
  rep(i, 0, (n - start) % loop) {
    ans += now;
    now = now * now % m;
  }
  cout << ans << endl;
  return 0;
}
