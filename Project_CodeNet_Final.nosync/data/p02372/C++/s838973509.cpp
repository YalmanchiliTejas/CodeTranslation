/*
O(E)
木の高さを求める
木の高さ:各頂点について、そこから最も遠い葉までの距離
verify:http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B&lang=ja
//(spaghetti sourceさんは違った)
http://www.prefield.com/algorithm/graph/tree_height.html
*/
#include <bits/stdc++.h>
using namespace std;
template<class T,class U>constexpr bool chmin(T&a,const U b){if(a<=b)return false;a=b;return true;}
template<class T,class U>constexpr bool chmax(T&a,const U b){if(a>=b)return false;a=b;return true;}


//辺 fromがない
template<typename T >
struct edge{
  int to;
  T cost;
  edge()=default;
  edge(int to, T cost) : to(to), cost(cost) {}
};
template<typename T>
using edges=vector<edge<T>>;
template<typename T>
using WeightGraph=vector<edges<T>>;

template<typename T>
pair<T,int> dfs(const WeightGraph<T> &g,int idx,int par,T dist,vector<T> &table){
    chmax(table[idx],dist);
    
    pair<T,int> ret={dist,idx};
    for(auto &e:g[idx]){
        if(e.to==par) continue;
        auto koho=dfs(g,e.to,idx,dist+e.cost,table);
        chmax(ret,koho);
    }
    return ret;
}

template<typename T>
vector<T> Height(const WeightGraph<T> &g){
    vector<T> ret(g.size(),0);
    pair<T,int> x;
    x.second=0;
    for(int i=0;i<3;i++){
        x=dfs(g,x.second,-1,0,ret);
    }
    return ret;
}

signed main(){
    int n;
    cin>>n;
    WeightGraph<int> g(n);
    for(int i=0;i<n-1;i++){
        int s,t,w;
        cin>>s>>t>>w;
        g[s].emplace_back(t,w);
        g[t].emplace_back(s,w);
    }
    auto ans=Height(g);
    for(int i=0;i<n;i++) cout<<ans[i]<<"\n";
}
