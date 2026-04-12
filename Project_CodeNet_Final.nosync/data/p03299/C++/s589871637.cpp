#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=105,MOD=1000000007;
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}

int n,a[MAXN],f[MAXN][MAXN],g[MAXN][MAXN];
void solve(int l,int r,int x)
{
	int y=1<<30,las=l-1,w=0;
	for(int i=l;i<=r;++i)chkmin(y,a[i]);
	for(int i=l;i<=r;++i)if(a[i]==y)++w;
	if(w==r-l+1)
	{
		f[l][r]=(1ll*qmi(2,y-x)+qmi(2,r-l+1)-2+MOD)%MOD;
		g[l][r]=qmi(2,y-x);
		return;
	}
	f[l][r]=qmi(2,w);
	g[l][r]=1;
	for(int i=l;i<=r+1;++i)
		if(i>r || a[i]==y)
		{
			if(i-las>=2)
			{
				solve(las+1,i-1,y);
				g[l][r]=1ll*g[l][r]*g[las+1][i-1]%MOD;
				f[l][r]=1ll*f[l][r]*(g[las+1][i-1]+f[las+1][i-1])%MOD;
			}
			las=i;
		}
	f[l][r]=(f[l][r]+1ll*g[l][r]*(qmi(2,y-x)-2+MOD))%MOD;
	g[l][r]=1ll*g[l][r]*qmi(2,y-x)%MOD;
//cerr<<l<<" "<<r<<":"<<f[l][r]<<" "<<g[l][r]<<endl;
}

int main()
{
	#ifndef ONLINE_JUDGE
//	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]);
	solve(1,n,0);
	printf("%d\n",f[1][n]);
	return 0;
}