#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 3010;
const ll INF = LLONG_MAX;

ll arr[MAX_N];
ll memo[MAX_N][MAX_N][2];

ll dp (int l, int r, int flag) {
  if (l > r) return 0;
  ll& ret = memo[l][r][flag];
  if (ret < INF) return ret;
  return ret = max(arr[l] - dp(l + 1, r, flag ^ 1), arr[r] - dp(l, r - 1, flag ^ 1));
}

int main () {
  for (int i = 0; i < MAX_N; i++) for (int j = 0; j < MAX_N; j++) for (int k = 0; k < 2; k++) memo[i][j][k] = INF;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  cout << dp(0, n - 1, 0) << endl;
  return (0);
}
