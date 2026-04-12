#include <bits/stdc++.h>
#define INF 1e+9
#define MOD (int)1e9+7
#define debug(x) cerr << #x << ": " << x << "\n";
using namespace std;
using ll = long long;
using P = pair<int, int>;

template <size_t N>
class unionFindTree{
    private:
        int par[N];
        int rank[N];
    public:
        unionFindTree(){
            for(int i = 0; i < (int) N; i++){
                par[i] = i;
                rank[i] = 0;
            }
        }
        void init(){
            for(int i = 0; i < (int) N; i++){
                par[i] = i;
                rank[i] = 0;
            }
        }
        int find(int x){
            if(par[x] == x){
                return x;
            }else{
                return par[x] = find(par[x]);
            }
        }
        void unite(int x, int y){
            x = find(x);
            y = find(y);
            if(x == y) return;

            if(rank[x] < rank[y]){
                par[x] = y;
            }else{
                par[y] = x;
                if(rank[x] == rank[y]) rank[x]++;
            }
        }
        bool same(int x, int y){
            return find(x) == find(y);
        }
};

P x[100000], y[100000];
unionFindTree<100000> uf;
struct edge{
    int from, to, cost;
};

int main(void){
    int N; cin >> N;
    int inx, iny;
    for(int i = 0; i < N; i++){
        cin >> inx >> iny;
        x[i].first = inx; x[i].second = i;
        y[i].first = iny; y[i].second = i;
        // debug(i);debug(inx);debug(iny);debug(x[i].first);
    }
    sort(x, x + N); sort(y, y + N);

    // for(int i = 0; i < N; i++){
    //     debug(x[i].first); debug(x[i].second);
    // }
    // for(int i = 0; i < N; i++){
    //     debug(y[i].first); debug(y[i].second);
    // }

    vector<edge> es;
    for(int i = 0; i < N - 1; i++){
        edge e1 = {x[i].second, x[i+1].second, abs(x[i].first - x[i+1].first)};
        edge e2 = {y[i].second, y[i+1].second, abs(y[i].first - y[i+1].first)};
        es.push_back(e1); es.push_back(e2);
    }
    sort(begin(es), end(es), [](edge e1, edge e2){return e1.cost < e2.cost;});

    ll res = 0;

    // for(int i = 0; i < N; i++){
    //     debug(es[i].from); debug(es[i].to); debug(es[i].cost);
    // }

    for(auto e: es){
        if(uf.same(e.from, e.to)) continue;
        uf.unite(e.from, e.to);
        res += e.cost;
    }

    cout << res << '\n';
    return 0;
}