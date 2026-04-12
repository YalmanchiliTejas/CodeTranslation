#include <bits/stdc++.h>

#define int long long

using namespace std;
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
static const ll maxLL = (ll)1 << 62;
const ll MOD=1000000007,INF=1e18;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

int n,x[100010],y[100010];
struct UF{
    vector<int>par,sz;
    void init(int n){
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
        sz[x]+=sz[y];
        par[y]=x;
    }
    bool same(int x,int y){
        return find(x)==find(y);
    }
    int size(int x){
        return sz[find(x)];
    }
};
UF uf;
vector<pair<int,pint>> edge;
pair <pint,int> p1[100010],p2[100010];

signed main(){
    cin>>n;
    rep(i,0,n){
        int a,b;
        cin>>a>>b;
        p1[i]=pair<pint,int>(pint(a,b),i);
        p2[i]=pair<pint,int>(pint(b,a),i);
    }
    sort(p1,p1+n);sort(p2,p2+n);
    rep(i,0,n-1){
        pint p=p1[i].fi,q=p1[i+1].fi;
        int ct=min(abs(p.fi-q.fi),abs(p.se-q.se));
        edge.pb(pair<int,pint>(ct,pint(p1[i].se,p1[i+1].se)));
    }
    rep(i,0,n-1){
        pint p=p2[i].fi,q=p2[i+1].fi;
        int ct=min(abs(p.fi-q.fi),abs(p.se-q.se));
        edge.pb(pair<int,pint>(ct,pint(p2[i].se,p2[i+1].se)));
    }
    sort(edge.begin(),edge.end());
    int ans=0;
    uf.init(n+2);
    rep(i,0,edge.size()){
        pint p=edge[i].se;
        if(!uf.same(p.fi,p.se)){
            uf.unite(p.fi,p.se);
            ans+=edge[i].fi;
        }
    }
    cout<<ans<<endl;
    
    
    
    
    
    return 0;
}