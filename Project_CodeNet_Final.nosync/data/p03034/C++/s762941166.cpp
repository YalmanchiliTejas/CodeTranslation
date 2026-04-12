#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define irep(i, a, n) for (int i = a; i < (int)(n); ++i)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define rrep1(i, n) for (int i = (int)(n); i >= 1; --i)
#define allrep(V, v) for (auto &&V : v)
#define all(x) (x).begin(), (x).end()
const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
using lint = long long;

using namespace std;

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> s(n);
  lint maxsum = -INFL;
  rep(i, n) cin >> s[i];
  int n1 = n - 1;
  rep1(c, n1 - 1) {
    set<int> alr;
    lint sum = 0;
    for (int nc = 0; nc < n1; nc += c) {
      int a = n1 - nc;
      int b = a - c;
      if (a <= b || b < 0) continue;
      if (alr.find(nc) != alr.end()) break;
      alr.insert(nc);
      if (alr.find(n1 - nc) != alr.end()) break;
      alr.insert(n1 - nc);
      sum += s[nc] + s[n1 - nc];
      maxsum = max(maxsum, sum);
    }
  }
  cout << maxsum << endl;
  return 0;
}