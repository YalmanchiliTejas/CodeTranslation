#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<long long> par;
    vector<long long> rank;
    vector<long long> time;
    const long long INF = 1e18;

    void initialize(long long n){
        par.resize(n);
        rank.resize(n);
        time.resize(n);
        for(long long i=0; i<n; i++){
            par[i] = i;
            rank[i] = 0;
            time[i] = INF;
        }
    }

    long long find(long long x, long long t){
        if(time[x] > t){
            return x;
        }else{
            return find(par[x], t);
        }
    }

    void unite(long long x, long long y, long long t){
        x = find(x, t);
        y = find(y, t);
        if(x == y) return;
        if(rank[x] < rank[y]){
            par[x] = y;
            time[x] = t;
        }else{
            par[y] = x;
            time[y] = t;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }

    bool same(long long x, long long y, long long t){
        return find(x, t) == find(y, t);
    }
};

struct edge{long long u, v, cost;};
bool comp(const edge& e1, const edge& e2){
    return e1.cost < e2.cost;
}

UnionFind uf;

long long kruskal(long long N, vector<edge> es){
    sort(es.begin(), es.end(), comp);
    uf.initialize(N);
    long long res = 0;
    for(long long i=0; i<es.size(); i++){
        edge e = es[i];
        if(!uf.same(e.u, e.v, e.cost)){
            uf.unite(e.u, e.v, e.cost);
            res += e.cost;
        }
    }
    return res;
}


int main(){
    long long i, j, k;
    long long N, M;
    cin >> N >> M;
    vector<edge> es;
    for(i=0; i<M; i++){
        long long a, b, c;
        cin >> a >> b >> c;
        es.push_back({a, b, c});
    }
    long long sum = kruskal(N+1, es);

    long long Q;
    cin >> Q;
    for(i=0; i<Q; i++){
        long long s, t;
        cin >> s >> t;
        long long ok=0, ng=1e10; 
        while(ng-ok>1){
            long long mid = (ng+ok)/2;
            if(uf.same(s, t, mid)){
                ng = mid;
            }else{
                ok = mid;
            }
        }
        cout << (sum-ok-1) << endl;
    }
    return 0;
}