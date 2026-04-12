#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<int> vec(n);
  for(int i=0; i<n; ++i){
    cin >> vec.at(i);
  }
  if(n%2 == 0){
    ll dp[n];
    dp[0] = vec.at(0); dp[1] = vec.at(1);
    for(int i=2; i<n; ++i){
      if(i%2 == 0) dp[i] = dp[i-2]+vec.at(i);
      else dp[i] = max(dp[i-2], dp[i-3])+ vec.at(i);
    }
    ll ans = max(dp[n-1],dp[n-2]);
    cout << ans << endl;
    return 0;
  }
  ll dp[n][3];
  dp[0][0] = vec.at(0); dp[1][1] = vec.at(1); dp[2][2] = vec.at(2);
  for(int i=2; i<n; i+=2){
    dp[i][0] = dp[i-2][0] + vec.at(i);
  }
  for(int i=3; i<n; i+=2){
    dp[i][1] = max(dp[i-2][1], dp[i-3][0]) + vec.at(i);
  }
  for(int i=4; i<n; i+=2){
    dp[i][2] = max(max(dp[i-2][2], dp[i-3][1]), dp[i-4][0]) + vec.at(i);
  }
  ll ans = max(max(dp[n-3][0], dp[n-2][1]), dp[n-1][2]);
  cout << ans << endl;
}