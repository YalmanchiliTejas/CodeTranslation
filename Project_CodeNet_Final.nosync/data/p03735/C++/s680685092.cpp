#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define re(i,a,b) for(int i=(a);i<(b);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define run(v) for(int k=head[v];k;k=e[k].ne)
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
typedef long long ll;typedef long double ld;typedef unsigned long long ull;
typedef pair<ll,ll> pa;
const int N=1e6+5,M=1e7+5,INF=1e9,mod=1e9+7;
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
	freopen("datax.out","w",stdout);}
il void gen(){freopen("data.in","w",stdout);}
int n,m,c[N],cc;
pa p[N],q[N];
int main(){//judge();
	read(n);
	ll mn=1e9,mx=-1e9,a1=-1e9,a2=1e9;
	rep(i,1,n){
		read(p[i].w1,p[i].w2);
		gmin(mn,p[i].w1);
		gmin(mn,p[i].w2);
		gmax(mx,p[i].w1);
		gmax(mx,p[i].w2);
		gmax(a1,min(p[i].w1,p[i].w2));
		gmin(a2,max(p[i].w1,p[i].w2));
		q[++m]=pa(p[i].w1,i);
		q[++m]=pa(p[i].w2,i);
	}
	ll r1=(a1-mn)*(mx-a2),r2=1e18;
	sort(q+1,q+1+m);
	ll r=0,tmp=1e9;
	while(r<m){
		r++;
		if(c[q[r].w2]==0)cc++;
		c[q[r].w2]++;
		if(cc==n)break;
	}
	rep(l,1,m){
		tmp=min(tmp,q[r].w1-q[l].w1);
		c[q[l].w2]--;
		while(c[q[l].w2]==0&&r+1<=m)c[q[r+1].w2]++,r++;
		if(c[q[l].w2]==0)break;
	}
	tmp*=(mx-mn);
	cout<<min(tmp,r1)<<endl;
}