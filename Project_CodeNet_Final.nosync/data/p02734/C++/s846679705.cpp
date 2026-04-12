#include<bits/stdc++.h>
#define Mod 998244353
#define Val(x) (((long long)x) % Mod)
#define maxn 3005
using namespace std;
int arr[maxn],dp[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,S;
	cin >> n >> S;
	for(int i=1;i<=n;i++)
		cin >> arr[i];
	memset(dp,-1,sizeof dp);
	dp[0] = 0;
	int ans = 0;
	for(int i=1;i<=n;i++) {
		if(arr[i] > S)	continue;
		
		if(arr[i] == S)
			ans = Val(i * (n-i+1) + ans);
		else if(dp[S - arr[i]] != -1)
			ans = Val(dp[S - arr[i]] * (n-i+1) + ans);
			
		for(int j=S;j>arr[i];j--)
			if(dp[j - arr[i]] != -1) {
				if(dp[j] == -1)		dp[j] = 0;
				dp[j] = Val(dp[j] + dp[j - arr[i]]);
			}
		if(dp[arr[i]] == -1)	dp[arr[i]] = 0;
		dp[arr[i]] = Val(dp[arr[i]] + i);
	}
	cout << ans << endl;
	return 0;
}
