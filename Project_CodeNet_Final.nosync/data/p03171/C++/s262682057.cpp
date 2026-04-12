#include<bits/stdc++.h>
#define ll long long
#include <iostream>
using namespace std;
int main() {
	ll int n;
	cin>>n;
	vector<ll int> a(n);
	for(ll int i=0;i<n;i++){
		cin>>a[i];
	}
	ll int dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	for(ll int i=1;i<=n;i++){
		dp[i][i]=a[i-1];
	}
	for(ll int i=n-1;i>=0;i--){
		for(ll int j=i+1;j<=n;j++){
			dp[i][j]=max(a[i-1]-dp[i+1][j],a[j-1]-dp[i][j-1]);
		}
	}
	cout<<dp[1][n];
	return 0;
}