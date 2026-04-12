#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<string>
#include<iostream>
#define ll long long
using namespace std;
const int maxn=100009*2;
const int maxm=100009*2;
struct node
{
    int x;int y;int id;
}a[100009*2],b[100009*2];
const bool com1(const node &a,const node &b)
{
    return a.x<b.x;
}
 const bool com2(const node &a,const node &b)
{
    return a.y<b.y;
}
struct Edge
{
    int u,v;
    ll dist;
    Edge(){}
    Edge(int u,int v,ll d):u(u),v(v),dist(d){}
    bool operator<(const Edge&rhs)const
    {
        return dist <rhs.dist;
    }
};

struct Kruskal
{
    int n,m;
    Edge edges[maxm];
    int fa[maxn];
    int findset(int x){ return fa[x]==-1? x: fa[x]=findset(fa[x]); }

    void init(int n)
    {
        this->n=n;
        m=0;
        memset(fa,-1,sizeof(fa));
    }

    void AddEdge(int u,int v,ll dist)
    {
        edges[m++]=Edge(u,v,dist);
    }

    ll kruskal()
    {
        ll sum=0;
        int cnt=0;
        sort(edges,edges+m);

        for(int i=0;i<m;i++)
        {
            int u=edges[i].u, v=edges[i].v;
            if(findset(u) != findset(v))
            {
                sum += edges[i].dist;
                fa[findset(u)] = findset(v);
                if(++cnt>=n-1) break;
            }
        }
        if(cnt<n-1) return -1;
        return sum;
    }
}KK;

int main()
{
    /*map<string,int> mp;
    ll max_sum;
    int n,m;
    scanf("%lf%d",&max_sum,&n);
    KK.init(n);
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        mp[s]=i;
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        string s1,s2;
        ll x;
        cin>>s1>>s2>>x;
        KK.AddEdge(mp[s1],mp[s2],x);
    }
    ll ans = KK.kruskal();
    if(ans==-1 || ans> max_sum) printf("Not enough cable\n");
    else printf("Need %.1f miles of cable\n",ans);
    return 0;*/
    int n;
    cin>>n;
     KK.init(n);
    for(int i=1;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;
        a[i].x=u;
        a[i].y=v;
        a[i].id=i;
        b[i].x=u;
        b[i].y=v;
        b[i].id=i;
    }
    sort(a+1,a+1+n,com1);
    sort(b+1,b+1+n,com2);
    for(int i=1;i<=n-1;i++)
    {
        KK.AddEdge(a[i].id,a[i+1].id,abs(a[i].x-a[i+1].x));
        KK.AddEdge(b[i].id,b[i+1].id,abs(b[i].y-b[i+1].y));
    }
     ll ans = KK.kruskal();
     cout<<ans<<endl;
}
