//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod = 1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it, len;
	fastio() {it=len=0;}
	inline char get()
	{
		if (it<len) return s[it++]; it=0;
		len=fread(s, 1, 100000, stdin);
		if (len==0) return EOF; else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while (c==' '||c=='\n') c=get();
		if (it>0) it--;
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
	ll r=0; bool ng=0; char c; c=_buff.get();
	while (c!='-'&&(c<'0'||c>'9')) c=_buff.get();
	if (c=='-') ng=1, c=_buff.get();
	while (c>='0'&&c<='9') r=r*10+c-'0', c=_buff.get();
	return ng?-r:r;
}
template <class T> inline void putnum(T x)
{
	if (x<0) putchar('-'), x=-x;
	register short a[20]={}, sz=0;
	while (x) a[sz++]=x%10, x/=10;
	if(sz==0) putchar('0');
	for (int i=sz-1; i>=0; i--) putchar('0'+a[i]);
}
inline char getreal() {char c=_buff.get(); while (c<=32) c=_buff.get(); return c;}
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
const int maxn = 200111;
int n, m;
int cntR=0, cntB=0;
char s[maxn];
int fac[maxn], ifac[maxn];
ll C(int x, int y) {return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;}
ll F(int n, int x)
{
	return C(n-(x-1), x);
}
int dp[maxn];
int sum[maxn], sum2[maxn];
int get_sum(int l, int r, int p)
{
	if (l%2!=p) l++;
	if (r%2!=p) r--;
	return (sum2[r]-(l>=2?sum2[l-2]:0)+mod)%mod;
}
int calc(int lim)
{
//	cerr<<"calc:"<<lim<<endl;
	assert(lim%2==1);
	memset(dp, 0, sizeof(dp));
	memset(sum, 0, sizeof(sum));
	memset(sum2, 0, sizeof(sum2));
	dp[0] = 1;
	sum[0] = sum[1] = 1;
	sum2[0] = 1;
	sum2[1] = 0;
	for (int i=2; i<maxn; i++)
	{
		dp[i] = sum2[i-2];
		if (i-2-lim-1>=0) dp[i] = (dp[i]-sum2[i-2-lim-1]+mod)%mod;
		sum[i] = (sum[i-1]+dp[i])%mod;
		sum2[i] = (sum2[i-2]+dp[i])%mod;
	}
	ll ret = lim>=n&&cntB==0;
	for (int i=1; i<=lim+1&&i<=n; i++)
	{
		int l = max(i, n-(lim-(i-1)))-i;
		int r = (i==1?n-1-i:n-i);
//		cerr<<l<<","<<r<<endl;
//		ret = (ret+(sum[r]-(l==0?0:sum[l-1])+mod))%mod;
		ret = (ret+get_sum(l, r, n%2==1))%mod;
	}
	return ret;
}
int solve()
{
//	cerr<<"solve:"<<endl;
	vector<int> v;
	int lst = 0;
	for (int i=1; i<=m; i++)
	{
		if (s[i]=='B')
		{
			v.PB(lst);
			lst = 0;
		}
		else
		{
			lst++;
		}
	}
	int lim = 1000000001;
	if (v.size()>0) lim = min(lim, v[0]+(v[0]%2==0));
	for (int i=1; i<v.size(); i++) if (v[i]%2==1) lim = min(lim, v[i]);
	return calc(lim);
}
int main()
{
	
	fac[0] = 1;
	for (int i=1; i<maxn; i++) fac[i] = 1ll*fac[i-1]*i%mod;
	for (int i=0; i<maxn; i++) ifac[i] = qpow(fac[i], mod-2);
	getii(n, m);
	for (int i=1; i<=m; i++)
	{
		s[i] = getreal();
	}
	if (s[1]=='B') for (int i=1; i<=m; i++) s[i] ^= 'R'^'B';
	for (int i=1; i<=m; i++)
	{
		cntR += s[i]=='R';
		cntB += s[i]=='B';
	}
	if (cntR==m)
	{
		int ans = 0;
		static int f[maxn][2];
		for (int s=0; s<2; s++)
		{
			memset(f, 0, sizeof(f));
			f[1][s] = 1;
			for (int i=1; i<=n; i++)
			{
				for (int t=0; t<2; t++)
				{
					for (int k=0; k<2; k++)
					{
						if (t==0&&k==0) continue;
						f[i+1][k] = (f[i+1][k]+f[i][t])%mod;
					}
				}
			}
			ans = (ans+f[n+1][s])%mod;
		}
		cout<<ans<<endl;
		return 0;
	}
	int ans = 0;
	ans = (ans+solve())%mod;
//	cerr<<"ans="<<ans<<endl;
	cout<<ans<<endl;
	return 0;
}
