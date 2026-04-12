#include <bits/stdc++.h>

using namespace std;



int main(){
	
	int n;cin>>n;
	long long A[n];
	for(int i=0; i<n; i++)cin>>A[i];
	long long dp[n][n];
	for(int l=n-1; l>=0; l--){
		for(int r = l; r<n; r++){
			if(l==r){
				dp[l][r] = A[l];
			}else{
				dp[l][r] = max(A[l]-dp[l+1][r],A[r]-dp[l][r-1]);
			}
		}
	}
	cout<<dp[0][n-1]<<endl;
	return 0;
}

