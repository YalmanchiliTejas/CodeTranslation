/* Author: $%U%$
 * Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
**/
#include <bits/stdc++.h>
using namespace std;
#define fore(i, a, b) for (int i = a, to = b; i < to; i++)
#define all(v) v.begin(), v.end()
#define SZ(v) (int)v.size()
#define pb push_back
typedef long long Long;
typedef pair<int, int> Pair;
vector<Long> v;
vector<Long> acum;
int n;
const Long INF = (1e15);
const int MX = 2e5;
Long memo[MX + 2][3];
Long vis[MX + 2][3];
Long dp(int pos, int dejo) {
  if (pos >= n) {
    if (n % 2 == 0) {
      if (dejo <= 1)
        return 0;
      else
        return -INF;
    } else {
      if (dejo == 2 || dejo == 1)
        return 0;
      else
        return -INF;
    }
  }
  if (dejo > 2) return -INF;
  if (vis[pos][dejo]) return memo[pos][dejo];
  vis[pos][dejo] = true;
  Long &ans = memo[pos][dejo] = -INF;
  ans = max(ans, dp(pos + 1, dejo + 1));
  ans = max(ans, dp(pos + 2, dejo) + v[pos]);
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  v.resize(n);
  fore(i, 0, n) cin >> v[i];
  acum.resize(n);
  acum[0] = v[0];
  acum[1] = v[1];
  Long mini = INF;
  fore(i, 1, n) {
    mini = min(mini, v[i]);
    i++;
  }
  fore(i, 2, n) {
    acum[i] = acum[i - 2] + v[i];
  }
  memset(memo, -1, sizeof memo);
  cout << dp(0, 0) << '\n';

  return 0;
}