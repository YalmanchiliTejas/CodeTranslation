#include<bits/stdc++.h>

using namespace std;

typedef struct edge
{
    int to,weight;
    edge(int t,int w)
    {
        to=t;weight=w;
    }
}edge;

const int N=1e4+10;
vector<edge> G[N];

void add(int s,int t,int w)
{
    G[s].push_back(edge(t,w));
    G[t].push_back(edge(s,w));
}

int height[N];

void getHeight(int v,int p)
{
    height[v]=0;
    for(int i=0;i<G[v].size();i++)
    {
        edge e=G[v][i];
        if(p!=e.to)
        {
            getHeight(e.to,v);
            height[v]=max(height[v],height[e.to]+e.weight);
        }
    }
}

int ans[N];
void solve(int v,int height_p,int p)
{
    vector<pair<int,int> > res;
    res.push_back(make_pair(0,-1));
    for(int i=0;i<G[v].size();i++)
    {
        edge e=G[v][i];
        if(p==e.to)
        {
            res.push_back(make_pair(height_p+e.weight,e.to));
        }else
        {
            res.push_back(make_pair(height[e.to]+e.weight,e.to));
        }
    }
    sort(res.rbegin(),res.rend());
    ans[v]=res[0].first;
    for(int i=0;i<G[v].size();i++)
    {
        edge e=G[v][i];
        if(p!=e.to)
        {
            int tmp=(e.to==res[0].second?res[1].first:res[0].first);
            solve(e.to,tmp,v);
        }
    }
}

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<n;i++)
    {
        int s,t,w;
        cin>>s>>t>>w;
        add(s,t,w);
    }

    getHeight(0,-1);
    solve(0,0,-1);

    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<endl;
    }

    return 0;
}

