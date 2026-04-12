#include<bits/stdc++.h>
using namespace std;
int n;
long long a[3010];
long long dp[3010][3010]; //[l, r)の要素が残っている状態から追加で得られる太郎君の最大得点
long long solve(int l, int r){
  if(l == r) return 0;
  if(dp[l][r] > 0) return dp[l][r];
  if((n - (r - l)) % 2 == 0) dp[l][r] = max(solve(l+1, r) + a[l], solve(l, r-1) + a[r-1]);
  else dp[l][r] = min(solve(l+1, r), solve(l, r-1));
  return dp[l][r];
}
int main(){
  cin >> n;
  for(int i=0; i<n; i++) cin >> a[i];
  solve(0, n);
  cout << dp[0][n] * 2 - accumulate(a, a+n, 0LL) << endl;
}