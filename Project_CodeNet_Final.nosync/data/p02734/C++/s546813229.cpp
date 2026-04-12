#include <bits/stdc++.h>
#define ii pair <long long, long long>
using namespace std;
 
const int N = 3010;
const long long md = 998244353;
const int inf = 123456789;
 
int n, s;
int a[N];
long long dp[N][N][3];
 
long long f(int idx, int cur, int tx) {
  if (cur < 0) return 0;
  if (tx == 2) return cur == 0;
  if (idx == n) return 0;  
  if (dp[idx][cur][tx] != -1) {
    return dp[idx][cur][tx];
  }
  if (tx == 0) {
    return dp[idx][cur][tx] = (f(idx + 1, cur, tx) + f(idx, cur, tx + 1)) % md;
  }
  if (tx == 1) {
    return dp[idx][cur][tx] = (f(idx + 1, cur, tx) + f(idx + 1, cur - a[idx], tx) + f(idx + 1, cur, tx + 1) + f(idx + 1, cur - a[idx], tx + 1)) % md;
  }
}
 
int main() {
  scanf("%d %d", &n, &s);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  long long ans = 0;
  memset(dp, -1, sizeof dp);
  //cout << f(0, s, 0) << endl;
  printf("%lld\n", f(0, s, 0));
  return 0;
}