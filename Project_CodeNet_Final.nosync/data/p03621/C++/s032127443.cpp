#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
#define pi pair<int,int>
#define pii pair<pi,int>
#define aa first
#define bb second
#define xx aa.aa
#define yy aa.bb
#define zz bb
#define mp make_pair
#define mpp(a,b,c) mp(mp(a,b),c)
using namespace std;
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef double ld;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
//why use this slow code?
//because FFT is super slow
const int MOD=998244353;
#define SZ 666666
ll w[2][SZ],rev[SZ];
inline ll qp(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%MOD;
        a=a*a%MOD; b>>=1;
    }
    return ans;
}
int K;
inline void fftinit(int n)
{
    for(K=1;K<n;K<<=1);
    w[0][0]=w[0][K]=1;
    ll g=qp(3,(MOD-1)/K);
    for(int i=1;i<K;i++) w[0][i]=w[0][i-1]*g%MOD;
    for(int i=0;i<=K;i++) w[1][i]=w[0][K-i];
}
inline void fft(int* x,int v)
{
    for(int i=0;i<K;i++) x[i]=(x[i]%MOD+MOD)%MOD;
    for(int i=0,j=0;i<K;i++)
    {
        if(i>j) swap(x[i],x[j]);
        for(int l=K>>1;(j^=l)<l;l>>=1);
    }
    for(int i=2;i<=K;i<<=1)
        for(int l=0;l<i>>1;l++)
        {
            register int W=w[v][K/i*l],*p=x+l+(i>>1),*q=x+l,t;
            for(register int j=0;j<K;j+=i)
            {
                p[j]=(q[j]-(t=(ll)p[j]*W%MOD)<0)?(q[j]-t+MOD):(q[j]-t);
                q[j]=(q[j]+t-MOD>=0)?(q[j]+t-MOD):(q[j]+t);
            }
        }
    if(!v) return;
    ll rv=qp(K,MOD-2);
    for(int i=0;i<K;i++) x[i]=x[i]*rv%MOD;
}
struct poly
{
    vector<int> ps;
    inline int cs() {return ps.size()-1;}
    inline int& operator [] (int x) {return ps[x];} //ps.at(x)
    inline void sc(int x) {ps.resize(x+1);}
    inline void dbg()
    {
        bool fi=0;
        for(int i=cs();i>=0;i--)
        {
            ps[i]=(ps[i]%MOD+MOD)%MOD;
            if(!ps[i]) continue;
            if(ps[i]>MOD/2) ps[i]-=MOD;
            if(fi)
            {
                if(i==0) printf("%+d",ps[i]);
                else if(ps[i]==1) printf("+");
                else if(ps[i]==-1) printf("-");
                else printf("%+d",ps[i]);
            }
            else
            {
                if(i==0) printf("%d",ps[i]);
                else if(ps[i]==1);
                else if(ps[i]==-1) printf("-");
                else printf("%d",ps[i]);
            }
            if(i>1) printf("x^%d",i);
            else if(i==1) printf("x");
            fi=1;
        }
        if(!fi) printf("0");
        putchar(10);
    }
    inline void clr()
    {
        int p=cs()+1;
        while(p&&!ps[p-1]) --p;
        sc(p-1);
    }
};
namespace PolyMul{int ta[SZ],tb[SZ],tc[SZ];}
inline poly operator * (poly a,poly b)
{
    using namespace PolyMul;
    if(a.cs()<180||b.cs()<180)
    {
        poly g;
        g.sc(a.cs()+b.cs());
        int*G=&g[0],*A=&a[0],*B=&b[0];
        for(int i=0;i<=a.cs();i++)
        {
            register int*h=G+i,j=0; register ll x=A[i];
            for(;j<=b.cs();++j) h[j]=(h[j]+x*(ll)B[j])%MOD;
        }
        return g;
    }
    poly c;
    int t=a.cs()+b.cs();
    c.sc(t); fftinit(t+1);
    memset(ta,0,sizeof(int)*K);
    memset(tb,0,sizeof(int)*K);
    memset(tc,0,sizeof(int)*K);
    for(int i=a.cs();i>=0;i--) ta[i]=a[i];
    for(int i=b.cs();i>=0;i--) tb[i]=b[i];
    fft(ta,0); fft(tb,0);
    for(int i=0;i<K;i++) tc[i]=(ll)ta[i]*tb[i]%MOD;
    fft(tc,1);
    for(int i=t;i>=0;i--) c[i]=tc[i];
    c.clr();
    return c;
}
const int q=998244353;
int n,a[20010],b[20010],m1,m2;
char s[10010],t[10010];
poly x,y,z;
inline int C(int n,int m)
{
	return (L)a[n]*b[m]%q*b[n-m]%q;
}
inline poly power(poly a,int b)
{
	if(!b)
	  {
	   poly x;
	   x.sc(0);
	   x[0]=1;
	   return x;
	  }
	poly c=power(a,b>>1);
	c=c*c;
	c.sc(m1+m2);
	if(b&1)
	  c=c*a,c.sc(m1+m2);
	return c;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%s%s",&s,&t);
	n=strlen(s);
	a[0]=1;
	for(i=1;i<=n*2;i++)
	  a[i]=(L)a[i-1]*i%q;
	b[0]=b[1]=1;
	for(i=2;i<=n*2;i++)
	  b[i]=q-(L)q/i*b[q%i]%q;
	for(i=2;i<=n*2;i++)
	  b[i]=(L)b[i]*b[i-1]%q;
	for(i=0;i<n;i++)
	  if(s[i]=='1')
	    if(t[i]=='1')
	      m1++;
	    else
	      m2++;
	x.sc(m1+m2);
	y.sc(m1+m2);
	for(i=0;i<=m1;i++)
	  {
	   x[i+1]=b[i+1];
	   y[i]=1;
	  }
	z=power(x,m2)*y;
	i=(L)z[m1+m2]*a[m1+m2]%q*a[m2]%q*a[m1]%q;
	i=(i+q)%q;
	printf("%d\n",i);
	return 0;
}
