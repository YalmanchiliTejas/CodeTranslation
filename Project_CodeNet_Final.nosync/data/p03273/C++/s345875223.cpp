#include <bits/stdc++.h>
#define FOR(i, m, n) for (ll i = m; i < (n); i++)
#define RFOR(i, m, n) for (ll i = (m - 1); i >= 0; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, n, 0)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define print(ele) cout << (ele) << "\n"
#define print10(ele) cout << fixed << setprecision(10) << (ele) << "\n"

using namespace std;
typedef long long ll;
typedef vector<int> ivec;
typedef vector<string> svec;
typedef vector<ll> lvec;

const int mod = 1e9 + 7;
const ll INF = 1000000000000000000LL;

int main() {
  int h, w;
  cin >> h >> w;
  svec a(h);
  REP(i, h) cin >> a[i];

  svec ans;
  REP(i, a.size()) {
    bool isBlank = true;
    REP(j, a[i].size()) {
      if (a[i][j] == '#') {
        isBlank = false;
      }
    }
    if (isBlank) {
      a.erase(a.begin() + i);
      i--;
    }
  }
  REP(i, a[0].size()) {
    bool isBlank = true;
    REP(j, a.size()) {
      if (a[j][i] == '#') {
        isBlank = false;
      }
    }
    if (isBlank) {
      REP(j, a.size()) { a[j].erase(a[j].begin() + i); }
      i--;
    }
  }
  REP(i, a.size()) print(a[i]);
  return 0;
}