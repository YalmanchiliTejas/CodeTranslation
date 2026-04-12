#include <cstdio>
#include <iostream>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define inver(a,mod) power(a,mod-2,mod)
using namespace std;
inline char nc()
{
    // return getchar();
    static char buf[100000],*l=buf,*r=buf;
    return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
template<class T> void read(T &x)
{
    x=0; int f=1,ch=nc();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=nc();}
    while(ch>='0'&&ch<='9'){x=x*10-'0'+ch;ch=nc();}
    x*=f;
}
typedef long long ll;
const int maxn=3000+50;
int mod,phi;
int n;
int fac[maxn],inv[maxn];
int S[maxn][maxn];
inline int add(int x) {return x>=mod?x-mod:x;}
ll power(ll x,ll y,int mod)
{
    ll re=1;
    while(y)
    {
        if(y&1) re=re*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return re;
}
inline ll binom(int x,int y)
{
    return (ll)fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void init(int n)
{
    fac[0]=1;
    for(int i=1;i<=n;++i) fac[i]=(ll)fac[i-1]*i%mod;
    inv[n]=inver(fac[n],mod);
    for(int i=n;i>=1;--i) inv[i-1]=(ll)inv[i]*i%mod;
    S[0][0]=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=i;++j)
        {
            S[i][j]=(S[i-1][j-1]+(ll)S[i-1][j]*j)%mod;
        }
    }
}
int ways(int i)
{
    int re=0,w1=power(2,n-i,mod),w=1;
    for(int j=0;j<=i;++j) 
    {
        re=(re+(ll)S[i+1][j+1]*w)%mod;
        w=(ll)w*w1%mod;
    }
    re=(ll)re*power(2,power(2,n-i,phi),mod)%mod;
    return re;
}
int main()
{
    read(n),read(mod),phi=mod-1;
    init(n+1);
    int an=0;
    for(int i=0,f=1;i<=n;++i)
    {
        an=(an+f*binom(n,i)%mod*ways(i))%mod;
        f=mod-f;
    }
    printf("%d\n",an);
    return 0;
}