#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define int long long

int patty[55];
int total[55];

int dfs(int n, int x) {
  if(n == 0) {
    if(x <= 0) return 0;
    else return 1;
  }

  int res = 0;
  if(x <= total[n - 1] + 1LL) {
    res += dfs(n - 1,x - 1);
  } else {
    res += patty[n - 1] + 1LL + dfs(n - 1, x - total[n - 1] - 2);
  }
  return res;
}

signed main() {
  int n,x;
  cin >> n >> x;

  patty[0] = total[0] = 1LL;
  for (int i = 1; i <= n + 1; i++) {
    patty[i] = patty[i - 1] * 2LL + 1LL;
    total[i] = total[i - 1] * 2LL + 2LL + 1LL;
  }

  int answer = dfs(n, x);
  cout << answer << endl;
}
