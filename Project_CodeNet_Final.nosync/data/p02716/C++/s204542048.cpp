#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int M=2e5+5;
const LL INF=0x3f3f3f3f3f3f3f3f;
int a[M];
map<int,LL> dp[M];
// dp[i][j] consider 1-i select j

LL getdp(int n,int k)
{
	//cout<<n<<" "<<k<<endl;
	if(k>(n+1)/2) return -INF;
	if(k==0||n<0) return 0;
	if(dp[n].count(k)) return dp[n][k];
	LL &ans=dp[n][k];
	ans=-INF;
	ans=max(getdp(n-1,k),getdp(n-2,k-1)+a[n]);
	return ans;
}

int main()
{
	int n; scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("%lld\n",getdp(n,n/2));
	return 0;
}