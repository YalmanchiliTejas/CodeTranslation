#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
const int maxn=2e5+10;
int v[maxn*2];
struct number
{
    int id,v;
} a[maxn*2];
typedef long long LL;
bool cmpv(const number& A,const number& B)
{
    return A.v<B.v;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].v,&a[i+n].v);
    for(int i=1;i<=n;i++)
    {
        a[i].id=i;
        a[i+n].id=i+n;
        if(a[i].v>a[i+n].v) swap(a[i].v,a[i+n].v);
    }
    for(int i=1;i<=n+n;i++) v[i]=a[i].v;
    int maxv=v[1],minv=v[1];
    for(int i=1;i<=n;i++)
    {
        maxv=max(maxv,v[i+n]);
        minv=min(minv,v[i]);
    }
    int maxl=v[1],minr=v[1+n];
    for(int i=1;i<=n;i++)
    {
        maxl=max(maxl,v[i]);
        minr=min(minr,v[i+n]);
    }
    LL ans=(1LL*(maxl-minv))*(maxv-minr);
    sort(a+1,a+n+n+1,cmpv);
    int cur=maxl;
    for(int i=1;i<=n+n;i++)
    {
        if(a[i].id>n) break;
        cur=max(cur,v[a[i].id+n]);
        ans=min(ans,(1LL*(maxv-minv))*(cur-a[i+1].v));
    }
    printf("%lld",ans);
    return 0;
}
