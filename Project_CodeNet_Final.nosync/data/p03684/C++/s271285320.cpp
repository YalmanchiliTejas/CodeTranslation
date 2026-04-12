#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=acos(-1);
const ll MOD=1e9+7;
const ll INF=(1LL<<60);

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};

struct edge{
    int u,v;
    ll cost;
};
bool comp(const edge& e1,const edge& e2){
    return e1.cost<e2.cost;
}

int n,e;
edge es[200010];

int kruskal(){
    sort(es,es+e,comp);
    UnionFind uf(n+1);
    ll res=0;
    for (int i=0;i<e;i++){
        edge e1=es[i];
        if (!uf.issame(e1.u,e1.v)){
            uf.merge(e1.u,e1.v);
            res+=e1.cost;
        }

    }
    return res;
}

int main() {
    cin>>n;
    vector<tuple<ll,ll,int>> vx,vy;
    rep(i,n){
        ll x,y;
        cin>>x>>y;
        vx.push_back(make_tuple(x,y,i));
        vy.push_back(make_tuple(y,x,i));
    }
    sort(all(vx));
    sort(all(vy));
    rep(i,n-1){
        ll x1=get<0>(vx[i]),x2=get<0>(vx[i+1]);
        int i1=get<2>(vx[i]),i2=get<2>(vx[i+1]);
        edge e1={i1,i2,abs(x1-x2)};
        es[i]=e1;
    }
    rep(i,n-1){
        ll x1=get<0>(vy[i]),x2=get<0>(vy[i+1]);
        int i1=get<2>(vy[i]),i2=get<2>(vy[i+1]);
        edge e1={i1,i2,abs(x1-x2)};
        es[i+n-1]=e1;
    }
    e=2*n-2;
    ll ans=kruskal();
    cout<<ans<<endl;

    

    return 0;
}