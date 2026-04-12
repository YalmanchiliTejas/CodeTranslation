#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int64_t i = 0; i < (n); ++i)
#define repe(i, n) for (int64_t i = 0; i <= (n); ++i)
#define reps(i, s, n) for (int64_t i = (s); i < (n); ++i)
#define repse(i, s, n) for (int64_t i = (s); i <= (n); ++i)
#define repr(i, n) for (int64_t i = (n); i >= 0; --i)
const int64_t inf = (int64_t)1e18;
const int64_t mod = (int64_t)1e9 + 7;


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N; cin >> N;
  vector<int64_t> hs(N);
  rep(i, N) cin >> hs[i];

  int64_t ans = 0;
  int64_t highest = 0;

  rep(i, N) {
    if (hs[i] >= highest) {
      ans++;
      highest = hs[i];
    }
  }

  cout << ans << endl;

  return 0;
}