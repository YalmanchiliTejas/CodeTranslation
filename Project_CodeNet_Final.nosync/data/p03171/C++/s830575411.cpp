#include <bits/stdc++.h>
using namespace std;
#define int long long



signed main() {
	int n;
	cin >> n;
	int val[n];
	for(int i=0;i<n;i++){
		cin >> val[i];
	}
	int dp[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i>j){
				dp[i][j]=0;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(i==0){
				dp[j][i+j]=val[j];
			}
			else{
				dp[j][i+j]=max(val[j]-dp[j+1][i+j],val[i+j]-dp[j][i+j-1]);
			}
		}
	}
	cout << dp[0][n-1];
	// your code goes here
	return 0;
}