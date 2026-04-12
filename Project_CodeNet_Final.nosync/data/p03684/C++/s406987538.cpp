#include <bits/stdc++.h>
using namespace std;

int n;

int pr[200005];

int findfa(int x)
{
    if(pr[x]==x)
        return x;
    return pr[x]=findfa(pr[x]);
}

struct ha
{
    long long x,y;
    int id;
}q[200005];

int p;

struct gg
{
    int l,r;
    long long v;
}a[200005];

bool cmpx(const ha &aa,const ha &bb)
{
    return aa.x<bb.x;
}
bool cmpy(const ha &aa,const ha &bb)
{
    return aa.y<bb.y;
}
bool cmp(const gg &aa,const gg &bb)
{
    return aa.v<bb.v;
}


int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",&q[i].x,&q[i].y);
        q[i].id=i;
    }
    sort(q+1,q+1+n,cmpx);
    for(int i=1;i<n;i++)
    {
        p++;
        a[p].l=q[i].id;
        a[p].r=q[i+1].id;
        a[p].v=abs(q[i+1].x-q[i].x);
    }
    sort(q+1,q+1+n,cmpy);
    for(int i=1;i<n;i++)
    {
        p++;
        a[p].l=q[i].id;
        a[p].r=q[i+1].id;
        a[p].v=abs(q[i+1].y-q[i].y);
    }

    sort(a+1,a+1+p,cmp);

    for(int i=1;i<=n;i++)
    {
        pr[i]=i;
    }

    long long ans=0;

    for(int i=1;i<=p;i++)
    {
        if(findfa(a[i].l)!=findfa(a[i].r))
        {
            //cout<<a[i].l<<" "<<a[i].r<<" "<<a[i].v<<endl;
            pr[findfa(a[i].l)]=findfa(a[i].r);
            ans+=a[i].v;
        }
    }

    printf("%lld",ans);

    return 0;
}
