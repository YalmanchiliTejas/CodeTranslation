#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind{
    public:
        UnionFind(){
            UnionFind();
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
            return par[x] = (par[x] == x ? x : root(par[x]));
        }

        bool same(int x, int y){
            return root(x) == root(y);
        }

        void unite(int x, int y){
            x = root(x);
            y = root(y);

            if(rnk[y] < rnk[x]){
                par[y] = x;
            }else{
                par[x] = y;
                if(rnk[x] == rnk[y]){
                    rnk[y]++;
                }
            }
        }

    private:
        vector<int> par, rnk;
};

class edge{
    public:
        int to, from, cost;
        edge(){};
        edge(int t, int f, int c):
        to(t), from(f), cost(c){};
        bool operator < (const edge &e) const{
            return cost < e.cost;
        }
};

class node{
    public:
        int x, y, id;
        node(){};
        node(int x, int y, int i):
        x(x), y(y), id(i){};
};

bool compX(const node &a, const node &b) {return a.x < b.x;}
bool compY(const node &a, const node &b) {return a.y < b.y;}

long long kruskal(int N, vector<edge> &es){
    long long totalCost = 0ll;
    sort(es.begin(), es.end());

    UnionFind uf = UnionFind(N);
    for(int i=0;i<es.size();i++){
        edge e = es[i];
        if(!uf.same(e.from, e.to)){
            totalCost += e.cost;
            uf.unite(e.from, e.to);
        }
    }
    return totalCost;
}

int main(){
    int N; cin >> N;
    vector<node> ns(N);
    int x,y;
    for(int i=0;i<N;i++){
        cin >> x >> y;
        ns[i] = node(x,y,i);
    }

    vector<edge> es;
    // sort X
    sort(ns.begin(), ns.end(), compX);
    for(int i=0;i<N-1;i++){
        edge e = edge(ns[i].id, ns[i+1].id, abs(ns[i].x - ns[i+1].x));
        es.push_back(e);
    }
    // sort Y
    sort(ns.begin(), ns.end(), compY);
    for(int i=0;i<N-1;i++){
        edge e = edge(ns[i].id, ns[i+1].id, abs(ns[i].y - ns[i+1].y));
        es.push_back(e);
    }

    cout << kruskal(N, es) << endl;
    return 0;
}