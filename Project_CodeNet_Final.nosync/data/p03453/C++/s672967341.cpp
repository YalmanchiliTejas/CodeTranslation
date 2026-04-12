#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

const ll mod = 1e9 + 7;
#define INF 1e16

struct edge{ll to,cost;};
 
void dijkstra(vector<vector<edge> > &graph, VL &d, VL &way, ll s){
    ll n = graph.size();
    fill(ALL(d), INF);
    fill(ALL(way), 0);
    d[s] = 0;
    way[s] = 1;
    priority_queue<PL, vector<PL>, greater<PL> > q;
    q.push(PL(0, s));
    while (!q.empty()){
        PL a = q.top();
        q.pop();
        ll now = a.second;
        if(d[now] < a.first) continue;
        REP(i,graph[now].size()){
            edge e = graph[now][i];
            ll next = e.to;
            if (d[next] == d[now] + e.cost){
                way[next] = (way[next] + way[now]) % mod;
            }
            if (d[next] > d[now] + e.cost){
                way[next] = way[now];
                d[next] = d[now] + e.cost;
                q.push(make_pair(d[next], next));
            }
        }
    }
}

int main() {
    ll n, m, s, t;
    cin >> n >> m >> s >> t;
    s--;
    t--;

    vector<vector<edge> > graph(n);
    REP(_,m){
        ll u, v, d;
        scanf("%lld %lld %lld", &u, &v, &d);
        u--;v--;
        graph[u].push_back((edge){v, d});
        graph[v].push_back((edge){u, d});
    }

    VL d1(n), way1(n), d2(n), way2(n);
    dijkstra(graph, d1, way1, s);
    dijkstra(graph, d2, way2, t);

    // REP(i,n){
    //     cout << d1[i] << " " << way1[i] << "   " << d2[i] << " " << way2[i] << endl;
    // }

    ll dmin = d1[t];
    ll ans = (way1[t] * way1[t]) % mod;

    REP(i,n){
        if (2 * d1[i] < dmin){
            for (edge e : graph[i]){
                ll next = e.to;
                if (2 * d2[next] < dmin && d1[i] + d2[next] + e.cost == dmin){
                    ll tmp = (way1[i] * way2[next]) % mod;
                    tmp = (tmp * tmp) % mod;
                    ans = (ans - tmp + mod) % mod;
                }
            }
        }
        if (2 * d1[i] == dmin){
            if (d1[i] + d2[i] == dmin){
                ll tmp = (way1[i] * way2[i]) % mod;
                tmp = (tmp * tmp) % mod;
                ans = (ans - tmp + mod) % mod;
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}
