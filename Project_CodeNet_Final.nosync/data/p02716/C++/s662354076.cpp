#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long a[n+1];
  for (int i =1; i <= n; ++i) cin >> a[i];
  vector<long long> dp(n+1,0);
	dp[1] = 0;
	vector<long long> prefix(n+1);
	prefix[1] = a[1];
	for(int i=3;i<=n;i+=2){
		prefix[i] = prefix[i-2]+a[i];
	}
	for(int i=2;i<=n;i++){
		if(i&1){
			dp[i]=max(dp[i-1],dp[i-2]+a[i]);
		}else{
			dp[i] = a[i] + dp[i-2];
			dp[i] = max(dp[i],prefix[i-1]);
		}
	}
	cout<<dp[n];
  return 0;
}
