#include <bits/stdc++.h>
using namespace std;
#define L pos*2+1
#define R pos*2+2
const int N=2e5+5;
int n,m,l,r;
long long a[N],seg[N*4],laz[N*4],dp[N],ans;
vector <pair<int,int> > v[N];
void push (int pos)
{
    if (laz[pos])
    {
        if (R<N*4)
        {
            laz[R]+=laz[pos];
            laz[L]+=laz[pos];
        }
        seg[pos]+=laz[pos];
        laz[pos]=0;
    }
}
void update (int st,int en,int pos,long long val)
{
    push(pos);
    if (st>r||en<l)
        return;
    if (st>=l&&en<=r)
    {
        laz[pos]+=val;
        push(pos);
        return;
    }
    int mid= (st+en)/2;
    update(st,mid,L,val);
    update(mid+1,en,R,val);
    seg[pos]=max(seg[L],seg[R]);
}
long long query (int st,int en,int pos)
{
    if (st>r||en<l)
        return 0;
    if (st>=l&&en<=r)
        return seg[pos];
    int mid= (st+en)/2;
    return max(query(st,mid,L),query(mid+1,en,R));
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        a[x]+=z;
        a[y+1]-=z;
        v[y].push_back({x,z});
    }
    for (int i=1;i<=n;i++)
        a[i]+=a[i-1];
    for (int i=1;i<=n;i++)
    {
        l=0;
        r=i-1;
        dp[i]=a[i]+query(0,n,0);
        l=i;
        r=i;
        update(0,n,0,dp[i]-a[i]);
        ans=max(ans,dp[i]);
        for (int j=0;j<v[i].size();j++)
        {
            l=v[i][j].first;
            r=i;
            update(0,n,0,v[i][j].second);
        }
    }
    l=0,r=n;
    printf("%lld",query(0,n,0));
    return 0;
}
