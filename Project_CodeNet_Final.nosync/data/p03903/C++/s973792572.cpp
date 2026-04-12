#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

const i64 MOD = 1e9+7;

const i64 INF = 1e18+7;

class UnionFind{
public:
    int n, c;
    vector<int> par;
    UnionFind(int n) : n(n), c(0), par(n, -1){}
    int Find(int x){return par[x] < 0 ? x : Find(par[x]);}
    bool Unite(int x, int y){
        if((x = Find(x)) == (y = Find(y)))
            return false;
        if(par[x] > par[y])
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
        ++c;
        return true;
    }
};

signed main(){
    int n, m, q;
    cin >> n >> m;
    vector<vector<pair<int,int>>> edges(n);
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> que;
    for(int i = 0; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        edges[--a].emplace_back(--b, c);
        edges[b].emplace_back(a, c);
        que.emplace(c, make_pair(a, b));
    }
    i64 mst_cost = 0;
    UnionFind uni(n);
    vector<vector<pair<int,int>>> tr(n);
    while(uni.c != n - 1){
        int cost;
        pair<int,int> p;
        tie(cost, p) = que.top();
        que.pop();
        if(uni.Unite(p.first, p.second)){
            mst_cost += cost;
            tr[p.first].emplace_back(p.second, cost);
            tr[p.second].emplace_back(p.first, cost);
        }
    }
    vector<vector<int>> v(n, vector<int>(n, -1));
    function<void(int,int, int)> max_cost = [&](int from, int pos, int ma){
        for(auto& e : tr[pos]){
            if(v[from][e.first] == -1){
                int nex = max(e.second, ma);
                v[from][e.first] = nex;
                max_cost(from, e.first, nex);
            }
        }
    };
    for(int i = 0; i < n; ++i){
        v[i][i] = 0;
        max_cost(i, i, 0);
    }
    cin >> q;
    for(int i = 0; i < q; ++i){
        int s, t;
        cin >> s >> t;
        cout << mst_cost - v[--s][--t] << endl;
    }
}
