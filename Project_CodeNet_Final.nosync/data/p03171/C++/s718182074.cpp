#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[3010][3010];
ll a[3010];
ll solve(int i, int j){
	if(i > j) return 0;
  	if(dp[i][j] != -1) return dp[i][j];
  	return dp[i][j] = max(a[i] - solve(i + 1, j), a[j] - solve(i, j - 1));
}
int main(){
  int n;
  cin >> n;
  memset(dp, -1, sizeof(dp));
  for(int i = 0; i < n; i++) cin >> a[i];
  cout << solve(0, n - 1);
}
