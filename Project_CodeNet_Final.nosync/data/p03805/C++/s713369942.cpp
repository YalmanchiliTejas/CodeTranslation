#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ll INF = 1e18;
const long double EPS = 1e-10;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<bool>> e(n, vector<bool>(n, false));
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    e[a - 1][b - 1]= true;
    e[b - 1][a - 1]= true;
  }

  int ans = 0;
  vector<int> v(n);
  rep(i, n) v[i] = i;
  while (1) {
    if (v[0] != 0) break;
    bool flag = true;
    rep(i, n - 1) {
      if (!e[v[i]][v[i + 1]]) {
        flag = false;
        break;
      }
    }
    if (flag) ans++;
    next_permutation(v.begin(), v.end());
  }
  cout << ans << endl;



  
  return 0;
}