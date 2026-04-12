#include<bits/stdc++.h>
#define ll long  long
using namespace std;
ll a[5000];
ll dp[5000][5000]={0};
ll n;
ll solve(ll s=0,ll l=n-1){
	if(s>l){
		return 0;
	}
	if(dp[s][l]){
		return dp[s][l];
	}
	dp[s][l]=max(a[s]-solve(s+1,l),a[l]-solve(s,l-1));
	return dp[s][l];
	
	
}
int main(){
	cin>> n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<solve();
	
	
	return 0;
	
}