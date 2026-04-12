#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template<class T, bool directed>
class Dinic {
    void bfs(int s){
        fill(level.begin(),level.end(), -1);
        queue<int> Q;
        level[s] = 0;
        Q.emplace(s);
        while(!Q.empty()){
            int v = Q.front(); Q.pop();
            for (auto &&e : G[v]){
                if(e.cap > 0 && level[e.to] < 0){
                    level[e.to] = level[v] + 1;
                    Q.emplace(e.to);
                }
            }
        }
    }

    T dfs(int v, int t, T f){
        if(v == t) return f;
        for(int &i = iter[v]; i < G[v].size(); i++){
            edge &e = G[v][i];
            if(e.cap > 0 && level[v] < level[e.to]){
                T d = dfs(e.to, t, min(f,  e.cap));
                if(d == 0) continue;
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
        return 0;
    }
public:
    struct edge {
        int to{}; T cap; int rev{};
        edge() = default;
        edge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {}
    };

    vector<vector<edge>> G;
    vector<int> level, iter;
    Dinic() = default;
    explicit Dinic(int n) : G(n), level(n), iter(n) {}

    void add_edge(int from, int to, int cap){
        if(!cap) return;
        G[from].emplace_back(to, cap, G[to].size());
        G[to].emplace_back(from, directed ? 0 : cap,  G[from].size()-1);
    }

    T flow(int s, int t, T lim = INF<T>){
        T ret = 0;
        while(true) {
            bfs(s);
            if(level[t] < 0 || lim == 0) break;
            fill(iter.begin(),iter.end(), 0);
            while(true){
                T f = dfs(s, t, lim);
                if(f == 0) break;
                ret += f;
                lim -= f;
            }
        }
        return ret;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> S(n), T(n); vector<u64> U(n), V(n);
    for (auto &&i : S) cin >> i;
    for (auto &&i : T) cin >> i;
    for (auto &&i : U) cin >> i;
    for (auto &&i : V) cin >> i;
    vector<vector<u64>> ans(n, vector<u64>(n, 0));
    for (int i = 0; i < 64; ++i) {
        Dinic<int, true> flow(2*n+4);
        int sum = 0;
        auto add = [&](int u, int v, int lb, int ub){
            flow.add_edge(u, v, ub-lb);
            flow.add_edge(2, v, lb);
            flow.add_edge(u, 3, lb);
            sum += lb;
        };
        for (int j = 0; j < n; ++j) {
            if(S[j] && (U[j]>>i)&1) add(0, 4+j, 1, n);
            else if(!S[j] && (U[j]>>i)&1) add(0, 4+j, n, n);
            else if(!S[j] && !((U[j]>>i)&1)) add(0, 4+j, 0, n-1);
            if(T[j] && (V[j]>>i)&1) add(4+n+j, 1, 1, n);
            else if(!T[j] && (V[j]>>i)&1) add(4+n+j, 1, n, n);
            else if(!T[j] && !((V[j]>>i)&1)) add(4+n+j, 1, 0, n-1);
            for (int k = 0; k < n; ++k) flow.add_edge(4+j, 4+n+k, 1);
        }
        int a = flow.flow(2, 3);
        int b = flow.flow(0, 3);
        int c = flow.flow(2, 1);
        flow.flow(0, 1);
        if(b == c && a+b== sum){
            for (int j = 4; j < 4+n; ++j) {
                for (auto &&k : flow.G[j]) {
                    int to = k.to-(4+n);
                    if(!k.cap && 0 <= to && to < n)  ans[j-4][to] |= (1ULL << i);
                }
            }
        }else {
            puts("-1");
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(j) printf(" ");
            printf("%llu", ans[i][j]);
        }
        puts("");
    }
    return 0;
}