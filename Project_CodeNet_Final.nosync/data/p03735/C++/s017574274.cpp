#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define inf 2123333333
 
struct node { ll x,y; }a[200010];
 
ll n,h1,h2,mn,minn,maxn,rmin,rmax,bmin,bmax,ans;
 
inline int rd()
{
    int x=0;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar());
    for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x;
}
 
inline bool cmp(node x,node y) { return x.x<y.x; }
 
int main()
{
    n=rd();minn=inf;maxn=0;
    for (int i=1;i<=n;i++)
    {
        a[i].x=rd();a[i].y=rd();
        if (a[i].x>a[i].y) swap(a[i].x,a[i].y);
        if (a[i].x<minn) h1=i,minn=a[i].x;
        if (a[i].y>maxn) h2=i,maxn=a[i].y;
    }
    sort(a+1,a+n+1,cmp);
    rmax=rmin=maxn,bmin=bmax=minn;
    for (int i=1;i<=n;i++) bmax=max(bmax,a[i].x),rmin=min(rmin,a[i].y);
    ans=(rmax-rmin)*(bmax-bmin);
    if (h1!=h2)
    {
        ll hh=maxn-minn,res=inf;
        rmax=max(a[n].x,a[1].y);
        rmin=min(a[2].x,mn=a[1].y);
        for (int i=2;i<n;i++)
        {
            rmax=max(a[i].y,rmax);
            mn=min(mn,a[i].y);
            rmin=min(mn,a[i+1].x);
            res=min(res,rmax-rmin);
        }
        ans=min(ans,hh*res);
    }
    printf("%lld\n",ans);
    return 0;
}