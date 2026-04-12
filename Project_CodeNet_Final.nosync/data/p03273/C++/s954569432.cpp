#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

int main() {
  ll h, w;
  cin >> h >> w;
  vector<string> s(h);
  REP(i, h) { cin >> s[i]; }
  vector<bool> r(h, false), c(w, false);
  REP(i, h) {
    REP(j, w) {
      if (s[i][j] == '#') {
        r[i] = true;
      }
    }
  }

  REP(j, w) {
    REP(i, h) {
      if (s[i][j] == '#') {
        c[j] = true;
      }
    }
  }

  REP(i, h) {
    if (!r[i]) {
      continue;
    }
    REP(j, w) {
      if (c[j]) {
        cout << s[i][j];
      }
    }
    cout << "\n";
  }
}