#include <cstdio>
#include <cctype>
#include <algorithm>
#define repu(i,x,y) for (int i=x; i<=y; ++i)
#define repd(i,x,y) for (int i=x; i>=y; --i) 
using namespace std;

typedef long long LL;
int n,min1,max2,minx[200100],maxy[200100],maxx,miny;
struct data
{
    int x,y;
    bool operator<(const data &t) const
    {
        return y<t.y;
    }
} a[200100];

int getint()
{
    char ch;
    while (!isdigit(ch=getchar()));
    int x=ch-'0';
    for (; isdigit(ch=getchar()); x=x*10+ch-'0');
    return x;
}

int main()
{
    n=getint();
    repu(i,1,n)
    {
        a[i].x=getint(),a[i].y=getint();
        if (a[i].x>a[i].y)
            swap(a[i].x,a[i].y);
    }
    sort(a+1,a+1+n),min1=miny=minx[n+1]=1<<30;
    repd(i,n,1)
    {
        minx[i]=min(minx[i+1],a[i].x);
        maxy[i]=max(maxy[i+1],a[i].y);
        min1=min(min1,a[i].x),max2=max(max2,a[i].x);
    }
    LL ans=1LL<<60;
    repu(i,1,n+1)
    {
        ans=min(ans,LL(max(maxy[i],maxx)-min1)*(max2-min(minx[i],miny)));
        max2=max(max2,a[i].y);
        maxx=max(maxx,a[i].x);
        miny=min(miny,a[i].y);
    }
    printf("%lld\n",ans);
    return 0;
}