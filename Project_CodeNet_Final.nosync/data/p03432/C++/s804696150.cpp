#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<bitset>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int N=8000+100,M=80+10;
const db pi=acos(-1.0);
#define lowbit(x) ((x)&(-x))
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define go(u,i) for (register int i=head[u],v=sq[i].to;i;i=sq[i].nxt,v=sq[i].to)
#define fir first
#define sec second
#define mkp make_pair
#define pb push_back
#define maxd 998244353
#define eps 1e-8
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

inline ll readll()
{
    ll x=0;int f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

namespace My_Math{
    #define N 100000

    int fac[N+100],invfac[N+100];

    int add(int x,int y) {return x+y>=maxd?x+y-maxd:x+y;}
    int dec(int x,int y) {return x<y?x-y+maxd:x-y;}
    int mul(int x,int y) {return 1ll*x*y%maxd;}
    ll qpow(ll x,int y)
    {
        ll ans=1;
        while (y)
        {
            if (y&1) ans=mul(ans,x);
            x=mul(x,x);y>>=1;
        }
        return ans;
    }
    int getinv(int x) {return qpow(x,maxd-2);}

    int C(int n,int m)
    {
        if ((n<m) || (n<0) || (m<0)) return 0;
        return mul(mul(fac[n],invfac[m]),invfac[n-m]);
    }

    void math_init()
    {
        fac[0]=invfac[0]=1;
        rep(i,1,N) fac[i]=mul(fac[i-1],i);
        invfac[N]=getinv(fac[N]);
        per(i,N-1,1) invfac[i]=mul(invfac[i+1],i+1);
    }
    #undef N
}
using namespace My_Math;

namespace Polynomial{

    int r[N<<2];

    int calcr(int len)
    {
        int lim=1,cnt=0;
        while (lim<len) {lim<<=1;cnt++;}
        rep(i,0,lim-1) 
            r[i]=((r[i>>1]>>1)|((i&1)<<(cnt-1)));
        return lim;
    }

    void ntt(int lim,int *a,int typ)
    {
        rep(i,0,lim-1)
            if (i<r[i]) swap(a[i],a[r[i]]);
        for (int mid=1;mid<lim;mid<<=1)
        {
            int gn=qpow(3,(maxd-1)/(mid<<1)),len=(mid<<1);
            if (typ==-1) gn=getinv(gn);
            for (int sta=0;sta<lim;sta+=len)
            {
                int g=1;
                for (int j=0;j<mid;j++,g=mul(g,gn))
                {
                    int x=a[sta+j],y=mul(a[sta+j+mid],g);
                    a[sta+j]=add(x,y);a[sta+j+mid]=dec(x,y);
                }
            }
        }
        if (typ==-1)
        {
            int invn=getinv(lim);
            rep(i,0,lim-1) a[i]=mul(a[i],invn);
        }
    }
}
using namespace Polynomial;

int F[N<<2],G[N<<2],f[N][M],n,m,lim;

void work(int id)
{
    rep(i,0,lim-1) F[i]=G[i]=0;
    rep(i,0,n)
    {
        if (i) F[i]=invfac[i+2];
        G[i]=mul(f[i][id-1],invfac[i]);
    }
    //rep(i,0,lim-1) cout << F[i] << " ";cout << endl;
    //rep(i,0,lim-1) cout << G[i] << " ";cout << endl;
    ntt(lim,F,1);ntt(lim,G,1);
    rep(i,0,lim-1) F[i]=mul(F[i],G[i]);
    ntt(lim,F,-1);
    //rep(i,0,lim-1) cout << F[i] << " ";cout << endl;
    rep(i,0,n)
    {
        f[i][id]=mul(fac[i+2],F[i]);
        int tmp=add(C(i,2),i+1);
        f[i][id]=add(f[i][id],mul(f[i][id-1],tmp));
    }
}

int main()
{
    n=read();m=read();
    math_init();
    f[0][0]=1;lim=calcr((n+1)<<1);
    rep(i,1,m) work(i);
    int ans=0;
    rep(i,0,n) ans=add(ans,mul(C(n,i),f[i][m]));
    printf("%d",ans);
    return 0;
}