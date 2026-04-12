#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

ll thick[55];
ll patty[55];

ll dfs(int n, ll x) {
  if (n == 0) {
    return (x <= 0) ? 0 : 1;
  } else if (x <= thick[n - 1] + 1) {
    return dfs(n - 1, x - 1);
  } else if (x <= thick[n]) {
    return 1 + patty[n - 1] + dfs(n - 1, x - 2 - thick[n - 1]);
  } else {
    return patty[n];
  }
}

int main() {
  int n;
  ll x;
  cin >> n >> x;
  thick[0] = 1;
  patty[0] = 1;

  FOR(i, 1, n + 1) {
    thick[i] = 2 * thick[i - 1] + 3;
    patty[i] = 2 * patty[i - 1] + 1;
  }

  cout << dfs(n, x) << endl;
}