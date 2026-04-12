#include <bits/stdc++.h>
 
using namespace std;
 
#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)
#define unless(p) if(!(p))
#define until(p) while(!(p))
 
using ll = long long;
using P = std::tuple<ll, ll>;
 
const int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1}, dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
 
int N, M;
int S, T;
vector<P> G[100100];
ll ways[100100], revWays[100100];
 
template <typename T>
T expt(T a, T n, T mod = std::numeric_limits<T>::max()){
    T res = 1;
    while(n){
        if(n & 1){res = res * a % mod;}
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
 
template <class T>
using priority_queue_with_greater = std::priority_queue<T, std::vector<T>, std::greater<T>>;
 
priority_queue_with_greater<P> pq;
ll dist[100100];
 
template <typename T, typename U, int n>
void dijkstra(T s, std::vector<std::tuple<T, U>> (&graph)[n], U (&dist)[n], priority_queue_with_greater<std::tuple<U, T> > &pq){
    std::fill(dist, dist+n, std::numeric_limits<U>::max() / 2);
    dist[s] = 0;
    pq.emplace(dist[s], s);
 
    while(!pq.empty()){
        T u;
        U d;
        std::tie(d, u) = pq.top();
        pq.pop();
 
        if(dist[u] < d){continue;}
 
        for(const auto& p : graph[u]){
            T v;
            U c;
            std::tie(v, c) = p;
            if(dist[v] > d + c){
                dist[v] = d + c;
                pq.emplace(dist[v], v);
            }
        }
    }
}
 
const ll MOD = 1000000000ll + 7;
bool used[100100];
vector<int> order;

void dfs(int v){
    used[v] = true;

    for(const auto &e : G[v]){
        int u, c;
        tie(u, c) = e;

        if(dist[u] + c == dist[v] && !used[u]){
            dfs(u);
        }
    }
    
    order.emplace_back(v);
}
 
int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
 
    std::cin >> N >> M;
    std::cin >> S >> T;
 
    for(int i=0;i<M;++i){
        int u, v, d;
        std::cin >> u >> v >> d;
 
        G[u].emplace_back(v, d);
        G[v].emplace_back(u, d);
    }
 
    dijkstra<ll, ll>(S, G, dist, pq);
    dfs(T);
    
    ways[S] = 1ll;
    revWays[T] = 1ll;

    for(int i=0;i+1<order.size();++i){
        int v = order[i];
        for(const auto &e : G[v]){
            int w, c;
            tie(w, c) = e;

            if(dist[v] + c == dist[w]){
                ways[w] = (ways[w] + ways[v]) % MOD;
            }
        }
    }

    for(int i=order.size()-1;i>0;--i){
        int v = order[i];
        for(const auto &e : G[v]){
            int u, c;
            tie(u, c) = e;

            if(dist[u] + c == dist[v]){
                revWays[u] = (revWays[u] + revWays[v]) % MOD;
            }
        }
    }
    
 
    ll invalid_n = 0ll;
    for(int v=1;v<=N;++v){
        // 頂点で出会う
        if(dist[v] * 2 == dist[T]){
            invalid_n = (invalid_n + expt(ways[v] * revWays[v] % MOD, 2ll, MOD)) % MOD;
        }
        
        // 辺(端点は含まない)で出会う
        for(const auto &e : G[v]){
            int w, c;
            tie(w, c) = e;
 
            if(dist[v] + c != dist[w]){
                continue;
            }
 
            if(2ll * dist[v] < dist[T] && dist[T] < 2ll * dist[w]){
                invalid_n = (invalid_n + expt(ways[v] * revWays[w] % MOD, 2ll, MOD)) % MOD;
            }
        }
    }
 
    ll all = expt(ways[T], 2ll, MOD), res = (all + MOD - invalid_n) % MOD;
    std::cout << res << std::endl;
}
