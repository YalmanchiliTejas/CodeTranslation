#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, a[3004];
long long dp[3004][3004];

int main() {
	cin>>n;
	for(int i = 1;i<=n;i++)
		cin>>a[i];
	for(int i = 1;i<=n;i++)
		dp[i][i] = a[i];
	for(int i = n-1;i>=0;i--)
		for(int j = i+1;j<=n;j++){
			dp[i][j] = max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
		}
	cout<<dp[1][n];
	return 0;
}