#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

// c++11
#include <array>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

#define mp make_pair
#define mt make_tuple
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF = 1 << 29;
const double EPS = 1e-9;
const ll MOD = 1000000007;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
//mod
template <typename T> class ModUtil {
public:
  ModUtil(int N, T mod)
      : N(N), mod(mod), inv(N + 1), fact(N + 1), inv_fact(N + 1) {
    calc();
  }
  //
  T get_inv(int n) { return inv[n]; }
  T get_fact(int n) { return fact[n]; }
  T get_inv_fact(int n) { return inv_fact[n]; }
  T get_P(int n, int k) {
    if (n < k)
      return 0;
    return fact[n] * inv_fact[n - k] % mod;
  }
  T get_C(int n, int k) {
    if (n < k)
      return 0;
    return get_P(n, k) * inv_fact[k] % mod;
  }

private:
  vector<T> inv, fact, inv_fact;
  int N;
  T mod;
  // O(N)
  void calc() {
    // cout << N << " " << mod << endl;
    inv[1] = 1;
    for (int i = 2; i <= N; i++) {
      inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    }
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
      fact[i] = i * fact[i - 1] % mod;
    }
    inv_fact[0] = 1;
    for (int i = 1; i <= N; i++) {
      inv_fact[i] = inv[i] * inv_fact[i - 1] % mod;
      // cout << i << " " << inv_fact[i] << endl;
    }
  }
};

int N, A, B, C, D;
const int MAX_N = 1010;
ModUtil<ll> mod_util(MAX_N, MOD);

ll dp[MAX_N][MAX_N];
ll memo(int n, int a) {
  if (n == 0) {
    return 1;
  }
  if (a > B){
    return 0;
  }
  ll &res = dp[n][a];
  if (res >= 0) {
    return res;
  }
  res = 0;
  res += memo(n, a + 1);
  ll f = 1;
  int cnt = 0;
  while (true){
    if (n - a < 0)
      break;
    f *= mod_util.get_C(n, a);
    f %= MOD;
    n -= a;
    cnt++;
    if (cnt > D)break;
    if (cnt >= C){
      res += memo(n, a + 1) * f % MOD * mod_util.get_inv_fact(cnt);
      res %= MOD;
    }
  }
  return res;
}

int main() {
  cin >> N >> A >> B >> C >> D;
  memset(dp, -1, sizeof(dp));
  cout << memo(N, A) << endl;

  return 0;
}
