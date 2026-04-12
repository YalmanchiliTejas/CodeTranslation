#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,MOD=1e9+7;

/*int cnt,head[N];
struct edge{int next,to;}e[N<<1];
inline add(int u,int v)
{
	cnt++;
	e[cnt].next=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}   */
	
int n,ans;
int a[N],sum[N];
signed main(){
	scanf("%lld",&n);
	for (register int i=1; i<=n; ++i) scanf("%lld",&a[i]),sum[i]=(sum[i-1]+a[i])%MOD;
	for (register int i=1; i<n; ++i)
	{
		ans=(ans+a[i]*((sum[n]-sum[i]+MOD)%MOD)%MOD)%MOD;	
	}
	printf("%lld\n",ans);
	
return 0;	
}