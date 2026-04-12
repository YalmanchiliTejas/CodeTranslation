#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[3001][3001]; //[i,j)のX-Yの値

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  //元の数列から連続する区間a[i~j]を抜き出した局面を考えていく
  for(int len = 1; len <= n; len++){
    for(int i = 0; i+len <= n; i++){
      int j = i + len;
      if((n-len)%2 == 0){
        dp[i][j] = max(dp[i+1][j] + a[i],dp[i][j-1] + a[j-1]);
      }
      else {
        dp[i][j] = min(dp[i+1][j] - a[i],dp[i][j-1] - a[j-1]);
      }
    }
  }
  cout << dp[0][n] << endl;

  return 0;
}
