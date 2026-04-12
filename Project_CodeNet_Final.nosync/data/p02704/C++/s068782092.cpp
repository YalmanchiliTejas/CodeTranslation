//#include<bits\stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<string>
#include<ctime>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<queue>
#include<deque>
#include<stack>
#include<vector>
#include<algorithm>
#include<utility>
#include<bitset>
#include<set>
#include<map>
#define ll long long
#define db double
#define INF 1000000000
#define ldb long double
#define pb push_back
#define get(x) x=read()
#define gt(x) scanf("%d",&x)
#define gi(x) scanf("%lf",&x)
#define put(x) printf("%d\n",x)
#define putl(x) printf("%lld\n",x)
#define gc(a) scanf("%s",a+1)
#define rep(p,n,i) for(RE ll i=p;i<=n;++i)
#define go(x) for(ll i=lin[x],tn=ver[i];i;tn=ver[i=nex[i]])
#define fep(n,p,i) for(RE ll i=n;i>=p;--i)
#define pii pair<ll,ll>
#define mk make_pair
#define RE register
#define P 1000000007
#define mod 998244353
#define S second 
#define F first
#define gf(x) scanf("%lf",&x)
#define pf(x) ((x)*(x))
#define ull unsigned long long
#define ui unsigned
#define zz p<<1
#define yy p<<1|1
using namespace std;
char buf[1<<15],*fs,*ft;
inline char getc()
{
    return (fs==ft&&(ft=(fs=buf)+fread(buf,1,1<<15,stdin),fs==ft))?0:*fs++;
}
inline ll read()
{
    register ll x=0,f=1;register char ch=getc();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getc();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getc();}
    return x*f;
}
const ll MAXN=510;
int n,cc;
int s[MAXN],t[MAXN];
ull v[MAXN],u[MAXN];
int b[MAXN][MAXN];	
int r[MAXN][2],c[MAXN][2];
ull a[MAXN][MAXN];
inline int solve()
{
	rep(0,63,k)
	{
		memset(b,-1,sizeof(b));
		memset(c,0,sizeof(c));
		memset(r,0,sizeof(r));
		rep(1,n,i)
		{
			int x=u[i]&1;
			if(s[i]==x)continue;
			rep(1,n,j)if(b[i][j]!=-1&&b[i][j]!=x)return 0;
			else b[i][j]=x;
		}
		rep(1,n,i)
		{
			int x=v[i]&1;
			if(t[i]==x)continue;
			rep(1,n,j)if(b[j][i]!=-1&&b[j][i]!=x)return 0;
			else b[j][i]=x;
		}
		rep(1,n,i)rep(1,n,j)
		{
			if((u[i]&1)==(v[j]&1))b[i][j]=(u[i]&1);
			if(b[i][j]==-1)b[i][j]=0;
			++r[i][b[i][j]];
			++c[j][b[i][j]];
		}
		rep(1,n,i)
			if(s[i]&&(u[i]&1))
			{
				if(r[i][1])continue;
				rep(1,n,j)
				{
					if(!t[j]&&!(v[j]&1)&&c[j][0]>1)
					{
						b[i][j]=1;
						--c[j][0];--r[i][0];
						++c[j][1];++r[i][1];
						break;
					}
				}
			}
		rep(1,n,i)
		{
			if(t[i]&&(v[i]&1))
			{
				if(c[i][1])continue;
				rep(1,n,j)
				{
					if(!s[j]&&!(u[j]&1)&&r[j][0]>1)
					{
						b[j][i]=1;
						--r[j][0];--c[i][0];
						++r[j][1];++c[i][1];
						break;
					}
				}
			}
		}
		rep(1,n,i)
		{
			if((u[i]&1)&&!s[i]&&r[i][1]!=n)return 0;
			if(!(u[i]&1)&&s[i]&&r[i][0]!=n)return 0;
			if(!(v[i]&1)&&t[i]&&c[i][0]!=n)return 0;
			if((v[i]&1)&&!t[i]&&c[i][1]!=n)return 0;
			if((u[i]&1)==s[i]&&!s[i]&&!r[i][0])return 0;
			if((u[i]&1)==s[i]&&s[i]&&!r[i][1])return 0;
			if((v[i]&1)==t[i]&&t[i]&&!c[i][1])return 0;
			if((v[i]&1)==t[i]&&!t[i]&&!c[i][0])return 0;
		}
		rep(1,n,i)rep(1,n,j)if(b[i][j])a[i][j]=a[i][j]|(1ull<<k);
		rep(1,n,i)u[i]>>=1,v[i]>>=1;
	}
	return 1;
}
signed main()
{
	//freopen("1.in","r",stdin);
	gt(n);
	rep(1,n,i)gt(s[i]);
	rep(1,n,i)gt(t[i]);
	rep(1,n,i)scanf("%llu",&u[i]);
	rep(1,n,i)scanf("%llu",&v[i]);
	if(!solve())puts("-1");
	else rep(1,n,i)rep(1,n,j)printf("%llu%c",a[i][j],j!=n?' ':'\n');
	return 0;
}
