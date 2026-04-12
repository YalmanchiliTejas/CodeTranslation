#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
const int N=5050;
const db pi=acos(-1.0);
#define lowbit(x) (x)&(-x)
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define fir first
#define sec second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define eps 1e-8
int n,maxd;
ll c[N+10][N+10],s[N+10][N+10];

int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

ll qpow(ll x,int y,int p)
{
	ll ans=1;
	while (y)
	{
		if (y&1) ans=ans*x%p;
		x=x*x%p;y>>=1;
	}
	return ans;
}

int main()
{
	n=read();maxd=read();
	rep(i,0,N)
	{
		s[i][0]=1;
		rep(j,1,i) s[i][j]=(s[i-1][j-1]+s[i-1][j]*(j+1))%maxd;
	}
	rep(i,0,N)
	{
		c[i][0]=1;
		rep(j,1,i) c[i][j]=(c[i-1][j-1]+c[i-1][j])%maxd;
	}
	ll ans=0;
	rep(i,0,n)
	{
		ll now=0,kd=qpow(2,qpow(2,n-i,maxd-1),maxd);
		rep(j,0,i)
		{
			ll tmp=qpow(2,(n-i)*j,maxd);
			now=(now+kd*tmp%maxd*s[i][j])%maxd;
		}
		now=now*c[n][i]%maxd;
		if (i&1) now=maxd-now;
		ans=(ans+now)%maxd;
	}
	printf("%lld",ans);
	return 0;
}
			
			
