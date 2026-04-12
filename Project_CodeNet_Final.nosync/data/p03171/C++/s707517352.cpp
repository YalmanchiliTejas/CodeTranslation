#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
#define chmax(x, v) do { x = max(x, v); } while (0)
#define chmin(x, v) do { x = min(x, v); } while (0)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

// p[i][j]: 先頭がi、終端がjの数列でX-Yの最大値
ll p[4000][4000];
// q[i][j]: 先頭がi、終端がjの数列でY-Xの最大値
ll q[4000][4000];

ll N;
vector<ll> a;

signed main() {
  cin >> N;
  a.resize(N);
  rep(i, N)
    cin >> a[i];
  rep(i, 4000) { p[i][i] = q[i][i] = 0; }
  for (ll len = 1; len <= 4000; len++) {
    rep(i, 3999) {
      ll j = i+len;
      if (j > N) continue;
      p[i][j] = max(a[i]-q[i+1][j], a[j-1]-q[i][j-1]);
      q[i][j] = max(a[i]-p[i+1][j], a[j-1]-p[i][j-1]);
    }
  }
  cout << p[0][N] << endl;
  return 0;
}
