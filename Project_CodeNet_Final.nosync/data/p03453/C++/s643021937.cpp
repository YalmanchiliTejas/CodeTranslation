#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;

struct edge { long long to, cost;};
typedef pair<long long, long long> Pair;
 
vector<long long> dijkstra(long long s, long long n, const vector<edge> G[]){
    vector<long long> dist(n);
    long long INF = 1LL<<60;
    for(int i=0; i<n; i++){
        dist[i] = INF;
    }
    priority_queue<Pair, vector<Pair>, greater<Pair>> que;
    dist[s] = 0;
    que.push(Pair(0, s));
    while(!que.empty()){
        Pair p = que.top();
        que.pop();
        long long v = p.second;
        if(dist[v] < p.first)continue;
        for(int i=0; i<G[v].size(); i++){
            edge e = G[v][i];
            if(dist[e.to] > dist[v] + e.cost){
                dist[e.to] = dist[v] + e.cost;
                que.push(Pair(dist[e.to], e.to));
            }
        }
    }
    return dist;
}


int main(){
    long long i, j, k;
    long long N, M, S, T;
    cin >> N >> M >> S >> T;
    S--; T--;
    vector<edge> edges[100000];
    vector<long long> U(M), V(M), D(M);
    for(i=0; i<M; i++){
        long long u, v, d;
        cin >> u >> v >> d;
        if(u>v) swap(u, v);
        edges[u-1].push_back({v-1, d});
        edges[v-1].push_back({u-1, d});
        U[i] = u-1; V[i] = v-1; D[i] = d;
    }
    auto dist_s = dijkstra(S, N, edges);
    auto dist_t = dijkstra(T, N, edges);
    long long dist = dist_s[T];

    vector<long long> num_s(N), num_t(N);
    for(i=0; i<N; i++){
        num_s[i] = 0;
        num_t[i] = 0;
    }
    vector<Pair> order(N);

    for(i=0; i<N; i++) order[i] = {dist_s[i], i};
    sort(order.begin(), order.end());
    num_s[S] = 1;
    for(auto p : order){
        i = p.second;
        for(auto e : edges[i]){
            if(dist_s[i] + e.cost == dist_s[e.to]) num_s[e.to] = (num_s[e.to] + num_s[i]) % MOD;
        }
    }

    for(i=0; i<N; i++) order[i] = {dist_t[i], i};
    sort(order.begin(), order.end());
    num_t[T] = 1;
    for(auto p : order){
        i = p.second;
        for(auto e : edges[i]){
            if(dist_t[i] + e.cost == dist_t[e.to]) num_t[e.to] = (num_t[e.to] + num_t[i]) % MOD;
        }
    }

    long long ans = num_s[T] * num_s[T] % MOD;

    for(i=0; i<N; i++){
        if(dist_s[i]*2 == dist){
            long long loss = num_s[i] * num_t[i] % MOD;
            loss = loss * loss % MOD;
            ans = (MOD + ans - loss) % MOD;
        }
    }

    for(i=0; i<M; i++){
        long long v1 = U[i];
        long long v2 = V[i];
        long long d = D[i];
        if(dist_s[v1]*2 == dist) continue;
        if(dist_s[v2]*2 == dist) continue;
        if(dist_s[v1]*2 <= dist && dist_t[v2]*2 <= dist && dist_s[v1] + dist_t[v2] + d == dist){
            long long loss = num_s[v1] * num_t[v2] % MOD;
            loss = loss * loss % MOD;
            ans = (MOD + ans - loss) % MOD;
        }
        if(dist_s[v2]*2 <= dist && dist_t[v1]*2 <= dist && dist_s[v2] + dist_t[v1] + d == dist){
            long long loss = num_s[v2] * num_t[v1] % MOD;
            loss = loss * loss % MOD;
            ans = (MOD + ans - loss) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
