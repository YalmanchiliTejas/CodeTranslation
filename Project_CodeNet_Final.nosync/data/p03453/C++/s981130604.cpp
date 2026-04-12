#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const int maxn = 2e5 + 5;
int n, m;
int S, T;
int U[maxn], V[maxn], D[maxn];
typedef long long LL;
const LL mod = 1e9 + 7;

vector<pair<int, int> > G[maxn];

bool vis[maxn];

vector<LL> dijkstra(int s, int n){
    priority_queue<pair<LL, int> > pq;
    pq.push(make_pair(0, s));
    vector<LL> d(n + 1, 1e18);
    d[s] = 0;
    memset(vis, false, sizeof(vis));
    while(!pq.empty()){
        pair<LL, int> p = pq.top();pq.pop();
        int u = p.second;
        LL dis = -p.first;
        if(vis[u]) continue;
        vis[u] = true;
        for(auto it : G[u]){
            int v = it.first;
            int cost = it.second; 
            if(d[v] > d[u] + cost){
                d[v] = d[u] + cost;
                pq.push(make_pair(-d[v], v));
            }
        }
    }
    return d;
}

vector<LL> count(int s, vector<LL> dis){
    vector<pair<LL, int> > p(0); 
    for(int i = 1;i <= n;i++){
        p.push_back(make_pair(dis[i], i));
    }
    sort(p.begin(), p.end());
    vector<LL> cnt(n + 1, 0);
    cnt[s] = 1;
    for(int i = 0;i < n;i++){
        LL d = p[i].first;
        int id = p[i].second;
        for(auto it : G[id]){
            int v = it.first;
            int cost = it.second;
            if(dis[v] == dis[id] + cost){
                cnt[v] = (cnt[v] + cnt[id]) % mod;
            }
        }
    }
    return cnt;
}

vector<LL> dis1, dis2;
vector<LL> cnt1, cnt2;

LL sqr(LL x){
    return 1LL * x * x % mod;
}
int main(){
    cin >> n >> m;
    cin >> S >> T;
    for(int i = 1;i <= m;i++){
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        U[i] = u, V[i] = v, D[i] = c;
        G[u].push_back(make_pair(v, c));
        G[v].push_back(make_pair(u, c));        
    }
    dis1 = dijkstra(S, n);
    dis2 = dijkstra(T, n); 
    for(int i = 1;i <= n;i++){
        G[i].clear();
    }
    for(int i = 1;i <= m;i++){
        if(dis1[U[i]] + dis2[V[i]] + D[i] == dis1[T]){
            G[U[i]].push_back(make_pair(V[i], D[i]));
            G[V[i]].push_back(make_pair(U[i], D[i]));
        }
        if(dis1[V[i]] + dis2[U[i]] + D[i] == dis1[T]){
            G[U[i]].push_back(make_pair(V[i], D[i]));
            G[V[i]].push_back(make_pair(U[i], D[i]));
        }
    }
    cnt1 = count(S, dis1);
    cnt2 = count(T, dis2);
    //assert(cnt1[T] == cnt2[S]);
    LL ans = cnt1[T] * cnt1[T] % mod;
    for(int i = 1;i <= n;i++){
        if(dis1[i] * 2 == dis1[T]){
            ans = (ans - sqr(cnt1[i]) * sqr(cnt2[i]) % mod + mod) % mod;
        }
    }
    for(int i = 1;i <= m;i++){
        if(dis1[U[i]] + dis2[V[i]] + D[i] == dis1[T]){
            if(dis1[U[i]] * 2 < dis1[T] and (dis1[U[i]] + D[i]) * 2 > dis1[T]){
                ans = (ans - sqr(cnt1[U[i]]) * sqr(cnt2[V[i]]) % mod + mod) % mod;
            }
        }
        if(dis1[V[i]] + dis2[U[i]] + D[i] == dis1[T]){
            if(dis1[V[i]] * 2 < dis1[T] and (dis1[V[i]] + D[i]) * 2 > dis1[T]){
                ans = (ans - sqr(cnt1[V[i]]) * sqr(cnt2[U[i]]) % mod + mod) % mod;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
