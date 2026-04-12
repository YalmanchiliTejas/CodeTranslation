#include <bits/stdc++.h>

using namespace std;

#define ll long long


const int mod = 998244353,MOD=1e9+7;

const int N=3e3;

ll dp[N][N][2];

int n,a[N];


ll solve(int l,int r,int p){
	if (l>r)
		return 0;
	ll &ret = dp[l][r][p];
	if (ret!=-1)
		return ret;
	if (!p)
		return ret=max(a[l]+solve(l+1,r,!p),a[r]+solve(l,r-1,!p));
	else
		return ret=min(solve(l+1,r,!p)-a[l],solve(l,r-1,!p)-a[r]);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("%lld\n",solve(0,n-1,0));
}
