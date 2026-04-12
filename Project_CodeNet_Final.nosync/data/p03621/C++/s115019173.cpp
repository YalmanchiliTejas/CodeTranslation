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
    #define sz 100101
    #define mod 998244353ll
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
        #ifndef ONLINE_JUDGE
        cout<<(clock()-t)/1000.0<<'\n';
        #endif
    }
    #ifdef mod
    ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
    ll inv(ll x){return ksm(x,mod-2);}
    #else
    ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x) if (y&1) ret=ret*x;return ret;}
    #endif
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int limit,r[sz];
void NTT_init(int n)
{
	limit=1;int l=-1;
	while (limit<=n+n) limit<<=1,++l;
	rep(i,0,limit-1) r[i]=(r[i>>1]>>1)|((i&1)<<l);
}
void NTT(ll *a,int type)
{
	rep(i,0,limit-1) if (i<r[i]) swap(a[i],a[r[i]]);
	for (int mid=1;mid<limit;mid<<=1)
	{
		ll Wn=ksm(3,(mod-1)/mid>>1);if (type==-1) Wn=inv(Wn);
		for (int j=0,len=mid<<1;j<limit;j+=len)
		{
			ll w=1;
			for (int k=0;k<mid;k++,w=w*Wn%mod)
			{
				ll x=a[j+k],y=a[j+k+mid]*w%mod;
				a[j+k]=(x+y)%mod,a[j+k+mid]=(x-y+mod)%mod;
			}
		}
	}
	if (type==1) return;
	ll I=inv(limit);
	rep(i,0,limit-1) a[i]=a[i]*I%mod;
}

int n;
char u[sz],v[sz];
int a,b;

ll fac[sz],_fac[sz];
ll C(int n,int m){return n>=m&&m>=0?fac[n]*_fac[m]%mod*_fac[n-m]%mod:0;}
ll s[sz];
ll f[sz],g[sz],tmp1[sz],tmp2[sz];
void Ksm(int y)
{
	NTT_init(n+3);
	while (y)
	{
		if (y&1)
		{
			rep(i,0,n) tmp1[i]=f[i],tmp2[i]=g[i];
			NTT(tmp1,1),NTT(tmp2,1);
			rep(i,0,limit-1) tmp1[i]=tmp1[i]*tmp2[i]%mod;
			NTT(tmp1,-1);
			rep(i,0,n) f[i]=tmp1[i];
			rep(i,0,limit-1) tmp1[i]=tmp2[i]=0;
//			rep(i,0,n) rep(j,0,n-i) (tmp[i+j]+=f[i]*g[j]%mod)%=mod;
//			rep(i,0,n) f[i]=tmp[i],tmp[i]=0;
		}
		y>>=1;
		rep(i,0,n) tmp1[i]=g[i];
		NTT(tmp1,1);
		rep(i,0,limit-1) tmp1[i]=tmp1[i]*tmp1[i]%mod;
		NTT(tmp1,-1);
		rep(i,0,n) g[i]=tmp1[i];
		rep(i,0,limit-1) tmp1[i]=0;
//		rep(i,0,n) rep(j,0,n-i) (tmp[i+j]+=g[i]*g[j]%mod)%=mod;
//		rep(i,0,n) g[i]=tmp[i],tmp[i]=0;
	}
}

int main()
{
    file();
	cin>>(u+1)>>(v+1),n=strlen(u+1);
	rep(i,1,n) if (u[i]=='1'||v[i]=='1') ++a,b+=u[i]^v[i];a-=b;b/=2;
	_fac[0]=fac[0]=1;rep(i,1,sz-1) _fac[i]=inv(fac[i]=fac[i-1]*i%mod);
	f[0]=g[0]=1;rep(i,1,n) g[i]=fac[i-1]*i%mod*_fac[i]%mod*_fac[i+1]%mod;Ksm(b);
	ll ans=0;
	rep(i,0,a) (ans+=C(a,i)*fac[a-i]%mod*fac[a+b]%mod*fac[b]%mod*f[i]%mod*fac[i]%mod)%=mod;
	cout<<ans;
	return 0;
}