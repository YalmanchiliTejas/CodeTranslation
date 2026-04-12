#include <bits/stdc++.h>

using namespace std;

long long inf=1e18;
const int MAX_N=100005;
long long ways[2][MAX_N];
long long afstand[2][MAX_N];
long long modd=1e9+7;

int n, m;
vector< vector< pair<long long, int> > > graph;

void dijkstra(int start, int id)
{
    ways[id][start]=1;
    afstand[id][start]=0;
    vector<bool> vis(n, false);
    priority_queue< pair<long long, int>, vector< pair<long long, int> >, greater< pair<long long, int> > > pq;
    pq.push(make_pair(0, start));
    while(!pq.empty())
    {
        pair<long long, int> p = pq.top();
        pq.pop();
        long long curr_dist = p.first;
        int curr_node = p.second;
        if(vis[curr_node]) continue;
        vis[curr_node]=true;
        for(pair<long long, int> p2 : graph[curr_node])
        {
            long long wei = p2.first;
            int neigh = p2.second;
            long long new_dist = curr_dist+wei;
            if(new_dist<afstand[id][neigh])
            {
                ways[id][neigh]=ways[id][curr_node];
                afstand[id][neigh]=new_dist;
                pq.push(make_pair(new_dist, neigh));
            }
            else if(new_dist==afstand[id][neigh])
            {
                ways[id][neigh]=(ways[id][neigh]+ways[id][curr_node])%modd;
            }
        }
    }
}
int s, t;
int main()
{
    //freopen("inp.in", "r", stdin);
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<MAX_N; j++)
        {
            ways[i][j]=0;
            afstand[i][j]=inf;
        }
    }
    scanf("%d %d", &n, &m);
    scanf("%d %d", &s, &t);
    s--;
    t--;
    vector< pair<long long, int> > foo;
    graph.assign(n, foo);
    for(int i=0; i<m; i++)
    {
        int u, v;
        long long d;
        scanf("%d %d %lld", &u, &v, &d);
        u--;
        v--;
        graph[u].push_back(make_pair(d, v));
        graph[v].push_back(make_pair(d, u));
    }
    dijkstra(s,0);
    dijkstra(t,1);
    //cerr << ways[0][t] << " " << ways[1][s] << endl;
    long long ans=(ways[0][t]*ways[0][t])%modd;
    long long shortest_dist = afstand[0][t];
    for(int i=0; i<n; i++)
    {
        if(2*afstand[0][i]==shortest_dist && 2*afstand[1][i]==shortest_dist)
        {
            long long through_i=(ways[0][i]*ways[1][i])%modd;
            ans=(ans-(through_i*through_i)+modd*modd)%modd;
        }
        for(pair<long long, int> p : graph[i])
        {
            long long wei = p.first;
            int neigh = p.second;
            if(i>neigh) continue;
            if((afstand[0][i]+wei+afstand[1][neigh] == shortest_dist) &&
               (afstand[0][i]<(shortest_dist+1)/2 && afstand[1][neigh]<(shortest_dist+1)/2))
            {
                long long use_edge=(ways[0][i]*ways[1][neigh])%modd;
                ans=(ans-(use_edge*use_edge)+modd*modd)%modd;
            }
            if((afstand[0][neigh]+wei+afstand[1][i] == shortest_dist) &&
               (afstand[0][neigh]<(shortest_dist+1)/2 && afstand[1][i]<(shortest_dist+1)/2))
            {
                long long use_edge=(ways[0][neigh]*ways[1][i])%modd;
                ans=(ans-(use_edge*use_edge)+modd*modd)%modd;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
