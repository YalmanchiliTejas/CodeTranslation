#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,a[3005];
ll f[3005][3005];
bool vis[3005][3005];
ll dfs(int l,int r)
{
	if(l>r)return 0;
	if(vis[l][r])return f[l][r];
	vis[l][r]=1;
	if((n-(r-l))&1)f[l][r]=max(dfs(l+1,r)+a[l],dfs(l,r-1)+a[r]);
	else f[l][r]=min(dfs(l+1,r)-a[l],dfs(l,r-1)-a[r]);
	return f[l][r];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	printf("%lld\n",dfs(1,n));
	return 0;
}