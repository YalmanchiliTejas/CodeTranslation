#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<vector<long> > dp(n,vector<long>(n,0));
	long long sum = 0 ;
	for(int i = 0 ; i < n ; i++){
		long long temp ;
		cin>>temp ;
		sum+=temp;
		dp[i][i] = temp;
	}
	for(int i = 1 ; i <= n-1 ; i++){
		for(int j = 0 ; i+j < n ; j++){
			int col = j+i;
			int row = j;
			if(i==1){
				dp[row][col] = max(dp[row+1][col],dp[row][col-1]);
			}
			else{
				dp[row][col] = max(dp[row][row] + min(dp[row+2][col],(dp[row+1][col-1])) 
					,dp[col][col] + min(dp[row+1][col-1],(dp[row][col-2])));
			}
		}
	}
	cout<<2*dp[0][n-1] - sum;

return 0;
}