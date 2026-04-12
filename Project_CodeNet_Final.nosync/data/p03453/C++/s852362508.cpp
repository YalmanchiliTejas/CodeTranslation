#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MOD=1e9+7;

template<uint_fast64_t Modulus> class modint{
    using u64=uint_fast64_t;
    public:
    u64 a;
    constexpr modint(const u64 x=0) noexcept:a(((x%Modulus)+Modulus)%Modulus){}
    constexpr u64 &value() noexcept{return a;}
    constexpr const u64 &value() const noexcept{return a;}
    constexpr modint &operator+=(const modint &rhs) noexcept{
        a+=rhs.a;
        if (a>=Modulus) a-=Modulus;
        return *this;
    }
    constexpr modint operator+(const modint &rhs) const noexcept{
        return modint(*this)+=rhs;
    }
    constexpr modint &operator++() noexcept{
        return ++a,*this;
    }
    constexpr modint operator++(int) noexcept{
        modint t=*this; return ++a,t;
    }
    constexpr modint &operator-=(const modint &rhs) noexcept{
        if (a<rhs.a) a+=Modulus;
        a-=rhs.a;
        return *this;
    }
    constexpr modint operator-(const modint &rhs) const noexcept{
        return modint(*this)-=rhs;
    }
    constexpr modint &operator--() noexcept{
        return --a,*this;
    }
    constexpr modint operator--(int) noexcept{
        modint t=*this; return --a,t;
    }
    constexpr modint &operator*=(const modint &rhs) noexcept{
        a=a*rhs.a%Modulus;
        return *this;
    }
    constexpr modint operator*(const modint &rhs) const noexcept{
        return modint(*this)*=rhs;
    }
    constexpr modint &operator/=(modint rhs) noexcept{
        u64 exp=Modulus-2;
        while(exp){
            if (exp&1) *this*=rhs;
            rhs*=rhs; exp>>=1;
        }
        return *this;
    }
    constexpr modint operator/(const modint &rhs) const noexcept{
        return modint(*this)/=rhs;
    }
    constexpr modint operator-() const noexcept{
        return modint(Modulus-a);
    }
    constexpr bool operator==(const modint &rhs) const noexcept{
        return a==rhs.a;
    }
    constexpr bool operator!=(const modint &rhs) const noexcept{
        return a!=rhs.a;
    }
    constexpr bool operator!() const noexcept{return !a;}
    friend constexpr modint pow(modint rhs,long long exp) noexcept{
        modint res{1};
        while(exp){
            if (exp&1) res*=rhs;
            rhs*=rhs; exp>>=1;
        }
        return res;
    }
    template<class T> friend constexpr modint operator+(T x,modint y) noexcept{
        return modint(x)+y;
    }
    template<class T> friend constexpr modint operator-(T x,modint y) noexcept{
        return modint(x)-y;
    }
    template<class T> friend constexpr modint operator*(T x,modint y) noexcept{
        return modint(x)*y;
    }
    template<class T> friend constexpr modint operator/(T x,modint y) noexcept{
        return modint(x)/y;
    }
    friend ostream &operator<<(ostream &s,const modint &rhs) noexcept{
        return s << rhs.a;
    }
    friend istream &operator>>(istream &s,modint &rhs) noexcept{
        u64 a; rhs=modint{(s >> a,a)}; return s;
    }
};

using mint=modint<MOD>;

const int MAX=5e5+10;
vector<mint> fac(MAX),finv(MAX),inv(MAX);
void COMinit(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for (int i=2;i<MAX;++i){
        fac[i]=fac[i-1]*i;
        inv[i]=-inv[MOD%i]*(MOD/i);
        finv[i]=finv[i-1]*inv[i];
    }
}
mint COM(int n,int k){
    if (n<k||n<0||k<0) return 0;
    return fac[n]*finv[k]*finv[n-k];
}

// Be careful with the value of MAX and conducting COMinit()

template<typename T>
struct Dijkstra{
    const T inf=numeric_limits<T>::max();
    using P=pair<T,int>;
    int n;
    vector<vector<pair<int,T>>> G;
    vector<T> d;
    vector<mint> cnt;
    Dijkstra(int n):n(n),G(n),d(n),cnt(n){}
    void add_edge(int u,int v,T w){
        G[u].emplace_back(v,w);
    }
    void build(int s){
        fill(d.begin(),d.end(),inf);
        fill(cnt.begin(),cnt.end(),0);
        d[s]=0; cnt[s]=1;
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.emplace(d[s],s);
        while(!pq.empty()){
            P p=pq.top(); pq.pop();
            int v=p.second;
            if (d[v]<p.first) continue;
            for (auto &e:G[v]){
                int u=e.first; T c=e.second;
                if (d[v]+c<d[u]){
                    d[u]=d[v]+c;
                    cnt[u]=cnt[v];
                    pq.emplace(d[u],u);
                } else if (d[u]==d[v]+c) cnt[u]+=cnt[v];
            }
        }
    }
    vector<T> distance(int s){
        build(s);
        return d;
    }
    vector<mint> cnt_path(int s){
        build(s);
        return cnt;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M,S,T; cin >> N >> M >> S >> T;
    Dijkstra<ll> D(N);
    struct edge{
        int u,v; ll d;
        edge(int u,int v,ll d):u(u),v(v),d(d){}
    };
    vector<edge> es;
    for (int i=0;i<M;++i){
        int u,v; ll d; cin >> u >> v >> d; --u,--v;
        D.add_edge(u,v,d); D.add_edge(v,u,d);
        es.emplace_back(u,v,d);
    }
    vector<ll> ds=D.distance(--S),dt=D.distance(--T);
    vector<mint> cs=D.cnt_path(S),ct=D.cnt_path(T);
    vector<mint> cntv(N,0),cnte(M,0);
    ll dist=ds[T];
    for (int i=0;i<N;++i){
        if (ds[i]*2==dist&&dt[i]*2==dist){
            cntv[i]+=cs[i]*ct[i];
        }
    }
    for (int i=0;i<M;++i){
        auto e=es[i];
        if (ds[e.u]+e.d+dt[e.v]==dist&&ds[e.u]*2<dist&&dist<ds[e.v]*2){
            cnte[i]+=cs[e.u]*ct[e.v];
        }
        if (ds[e.v]+e.d+dt[e.u]==dist&&ds[e.v]*2<dist&&dist<ds[e.u]*2){
            cnte[i]+=cs[e.v]*ct[e.u];
        }
    }
    mint sum=0,ans=0;
    for (int i=0;i<N;++i) sum+=cntv[i];
    for (int i=0;i<M;++i) sum+=cnte[i];
    for (int i=0;i<N;++i) ans+=cntv[i]*(sum-cntv[i]);
    for (int i=0;i<M;++i) ans+=cnte[i]*(sum-cnte[i]);
    cout << ans << '\n';
}