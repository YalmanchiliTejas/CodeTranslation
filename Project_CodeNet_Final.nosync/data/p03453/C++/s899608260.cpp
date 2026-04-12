#include<bits/stdc++.h>
//using namespace std;
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define rep(i,j,n) for(ll i=(ll)(j);i<(ll)(n);i++)
#define REP(i,j,n) for(ll i=(ll)(j);i<=(ll)(n);i++)
#define per(i,j,n) for(ll i=(ll)(j);(ll)(n)<=i;i--)
#define ll long long
#define ALL(a) (a).begin(),(a).end()
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(ll)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(ll)(key)))
#define pb emplace_back
#define mp std::make_pair
#define endl "\n"
//using std::endl;
using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::upper_bound;
using std::lower_bound;
using vi=vector<ll>;
using vii=vector<vi>;
using pii=std::pair<ll,ll>;
//
constexpr ll MOD=1e9+7;
//constexpr ll MOD=998244353;
//constexpr ll MOD=10000000;
constexpr ll MAX=1e6;
constexpr ll INF=(1ll<<62);
template<class T>
class prique :public std::priority_queue<T, std::vector<T>, std::greater<T>> {};
struct Segment_tree{
    ll N;
    vector<pii> node;
    Segment_tree(ll sz){
        N=1;
        while(N<sz) N*=2;
        node.resize(2*N-1,mp(INF,INF));
        per(i,N-2,0){
            node[i]=std::min(node[i*2+1],node[i*2+1]);
        }
    }
    void update(ll X,pii val){
        X+=N-1;
        node[X]=val;
        while(X>0){
            X=(X-1)/2;
            node[X]=std::min(node[X*2+1],node[X*2+2]);
        }
    }
    pii RMQ(ll a,ll b,ll now,ll l,ll r){ //[a,b),[l,r)
        if(r<0) r=N;
        if(r<=a||b<=l) return mp(INF,INF);
        if(a<=l&&r<=b) return node[now];
        auto vl=RMQ(a,b,now*2+1,l,(l+r)/2),vr=RMQ(a,b,now*2+2,(l+r)/2,r);
        return std::min(vl,vr);
    }
};
struct Binary_indexed_tree{
    int N;
    vi bit;
    Binary_indexed_tree(int n):N(n){
        bit.resize(N+1,0);
    }
    void add(int x,int a){
        for(x;x<=N;x+=(x&-x)) bit[x]+=a;
    }
    ll sum(int x){
        ll ret=0;
        for(x;x>0;x-=(x&-x)) ret+=bit[x];
        return ret;
    }
    ll lower_bound(ll X){
        if(sum(N)<X) return -1;
        ll ret=0,memo=1,sum=0;
        while(memo*2<=N) memo*=2;
        while(memo>0){
            if(memo+ret<=N&&sum+bit[memo+ret]<X){
                sum+=bit[memo+ret];
                ret+=memo;
            }
            memo/=2;
        }
        return ret+1;
    }
};
struct Union_Find{
    ll N;
    vi par;
    vi siz;
    Union_Find(int n):N(n){
        par.resize(N);
        siz.resize(N,1);
        rep(i,0,N) par[i]=i;
    }
    ll root(ll X){
        if(par[X]==X) return X;
        return par[X]=root(par[X]);
    }
    bool same(ll X,ll Y){
        return root(X)==root(Y);
    }
    void unite(ll X,ll Y){
        X=root(X);
        Y=root(Y);
        if(X==Y) return;
        par[X]=Y;
        siz[Y]+=siz[X];
        siz[X]=0;
    }
    ll size(ll X){
        return siz[root(X)];
    }
};
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
vi fac,finv,inv;
void COMinit() {
    fac.resize(MAX);
    finv.resize(MAX);
    inv.resize(MAX);
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
ll COM(ll n,ll r){
    if(n<r||n<0||r<0) return 0;
    return fac[n]*finv[r]%MOD*finv[n-r]%MOD;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll N,M; cin>>N>>M;
    vector<vector<pii>> edge(N);
    vi p(2);
    rep(i,0,2) cin>>p[i];
    rep(i,0,M){
        ll X,Y,Z; cin>>X>>Y>>Z;
        edge[X-1].pb(mp(Y-1,Z));
        edge[Y-1].pb(mp(X-1,Z));
    }
    vii dist(2,vi(N,INF));
    rep(i,0,2){
        prique<pii> que;
        que.push(mp(0,p[i]-1));
        dist[i][p[i]-1]=0;
        while(!que.empty()){
            ll X=que.top().second,Y=que.top().first;
            que.pop();
            rep(j,0,edge[X].size()){
                ll P=edge[X][j].first,Q=edge[X][j].second+Y;
                if(dist[i][P]>Q){
                    dist[i][P]=Q;
                    que.push(mp(Q,P));
                }
            }
        }
    }
    vii dp(2,vi(N));
    rep(i,0,2){
        dp[i][p[i]-1]=1;
        vector<pii> C(N);
        rep(j,0,N) C[j]=mp(dist[i][j],j);
        sort(ALL(C));
        rep(j,0,C.size()){
            ll X=C[j].second,Y=C[j].first;
            rep(k,0,edge[X].size()){
                ll Z=edge[X][k].first;
                if(dist[0][Z]+dist[1][Z]==dist[0][p[1]-1]&&dist[i][Z]-dist[i][X]==edge[X][k].second){
                    dp[i][Z]+=dp[i][X];
                    dp[i][Z]%=MOD;
                }
            }
        }
    }
    ll ans=dp[0][p[1]-1]*dp[1][p[0]-1]%MOD;
    rep(i,0,N){
        if(dist[0][i]+dist[1][i]==dist[0][p[1]-1]&&dist[0][i]==dist[1][i]){
            ans=(ans+MOD-dp[0][i]*dp[1][i]%MOD*dp[0][i]%MOD*dp[1][i]%MOD)%MOD;
        }
    }
    rep(i,0,N){
        if(dist[0][i]+dist[1][i]!=dist[0][p[1]-1]) continue;
        if(dist[0][i]>=dist[1][i]) continue;
        rep(j,0,edge[i].size()){
            ll X=edge[i][j].first;
            if(dist[0][i]+dist[1][X]+edge[i][j].second==dist[0][p[1]-1]&&dist[1][X]*2<dist[0][p[1]-1]){
                ans=(ans+MOD-dp[0][i]*dp[1][X]%MOD*dp[0][i]%MOD*dp[1][X]%MOD)%MOD;
            }
        }
    }
    cout<<ans<<endl;
}