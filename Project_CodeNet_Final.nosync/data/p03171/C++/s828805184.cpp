#include <bits/stdc++.h>


using namespace std;
//dp[i] first player winns if its true stones left


long long int dp[3005][3005];

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int r=0,l=n-1;

	for(l=n-1;l>=0;--l){
		for(r=l;r<n;++r){
			if(l==r){
				dp[l][r]=arr[l];
			}
			else{
			dp[l][r]=max(arr[l]-dp[l+1][r],arr[r]-dp[l][r-1]);
		}
	}
	}
	cout<<dp[0][n-1];
	return 0;
}
