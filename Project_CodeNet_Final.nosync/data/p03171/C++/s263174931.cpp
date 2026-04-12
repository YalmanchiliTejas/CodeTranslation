#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e18;
const int N = 3005;

ll a[N], dp[N][N];

ll fun(int L, int R) {
  if (L > R) return 0;
  if (L == R) return a[L];
  ll &ret = dp[L][R];
  if (ret != -INF) return ret;
  ret = max(ret, a[L] - fun(L + 1, R));
  ret = max(ret, a[R] - fun(L, R - 1));
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = -INF;
    }
  }
  cout << fun(0, n - 1) << endl;
  return 0;
}
