#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
#define ll long long
const int maxn=2e5+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll ans[maxn];
vector<pair<int,ll> > head[maxn],tail[maxn];
struct node
{
    int l,r;
    ll maxx,lz;
}tree[4*maxn];
void push_up(int cur)
{
    tree[cur].maxx=max(tree[cur<<1].maxx,tree[cur<<1|1].maxx);
    return;
}
void build(int l,int r,int cur)
{
    tree[cur].l=l;
    tree[cur].r=r;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(l,mid,cur<<1);
    build(mid+1,r,cur<<1|1);
    return;
}
void push_down(int cur)
{
    if(tree[cur].lz)
    {
        tree[cur<<1].maxx+=tree[cur].lz;
        tree[cur<<1].lz+=tree[cur].lz;
        tree[cur<<1|1].maxx+=tree[cur].lz;
        tree[cur<<1|1].lz+=tree[cur].lz;
        tree[cur].lz=0;
    }
    return;
}
void add(int l,int r,ll val,int cur)
{
    if(tree[cur].l>=l&&tree[cur].r<=r)
    {
        tree[cur].maxx+=val;
        tree[cur].lz+=val;
        return;
    }
    if(tree[cur].l>r||tree[cur].r<l)
        return;
    push_down(cur);
    add(l,r,val,cur<<1);
    add(l,r,val,cur<<1|1);
    push_up(cur);
    return;
}
ll query(int l,int r,int cur)
{
    if(tree[cur].l>=l&&tree[cur].r<=r)
        return tree[cur].maxx;
    if(tree[cur].l>r||tree[cur].r<l)
        return -INF;
    push_down(cur);
    ll res=max(query(l,r,cur<<1),query(l,r,cur<<1|1));
    push_up(cur);
    return res;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int l,r;
        ll val;
        scanf("%d%d%lld",&l,&r,&val);
        head[l].push_back(make_pair(r,val));
        tail[r].push_back(make_pair(l,val));
    }
    ll ret=0;
    build(0,n,1);
    for(int i=1;i<=n;i++)
    {
        ll sum=0;
        for(int j=0;j<(int)head[i].size();j++)
            sum+=head[i][j].second;
        add(0,i-1,sum,1);
        for(int j=0;j<(int)tail[i-1].size();j++)
            add(0,tail[i-1][j].first-1,-tail[i-1][j].second,1);
        ans[i]=query(0,i-1,1);
        ret=max(ret,ans[i]);
        add(i,i,ans[i],1);
    }
    printf("%lld\n",ret);
    return 0;
}
/*
5 3
1 3 10
2 4 -10
3 5 10
 
3 4
1 3 100
1 1 -10
2 2 -20
3 3 -30
 
1 1
1 1 -10
 
1 5
1 1 1000000000
1 1 1000000000
1 1 1000000000
1 1 1000000000
1 1 1000000000
 
6 8
5 5 3
1 1 10
1 6 -8
3 6 5
3 4 9
5 5 -2
1 3 -6
4 6 -7
 */
