#include<cctype>
#include<cstdio>
#include<cstring>
#include<algorithm>
const int N=1<<14|1,P=998244353;
int n,m,lim,fac[N],ifac[N],w[N],rev[N],f[N],g[N],t[N];
int read(){int x=0,c=getchar();while(isspace(c))c=getchar();while(isdigit(c))(x*=10)+=c&15,c=getchar();return x;}
void inc(int&a,int b){a+=b-P,a+=a>>31&P;}
void dec(int&a,int b){a-=b,a+=a>>31&P;}
void mul(int&a,int b){a=1ll*a*b%P;}
int pow(int a,int b){int r=1;for(;b;b>>=1,mul(a,a))if(b&1)mul(r,a);return r;}
void init(int n)
{
    int half=(lim=1<<(33-__builtin_clz(n)))/2,g=pow(3,(P-1)/lim);
    w[half]=fac[0]=ifac[0]=1;
    for(int i=1;i<lim;++i) rev[i]=(rev[i>>1]>>1)|(i&1? half:0),mul(fac[i]=fac[i-1],i),ifac[i]=pow(fac[i],P-2);
    for(int i=half+1;i<lim;++i) mul(w[i]=w[i-1],g);
    for(int i=half-1;i;--i) w[i]=w[i<<1];
}
void NTT(int*a,int f)
{
    if(!~f) std::reverse(a+1,a+lim);
    for(int i=1;i<lim;++i) if(i<rev[i]) std::swap(a[i],a[rev[i]]);
    for(int i=1;i<lim;i<<=1) for(int j=0,d=i<<1;j<lim;j+=d) for(int k=0,x;k<i;++k) x=1ll*a[i+j+k]*w[i+k]%P,dec(a[i+j+k]=a[j+k],x),inc(a[j+k],x);
    if(!~f) for(int i=0,x=P-(P-1)/lim;i<lim;++i) mul(a[i],x);
}
int main()
{
    int n=read(),m=read(),ans=0;
    init(n),memcpy(g+1,ifac+3,4*n),NTT(g,1),f[0]=t[0]=1;
    for(int i=1;i<=m;++i)
    {
	NTT(f,1);
	for(int j=0;j<lim;++j) mul(f[j],g[j]);
	NTT(f,-1);
        for(int j=0;j<=n;++j) t[j]=(1ll*f[j]*fac[j+2]+t[j]*(j*(j+1)/2+1ll))%P,mul(f[j]=t[j],ifac[j]);
	memset(f+n+1,0,4*(lim-n-1));
    }
    for(int i=0;i<=n;++i) inc(ans,1ll*ifac[i]*ifac[n-i]%P*t[i]%P);
    mul(ans,fac[n]),printf("%d",ans);
}
