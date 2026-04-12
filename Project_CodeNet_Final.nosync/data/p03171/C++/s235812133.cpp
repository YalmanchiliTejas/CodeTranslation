#include<bits/stdc++.h>
using namespace std;

//int nax = 3005;
long long dp[3005][3005];

int main(){

	int n;cin>>n;
	long long aa;
	vector<long long> arr(n);
	for(int i=0;i<n;i++){
		cin>>aa;
		arr[i] = aa;
	}
	
	for(int l=n-1;l>=0;l--){
		for(int r=l;r<n;r++){
			if(l==r) dp[l][r] = arr[l];
			else
			dp[l][r] = max(arr[l] - dp[l+1][r] ,arr[r] - dp[l][r-1]);
		}
	}
	cout<<dp[0][n-1];
	
	return 0;
	
	
	
}
