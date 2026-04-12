#include <bits/stdc++.h>

using namespace std;

#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)

using ll = long long;
using P = std::tuple<int,int>;
using Q = std::tuple<int,int,int>;

const int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1}, dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

std::vector<P> X, Y;
priority_queue<Q, std::vector<Q>, std::greater<Q>> pq;

template <int n>
struct UnionFind{
    UnionFind(){
        for(int i=0;i<n;i++){
            par[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x){
        if(x == par[x])return x;
        return par[x] = find(par[x]);
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y){return;}
        
        if(rank[x] > rank[y]){
            par[y] = x;
        }else{
            par[x] = y;
            if(rank[x] == rank[y]){rank[y]++;}
        }
    }
    int rank[n], par[n];
};

UnionFind<100100> uf;

int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    for(int i=0;i<N;++i){
        int x, y;
        std::cin >> x >> y;
        
        X.emplace_back(x, i);
        Y.emplace_back(y, i);
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    for(int i=0;i+1<X.size();++i){
        int v, a, v2, b;
        tie(v, a) = X[i];
        tie(v2, b) = X[i+1];
        pq.emplace(v2 - v, a, b);
    }

    for(int i=0;i+1<Y.size();++i){
        int v, a, v2, b;
        tie(v, a) = Y[i];
        tie(v2, b) = Y[i+1];
        pq.emplace(v2 - v, a, b);
    }

    ll res = 0ll;
    while(!pq.empty()){
        int cost, a, b;
        tie(cost, a, b) = pq.top();
        pq.pop();

        // std::cout << cost << ", " << a << ", " << b << std::endl;

        if(uf.same(a, b)){continue;}

        res += cost;
        uf.unite(a, b);
    }

    std::cout << res << std::endl;
}
