#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <utility>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int,int> pii;
class UnionFind {
private:
    int sz;
    vector<int> par, size_;
public:
    UnionFind(){}
    UnionFind(int node_size) : sz(node_size), par(sz), size_(sz, 1){
        rep(i,sz)par[i] = i;
    }
    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x,int y){
        x = find(x), y = find(y);
        if(x == y) return;
        if(size_[x] < size_[y]) swap(x,y);
        par[y] = x;
        size_[x] += size_[y];
    }
    int size(int x){
        x = find(x);
        return size_[x];
    }
    bool same(int x,int y){
        return find(x) == find(y);
    }
};
struct edge{
    int u,v;
    int cost;
};
bool operator<(const edge&a, const edge&b){
    return a.cost < b.cost;
}
int main(){
    int n;
    cin >> n;
    vector<pii>x(n);
    vector<pii>y(n);
    rep(i,n){
        cin >> x[i].first  >> y[i].first;
        x[i].second = y[i].second = i;
    }
    sort(x.begin(),x.end(),[&](pii a,pii b){return a.first < b.first;});
    sort(y.begin(),y.end(),[&](pii a,pii b){return a.first < b.first;});
    vector<edge>a;
    rep(i,n-1){
        a.push_back({x[i].second,x[i+1].second,x[i+1].first-x[i].first});
        a.push_back({y[i].second,y[i+1].second,y[i+1].first-y[i].first});    
    }
    sort(a.begin(),a.end());
    ll ans = 0;
    UnionFind uf(n);
    for(auto &e:a){
        if(uf.same(e.u,e.v))continue;
        uf.unite(e.u,e.v);
        ans += e.cost;
    }
    cout << ans << endl;
}