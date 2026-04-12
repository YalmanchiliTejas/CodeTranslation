#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,ix;
	cin>>n;
	int a[n];
	for (int i=0;i<n;i++)
		cin>>a[i];
	long long int dp[n][n][2];
	for (int i=0;i<n;i++){
		dp[i][i][0] = a[i];
		dp[i][i][1] = -a[i];
	}
	for (int i=1;i<n;i++){
		for (int j=i;j<n;j++){
			ix = j-i;
			dp[ix][j][0] = max(dp[ix+1][j][1]+a[ix], dp[ix][j-1][1]+a[j]);
			dp[ix][j][1] = min(dp[ix+1][j][0]-a[ix], dp[ix][j-1][0]-a[j]);
		}
	}
	cout<<dp[0][n-1][0];
}