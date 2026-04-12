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
//constexpr ll MOD=1e9+7;
//
constexpr ll MOD=998244353;
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
ll modpow(ll X,ll Y,ll mod){
    ll sum=X,cnt=1;
    vi A;
    while(cnt<=Y){
        A.pb(sum);
        sum*=sum;
        sum%=mod;
        cnt*=2;
    }
    int M=A.size();
    ll ret=1;
    REP(i,1,M){
        if(Y>=(1ll<<M-i)){
            Y-=(1ll<<M-i);
            ret*=A[M-i];
            ret%=mod;
        }
    }
    return ret;
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
    ll N; cin>>N;
    vector<pii> A(N);
    std::map<ll,ll> cnt1,cnt2;
    rep(i,0,N){
        cin>>A[i].first>>A[i].second;
        if(A[i].first>A[i].second) std::swap(A[i].first,A[i].second);
        cnt1[A[i].second]++;
        cnt2[A[i].first]++;
    }
    sort(ALL(A));
    ll ans=INF;
    rep(i,0,N){
        auto p=*rbegin(cnt1),q=*begin(cnt1),r=*rbegin(cnt2),s=*begin(cnt2);
        ans=std::min(ans,(p.first-q.first)*(r.first-s.first));
        ll X=A[i].first,Y=A[i].second;
        cnt2[X]--;
        if(cnt2[X]==0) cnt2.erase(X);
        cnt1[X]++;
        cnt1[Y]--;
        if(cnt1[Y]==0) cnt1.erase(Y);
        cnt2[Y]++;
    }
    cout<<ans<<endl;
}
