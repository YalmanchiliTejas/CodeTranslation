#include <bits/stdc++.h>
using namespace std;
int main() {
	long long i,j,k,n;
	cin>>n;
	long long arr[n+1];
	for(i=1;i<=n;i++){
	    cin>>arr[i];
	}
	long long dp[n+1][n+1];
	for(i=1;i<=n;i++){
	    dp[i][i]=arr[i];
	}
	for(i=n;i>=1;i--){
	    for(j=i;j<=n;j++){
	        if(i!=j){
	            dp[i][j]=max(arr[i]-dp[i+1][j],arr[j]-dp[i][j-1]);
	        }
	    }
	}
	cout<<dp[1][n];
}