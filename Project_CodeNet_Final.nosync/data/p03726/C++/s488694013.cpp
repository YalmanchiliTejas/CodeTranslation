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
//#define endl "\n"
//
using std::endl;
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
//constexpr ll MOD=998244353;
//constexpr ll MOD=10000000;
//
constexpr ll MOD=1e5;
constexpr ll MAX=1e6;
constexpr ll INF=(1ll<<62);
template<class T>
class prique :public std::priority_queue<T, std::vector<T>, std::greater<T>> {};
template<typename T>
struct Segment_tree{
    ll N;
    T mem;
    vector<T> node;
    Segment_tree(vector<T> &X,T m):mem(m){
        ll sz=X.size();
        N=1;
        while(N<sz) N*=2;
        node.resize(2*N-1,mem);
        rep(i,0,sz) node[N-1+i]=X[i];
        per(i,N-2,0){
            node[i]=Compare(node[i*2+1],node[i*2+2]);
        }
    }
    T Compare(T &A,T &B){
        return std::min(A,B);
    }
    void update(ll X,T val){
        X+=N-1;
        node[X]=val;
        while(X>0){
            X=(X-1)/2;
            node[X]=Compare(node[X*2+1],node[X*2+2]);
        }
    }
    T Query(ll a,ll b,ll now,ll l,ll r){ //[a,b),[l,r)
        if(r<0) r=N;
        if(r<=a||b<=l) return mem;
        if(a<=l&&r<=b) return node[now];
        auto vl=Query(a,b,now*2+1,l,(l+r)/2),vr=Query(a,b,now*2+2,(l+r)/2,r);
        return Compare(vl,vr);
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
ll dfs(ll X,vector<bool> &F,vii &edge,string &ans){
    bool flag=1;
    vi c(2);
    rep(i,0,edge[X].size()){
        ll Y=edge[X][i];
        if(F[Y]){
            flag=0;
            F[Y]=0;
            auto p=dfs(Y,F,edge,ans);
            c[p]++;
        }
    }
    if(flag){
        return 0;
    }
    if(c[0]>1) ans="First";
    if(c[0]==0) return 0;
    return 1;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll N; cin>>N;
    vii edge(N);
    rep(i,1,N){
        ll X,Y; cin>>X>>Y;
        edge[X-1].pb(Y-1);
        edge[Y-1].pb(X-1);
    }
    string ans="Second";
    vector<bool> F(N,1);
    rep(i,0,N){
        if(edge[i].size()>1){
            F[i]=0;
            auto p=dfs(i,F,edge,ans);
            if(!p&&N%2==1) ans="First";
            break;
        }
    }
    cout<<ans<<endl;
}
