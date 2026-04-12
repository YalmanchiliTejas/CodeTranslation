#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define maxn 200010
#define inf 1000000007
using namespace std;
typedef long long ll;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
struct P{
    int x,y;
}a[maxn];
ll ans=1999999999999999999ll;
void solve1()
{
    int mn1=inf,mx1=-inf,mn2=inf,mx2=-inf;
    for(int i=1;i<=n;i++)
    {
        mn1=min(mn1,a[i].x);mx1=max(mx1,a[i].x);
        mn2=min(mn2,a[i].y);mx2=max(mx2,a[i].y);
    }
    ans=min(ans,1ll*(mx1-mn1)*(mx2-mn2));
}
bool cmp(P a,P b)
{
    if(a.x!=b.x)  return a.x<b.x;
    return a.y<b.y;
}
int mn1[maxn],mn2[maxn],mx1[maxn],mx2[maxn];
void solve2()
{
    sort(a+1,a+n+1,cmp);
    mn1[n+1]=mn2[n+1]=inf;
    mx1[n+1]=mx2[n+1]=-inf;
    for(int i=n;i>=1;i--)
    {
        mn1[i]=min(mn1[i+1],a[i].x);mx1[i]=max(mx1[i+1],a[i].x);
        mn2[i]=min(mn2[i+1],a[i].y);mx2[i]=max(mx2[i+1],a[i].y);
    }
    int MN1=inf,MX1=-inf,MN2=inf,MX2=-inf;
    for(int i=1;i<=n;i++)
    {
        int mnn1=min(a[i].y,min(MN1,mn1[i+1]));
        int mxx1=max(a[i].y,max(MX1,mx1[i+1]));
        int mnn2=min(a[i].x,min(MN2,mn2[i+1]));
        int mxx2=max(a[i].x,max(MX2,mx2[i+1]));
        ans=min(ans,1ll*(mxx1-mnn1)*(mxx2-mnn2));
        MN1=min(MN1,a[i].y);MX1=max(MX1,a[i].y);
        MN2=min(MN2,a[i].x);MX2=max(MX2,a[i].x);
    }
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)  a[i].x=read(),a[i].y=read();
    for(int i=1;i<=n;i++)
      if(a[i].x>a[i].y)  swap(a[i].x,a[i].y);
    solve1();
    solve2();
    cout<<ans<<endl;
    return 0;
}