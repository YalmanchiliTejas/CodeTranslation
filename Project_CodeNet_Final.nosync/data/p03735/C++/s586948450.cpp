#include<bits/stdc++.h>
#define INF 1000000007
using namespace std;
const int MAXN = 222222;
struct sakura
{
    long long x;
    long long y;
}ball[MAXN];

long long x[MAXN];
long long y[MAXN];
long long maxn[MAXN];
long long minl[MAXN];
long long n,ans,ans1,ans2,bmax,bmin,rmax,rmin;
inline bool cmp(sakura xx,sakura yy){ return xx.x<yy.x; }
int main()
{
    scanf("%lld",&n);
    bmax=rmax=-1;bmin=rmin=INF;
    for(register int i=1;i<=n;++i)
    {
        scanf("%lld%lld",&x[i],&y[i]);
        if(x[i]>y[i]) swap(x[i],y[i]);
        ball[i].x=x[i];ball[i].y=y[i];
        bmax=max(bmax,y[i]);
        bmin=min(bmin,y[i]);
        rmax=max(rmax,x[i]);
        rmin=min(rmin,x[i]);
    }
    ans1=(bmax-bmin)*(rmax-rmin);
    bmin=rmin;sort(ball+1,ball+n+1,cmp);
    ans2=INF;maxn[1]=minl[1]=ball[1].y;
    for(register int i=2;i<=n;++i)
    {
        maxn[i]=max(maxn[i-1],ball[i].y);
        minl[i]=min(minl[i-1],ball[i].y);
        if(i!=n) ans2=min(ans2,max(maxn[i],ball[n].x)-min(minl[i],ball[i+1].x));
    }
    ans2*=(bmax-bmin);ans=min(ans1,ans2);
    printf("%lld\n",ans);
    return 0;
}