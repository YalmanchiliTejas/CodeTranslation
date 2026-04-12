#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int INF = 100100100;
const double PI = 3.14159265358979323846;
typedef long long ll;
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define REP(i, n) for (ll i = 0; i < (n); ++i)

int main() {
  int n, m, ans = 0;
  cin >> n >> m;
  vector<int> a(m), b(m), v(n);
  REP(i, m) cin >> a[i] >> b[i];
  REP(i, n) v[i] = i + 1;
  do {
    if (v[0] != 1) break;
    bool exist = true;
    int i;
    for (i = 0; exist && i < n - 1; ++i) {
      exist = false;
      REP(j, m) {
        if (v[i] == a[j] && v[i + 1] == b[j]) exist = true;
        if (v[i] == b[j] && v[i + 1] == a[j]) exist = true;
      }
    }
    if (exist && i >= n - 1) ++ans;
  } while (next_permutation(v.begin(), v.end()));
  cout << ans << endl;
  return 0;
}