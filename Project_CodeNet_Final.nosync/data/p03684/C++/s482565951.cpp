#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,s,e) for (int i=s;i<(e);i++)
#define All(v) (v).begin(),(v).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define int long long
using namespace std;
typedef long long llint;
typedef pair<int, int> P;
const int MOD = (int)1e9 + 7;
const int INF = 999999999;


struct edge
{
    int from;
    int to;
    int cost;
    edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
};
typedef vector<edge> Edges;

struct UnionFind
{
    vector< int > data;
    
    UnionFind(int sz){
        data.assign(sz, -1);
    }
    
    bool unite(int x, int y){
        x = root(x), y = root(y);
        if(x == y) return false;
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }
    
    int root(int k){
        if(data[k] < 0) return(k);
        return (data[k] = root(data[k]));
    }
    
    int size(int k){
        return -data[root(k)];
    }
};

int Kruskal(Edges &E, int V){
    sort(All(E), [](const edge &a, const edge &b) {
        return (a.cost < b.cost);
    });

    UnionFind MST(V);
    int res = 0;
    for(auto e: E){
        if(MST.unite(e.from, e.to)) res += e.cost;
    }

    return res;
}


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<P> cityX, cityY;
    REP(i, N){
        int x, y;
        cin >> x >> y;
        cityX.pb(mp(x, i));
        cityY.pb(mp(y, i));
    }
    sort(All(cityX));
    sort(All(cityY));

    Edges E;
    REP(i, N-1) E.pb(edge(cityX[i].second, cityX[i+1].second, cityX[i+1].first - cityX[i].first));
    FOR(i, 1, N) E.pb(edge(cityX[i].second, cityX[i-1].second, cityX[i].first - cityX[i-1].first));

    REP(i, N-1) E.pb(edge(cityY[i].second, cityY[i+1].second, cityY[i+1].first - cityY[i].first));
    FOR(i, 1, N) E.pb(edge(cityY[i].second, cityY[i-1].second, cityY[i].first - cityY[i-1].first));

    cout << Kruskal(E, N) << "\n";
    return 0;
}