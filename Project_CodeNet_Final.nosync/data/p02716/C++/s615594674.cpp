#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); i++)

int64_t dp[4][2];

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  REP(i, n){
    if(i % 2 == 0){
      dp[0][1] = dp[1][0] + a[i];
      dp[2][1] = dp[3][0] + a[i];
      dp[2][0] = max(dp[1][0], dp[1][1]);
    }else{
      dp[1][1] = dp[2][0] + a[i];
      dp[3][0] = max(dp[2][0], dp[2][1]);
      dp[1][0] = dp[0][1];
    }
  }
  if(n % 2 == 0){
    cout << max(dp[1][0], dp[1][1]) << endl;
  }else{
    cout << max(dp[2][0], dp[2][1]) << endl;
  }
  return 0;
}