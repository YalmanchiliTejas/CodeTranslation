#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N=998244353;
int dp[3005][3005][3];
// i sum type
 main() {
	int n, s;
	cin>>n>>s;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	dp[0][0][0]=1;
	dp[0][0][1]=1;
	dp[0][arr[0]][1]=1;
	dp[0][arr[0]][2]=1;
	for(int i=1; i<n; i++){
		for(int j=0; j<=3000; j++){
			dp[i][j][0]=(dp[i][j][0]+dp[i-1][j][0])%N;
			dp[i][j][1]=(dp[i][j][1]+dp[i-1][j][0]+dp[i-1][j][1])%N;
			dp[i][j][2]=(dp[i][j][2]+dp[i-1][j][2]+dp[i-1][j][1])%N;
			if(j+arr[i]<=3000){
				dp[i][j+arr[i]][1]=(dp[i][j+arr[i]][1]+dp[i-1][j][0]+dp[i-1][j][1])%N;
				dp[i][j+arr[i]][2]=(dp[i][j+arr[i]][2]+dp[i-1][j][1]+dp[i-1][j][0])%N;
			}
		}
	}
	cout<<dp[n-1][s][2];
	return 0;
}