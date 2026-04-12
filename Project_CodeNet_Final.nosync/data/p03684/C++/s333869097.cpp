#include<bits/stdc++.h>
using namespace std;

using ll=long long;

class UnionFind{
    int N;
    vector<int> par;
    vector<int> rank;
    public:
    UnionFind(int N):N(N),par(N),rank(N,0){iota(par.begin(),par.end(),0);}
    int find(int x);
    void unite(int x,int y);
    bool same(int x,int y){return find(x)==find(y);}
};

int UnionFind::find(int x){
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}
void UnionFind::unite(int x,int y){
    x=find(x),y=find(y);
    if(x==y) return;
    if(rank[x]>=rank[y]){
        if(rank[x]==rank[y]) rank[x]++;
        par[y]=x;
    }else{
        par[x]=y;
    }
}

int main(){
    int n;
    cin>>n;
    vector<ll> x(n),y(n);
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];
    vector<pair<ll,int>> xid(n);
    vector<pair<ll,int>> yid(n);
    for(int i=0;i<n;i++){
        xid[i]={x[i],i};
        yid[i]={y[i],i};
    }
    sort(xid.begin(),xid.end());
    sort(yid.begin(),yid.end());
    using Edge=pair<ll,pair<int,int>>;
    vector<Edge> edges;
    for(int i=0;i<n-1;i++){
        edges.push_back(Edge{xid[i+1].first-xid[i].first,{xid[i].second,xid[i+1].second}});
        edges.push_back(Edge{yid[i+1].first-yid[i].first,{yid[i].second,yid[i+1].second}});
    }
    sort(edges.begin(),edges.end());
    UnionFind u(n);
    ll res=0;
    for(auto &e:edges){
        ll d=e.first;
        int a=e.second.first,b=e.second.second;
        if(!u.same(a,b)){
            u.unite(a,b);
            res+=d;
        }
    }
    cout<<res<<endl;
    return 0;
}