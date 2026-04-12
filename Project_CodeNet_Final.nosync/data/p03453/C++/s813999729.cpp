#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<queue>
#include<string.h>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define pi pair < ll,ll >
#define mp(a,b) make_pair(a,b)
#define mid (low+high)/2
#define rep(i,a,b) for(int i = a;i < b;i++)
#define N 300004

using namespace std;

ll n,m,s,t,a,b,c,mod=1e9+7;
vector < pi > graph[N];
ll dist[N][2],ways[N][2];
vector < pair < pi,ll > > edges;

void dijkstra(ll root,ll id)
{
    rep(i,0,n+1)
    {
        dist[i][id] = -1;
        ways[i][id] = 0;
    }

    dist[root][id] = 0;
    ways[root][id] = 1;

    priority_queue < pi > pq;
    pq.push(mp(0,root));

    while(!pq.empty())
    {
        pi cur = pq.top();
        pq.pop();

        if(-cur.first > dist[cur.second][id])
            continue;

        rep(i,0,graph[cur.second].size())
        {
            ll v = graph[cur.second][i].first;
            c = graph[cur.second][i].second;

            if(dist[v][id] == -1 || dist[v][id] > dist[cur.second][id] + c)
            {
                dist[v][id] = dist[cur.second][id] + c;
                ways[v][id] = ways[cur.second][id];
                pq.push(mp(-dist[v][id],v));
            }
            else if(dist[v][id] == dist[cur.second][id]+c)
                ways[v][id] = (ways[v][id] + ways[cur.second][id])%mod;
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    cin >> s >> t;

    rep(i,0,m)
    {
        cin >> a >> b >> c;
        graph[a].push_back(mp(b,c));
        graph[b].push_back(mp(a,c));
        edges.push_back(mp(mp(a,b),c));
    }

    dijkstra(s,0);
    dijkstra(t,1);

    ll ans = (ways[t][0]*ways[s][1])%mod;
    ll S = dist[t][0];

    // meet at vertex

    rep(i,1,n+1)
    {
        if(dist[i][0] == dist[i][1] && dist[i][0] + dist[i][1] == S)
        {
            ll paths = (ways[i][0]*ways[i][1])%mod;

            ans = (ans - (paths*paths)%mod + mod)%mod;
        }
    }

    // meet at edge

    rep(i,0,m)
    {
        ll u = edges[i].first.first;
        ll v = edges[i].first.second;
        c = edges[i].second;

        if(dist[u][0] + dist[v][1] + c == S)
        {
            if(dist[u][0] < S/2.0 && dist[v][0] > S/2.0)
            {
                //cout << "meet from " << u << " to " << v << endl;
                ll paths = (ways[u][0]*ways[v][1])%mod;
                ans = (ans - (paths*paths)%mod + mod)%mod;
            }
        }
        if(dist[v][0] + dist[u][1] + c == S)
        {
            if(dist[v][0] < S/2.0 && dist[u][0] > S/2.0)
            {
               // cout << "meet from " << v << " to " << u << endl;
                ll paths = (ways[u][1]*ways[v][0])%mod;
                ans = (ans - (paths*paths)%mod + mod)%mod;
            }
        }
    }

    cout << ans;

    return 0;
}

/*
5 6
1 5
1 2 1
1 3 1
2 4 1
3 4 1
4 5 1
1 5 100

5 7
1 5
1 2 1
1 3 1
3 4 1
3 5 2
5 2 2
5 4 1
2 4 1

6 7
1 5
1 2 1
1 3 1
2 4 1
3 4 1
4 5 2
5 6 1
6 4 1

7 8
1 5
1 2 1
1 3 1
2 4 1
3 4 1
7 4 1
7 6 1
6 5 1
7 5 2

*/
