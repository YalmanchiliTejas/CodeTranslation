//Life is like a tube of toothpaste. When you've used all the toothpaste down the last squeeze, that's when you've really lived. Live with all your might. And struggle as long as you have life.
#include<bits/stdc++.h>
using namespace std;

#define s second
#define f first

const long long maxn = 1e6 + 10;
const long long inf = 1e18 + 7;
const long long mod = 1e9 + 7;

long long ans;
long long n, m;
long long s, t;
long long weight[maxn];
long long dis[2][maxn];
long long num[2][maxn];
pair<long long, long long> sarotah[maxn];
vector<pair<long long, long long>> adj[maxn];

void in();
void solve();
void echeck(long long e);
void vcheck(long long u);
void dfs(long long id, long long u);
void dijk(long long id, long long u);
void out();

int main(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    in();
    solve();
    out();
}

void in(){
    cin >> n >> m;
    cin >> s >> t;
    s--;
    t--;
    for(long long i = 0; i < m; i++){
        long long u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        weight[i] = w;
        sarotah[i] = {u, v};
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}

void solve(){
    dijk(0, s);
    dijk(1, t);
    dfs(0, t);
    dfs(1, s);
    for(long long i = 0; i < n; i++)
        vcheck(i);
    for(long long i = 0; i < m; i++)
        echeck(i);
}

void echeck(long long e){
    long long u = sarotah[e].f;
    long long v = sarotah[e].s;
    if(dis[0][u] < dis[0][v])
        swap(u, v);
    if(dis[0][v] + dis[1][u] + weight[e] == dis[0][t] && dis[0][v] < (dis[0][t] + 1) / 2 && dis[1][u] < (dis[0][t] + 1) / 2){
        ans += num[0][v] * num[1][u] % mod * (((num[0][t] - num[0][v] * num[1][u] % mod) + mod) % mod) % mod;
        ans %= mod;
    }
}

void vcheck(long long u){
    if(dis[0][t] % 2 == 0 && dis[0][u] == dis[1][u] && dis[0][u] == dis[0][t] / 2){
        ans += num[0][u] * num[1][u] % mod * (((num[0][t] - num[0][u] * num[1][u] % mod) + mod) % mod) % mod;
        ans %= mod;
    }
}

void dfs(long long id, long long u){
    if(num[id][u] != 0)
        return;
    if(dis[id][u] == 0){
        num[id][u] = 1;
        return;
    }
    for(auto v: adj[u]){
        if(dis[id][u] - v.s == dis[id][v.f]){
            dfs(id, v.f);
            num[id][u] += num[id][v.f];
            num[id][u] %= mod;
        }
    }
}

void dijk(long long id, long long u){
    set<pair<long long, long long>> dijkstra;
    for(long long i = 0; i < n; i++){
        if(i != u)
            dis[id][i] = inf;
        dijkstra.insert({dis[id][u], u});
    }
    while(dijkstra.size()){
        auto x = (*dijkstra.begin()).s;
        dijkstra.erase({dis[id][x], x});
        for(auto v: adj[x]){
            if(dis[id][x] + v.s < dis[id][v.f]){
                dijkstra.erase({dis[id][v.f], v.f});
                dis[id][v.f] = dis[id][x] + v.s;
                dijkstra.insert({dis[id][v.f], v.f});
            }
        }
    }
}

void out(){
    cout << ans;
}
