#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

struct UnionFindTree{
    vector<int>par,sz;
    UnionFindTree(int n){
        par.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            sz[i]=1;
        }
    }
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    void unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return;
        if(sz[x]<sz[y])swap(x,y);
        sz[x]+=sz[y];
        par[y]=x;
    }
    bool areSame(int x,int y){
        return find(x)==find(y);
    }
    int size(int x){
        return sz[find(x)];
    }
};

int N,M;
vpint G[4444];

int A[444444],B[444444],C[444444];

int cost[4444][4444];

void dfs(int v,int p,int c,int s){
    cost[s][v]=c;
    for(auto &e:G[v]){
        if(e.fi==p)continue;
        dfs(e.fi,v,max(c,e.se),s);
    }
}

signed main(){
    cin>>N>>M;

    vpint ord;
    rep(i,M){
        cin>>A[i]>>B[i]>>C[i];
        A[i]--;B[i]--;
        ord.pb({C[i],i});
    }
    sort(all(ord));

    int sum=0;
    UnionFindTree uf(N);
    rep(i,M){
        int w=ord[i].se;
        if(uf.areSame(A[w],B[w]))continue;
        uf.unite(A[w],B[w]);
        G[A[w]].pb({B[w],C[w]});
        G[B[w]].pb({A[w],C[w]});
        sum+=C[w];
    }

    rep(i,N)dfs(i,-1,0,i);

    int Q;cin>>Q;
    while(Q--){
        int a,b;
        cin>>a>>b;
        a--;b--;
        cout<<sum-cost[a][b]<<endl;
    }
    return 0;
}
