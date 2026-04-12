#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
struct edge{ll to,cost;};
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<=n;++i)
#define eachdo(e,array) for(const auto& e : array)
#define upper_index(v,a) (ll)distance(v.begin(), upper_bound((v).begin(),(v).end(),a))
#define lower_index(v,a) (ll)distance(v.begin(), lower_bound((v).begin(),(v).end(),a))
template<class T> bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
const int inf=1<<31-1;
const ll INF=1LL<<63-1;
const ll MOD=1e9+7;

struct Graph{
private:
    ll V;
    vector<vector<edge>> G;
    vector<vector<ll>> Gmat;
public:
    Graph(ll node){
        V=node;
        G.resize(V);
    }
    void add(ll from,ll to,ll cost=1){
        G[from].push_back({to,cost});
    }

    void toMatrix(){
        Gmat.resize(V);
        rep(i,V){
            Gmat[i].resize(V,INF);
            eachdo(e,G[i]){
                Gmat[i][e.to]=e.cost;
            }
        }
    }

    vector<ll> dijkstra(ll start){
        vector<ll> dist(V,INF);
        priority_queue<P,vector<P>,greater<P>> que;
        dist[start]=0;
        que.push(P(0,start)); 
        while(!que.empty()){
            P p=que.top();que.pop();
            ll v=p.second;
            if(dist[v]<p.first) continue;
            rep(i,G[v].size()){
                edge e = G[v][i];
                if(dist[v]+e.cost<dist[e.to]){
                    dist[e.to]=dist[v]+e.cost;
                    que.push(P(dist[e.to],e.to));
                }
            }
        }
        return dist;
    }
};

class UnionFind {
public:
    vector <ll> par; // 各元の親を表す配列
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }

    // Member Function
    // Find
    ll root(ll x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }

    // Union(Unite, Merge)
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y) { // 連結判定
        return root(x) == root(y);
    }

    ll size(ll x) { // 素集合のサイズ
        return siz[root(x)];
    }
};

struct SegmentTree{
private:
    ll unit=0;
    ll op(ll a,ll b){return a+b;}
    ll n;
    vector<ll> node;

public:
    SegmentTree(vector<ll> v){
        ll sz=(ll)v.size();
        n=1;while(n<sz) n*=2;
        node.resize(2*n-1,unit);
        for(ll i=0;i<sz;i++) node[i+n-1]=v[i];
        for(ll i=n-2;i>=0;i--) node[i]=op(node[2*i+1],node[2*i+2]);
    }

    void update(ll x,ll val){
        x+=n-1;
        node[x]+=val;
        while(x>0){
            x=(x-1)/2;
            node[x]=op(node[2*x+1],node[2*x+2]);
        }
    }

    ll query(ll a,ll b,ll k=0,ll l=0,ll r=-1){
        if (r<0) r=n;
        if (r<=a || b<=l) return unit;
        if (a<=l && r<=b) return node[k];
        ll vl = query(a,b,2*k+1,l,(l+r)/2);
        ll vr = query(a,b,2*k+2,(l+r)/2,r);
        return op(vl,vr);
    }
};

struct LazySegmentTree{
private:
    ll n;
    vector<ll> node,lazy;
public:
    LazySegmentTree(vector<ll> v){
        ll sz=(ll)v.size();
        n=1;while(n<sz) n*=2;
        node.resize(2*n-1);
        lazy.resize(2*n-1);
        for(ll i=0;i<sz;i++) node[i+n-1]=v[i];
        for(ll i=n-2;i>=0;i--) node[i]=node[2*i+1]+node[2*i+2];
    }

    void lazyEval(ll k,ll l,ll r){
        if(lazy[k]!=0){
            node[k]+=lazy[k];
            if(r-l>1){
                lazy[2*k+1]+=lazy[k]/2;
                lazy[2*k+2]+=lazy[k]/2;
            }
            lazy[k]=0;
        }
    }
    void update(ll a,ll b,ll x,ll k=0,ll l=0,ll r=-1){
        if(r<0) r=n;
        lazyEval(k,l,r);
        if(b<=l || r<=a) return;
        if(a<=l && r<=b){
            lazy[k]+=(r-l)*x;
            lazyEval(k,l,r);
        }
        else{
            update(a,b,x,2*k+1,l,(l+r)/2);
            update(a,b,x,2*k+2,(l+r)/2,r);
            node[k]=node[2*k+1]+node[2*k+2];
        }
    }

    ll query(ll a,ll b,ll k=0,ll l=0,ll r=-1){
        if(r<0) r=n;
        if(b<=l || r<=a) return 0; 

        lazyEval(k,l,r);
        if(a<=l && r<=b) return node[k];
        ll vl=query(a,b,2*k+1,l,(l+r)/2);
        ll vr=query(a,b,2*k+2,(l+r)/2,r);
        return vl+vr;
    }

    ll at(ll a){return query(a,a+1);}
};

ll modinv(ll a,ll m) {
    ll b=m,u=1,v=0;
    while(b){
        ll t=a/b;
        a-=t*b;
        swap(a,b);
        u-=t*v;
        swap(u,v);
    }
    u%=m;
    if(u<0) u+=m;
    return u;
}

void division(unordered_map<ll,ll> &hash,ll num){
    while(1<num){
        bool flag=true;
        ll t=(ll)pow(num,1/2.0)+1;
        for(ll i=2;i<t;++i){
            if(num%i==0){
                flag=false;
                if(!hash.count(i)){
                    hash[i]=1;
                }else{
                    hash[i]+=1;
                }
                num/=i;
                break;
            }
        }
        if(flag){
            if(!hash.count(num)){
                hash[num]=1;
            }else{
                hash[num]+=1;
            }
            return;
        }
    }
    return;
}

int main(){
    string N;cin>>N;
    ll K;cin>>K;
    vector<ll> S;
    eachdo(e,N) S.push_back(e-'0');
    ll siz=S.size();
    vector<vector<vector<ll>>> dp(siz+1,vector<vector<ll>>(2,vector<ll>(K+1,0)));
    dp[0][0][0]=1;
    rep(i,siz)rep(k,K+1)rep(x,10){

        if(x==0){
            if(S[i]==x) dp[i+1][0][k]+=dp[i][0][k];
            if(x<S[i]) dp[i+1][1][k]+=dp[i][0][k];
            dp[i+1][1][k]+=dp[i][1][k];
        }else{
            if(S[i]==x) dp[i+1][0][k]+=k==0 ? 0 : dp[i][0][k-1];
            if(x<S[i]) dp[i+1][1][k]+=k==0 ? 0 : dp[i][0][k-1];
            dp[i+1][1][k]+=k==0 ? 0 : dp[i][1][k-1];
        }
    }

 
    cout<<dp[siz][0][K]+dp[siz][1][K]<<endl;
    return 0;
}