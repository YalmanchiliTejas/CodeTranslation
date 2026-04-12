#include "bits/stdc++.h"
#include <array>
using namespace std;


/*
int solve(int i){
	if(i == 0) return 0;
	if(i == 1) return 0;
	if(memo[i] != -1) return memo[i];
	int m = INT_MAX;
	for(int d = 1; d <= k; d++){
		if(i - d < 0) break;
		m = min(solve(i-d, k)+abs(h[i]-h[i-d]), m);
	}
	return memo[i] = m;
}*/


int n;
long long a[3000];

long long dp[3001][3001] = {};


long long solve(int l, int r, bool first){
	if(dp[l][r] != 0) return dp[l][r];
	if(l == r) return 0;
	long long ret;
	if(first){
		ret =
			max(solve(l+1, r, false) + a[l],
			solve(l, r-1, false) + a[r-1]);
	}
	else{
		ret =
			min(solve(l+1, r, true) - a[l],
			solve(l, r-1, true) - a[r-1]);
	}
	return dp[l][r] = ret;
}


int main(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	

	cout << solve(0, n, true) << endl;
	//cout << setprecision(12) << solve(k) << endl;

    return 0;
}
