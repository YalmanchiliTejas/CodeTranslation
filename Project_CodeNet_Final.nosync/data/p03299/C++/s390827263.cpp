#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL

ll f[110][2],bin[110];
int h[110],n,tt;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline ll pls(const ll &x,const ll &y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }
inline ll ksm(ll x,ll y) { ll res=1;for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;return res; }

inline void pre_gao()
{
	bin[0]=1;
	for (int i=1;i<=n;i++) bin[i]=bin[i-1]*2%mod;
}

inline void solve(int l,int r)
{
	int id=++tt,mn=h[l];
	for (int i=l;i<=r;i++) mn=min(mn,h[i]);
	ll g[110][2];
	memset(g,0,sizeof(g));
	g[l-1][0]=0;g[l-1][1]=2;
	for (int i=l;i<=r;i++)
	{
		if (h[i]==mn)
		{
			g[i][0]=pls(g[i-1][0]*2%mod,(i==l)?0:g[i-1][1]);
			g[i][1]=g[i-1][1];
		}
		else
		{
			int j=i;
			for (;j<=r&&h[j]>mn;j++);j--;
			for (int k=i;k<=j;k++) h[k]-=mn;
			int now=tt+1;solve(i,j);
			g[j][0]=pls(g[i-1][0]*pls(f[now][0],f[now][1]*2%mod)%mod,(i==l)?f[now][0]:g[i-1][1]*pls(f[now][0],f[now][1])%mod);
			g[j][1]=g[i-1][1]*f[now][1]%mod;
			i=j;
		}
	}
	f[id][0]=g[r][0];f[id][1]=g[r][1]*ksm(2,mn-1)%mod;
}

int main()
{
	n=rd();pre_gao();
	for (int i=1;i<=n;i++) h[i]=rd();
	solve(1,n);
	printf("%lld\n",pls(f[1][0],f[1][1]));
	return 0;
}