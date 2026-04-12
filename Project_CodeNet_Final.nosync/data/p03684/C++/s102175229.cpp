#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <functional>
#include <tuple>

using namespace std;
using ll = long long;

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)

using pii = pair<int,int>;
using tiii = tuple<int,int,int>;

struct Union_find{
    vector<int> par,rank;

//
    void init (int n){
        par.resize(n);
        rank.resize(n);
        rep(i,n){
            par[i] =i;
            rank[i] = 0;
        }
    }

//親を探索
    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

//併合
    void unite(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return;//両方とも親が同じ

        if(rank[x] < rank[y]) par[x] = y;//小さいものから大きいものへ辺をはる
        else{
            par[y] = x;
            if(rank[x] == rank[y]) rank[x]++;//高さが同じ
        }
    }

    bool same(int x,int y){
        return find(x) == find(y);
    }
};

/*
必要な辺？
頂点集合について、x,yでソートしたものを用意する。

*/

struct edge{int u,v,cost;};
const int MAX_E = 2e5+10;
edge es[MAX_E];

int main(){
    int n;
    cin >> n;//頂点数

    vector<tiii> v,sort_x,sort_y;
    int x,y;
    rep(i,n){
        cin >> x >> y;
        v.push_back(make_tuple(i,x,y));
    }

    sort(v.begin(),v.end(),[](const tiii& a,const tiii& b){return get<1>(a) < get<1>(b); });
    sort_x = v;//xについてソート
    sort(v.begin(),v.end(),[](const tiii& a,const tiii& b){return get<2>(a) < get<2>(b); });
    sort_y = v;//yについてソート

    rep(i,n-1){
        es[2*i] = {get<0>(sort_x[i]),get<0>(sort_x[i+1]),abs(get<1>(sort_x[i]) - get<1>(sort_x[i+1]))};//i->i+1へのx方向の辺
        es[2*i+1] = {get<0>(sort_y[i]),get<0>(sort_y[i+1]),abs(get<2>(sort_y[i]) - get<2>(sort_y[i+1])) };//i->i+1へのy方向の辺
    }
    sort(es,es+2*(n-1),[](const edge& e1,const edge& e2){return e1.cost < e2.cost;});
    
    Union_find uf;
    uf.init(n);
    int res = 0;

    rep(i,2*(n-1)){
        edge e = es[i];
        if(!uf.same(e.u,e.v)){
            uf.unite(e.u,e.v);
            res += e.cost;
        }
    }
    cout << res << endl;

    return 0;
}