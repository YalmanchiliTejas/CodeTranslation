#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define N 200010
using namespace std;

struct query{ll l,r,v;} a[N];
ll n,m,cnt,t[N<<2],lt[N<<2];

bool cmp(query a,query b) { return a.r<b.r; }

void push(int x)
{
    t[x<<1]+=lt[x];
    lt[x<<1]+=lt[x];
    t[x<<1|1]+=lt[x];
    lt[x<<1|1]+=lt[x];
    lt[x]=0;
}

void update(int x,int l,int r,int a,int b,ll v)
{
    if(b<l || a>r) return;
    if(l==a && r==b)
    {
        t[x]+=v;
        lt[x]+=v;
        return;
    }
    push(x);
    int m=(l+r)/2;
    update(2*x,l,m,a,min(b,m),v);
    update(2*x+1,m+1,r,max(a,m+1),b,v);
    t[x]=max(t[2*x],t[2*x+1]);
}

ll query(int x,int l,int r,int a,int b)
{
    if(b<l || a>r) return 0;
    if(l==a && r==b) return t[x];
    push(x);
    int m=(l+r)/2;
    return max(query(2*x,l,m,a,min(b,m)),query(2*x+1,m+1,r,max(a,m+1),b));
}

int main()
{
    cin>>n>>m;
    FOR(i,0,m) cin>>a[i].l>>a[i].r>>a[i].v;
    sort(a,a+m,cmp);
    FOR(i,1,n+1)
    {
        update(1,1,n,i,i,query(1,1,n,1,i));
        while(a[cnt].r==i)
        {
            update(1,1,n,a[cnt].l,a[cnt].r,a[cnt].v);
            cnt++;
        }
    }
    cout<<max(t[1],0ll)<<'\n';

    return 0;
}