#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll dp[3010][3010],v[3010];
ll ds(int l, int r) {
	if(l+r == n) {return 0;}
	if(dp[l][r] != 1LL<<35) {return dp[l][r];}
	if((l+r)%2) {
		return dp[l][r] = min(-v[l]+ds(l+1,r),-v[n-r-1]+ds(l,r+1));
	} else {
		return dp[l][r] = max(v[l]+ds(l+1,r),v[n-r-1]+ds(l,r+1));
	}
}
int main() {
	scanf("%d ",&n);
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			dp[i][j] = 1LL<<35;
		}
	}
	for(int i=0;i<n;i++) {
		int t;
		scanf("%d ",&t);v[i]=t;
	}
	printf("%lld\n",ds(0,0));
}