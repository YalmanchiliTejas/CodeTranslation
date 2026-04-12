#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main (){
	int n;
	cin>>n;
	vector<ll> v(n);
	vector<vector<ll>> dp(n, vector<ll>(n));
	for(int i=0; i<n; ++i) cin>>v[i];
	for(int r=0; r<n; ++r){
		for(int l=r; l>=0; --l){
			if(l==r) dp[l][r]=v[l];
			else dp[l][r]=max(v[l]-dp[l+1][r], v[r]-dp[l][r-1]);
		}
	}
	cout << dp[0][n-1];


	return 0;
}
