#include<bits/stdc++.h>
#define N 200005
#define ll long long
#define int long long
using namespace std;
const int inf = 0x3f3f3f3f;
int n;
struct node
{
    int x,y;
    friend bool operator < (const node &aa,const node &bb)
    {
        return aa.x>bb.x;
    }
}a[N];
int mx1[N],mx2[N],mn1[N],mn2[N];
signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",&a[i].x,&a[i].y);
        if(a[i].x<a[i].y)swap(a[i].x,a[i].y);
    }
    sort(a+1,a+n+1);
    mn1[0]=mn2[0]=inf;
    for(int i=1;i<=n;i++)
    {
        mn1[i]=min(mn1[i-1],a[i].x);
        mn2[i]=min(mn2[i-1],a[i].y);
        mx1[i]=max(mx1[i-1],a[i].x);
        mx2[i]=max(mx2[i-1],a[i].y);
    }
    ll ans=1LL<<62;
    for(int i=1;i<n;i++)
    {
        int Rmax=a[1].x,Lmax=max(a[i+1].x,mx2[i]);
        int Rmin=mn2[n],Lmin=min(mn2[i],a[n].x);
        ans=min(ans,(Rmax-Rmin)*(Lmax-Lmin));
        Lmin=mn2[n],Rmin=min(a[i+1].y,a[n].x);
        ans=min(ans,(Rmax-Rmin)*(Lmax-Lmin));
    }
   // cout<<mx2[n]<<' '<<mn2[n]<<endl;
    ans=min(ans,(mx1[n]-mn1[n])*(mx2[n]-mn2[n]));
    cout<<ans<<endl;
    return 0;
}
