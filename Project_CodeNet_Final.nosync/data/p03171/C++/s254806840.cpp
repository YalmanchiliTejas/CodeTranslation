/*
	dp[i][j][0] = max. possible score possible from a[i, i+1, .... j-1, j]
	dp[i][j][1] = min. possible score possible from a[i, i+1, .... j-1, j]
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[3005][3005][2];

int main(){
	int n;
	vector<ll> a;
	cin>>n;
	a.assign(n+1, 0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	memset(dp, 0, sizeof dp);
	for(int i=n-1;i>=0;i--){
		dp[i][i][0] = a[i];
		dp[i][i][1] = -a[i]; 
		for(int j=i+1;j<n;j++){
			dp[i][j][0] = max(dp[i+1][j][1]+a[i], dp[i][j-1][1]+a[j]);
			dp[i][j][1] = min(dp[i+1][j][0]-a[i], dp[i][j-1][0]-a[j]);
		}
	}
	cout<<dp[0][n-1][0]<<"\n";
	return 0;
}