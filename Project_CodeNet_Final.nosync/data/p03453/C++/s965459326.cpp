#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// typedef __int128 ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define FR first
#define SE second
#define MP make_pair
#define PB push_back
#define vc vector
#define db double
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define bin(x) (1ll<<(x))
#define fo(i,l,r) for(int i=(l),I=(r);i<=I;i++)
#define fd(i,r,l) for(int i=(r),I=(l);i>=I;i--)
#define mem(x,val) memset(x,val,sizeof x)
#define Swap(a,b,n) for(int I=0;I<=n;I++) swap(a[I],b[I])
#define PC __builtin_popcountll
#ifdef DEBUG
	#define debug(A,args...) fprintf(stderr,A,##args)
#else
	#define debug(A,args...) printf("")
#endif
namespace mine
{
	ll qread()
	{
		ll ans=0,f=1;char c=getchar();
		while(c<'0' or c>'9') {if(c=='-')f=-1;c=getchar();}
		while('0'<=c and c<='9') ans=ans*10+c-'0',c=getchar();
		return ans*f;
	}
	void write(ll num){if(num<0) putchar('-'),num=-num;if(num>=10) write(num/10);putchar('0'+num%10);}
	void write1(ll num){write(num);putchar(' ');}
	void write2(ll num){write(num);putchar('\n');}
	template<typename T>inline bool chmax(T&a,const T&b){return a<b?a=b,1:0;}
	template<typename T>inline bool chmin(T&a,const T&b){return a>b?a=b,1:0;}
	ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
	bool IN(ll x,ll l,ll r){return l<=x and x<=r;}
	void GG(){puts("No");exit(0);}
	
	const db eps=1e-8;
	const int INF=0x3f3f3f3f;
	const int MOD=1e9+7;
	int mm(const int x){return x>=MOD?x-MOD:x;}
	template<typename T> void add(T &x,const int &y){x=(x+y>=MOD?x+y-MOD:x+y);}
	ll qpower(ll x,ll e,int mod=MOD){ll ans=1;while(e){if(e&1)ans=ans*x%mod;x=x*x%mod;e>>=1;}return ans;}
	ll invm(ll x){return qpower(x,MOD-2);}
	const int M=5e6+10;
	ll fac[M],facinv[M],Inv[M];ll C(int n,int m){return n<0 or n<m?0:fac[n]*facinv[m]%MOD*facinv[n-m]%MOD;}
	void PRE()
	{
		fac[0]=1;fo(i,1,M-1) fac[i]=fac[i-1]*i%MOD;
		facinv[M-1]=invm(fac[M-1]);fd(i,M-1,1) facinv[i-1]=facinv[i]*i%MOD;
		Inv[1]=1;fo(i,2,M-1) Inv[i]=(MOD-MOD/i)*Inv[MOD%i]%MOD;
	}
	const int N=4e5+10;
	//------------------FIXED------------------
	vc<pii> to[N];int n;
	priority_queue<pll,vc<pll>,greater<pll>> q;
	void dij(int st,ll dis[],ll f[])
	{
		fo(i,1,n) dis[i]=bin(60);dis[st]=0;f[st]=1;q.push({dis[st],st});
		while(sz(q))
		{
			int x=q.top().SE;ll dd=q.top().FR;q.pop();if(dd!=dis[x]) continue;
			for(auto t:to[x])
			{
				int y=t.FR;
				if(dis[y]>dd+t.SE) dis[y]=dd+t.SE,q.push({dis[y],y}),f[y]=f[x];
				else if(dis[y]==dd+t.SE) add(f[y],f[x]);
			}
		}
	}
	ll d1[N],d2[N],f[N],g[N];
	void main()
	{
		n=qread();int m=qread(),st=qread(),ed=qread();
		fo(i,1,m){ int x=qread(),y=qread(),d=qread();to[x].PB({y,d}),to[y].PB({x,d}); }
		ll ans=0;dij(st,d1,f),dij(ed,d2,g);ll L=d1[ed],S=f[ed];
		if(L%2==0) fo(x,1,n) if(d1[x]+d2[x]==L and d1[x]==L/2) add(ans, f[x]*g[x]%MOD*(S+MOD-f[x]*g[x]%MOD)%MOD );
		fo(x,1,n) for(auto t:to[x])
		{ 
			int y=t.FR;
			if(d1[x]*2<L and d1[y]*2>L and d1[x]+t.SE+d2[y]==L) add(ans, f[x]*g[y]%MOD*(S+MOD-f[x]*g[y]%MOD)%MOD );
		}write(ans);
	}
};//??????????
signed main()
{
	#ifdef DEBUG
	//freopen("a.in","r",stdin);
	freopen("z.txt","r",stdin);
	//freopen("a.out","w",stdout);
	#endif
	srand(time(0));
	mine::PRE();//??????????????
	mine::main();
	debug("\n---------------------Zory---------------------\nTime: %.2lf s",1.0*clock()/CLOCKS_PER_SEC);
}