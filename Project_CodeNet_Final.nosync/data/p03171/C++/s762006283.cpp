#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int n;
	cin >> n;
	long long int ar[n];
	long long int dp[n][n];
	for(long long int i = 0;i < n; i++){
		cin >> ar[i];
	}
	for(long long int i=n-1;i>=0;i--){
		for(long long int j=0;j<n;j++){
			if(j==0) dp[i][j] = ar[j];
			else if(i==n-1) dp[i][j] = ar[n-1];
			else if(i > j) dp[i][j] = 0;
			else dp[i][j] = max(ar[i]-dp[i+1][j],ar[j]-dp[i][j-1]);
		}
	}
	cout<<dp[0][n-1];	
}