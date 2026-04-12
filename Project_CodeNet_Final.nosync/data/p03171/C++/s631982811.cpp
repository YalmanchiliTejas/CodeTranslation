#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int a[1000005];
ll f[3005][3005];
ll solve(int l,int r)
{
	if(f[l][r]!=-1) return f[l][r];
	int ty=((l+r)%2==n%2)?-1:1;
	//printf("l=%d r=%d ty=%d\n",l,r,ty);
	if(l==r) return f[l][r]=a[l]*ty;
	if(ty==1) return f[l][r]=max(solve(l+1,r)+a[l],solve(l,r-1)+a[r]);
	else return f[l][r]=min(solve(l+1,r)-a[l],solve(l,r-1)-a[r]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(f,-1,sizeof(f));
	printf("%lld\n",solve(1,n));
	return 0;
}