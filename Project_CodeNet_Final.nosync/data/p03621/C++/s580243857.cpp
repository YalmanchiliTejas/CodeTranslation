#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define re(i,a,b) for(int i=(a);i<(b);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define run(a) for(int k=head[a];k;k=e[k].ne)
#define v e[k].t
#define clr(a) memset(a,0,sizeof(a));
#define il inline
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back 
#define w1 first
#define w2 second
#define adm(a,b,c) {a=a+b;if(a>=c)a-=c;else if(a<0)a+=c;}
typedef double db;
typedef long long ll;typedef long double ld;typedef unsigned long long ull;
typedef pair<ll,ll> pa;
const int N=1e4+5,M=5e3+5,INF=1e9,mod=998244353;
const ll linf=1e18;const double eps=1e-8,pi=acos(-1);
il int gmin(int &a,int b){if(a>b)a=b;}il ll gmin(ll &a,ll b){if(a>b)a=b;}il int gmax(int &a,int b){if(a<b)a=b;}il ll gmax(ll &a,ll b){if(a<b)a=b;}
il void read(ll&x){ll f=1,t=0;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){t=t*10+ch-'0';ch=getchar();}x=t*f;}il ll read(ll&x,ll&y){read(x);read(y);}
il void read(int&x){int f=1,t=0;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){t=t*10+ch-'0';ch=getchar();}x=t*f;}il int read(int&x,int&y){read(x);read(y);}
il void read(int&a,int&b,int&c){read(a);read(b);read(c);}il void read(ll&a,ll&b,ll&c){read(a);read(b);read(c);}
il int read(){int x;read(x);return x;}
il ll qpow(ll a,ll b,ll p){ll ret=1;for(;b;b>>=1,a=a*a%p)if(b&1)ret=ret*a%p;return ret;}il ll qpow(ll a,ll b){ll ret=1;for(;b;b>>=1,a=a*a%mod)if(b&1)ret=ret*a%mod;return ret;}
il ll qmul(ll a,ll b,ll p){ll ret=0;for(;b;b>>=1,a=(a<<1)%p)if(b&1)adm(ret,a,p);return ret;}il ll qmul(ll a,ll b){ll ret=0;for(;b;b>>=1,a=(a<<1)%mod)if(b&1)adm(ret,a,mod);return ret;}
il void judge(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);}
char s1[N],s2[N];
ll fac[N],ifac[N],f[N][N];;
ll C(int n,int m){
	if(n<0||m<0||n-m<0)return 0;
	return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main(){
	scanf("%s%s",s1+1,s2+1);int len=strlen(s1+1);
	int sam=0,dif=0;fac[0]=1;
	rep(i,1,len)if(s1[i]=='1'&&s2[i]=='1')sam++;
	rep(i,1,len)if(s1[i]=='1'&&s2[i]=='0')dif++;
	rep(i,1,len)fac[i]=fac[i-1]*i%mod;
	ifac[len]=qpow(fac[len],mod-2,mod);
	repd(i,len-1,0)ifac[i]=ifac[i+1]*(i+1)%mod;
	rep(i,0,dif)f[0][i]=1ll*fac[i]*fac[i]%mod;
	rep(i,1,sam)rep(j,1,dif)f[i][j]=1ll*(1ll*f[i-1][j]*i%mod+1ll*f[i][j-1]*j%mod)*j%mod;
	ll ans=0;
	rep(i,0,sam){
		ans=(ans+1ll*f[sam-i][dif]*fac[i]%mod*fac[i]%mod*C(sam,i)%mod*C(sam+dif,i)%mod)%mod;
	}cout<<ans<<endl;
}