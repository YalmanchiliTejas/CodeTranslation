#include <bits/stdc++.h>
using namespace std;

struct data
{
    int u,v,id;
};

data a[100005];
typedef pair<int,int> ii;
int n,res=1e9,d[100005];
vector<ii> g[100005];
set<ii> s;
map<ii,bool> mm;

bool cmp1(data x1,data x2)
{
    if(x1.u==x2.u)
        return x1.v<x2.v;
    return x1.u<x2.u;
}

bool cmp2(data x1,data x2)
{
    if(x1.v==x2.v)
        return x1.u<x2.u;
    return x1.v<x2.v;
}

void Prim()
{
    for(int i=1; i<=n; i++)
        d[i]=1e9;
    d[1]=0;
    int res=0;
    s.insert(ii(0,1));
    while(s.size()>0)
    {
        ii tmp=*s.begin();
        s.erase(s.begin());
        int u=tmp.second;
        res+=d[u];
        d[u]=0;
        for(int i=0; i<g[u].size(); i++)
        {
            int v=g[u][i].first;
            int w=g[u][i].second;
            if(d[v]>w)
            {
                if(d[v]!=1e9)
                    s.erase(s.find(ii(d[v],v)));
                d[v]=w;
                s.insert(ii(d[v],v));
            }
        }
    }
    cout<<res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("TEST.INP","r",stdin);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i].u>>a[i].v;
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp1);
    for(int i=2;i<=n;i++)
        if(mm[ii(a[i].id,a[i-1].id)]==false)
        {
            int w=min(abs(a[i].u-a[i-1].u),abs(a[i].v-a[i-1].v));
            g[a[i].id].push_back(ii(a[i-1].id,w));
            g[a[i-1].id].push_back(ii(a[i].id,w));
            mm[ii(a[i].id,a[i-1].id)]=true;
            mm[ii(a[i-1].id,a[i].id)]=true;
        }
    sort(a+1,a+n+1,cmp2);
    for(int i=2;i<=n;i++)
        if(mm[ii(a[i].id,a[i-1].id)]==false)
        {
            int w=min(abs(a[i].u-a[i-1].u),abs(a[i].v-a[i-1].v));
            g[a[i].id].push_back(ii(a[i-1].id,w));
            g[a[i-1].id].push_back(ii(a[i].id,w));
            mm[ii(a[i].id,a[i-1].id)]=true;
            mm[ii(a[i-1].id,a[i].id)]=true;
        }
    Prim();
}
