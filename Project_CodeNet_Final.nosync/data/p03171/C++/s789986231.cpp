#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<map>

using namespace std;
#define mod 1000000007
#define ll long long 


ll n, arr[3009];
ll dp[3009][3009];


long long solve(int idx, int jdx) {
	
	if(idx > jdx)
		return 0;

	if(dp[idx][jdx] != -1)
		return dp[idx][jdx];

	ll ans = arr[idx] - solve(idx + 1, jdx);
	ans = max(ans, arr[jdx] - solve(idx, jdx - 1));

	return dp[idx][jdx] = ans;
}


int main() {

	// memset(dp, -1, sizeof(dp));
	for(int i = 0; i < 3009; i++) {
		for(int j = 0; j < 3009; j++)
			dp[i][j] = -1;
	}

	cin>>n;

	for(int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}

	cout<<solve(0, n - 1)<<endl;

	return 0;
}