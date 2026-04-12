#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,q;
  cin >> n >> q;
  int dp[n][2];
  memset(dp,0,sizeof(dp));
  dp[0][0]=dp[1][1]=1;
  while(q--) {
    int x,y;
    cin >> x >> y;
    x--,y--;
    swap(dp[x][0],dp[y][0]);
    swap(dp[x][1],dp[y][1]);
    if(y>0) {
      dp[y-1][1]|=dp[y][0];
      dp[y][1]|=dp[y-1][0];
    }
    if(y+1<n) {
      dp[y+1][1]|=dp[y][0];
      dp[y][1]|=dp[y+1][0];
    }
    if(x>0) {
      dp[x-1][1]|=dp[x][0];
      dp[x][1]|=dp[x-1][0];
    }
    if(x+1<n) {
      dp[x+1][1]|=dp[x][0];
      dp[x][1]|=dp[x+1][0];
    }
  }
  int ans=0;
  for(int i=0; i<n; i++) {
    int f=dp[i][0]|dp[i][1];
    if(i) f|=dp[i-1][0];
    if(i+1<n) f|=dp[i+1][0];
    ans+=f;
  }
  cout << ans << endl;
  return 0;
}
