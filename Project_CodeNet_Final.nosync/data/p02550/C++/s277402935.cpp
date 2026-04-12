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
//
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
//constexpr ll MOD=1e4;
//constexpr ll MOD=1e5;
constexpr ll MAX=3e6;
constexpr ll inf=(1ll<<60);
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
        return std::max(A,B);
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
template<typename T>
struct lazy_Segment_tree{
    int N;
    vector<T> node,lazy;
    T INF;
    lazy_Segment_tree(vector<T> X,T Y):INF(Y){
        N=1;
        while(X.size()>N) N*=2;
        node.resize(2*N-1,Y);
        lazy.resize(2*N-1);
        rep(i,0,X.size()) node[i+N-1]=X[i];
        per(i,N-2,0) node[i]=compare(node[i*2+1],node[i*2+2]);
    }
    T compare(T X,T Y){
        return std::max(X,Y);
    }
    T plus(T X,int l,int r){
        return X;
    }
    void eval(int now,int l,int r){
        if(lazy[now]==0) return;
        node[now]+=lazy[now];
        if(r-l>1){
            lazy[now*2+1]+=plus(lazy[now],l,r);
            lazy[now*2+2]+=plus(lazy[now],l,r);
        }
        lazy[now]=0;
    }
    void update(int a,int b,T add,int now=0,int l=0,int r=-1){
        if(r<0) r=N;
        eval(now,l,r);
        if(b<=l||r<=a) return;
        if(a<=l&&r<=b){
            lazy[now]+=add;
            eval(now,l,r);
        }
        else{
            update(a,b,add,now*2+1,l,(r+l)/2);
            update(a,b,add,now*2+2,(r+l)/2,r);
            node[now]=compare(node[now*2+1],node[now*2+2]);
        }
    }
    T Query(int a,int b,int now=0,int l=0,int r=-1){
        if(r<0) r=N;
        eval(now,l,r);
        if(b<=l||r<=a) return INF;
        if(a<=l&&r<=b) return node[now];
        return compare(Query(a,b,now*2+1,l,(r+l)/2),Query(a,b,now*2+2,(r+l)/2,r));
    }
};
struct Tree{
    int N;
    vii dp;
    vi dist;
    Tree(vii edge){
        N=edge.size();
        dp.resize(N);
        dist.resize(N,-1);
        for(int i=0;i<N;i++) dp[i].resize(30);
        dist[0]=dp[0][0]=0;
        std::queue<int> que;
        que.push(0);
        while(!que.empty()){
            int now=que.front(); que.pop();
            for(int i=0;i<edge[now].size();i++){
                int next=edge[now][i];
                if(dist[next]==-1){
                    dist[next]=dist[now]+1;
                    que.push(next);
                    dp[next][0]=now;
                }
            }
        }
        for(int i=1;i<30;i++){
            for(int j=0;j<N;j++) dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }
    int LCA(int X,int Y){
        if(dist[X]<dist[Y]) std::swap(X,Y);
        {
            int Z=dist[X]-dist[Y];
            for(int i=0;i<30;i++){
                if(Z&(1<<i)){
                    X=dp[X][i];
                }
            }
        }
        if(X==Y) return X;
        for(int i=29;i>=0;i--){
            if(dp[X][i]!=dp[Y][i]){
                X=dp[X][i];
                Y=dp[Y][i];
            }
        }
        return dp[X][0];
    }
};
struct Binary_indexed_tree{
    int N;
    vi bit;
    Binary_indexed_tree(int n):N(n){
        bit.resize(N+1,0);
    }
    void add(int x,ll a){
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
void comp(vi &A){
    std::map<ll,ll> memo;
    rep(i,0,A.size()) memo[A[i]]=0;
    ll cnt=1;
    for(auto &p:memo) p.second=cnt++;
    rep(i,0,A.size()) A[i]=memo[A[i]];
}
void dec(std::map<ll,ll> &mem,ll X){
    mem[X]--;
    if(mem[X]==0) mem.erase(X);
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::random_device rnd;
    std::mt19937 mt(rnd()); 
    ll N,M,X; cin>>N>>X>>M;
    vi mem(1);
    vi sum(1);
    vi mem2(M,-1);
    mem2[X]=1;
    mem2[0]=0;
    mem.pb(X);
    sum.pb(X);
    ll ans;
    while(1){
        ll Y=modpow(mem[mem.size()-1],2,M);
        if(mem2[Y]==-1){
            mem.pb(Y);
            sum.pb(sum[sum.size()-1]+Y);
            mem2[Y]=mem.size()-1;
        }
        else{
            mem.pb(Y);
            sum.pb(sum[sum.size()-1]+Y);
            ll Z=mem.size()-1-mem2[Y];
            if(Y==0){
                ans=sum[std::min((ll)sum.size()-1,N)];
            }
            else if(mem2[Y]>=N){
                ans=sum[N];
            }
            else{
                ans=sum[mem2[Y]];
                ans+=(sum[sum.size()-1]-sum[mem2[Y]])*((N-mem2[Y])/Z);
                ans+=sum[(N-mem2[Y])%Z+mem2[Y]]-sum[mem2[Y]];
            }
            break;
        }
    }
    cout<<ans<<endl;
}
