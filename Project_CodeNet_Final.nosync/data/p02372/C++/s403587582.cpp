#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
const int INF=2e9;
const int maxv= 10000+10;
int V;
struct Edge{int to,cost;};
vector<Edge> g[maxv];

typedef pair<int,int> P;

vector<int> dijkstra(int s)
{
    vector<int> d(V);
    fill(d.begin(),d.end(),INF);
    priority_queue<P,vector<P>,greater<P> > que;
    que.push(P(0,s));
    d[s]=0;
    while(!que.empty())
    {
        P p=que.top();que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(int i=0;i<g[v].size();i++)
        {
            Edge &e=g[v][i];
            if(d[v]!=INF&&d[e.to]>d[v]+e.cost)
            {
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }

    }
    return d;

}
int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%d",&V);
    int u,v,cost;
    while(~scanf("%d%d%d",&u,&v,&cost))
    {
        g[u].push_back((Edge){v,cost});
         g[v].push_back((Edge){u,cost});
    }
    vector<int> d=dijkstra(0);
    int target=max_element(d.begin(),d.end())-d.begin();
    d=dijkstra(target);
    target=max_element(d.begin(),d.end())-d.begin();
    vector<int> d1=dijkstra(target);
    for(int i=0;i<V;i++)
        printf("%d\n",max(d[i],d1[i]));

    return 0;

}