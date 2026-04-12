#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m, a, b;
  cin >> n >> m;
  vector<vector<bool>> vn(n, vector<bool>(n,false));
  for(int i=0; i<m; ++i){
    cin >> a >> b;
    --a; --b;
    vn[a][b] = true;
    vn[b][a] = true;
  }
  vector<vector<int>> dp(n, vector<int>((1<<n),0));
  dp[0][1] = 1;
  for(int i=1; i<(1<<n); ++i) for(int j=0; j<n; ++j){
    if(i >> j &1){
      for(int k=0; k<n; ++k){
        if(!vn[j][k]) continue;
        if((i >> k &1) == 0) continue;
        dp[j][i] += dp[k][i -(1 << j)];
      }
    }
  }
  int ans = 0;
  for(int i=1; i<n; ++i){
    ans += dp[i][(1<<n)-1];
  }
  cout << ans << endl;
}