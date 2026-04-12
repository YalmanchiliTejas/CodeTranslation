#include<bits/stdc++.h>
using namespace std;
#define LL long long

int n,a[3005];
LL dp[3005][3005][2];

LL doit(int fr,int to,int now) {
	if (fr > to) {
		return 0;
	}
	if (dp[fr][to][now] < 1e15) return dp[fr][to][now];
	if (now == 0) {
		dp[fr][to][now] = max(doit(fr+1,to,1-now)+a[fr], doit(fr,to-1,1-now)+a[to]);
	}
	else {
		dp[fr][to][now] = min(doit(fr+1,to,1-now)-a[fr], doit(fr,to-1,1-now)-a[to]);
	}
	return dp[fr][to][now];
}

int main() {
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	memset(dp,62,sizeof(dp));
	printf("%lld\n",doit(0,n-1,0));
	return 0;
}
