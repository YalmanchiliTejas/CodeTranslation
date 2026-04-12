#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb emplace_back
#define INF (1LL<<59)

struct data{
    int y,x,num;
};

class UF{
private:
    vector<int> par,rank,elm;
    vector<vector<int>> elmList;	//don't be validated
public:
    int groups;
    
    UF(int __size):par(__size) , rank(__size,0) , elm(__size,1) , groups(__size), elmList(__size){
        rep(i,__size)elmList[i] = vector<int>(1,i);
        for(int i=0;i<__size;i++)par[i]=i;
    }
    
    int getElements(int n){ return elm[find(n)]; }
    vector<int> getElementsList(int n){ return elmList[find(n)]; }
    
    int find(int x){
        if(par[x]==x) {
            return x;
        }else{
            return par[x]=find(par[x]);
        }
    }
    
    void unite(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y) return;
        
        groups--;
        if(rank[x]<rank[y]){
            par[x]=y;
            elm[y]+=elm[x];
            for(auto &e:elmList[x])elmList[y].pb(e);
            
        }else{
            par[y]=x;
            elm[x]+=elm[y];
            for(auto &e:elmList[y])elmList[x].pb(e);
            if(rank[x]==rank[y])rank[x]++;
        }
    }
    
    bool isSame(int x,int y){
        return find(x)==find(y);
    }
};

#define MAX_V 100000
struct edge{int to,cost;};
int kruskal(int v, vector<edge> G[MAX_V]){
    int ret=0;
    vector<pair<int,pii>> edges;
    
    rep(i,MAX_V)for(auto &e:G[i])edges.pb(make_pair(e.cost,pii(i,e.to)));
    
    sort(all(edges));
    
    UF uf(v);
    rep(i,edges.size()){
        int c,u,v;
        c = edges[i].first;
        tie(u,v) = edges[i].second;
        
        if(!uf.isSame(u,v)){
            uf.unite(u,v);
            ret+=c;
        }
    }
    return ret;
}

int cost(data a, data b ){
    return min(abs(a.y-b.y),abs(a.x-b.x));
}

void add_edge( data a, data b, vector<edge> G[MAX_V] ){
    G[a.num].pb(edge{b.num,cost(a,b)});
    G[b.num].pb(edge{a.num,cost(a,b)});
}


signed main(){
    vector<edge> G[MAX_V];
    int n;
    cin>>n;

    vector<data> v(n);
    rep(i,n){
        int x,y;
        cin>>x>>y;
        v[i] = data{y,x,(int)i};
    }

    sort(all(v),[](data a, data b){ return a.y<b.y; });
    rep(i,v.size()){
        if(i-1>=0) add_edge(v[i],v[i-1], G);
        if(i+1<v.size()) add_edge(v[i],v[i+1], G);
    }

    sort(all(v),[](data a, data b){ return a.x<b.x; });
    rep(i,v.size()){
        if(i-1>=0) add_edge(v[i],v[i-1], G);
        if(i+1<v.size()) add_edge(v[i],v[i+1], G);
    }
    
    cout<<kruskal(n,G)<<endl;

}