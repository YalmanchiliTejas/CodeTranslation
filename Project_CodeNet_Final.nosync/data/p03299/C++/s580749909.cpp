//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
int n,a[111];
ll w[111][111],dp[111];
vector<pair<pair<int,int>,int> >V;
int pw2[211];
void solve(int pre,int l,int r)
{
	int mn=a[l];
	for(int i=l;i<=r;i++)mn=min(mn,a[i]);
	V.PB(MP(MP(l,r),mn-pre));
	for(int i=l;i<=r;i)
	{
		if(a[i]==mn)i++;
		else
		{
			int r=i;
			while(a[r]>mn)r++;
			solve(mn,i,r-1);
			i=r;
		}
	}
}
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)
	{
		geti(a[i]);
	}
	solve(0,1,n);
	for(int i=0;i<V.size();i++)pw2[i]=qpow(2,V[i].SS);
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			w[i][j]=1;
			for(int k=0;k<V.size();k++)
			{
				if(i<=V[k].FF.FF&&V[k].FF.SS<=j)
				{
					w[i][j]=1ll*w[i][j]*pw2[k]%mod;
				}
			}
		}
	}
	w[1][n]=1ll*w[1][n]*qpow(2,mod-2)%mod;
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		dp[i]=0;
		for(int j=1;j<=i;j++)
		{
			dp[i]=(dp[i]+1ll*w[j][i]*dp[j-1])%mod;
		}
	}
	cout<<(2ll*dp[n]%mod+mod)%mod;
	return 0;
}
