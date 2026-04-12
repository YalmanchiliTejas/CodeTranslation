#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define int long long
#define all(a) a.begin(), a.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e18;
const int MAX_V = 100010;

struct edge{
   int to, cost;
   edge(int to, int cost):to(to), cost(cost){}
};

vector<edge> G[MAX_V];

struct Dijkstra{
    vector<int> d, dp;
    Dijkstra(){}
    Dijkstra(int V){
        d.resize(V, INF);
        dp.resize(V, 0);
    }
    void calc(int s){
        d[s] = 0;
        dp[s] = 1;
        priority_queue<P, vector<P>, greater<P> > q;
        q.push(P(d[s], s));
        while(!q.empty()){
            P p = q.top(); q.pop();
            int from = p.second;
            int cost = p.first;
            if(d[from] < cost) continue;
            rep(i, 0, G[from].size()){
                int next = G[from][i].to;
                int newCost = cost + G[from][i].cost;
                if(d[next] > newCost){
                    d[next] = newCost;
                    dp[next] = dp[from];
                    q.push(P(newCost, next));
                }else if(d[next] == newCost){
                    dp[next] = (dp[next] + dp[from]) % mod;
                }
            }
        }
    }
};


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--; t--;
    vector<int> u(m), v(m), d(m);
    rep(i, 0, m){
        cin >> u[i] >> v[i] >> d[i];
        u[i]--; v[i]--;
        G[u[i]].push_back({v[i], d[i]});
        G[v[i]].push_back({u[i], d[i]});
    }
    Dijkstra ds1(n), ds2(n);
    ds1.calc(s);
    ds2.calc(t);
    int len = ds1.d[t];
    int ans = ds1.dp[t] * ds1.dp[t] % mod;
    rep(i, 0, n){
        if(ds1.d[i] * 2 == len){
            ans = (ans - ds1.dp[i] * ds1.dp[i] % mod * ds2.dp[i] % mod * ds2.dp[i] % mod + mod) % mod;
        }
    }
    rep(i, 0, m){
        if(ds1.d[u[i]] > ds1.d[v[i]]) swap(u[i], v[i]);
        int pre = 2 * ds1.d[u[i]];// + ds2.d[v[i]];
        int aft = 2 * ds1.d[v[i]];// + ds2.d[u[i]];
        // if(ds1.d[u[i]] + d[i] != ds1.d[v[i]]) continue;
        if(ds1.d[u[i]] + d[i] + ds2.d[v[i]] != len) continue;
        if(pre < len && len < aft){
            ans = (ans - ds1.dp[u[i]] * ds1.dp[u[i]] % mod * ds2.dp[v[i]] % mod * ds2.dp[v[i]] % mod + mod) % mod;
        }
    }
    cout << ans << endl;
}