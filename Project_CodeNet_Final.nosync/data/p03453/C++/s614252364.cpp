#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e12;

struct edge{
   int to, cost;
   edge(int to, int cost):to(to), cost(cost){}
};
vector<edge> G[100010];
int d[100010], d2[100010]; 
int n, m, s, t;
int tim, ans;
int dp[100010];
int dp2[100010];
int u[200010], v[200010], c[200010];

void dijkstra(int s){
    fill(d, d + 100010, INF);//V, INF
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P> > q;
    q.push(P(d[s], s));
    dp[s] = 1;
    while(!q.empty()){
        P p = q.top(); q.pop();
        int from = p.second;
        int cost = p.first;
        if(d[from] < cost) continue;
        rep(i, 0, G[from].size()){
            edge e = G[from][i];
            int next = e.to;
            int newCost = e.cost + cost;
            if(d[next] > newCost){
                dp[next] = dp[from];
                d[next] = newCost;
                q.push(P(newCost, next));
            }else if(d[next] == newCost){
                (dp[next] += dp[from]) %= mod;
            }
        }
    }
}

void dijkstra2(int s){
    fill(d2, d2 + 100010, INF);//V, INF
    d2[s] = 0;
    priority_queue<P, vector<P>, greater<P> > q;
    q.push(P(d2[s], s));
    dp2[s] = 1;
    while(!q.empty()){
        P p = q.top(); q.pop();
        int from = p.second;
        int cost = p.first;
        if(d2[from] < cost) continue;
        rep(i, 0, G[from].size()){
            edge e = G[from][i];
            int next = e.to;
            int newCost = e.cost + cost;
            if(d2[next] > newCost){
                dp2[next] = dp2[from];
                d2[next] = newCost;
                q.push(P(newCost, next));
            }else if(d2[next] == newCost){
                (dp2[next] += dp2[from]) %= mod;
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s >> t;
    s--; t--;
    rep(i, 0, m){
        cin >> u[i] >> v[i] >> c[i];
        u[i]--; v[i]--;
        G[u[i]].push_back(edge{v[i], c[i]});
        G[v[i]].push_back(edge{u[i], c[i]});
    }
    dijkstra(s);
    tim = d[t];    
    dijkstra2(t);
    ans = dp[t] * dp[t] % mod;
    rep(i, 0, n){
        if(d[i] * 2 == tim){
            // cout << " " << i << " " << d[i] << " " << dp[i] << " " << dp2[i] << endl;
            ans = (ans - dp[i] * dp[i] % mod * dp2[i] % mod * dp2[i] % mod + mod) % mod;
        }
    }
    rep(i, 0, m){
        if(d[u[i]] > d[v[i]]) swap(u[i], v[i]);
        if(d[u[i]] * 2 < tim && d[v[i]] * 2 > tim && d[u[i]] + c[i] == d[v[i]] && d[u[i]] + c[i] + d2[v[i]] == tim){
            // cout << u[i] << ' ' << v[i] << " " << d[u[i]] <<" " << d[v[i]] << endl;
            ans = (ans - dp[u[i]] * dp[u[i]] % mod * dp2[v[i]] % mod * dp2[v[i]] % mod + mod) % mod;
        }
    }
    cout << ans << endl;
}