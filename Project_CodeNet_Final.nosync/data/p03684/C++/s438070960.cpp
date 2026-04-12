#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pii pair <int,int>
#define reset(x) memset(x, 0,sizeof(x))
#define PB push_back
#define mp make_pair
#define maxn 1000005

using namespace std;
int n,cnt,p[maxn],res,rk[maxn];
struct data
{
    int x,y,id;
} a[maxn],b[maxn];
bool cmp1(data a,data b)
{
    return a.x<b.x;
}
bool cmp2(data a,data b)
{
    return a.y<b.y;
}
bool cmp3(data a,data b)
{
    return a.id<b.id;
}
int FIND(int u)
{
    int v=p[u];
    while(v!=u)
    {
        u=v;
        v=p[u];
    }
    return u;
}
void Union(int u,int v)
{
    int x=FIND(u);
    int y=FIND(v);
    if(x==y)
        return;
    else
    {
        if(rk[x]>rk[y])
            p[y]=x;
        if(rk[x]<rk[y])
            p[x]=y;
        if(rk[x]==rk[y])
        {
            p[y]=x;
            rk[x]++;
            return ;
        }
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    //freopen("built.inp","r",stdin);
    //freopen("built.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i].x>>a[i].y;
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmp1);
    for(int i=1; i<n; i++)
    {
        b[++cnt].x=a[i].id;
        b[cnt].y=a[i+1].id;
        b[cnt].id=min(abs(a[i].x-a[i+1].x),abs(a[i].y-a[i+1].y));
    }
    sort(a+1,a+1+n,cmp2);
    for(int i=1; i<n; i++)
    {
        b[++cnt].x=a[i].id;
        b[cnt].y=a[i+1].id;
        b[cnt].id=min(abs(a[i].x-a[i+1].x),abs(a[i].y-a[i+1].y));
    }
    sort(b+1,b+1+cnt,cmp3);
    for(int i=1; i<=cnt; i++)
        p[i]=i;
    for(int i=1; i<=cnt; i++)
        if(FIND(b[i].x)!=FIND(b[i].y))
        {
            Union(b[i].x,b[i].y);
            res+=b[i].id;
        }
    cout<<res;

}
