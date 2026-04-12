#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long
typedef pair<ll, ll> P;
typedef pair<ll, P> Edge;

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain; 

/* union find */
struct UnionFind {
    vector<int> par;
    UnionFind(int n) : par(n, -1) { }

    int find(int x) {
        if (par[x] < 0) return x;
        else return par[x] = find(par[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    void unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (-par[x] < -par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
    }
};

int main(){
    int n;
    cin >> n;

    vector<Edge> edges; /* コスト、どことどこ */
    vector<P> x_element;
    vector<P> y_element;
    vector<ll> x(n), y(n);

    REP(i, n) {
        cin >> x[i] >> y[i];
        x_element.push_back(make_pair(x[i], i));
        y_element.push_back(make_pair(y[i], i));
    }

    /* x座標で隣接してるもの */
    sort(x_element.begin(), x_element.end());
    REP(i, n-1) {
        ll cost = x_element[i+1].first - x_element[i].first;
        //cout << cost << endl;
        edges.push_back(Edge(cost, make_pair(x_element[i].second, x_element[i+1].second)));
    }

    /* y座標で隣接してるもの */
    sort(y_element.begin(), y_element.end());
    REP(i, n-1) {
        ll cost = y_element[i+1].first - y_element[i].first;
        //cout << cost << endl;
        edges.push_back(Edge(cost, make_pair(y_element[i].second, y_element[i+1].second)));
    }

    /* クラスカル法 */
    sort(edges.begin(), edges.end()); /* コストが小さい順にソート */
    UnionFind uf(n);
    ll ans = 0;
    for(auto e: edges){
        int u = e.second.second;
        int v = e.second.first;
        if(!uf.same(u, v)) {
            uf.unite(u, v);
            ans += e.first;
        }
    }

    cout << ans << endl;
    
    return 0;
}