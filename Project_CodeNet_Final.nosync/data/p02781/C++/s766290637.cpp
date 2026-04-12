#include<bits/stdc++.h>
using namespace std;

#define int long long int

string n;

int dp[101][2][4];

int f(string n, int i, bool smaller, int k) {
  	if(i == n.size())
      	return k == 0;
  	if(k < 0)
    	return 0;
  	if(dp[i][smaller][k] != -1)
    	return dp[i][smaller][k];
  	int val = n[i] - '0';
  	int ans = 0;
	for(int j = 0; j <= (smaller ? 9 : val); j++) {
      bool status = smaller | (j < val);
      if(j == 0)
      	ans += f(n, i + 1, status, k);
      else
        ans += f(n, i + 1, status, k - 1);
    }
    return dp[i][smaller][k] = ans;
}

signed main() {
  int k;
  cin >> n >> k;
  memset(dp, -1, sizeof dp);
  int ans = 0;
  for(int i = 0; i < n[0] - '0'; i++) {
    if(i == 0)
    	ans += f(n, 1, true, k);
    else
      	ans += f(n, 1, true, k - 1);
  }
  ans += f(n, 1, false, k - 1);
  cout << ans << endl;
}