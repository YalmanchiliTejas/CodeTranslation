#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
#define MAX_V 400010
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define ALL(c) (c).begin(),(c).end()
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}

#define INF 1e9+7
#define LLINF 1e18+7
ll MOD=1e9+7;
#define N 1055050

struct edge{
    int from,to;
    ll cost;
    bool operator<(const edge& e)const{
        return cost<e.cost;
    };
};
struct UnionFind{
    vector<int> par,sizes;
    UnionFind(int n):par(n+1),sizes(n+1,1){
        rep2(i,1,n)par[i]=i;
    }
    int find(int x){
        return (x==par[x]?x:par[x]=find(par[x]));
    }
    bool unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return false;
        if(sizes[x]<sizes[y]){
            swap(x,y);
        }
        par[y]=x;
        sizes[x]+=sizes[y];
        return true;
    }
    bool same(int x,int y) {return (find(x)==find(y));}
    int size(int x) {return sizes[find(x)];}
};
vector<vector<pll>> G(N);
ll kruskal(vector<edge> &edges,int v){
    sort(ALL(edges),[](edge a,edge b){
        return a.cost<b.cost;
    });
    UnionFind u(v+1);
    ll ret=0;
    for(auto e:edges){
        if(u.unite(e.from,e.to)){
            ret+=e.cost;
            G[e.from].pb({e.to,e.cost});
            G[e.to].pb({e.from,e.cost});
        }
    }
    return ret;
}
ll n,m;
ll d[5000][5000];
void dfs(int from,int now,int par,ll MAX){
    d[from][now]=MAX;
    for(auto e:G[now]){
        if(e.first!=par){
            dfs(from,e.first,now,max(MAX,e.second));
        }
    }
    return ;
}
main(){
    n=in();
    m=lin();
    vector<edge> ed;
    rep(i,m){
        int a=in(),b=in(),c=lin();
        ed.pb(edge{a,b,c});
    }
    ll MST=kruskal(ed,n);
    rep2(i,1,n){
        dfs(i,i,0,0);
    }
    int q=in();
    rep(iii,q){
        int s=in(),t=in();
        cout<<MST-d[s][t]<<endl;
    }
}