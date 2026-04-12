#include <cstdio>
#include <iostream>
#include <vector>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define fi first
#define se second
using namespace std;
inline char nc()
{
//	return getchar();
	static char buf[100000],*l=buf,*r=buf;
	return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
template<class T> void read(T &x)
{
	x=0; int f=1,ch=nc();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=nc();}
	while(ch>='0'&&ch<='9'){x=x*10-'0'+ch;ch=nc();}
	x*=f;
}
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7;
const int maxn=100+5;
int n;
int h[maxn];
int dp[maxn][maxn][2];
vector<pii> rec[maxn];
inline void upd(int &x,int y) {x+=y; if(x>=mod) x-=mod;}
ll power(ll x,ll y)
{
	ll re=1;
	while(y)
	{
		if(y&1) re=re*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return re;
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i) read(h[i]);
	for(int i=1;i<=n;++i) if(h[i]!=1)
	{
		int l=i,r=i,ok=1;
		for(l=i;;--l)
		{
			if(l!=i&&h[l]==h[i]) {ok=0; break;}
			if(l==1||h[l-1]<h[i]) break;
		}
		if(!ok) continue;
		for(r=i;;++r)
		{
			if(r==n||h[r+1]<h[i]) break;
		}
//		debug("%d %d %d %d\n",l,r,h[i],h[i]-max(l==1?1:h[l-1],r==n?1:h[r+1]));
		rec[r].push_back(make_pair(l,power(2,h[i]-max(l==1?1:h[l-1],r==n?1:h[r+1]))));
	}
	dp[1][0][0]=dp[1][0][1]=rec[1].size()?rec[1][0].se:1;
	for(int i=2;i<=n;++i) 
	{
		for(int j=0;j<i;++j) for(int k=0;k<2;++k) if(dp[i-1][j][k])
		{
			upd(dp[i][i][k],dp[i-1][j][k]);
			upd(dp[i][j][k^1],dp[i-1][j][k]);
		}
		for(int j=0;j<=i;++j) for(int k=0;k<2;++k) if(dp[i][j][k])
		{
			for(int l=0;l<rec[i].size();++l)
			{
				if(j<=rec[i][l].fi) dp[i][j][k]=(ll)dp[i][j][k]*rec[i][l].se%mod;
			}
		}
	}
	int an=0;
	for(int j=0;j<=n;++j) for(int k=0;k<2;++k) upd(an,dp[n][j][k]);
	printf("%d\n",an);
	return 0;
}