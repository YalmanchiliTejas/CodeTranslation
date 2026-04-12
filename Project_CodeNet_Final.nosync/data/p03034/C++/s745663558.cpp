#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../lib/dump.hpp"
#else
#define dump(...)
#define dumpv(...)
#endif

#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

void solve() {
  int N;
  cin >> N;
  vector<int> s(N);
  rep(i, N) cin >> s[i];
  ll ans = 0;
  for (int c = 1; c <= N; c++) {
    ll score = 0;
    set<int> used;
    for (int x = 0; x < N; x++) {
      if (N < c * x) break;
      int A = (N - 1) - c * x;
      int B = A - c;
      if (B <= 0) break;
      if (used.find(c * x) != used.end()) break;
      used.insert(c * x);
      score += s[c * x];
      if (used.find((N - 1) - c * x) != used.end()) break;
      used.insert((N - 1) - c * x);
      score += s[(N - 1) - c * x];
      ans = max(ans, score);
    }
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  // freopen("temp.1", "r", stdin);
  solve();
  return 0;
}