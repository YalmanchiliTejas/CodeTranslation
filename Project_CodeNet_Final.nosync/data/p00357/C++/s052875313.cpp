#include "bits/stdc++.h"
#define int long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define LOWER_BOUND(A, key) distance(A.begin(), lower_bound(ALL(A), key))
#define UPPER_BOUND(A, key) distance(A.begin(), upper_bound(ALL(A), key))

using namespace std;
using ll      = long long;
const int MOD = (int)(1e9 + 7);
const int INF = (int)(1e13 + 7);

int bpm(int x, unsigned int y) {
  if (x == 0) return 0;
  if (y == 0) return 1;
  int ans   = 1;
  int digit = (int)((log((double)y) / log((double)2) / 1 + 1));
  x %= MOD;
  for (unsigned int i = 0; i < digit; i++) {
    if (((y >> i) & 1u) == 1) ans = ans * x % MOD;
    x = x * x % MOD;
  }
  return ans;
}

signed main() {
  int N;
  cin >> N;
  vector<int> d(N);
  rep(i, N) cin >> d[i];
  int Maxi = 0;
  rep(i, N) {
    if (10 * i > Maxi) {
      cout << "no" << endl;
      return 0;
    }
    Maxi = max(Maxi, 10 * i + d[i]);
  }
  int Mini = 10 * (N - 1);
  rep(i, N) {
    if (Mini > 10 * (N - 1 - i)) {
      cout << "no" << endl;
      return 0;
    }
    Mini = min(Mini, 10 * (N - 1 - i) - d[N - 1 - i]);
  }
  cout << "yes" << endl;
}

