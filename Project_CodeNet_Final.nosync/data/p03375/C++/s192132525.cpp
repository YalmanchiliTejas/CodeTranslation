#include<bits/stdc++.h>
clock_t t=clock();
namespace my_std{
	using namespace std;
	#define pii pair<int,int>
	#define fir first
	#define sec second
	#define MP make_pair
	#define rep(i,x,y) for (int i=(x);i<=(y);i++)
	#define drep(i,x,y) for (int i=(x);i>=(y);i--)
	#define go(x) for (int i=head[x];i;i=edge[i].nxt)
	#define templ template<typename T>
	#define sz 3555
	typedef long long ll;
	typedef double db;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	templ inline T rnd(T l,T r) {return uniform_int_distribution<T>(l,r)(rng);}
	templ inline bool chkmax(T &x,T y){return x<y?x=y,1:0;}
	templ inline bool chkmin(T &x,T y){return x>y?x=y,1:0;}
	templ inline void read(T& t)
	{
		t=0;char f=0,ch=getchar();double d=0.1;
		while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
		while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
		if(ch=='.'){ch=getchar();while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();}
		t=(f?-t:t);
	}
	template<typename T,typename... Args>inline void read(T& t,Args&... args){read(t); read(args...);}
	char __sr[1<<21],__z[20];int __C=-1,__zz=0;
	inline void Ot(){fwrite(__sr,1,__C+1,stdout),__C=-1;}
	inline void print(register int x)
	{
		if(__C>1<<20)Ot();if(x<0)__sr[++__C]='-',x=-x;
		while(__z[++__zz]=x%10+48,x/=10);
		while(__sr[++__C]=__z[__zz],--__zz);__sr[++__C]='\n';
	}
	void file()
	{
		#ifdef NTFOrz
		freopen("a.in","r",stdin);
		#endif
	}
	inline void chktime()
	{
		#ifndef NTFOrz
		cout<<(clock()-t)/1000.0<<'\n';
		#endif
	}
	ll mod;
	ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
	ll ksm(ll x,int y,ll mod){ll ret=1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
	ll inv(ll x){return ksm(x,mod-2);}
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n;

ll fac[sz],_fac[sz];
void init(){fac[0]=_fac[0]=1;rep(i,1,sz-1) _fac[i]=inv(fac[i]=fac[i-1]*i%mod);}
ll C(int n,int m){return n>=m&&m>=0?fac[n]*_fac[m]%mod*_fac[n-m]%mod:0;}

ll S[sz][sz],Ssum[sz][sz];
ll F[sz][sz],Fsum[sz][sz];

ll pw2[sz];
namespace SHIT
{
	#define S 32768
	ll pw1[S],pw2[S];
	void init()
	{
		pw1[0]=1;rep(i,1,S-1) pw1[i]=pw1[i-1]*2%mod;
		pw2[0]=1;pw2[1]=pw1[S-1]*2%mod;rep(i,2,S-1) pw2[i]=pw2[i-1]*pw2[1]%mod;
	}
	ll ksm(int x){return pw2[x>>15]*pw1[x&32767]%mod;}
	#undef S
}

int main()
{
	file();
	read(n,mod);
	init();SHIT::init();
	S[0][0]=1;rep(i,1,n) rep(j,1,i) (S[i][j]+=S[i-1][j-1]+S[i-1][j]*j%mod)%=mod;
	rep(i,0,n) rep(j,1,n) (Ssum[i][j]=Ssum[i][j-1]+S[i][j])%=mod;
	rep(p,0,n) rep(i,0,n) (F[0][p]+=S[i][0]*C(p,i)%mod)%=mod;
	Fsum[0][0]=F[0][0];rep(p,1,n) Fsum[0][p]=(Fsum[0][p-1]+F[0][p])%mod;
	rep(m,1,n) rep(i,0,n) (F[m][0]+=S[i][m]*C(0,i)%mod)%=mod,Fsum[m][0]=F[m][0];
	rep(m,1,n) rep(p,1,n) (F[m][p]=Fsum[m][p-1]*m%mod+Fsum[m-1][p-1])%=mod,Fsum[m][p]=(Fsum[m][p-1]+F[m][p])%mod;
	pw2[0]=1;rep(i,1,n) pw2[i]=pw2[i-1]*2%(mod-1);
	ll ans=0;
	rep(k,0,n)
		rep(l,0,n)
			(ans+=F[l][n-k]*(((n+k)&1)?mod-1:1ll)%mod*SHIT::ksm((k*l+pw2[k])%(mod-1))%mod*C(n,k)%mod)%=mod;
	cout<<ans;
	return 0;
}