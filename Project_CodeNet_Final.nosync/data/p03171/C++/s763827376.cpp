#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL n, dp[3010][3010], a[3010];

LL solve(int l, int r) {
	if(l > r) return 0;
	LL &ret = dp[l][r];
	if(ret != -1) return ret;
	LL left = a[l] - solve(l+1, r);
	LL right = a[r] - solve(l, r-1);
	return ret = max(left, right);
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin>>n;
	for(int i = 0; i < n; i++) cin>>a[i];
	cout<<solve(0, n-1)<<endl;
	return 0;
}
