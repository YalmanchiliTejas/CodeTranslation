#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#define maxn 105
#define R register
#define INF 0x3f3f3f3f
using namespace std;
typedef long long lxl;
const lxl mod = 1e9+7;

inline lxl read()
{
	lxl x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}

inline lxl fmi(lxl a,lxl b)
{
	lxl ans=1;
	while(b>0)
	{
		if(b&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}

lxl n,h[maxn],H[maxn],W[maxn],X[maxn],Rm[maxn],tot;
int d[maxn][20],lg[maxn];
std::vector<int> ch[maxn];

inline void init()
{
	lg[0]=-1;
	for(R int i=1;i<=n;++i)
		lg[i]=lg[i>>1]+1;
	for(R int i=1;i<=n;++i)
		d[i][0]=h[i];
	for(R int j=1;j<=15;++j)
		for(R int i=1;i+(1<<(j-1))<=n;++i)
			d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}

inline int query(int l,int r)
{
	int k=lg[r-l+1];
	return min(d[l][k],d[r-(1<<k)+1][k]);
}

inline int build(int l,int r,int fa)
{
	if(l>r) return 0;
	int p=++tot;
	int x=X[p]=query(l,r);
	H[p]=X[p]-X[fa];
	W[p]=r-l+1;
	int tl=l-1,tr=l-1;
	for(R int i=l;i<=r;++i)
	{
		if(h[i]==x&&tl<tr)
			ch[p].push_back(build(tl+1,tr,p));
		if(h[i]==x) tl=i,++Rm[p];
		else tr=i;
	}
	if(tl<tr) ch[p].push_back(build(tl+1,tr,p));
	return p;
}

lxl f[maxn][2];

inline void dp(int u)
{
	lxl res1=1,res2=1;
	for (std::vector<int>::iterator it = ch[u].begin(); it != ch[u].end(); ++it)
	{
		dp(*it);
		res1=(res1*f[*it][0])%mod;
		res2=(res2*((f[*it][0]*2%mod+f[*it][1])%mod))%mod;
	}
	f[u][0]=(fmi(2,H[u])*res1)%mod;
	f[u][1]=(fmi(2,Rm[u])*res2+(mod-2*res1%mod)%mod)%mod;
}

int main()
{
	n=read();
	for(R int i=1;i<=n;++i)
		h[i]=read();
	init();
	int rt=build(1,n,0);
	dp(rt);
	printf("%lld",(f[rt][1]+f[rt][0])%mod);
	return 0;
}
