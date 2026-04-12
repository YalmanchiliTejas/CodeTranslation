#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
typedef pair<int, int> pii;
struct edge{int u, v, cost;};

bool comp(const edge& e1, const edge& e2){
    return e1.cost < e2.cost;
}

struct UnionFind {
  vector< int > data;
 
  UnionFind(int sz) {
    data.assign(sz, -1);
  }
 
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
 
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }
 
  int size(int k) {
    return (-data[find(k)]);
  }

  bool is_same(int x, int y){
    return find(x) == find(y);
  }
};

int main(){
    int n; cin >> n;
    vector<pii> v;
    map<pii, int> eid;
    vector<edge> g;
    rep(i,n){
        int x, y; cin >> x >> y;
        v.push_back(make_pair(x, y));
        eid[make_pair(x, y)] = i;
    }

    vector<pii> x_order;
    x_order = v;
    sort(ALL(x_order));
    int from, to; int cost;
    rep(i,n-1){
        from = eid[x_order[i]];
        to = eid[x_order[i+1]];
        cost = min(abs(x_order[i+1].second - x_order[i].second), abs(x_order[i+1].first - x_order[i].first));
        g.push_back((edge){from, to, cost});
    }

    vector<pii> y_order;
    y_order = v;
    rep(i,n) swap(y_order[i].first, y_order[i].second);
    sort(ALL(y_order));
    rep(i,n) swap(y_order[i].first, y_order[i].second);
    rep(i,n-1){
        from = eid[y_order[i]];
        to = eid[y_order[i+1]];
        cost = min(abs(y_order[i+1].second - y_order[i].second), abs(y_order[i+1].first - y_order[i].first));
        g.push_back((edge){from, to, cost});
    }

    sort(ALL(g), comp);
    UnionFind tree(n);
    ll ans = 0;
    rep(i, 2*n-2){
        edge e = g[i];
        if(!tree.is_same(e.u, e.v)){
            tree.unite(e.u, e.v);
            ans += (ll)e.cost;
        }
    }
    cout << ans << endl;
}