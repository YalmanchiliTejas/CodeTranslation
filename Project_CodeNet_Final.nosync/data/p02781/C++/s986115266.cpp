#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define MOD (1000000007l)
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)

using namespace std;

ll foo[110][5];
ll bar[110][5];

void solve() {
  string STR;
  cin >> STR;
  ll K;
  cin >> K;
  ll N = STR.size();

  rep (i, 110) rep (j, 5) foo[i][j] = 0;
  rep (i, 110) rep (j, 5) bar[i][j] = 0;

  foo[0][0] = 1;

  rep (i, N) {
    rep (num, 10) {
      if (num == 0) {
        rep (j, 4) {
          if (num < STR[i] - '0') {
            bar[i+1][j] += foo[i][j];
          } else if (num == STR[i] - '0') {
            foo[i+1][j] += foo[i][j];
          }
          bar[i+1][j] += bar[i][j];
        }
      } else {
        rep (j, 3) {
          bar[i+1][j+1] += bar[i][j];
          if (num < STR[i] - '0') {
            bar[i+1][j+1] += foo[i][j];
          } else if (num == STR[i] - '0') {
            foo[i+1][j+1] += foo[i][j];
          }
        }
      }
    }
  }

  ll ans = foo[N][K] + bar[N][K];
  cout << ans << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(12);
  cout << fixed;
  solve();
  return 0;
}
