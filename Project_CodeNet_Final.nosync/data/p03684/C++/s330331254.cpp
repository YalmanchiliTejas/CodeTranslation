#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

class UnionFind{
    public:
        UnionFind(){
            UnionFind(0);
        }
        UnionFind(int N){
            par.resize(N);
            rnk.resize(N);
            for(int i=0;i<N;i++){
                par[i] = i;
                rnk[i] = 0;
            }
        }

        int root(int x){
            return par[x] = par[x] == x ? x : root(par[x]);
        }

        bool same(int x, int y){
            return root(x) == root(y);
        }

        void unite(int x, int y){
            x = root(x); y = root(y);
            if(x == y) return;

            if(rnk[x] < rnk[y]){
                par[x] = y;
            }else{
                par[y] = x;
                if(rnk[x] == rnk[y]){
                    rnk[x]++;
                }
            }
        }
    private:
        vector<int> par, rnk;
};

struct town{
    ll x,y,id;
    town(){};
    town(int x,int y, int id) : x(x), y(y), id(id){};
};

struct edge{
    ll from, to, cost;
    edge(){};
    edge(int f, int t, int c) : from(f), to(t), cost(c){};
    bool operator<(const edge &e) const {
        return cost < e.cost;
    }
};

bool comp_x(const town &a, const town &b){
    return a.x < b.x;
}
bool comp_y(const town &a, const town &b){
    return a.y < b.y;
}

int main(){
    int N; cin >> N;
    vector<town> ts(N);
    for(int i=0;i<N;i++){
        int x,y; cin >> x >> y;
        ts[i] = town(x,y,i);
    }

    vector<edge> es;
    sort(ts.begin(), ts.end(), comp_x);
    for(int i=0;i<N-1;i++){
        es.push_back(edge(ts[i].id, ts[i+1].id, abs(ts[i].x-ts[i+1].x)));
    }
    sort(ts.begin(), ts.end(), comp_y);
    for(int i=0;i<N-1;i++){
        es.push_back(edge(ts[i].id, ts[i+1].id, abs(ts[i].y-ts[i+1].y)));
    }

    sort(es.begin(), es.end());
    ll ans = 0ll;
    UnionFind uf = UnionFind(N);

    for(auto e : es){
        if(!uf.same(e.from, e.to)){
            uf.unite(e.from, e.to);
            ans += e.cost;
        }
    }
    cout << ans << endl;
    return 0;
}