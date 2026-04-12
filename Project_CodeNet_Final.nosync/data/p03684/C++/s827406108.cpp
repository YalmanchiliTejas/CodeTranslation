#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
vector<P> x, y;
int n;
class Edge{
public:
        long long cost;
        int from, to;
        Edge(long long c, int f, int t){
                cost = c;
                from = f;
                to = t;
        }
};
vector<Edge> v;
bool operator < (const Edge &e, const Edge &f){
        return e.cost != f.cost ? e.cost < f.cost : e.from != f.from ? e.from < f.from : e.to < f.to;
}
class UnionFind{
public:
        vector<int> Parent;
        vector<int> Rank;
        UnionFind(int n){
                ++n;
                Parent.resize(n, 0);
                Rank.resize(n, 0);
                for(int i=0; i<n; ++i)
                        Parent[i] = i;
        }

        int find(int x){
                if(Parent[x] == x) return x;
                return Parent[x] = find(Parent[x]);
        }

        void unite(int x, int y){
                x = find(x);
                y = find(y);
                if(x == y) return;
                if(Rank[x] < Rank[y]) Parent[x] = y;
                else{
                        Parent[y] = x;
                        if(Rank[x] == Rank[y]) ++Rank[x];
                }
        }

        bool same(int x, int y){
                return find(x) == find(y);
        }
};

int main(){
//      cin.tie(0);
//      ios::sync_with_stdio(false);
        cin >> n;
        for(int i=0; i<n; ++i){
                int s, t;
                cin >> s >> t;
                x.push_back(P(s, i));
                y.push_back(P(t, i));
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        for(int i=0; i<n-1; ++i){
                v.push_back(Edge(x[i+1].first - x[i].first, x[i].second, x[i+1].second));
                v.push_back(Edge(y[i+1].first - y[i].first, y[i].second, y[i+1].second));
        }
        sort(v.begin(), v.end());
//      for(auto e:v)
//              cout << e.cost << " " << e.from << " " << e.to << "\n";
        UnionFind uf(n);
        long long ans = 0;
        for(int i=0; i+1<v.size(); ++i){
                if(!uf.same(v[i].from, v[i].to)){
                        ans += v[i].cost;
                        uf.unite(v[i].from, v[i].to);
                }
        }
        cout << ans << "\n";
}