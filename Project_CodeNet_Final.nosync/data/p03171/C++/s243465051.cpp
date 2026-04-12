#include <bits/stdc++.h>
using namespace std;

int n;

long long a[3010];
long long memo[3010][3010][2];

long long dp(int l, int r, int t){
  if(l > r) return 0;

  if(memo[l][r][t] != LLONG_MIN) return memo[l][r][t];

  if(t == 0){
    return memo[l][r][t] = max(dp(l+1, r, 1) + a[l], dp(l, r-1, 1) + a[r]);
  }else{
    return memo[l][r][t] = min(dp(l+1, r, 0) - a[l], dp(l, r-1, 0) - a[r]);
  }
}

int main(){
  cin >> n;

  for(int i = 0;i < n;i++){
    cin >> a[i];
  }

  for(int i = 0;i < 3010;i++){
    for(int j = 0;j < 3010;j++){
      for(int k = 0;k < 2;k++){
        memo[i][j][k] = LLONG_MIN;
      }
    }
  }

  cout << dp(0, n-1, 0) << endl;

  return 0;
}
