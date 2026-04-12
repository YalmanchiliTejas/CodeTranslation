#include <bits/stdc++.h>
using namespace std;
const int MX  = 3e3+5;
long long dp[MX][MX] = {};
int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i]*1LL;
    dp[i][i] = a[i];
  }
  for (int i = n-1; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
      if(i== j) {
        continue;
      }else if(j - i == 1) {
        dp[i][j] = max(a[j], a[i]);
      }else if(j - i  > 1) {
        dp[i][j] = max(min(dp[i+2][j],dp[i+1][j-1]) + a[i], min(dp[i][j-2], dp[i+1][j-1])+a[j]);
      }
    }
  }
  cout << -1*(sum - 2LL*dp[0][n-1]);
  return 0;
}


