#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll MOD = 1000000007;
const ll INF = 100000000000000007;

template <typename T>
struct Edge
{
    int to;
    T cost;
};

template <typename T>
struct WeightedGraph
{
    int n;
    vector<vector<Edge<T>>> g;
    
    WeightedGraph(int n) : n(n){
        g.resize(n);
    }
    
    void init(int n_){
        n = n_;
        g.resize(n_);
    }
    
    void add_edge(int from, int to, T cost){
        g[from].push_back((Edge<T>){to, cost});
    }
};

struct Graph
{
    int n;
    vector<vector<int>> g;
    
    Graph(int n) : n(n){
        g.resize(n);
    }
    
    void init(int n_){
        n = n_;
        g.resize(n_);
    }
    
    void add_edge(int from, int to){
        g[from].push_back(to);
    }
};

vector<P> Dijkstra(WeightedGraph<ll> &g, int s){
    int n = g.n;
    vector<P> d(n);
    fill(d.begin(), d.end(), P(INF, 0));
    priority_queue<P, vector<P>, greater<P>> que;
    d[s] = P(0, 1);
    que.push(P(0, s));
    while(que.size()){
        P nowp = que.top();
        que.pop();
        if(d[nowp.second].first < nowp.first) continue;
        for(Edge<ll> e : g.g[nowp.second]){
            if(d[e.to].first > d[nowp.second].first + e.cost){
                d[e.to].first = d[nowp.second].first + e.cost;
                d[e.to].second = d[nowp.second].second;
                que.push(P(d[e.to].first, e.to));
            }
            else if(d[e.to].first == d[nowp.second].first + e.cost){
                d[e.to].second = (d[e.to].second + d[nowp.second].second) % MOD;
            }
        }
    }
    return d;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    s--; t--;
    WeightedGraph<ll> g(n);
    int u[200002], v[200002];
    ll d[200002];
    for(int i = 0; i < m; i++){
        cin >> u[i] >> v[i] >> d[i];
        u[i]--; v[i]--;
        g.add_edge(u[i], v[i], d[i]);
        g.add_edge(v[i], u[i], d[i]);
    }
    vector<P> d1 = Dijkstra(g, s);
    vector<P> d2 = Dijkstra(g, t);
    ll dis = d1[t].first;
    ll ans = d1[t].second * d2[s].second % MOD;
    for(int i = 0; i < n; i++){
        if(d1[i].first == d2[i].first && d1[i].first + d2[i].first == dis)
            ans = (ans + MOD - d1[i].second * d2[i].second % MOD * d1[i].second % MOD * d2[i].second % MOD) % MOD;
    }
    for(int i = 0; i < m; i++){
        if(d1[u[i]].first * 2 < dis && d2[v[i]].first * 2 < dis && d1[u[i]].first + d2[v[i]].first + d[i] == dis)
            ans = (ans + MOD -
                   d1[u[i]].second * d2[v[i]].second % MOD * d1[u[i]].second % MOD * d2[v[i]].second % MOD) % MOD;
        if(d1[v[i]].first * 2 < dis && d2[u[i]].first * 2 < dis && d1[v[i]].first + d2[u[i]].first + d[i] == dis)
            ans = (ans + MOD -
                   d1[v[i]].second * d2[u[i]].second % MOD * d1[v[i]].second % MOD * d2[u[i]].second % MOD) % MOD;
    }
    cout << ans << endl;
}