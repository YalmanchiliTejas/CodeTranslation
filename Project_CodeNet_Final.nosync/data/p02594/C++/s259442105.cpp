#include <bits/stdc++.h>
#define FAST_INPUT ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
 
using namespace std;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
using ll= long long;
const int mxN = 500;
const ll INF = 0x3f3f3f3f3f3f3f3fL;
// ll dist[mxN][mxN];
 
void dfs(ll u, vector<vector<ll>>& graph, vector<bool>& visited){
    if(visited[u])
        return;
    visited[u] = true;
    for(ll v: graph[u]){
        dfs(v, graph, visited);
    }
}

bool relax(vector<ll>& dist, vector<vector<ll>>& edges, vector<bool>& visited){
    bool changed = false;
    for(vector<ll>& edge: edges){
        ll u = edge[0];
        ll v = edge[1];
        ll w = edge[2];

        if(visited[u] && visited[v] && dist[u] != INF){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                // if(v ==  visited.size() - 1)
                    changed = true;
                // cout << u + 1 << " " << v + 1<< " " << dist[u] << " " << dist[v] << endl;
            }
        }
    }
    return changed;
}

void dijkstra(ll s, vector<ll>& dist, vector<vector<pair<ll,ll>>>& graph){
    priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0,s});
    dist[s] = 0;
    while(!pq.empty()){
        pair<ll,int> top = pq.top(); pq.pop();
        ll u = top.second;
        ll d = top.first;
        if(d > dist[u])
            continue;

        for(pair<ll,ll>& next: graph[u]){
            ll v = next.first;
            ll w = next.second;
            if(dist[v] > d + w){
                dist[v] = d + w;
                pq.push({dist[v], v});
            }            
        }
    }
}

void solve() {
    int n; cin >> n;
    cout << (n >= 30 ? "Yes" : "No") << endl;
}
 
int main() {
    FAST_INPUT;
    
    solve();
    return 0;
}