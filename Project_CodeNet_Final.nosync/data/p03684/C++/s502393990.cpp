#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//V,P(大文字)使用不可

const ll INF=1e18;

const int max_E=200005;

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

struct edge{int u,v;ll cost;};

bool comp(const edge& e1,const edge& e2){
    return e1.cost<e2.cost;
}

edge es[max_E];
int N,M;

ll kruskal(){
    sort(es,es+M,comp);
    UnionFind tree(N);
    ll res=0;
    for(int i=0;i<M;i++){
        edge e=es[i];
        if(!tree.same(e.u,e.v)){
            tree.unite(e.u,e.v);
            res+=e.cost;
        }
    }
    return res;
}

signed main(){
    cin>>N;
    M=2*N-2;
    V<pair<ll,pair<ll,int>>> p(N),q(N);
    rep(i,N){
        ll x,y;
        cin>>x>>y;
        p[i]=make_pair(x,make_pair(y,i));
        q[i]=make_pair(y,make_pair(x,i));
    }
    sort(all(p));
    sort(all(q));
    V<pair<ll,pair<int,int>>> pq;
    rep(i,N-1){
        pq.push_back(make_pair(p[i+1].ft-p[i].ft,make_pair(p[i+1].sc.sc,p[i].sc.sc)));
        pq.push_back(make_pair(q[i+1].ft-q[i].ft,make_pair(q[i+1].sc.sc,q[i].sc.sc)));
    }
    sort(all(pq));
    int s=0;
    for(auto pp:pq){
        es[s].u=pp.sc.ft;
        es[s].v=pp.sc.sc;
        es[s].cost=pp.ft;
        s++;
    }
    cout<<kruskal()<<endl;
}