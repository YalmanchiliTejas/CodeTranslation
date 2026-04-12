#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;

int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  VI a(n);
  for (int& x: a) cin >> x;

  vector<vector<ll>> score(n, vector<ll>(n));
  for (int i = 0; i < n; i++) {
    score[i][i] = a[i];
  }
  for (int len = 2; len <= n; len++) {
    for (int l = 0; l + len <= n; l++) {
      int r = l + len - 1;
      score[l][r] = max(a[l] - score[l + 1][r], a[r] - score[l][r - 1]);
    }
  }
  cout << score[0][n - 1] << endl;

  return 0;
}
