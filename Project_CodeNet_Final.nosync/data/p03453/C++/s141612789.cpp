#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
//MINT
// modint: mod 計算を int を扱うように扱える構造体
template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) v += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr istream& operator >> (istream &is, Fp<MOD>& x) noexcept {
        return is >> x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};
const int MOD = 1000000007;
using mint = Fp<MOD>;
//MINT

vector<mint> path,patr;

vector<ll> dijkstraSpecial(int s,vector<vector<pair<int,ll>>> &G){
    using P=pair<ll,int>;
    int n=G.size();
    vector<ll> d(n,LINF);
    vector<int> b(n,-1);//previous point
    priority_queue<P,vector<P>,greater<P>> q;
    d[s]=0;path[s]=1;
    q.emplace(d[s],s);

    while(!q.empty()){
        P p=q.top();q.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(auto& e:G[v]){
            int u=e.first;
            ll c=e.second;
            if(d[u]>d[v]+c){
                d[u]=d[v]+c;
                path[u]=path[v];
                b[u]=v;
                q.emplace(d[u],u);
            }
            else if(d[u]==d[v]+c){
                path[u]+=path[v];
            }
        }
    }
    return d;
}

vector<ll> dijkstraUltra(int s,vector<vector<pair<int,ll>>> &G){
    using P=pair<ll,int>;
    int n=G.size();
    vector<ll> d(n,LINF);
    vector<int> b(n,-1);//previous point
    priority_queue<P,vector<P>,greater<P>> q;
    d[s]=0;patr[s]=1;
    q.emplace(d[s],s);

    while(!q.empty()){
        P p=q.top();q.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(auto& e:G[v]){
            int u=e.first;
            ll c=e.second;
            if(d[u]>d[v]+c){
                d[u]=d[v]+c;
                patr[u]=patr[v];
                b[u]=v;
                q.emplace(d[u],u);
            }
            else if(d[u]==d[v]+c){
                patr[u]+=patr[v];
            }
        }
    }
    return d;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m;cin>>n>>m;
    int s,t;cin>>s>>t;s--,t--;
    vector<vector<pair<int,ll>>> g(n);
    rep(i,m){
        int u,v;ll c;cin>>u>>v>>c;u--,v--;
        g[u].push_back(make_pair(v,c));
        g[v].push_back(make_pair(u,c));
    }
    path=vector<mint>(n,0);
    patr=vector<mint>(n,0);
    auto dis=dijkstraSpecial(s,g);
    auto dir=dijkstraUltra(t,g);
    ll mindis=dis[t];

    mint ans=path[t]*patr[s];
    // cout<<ans<<endl;
    rep(u,n){
        if(dis[u]*2==mindis and dis[u]+dir[u]==mindis){
            ans-=path[u]*path[u]*patr[u]*patr[u];
            // cout<<"point: "<<u<<endl;
        }
        for(auto x:g[u]){
            int v=x.first;
            ll cost=x.second;
            // この辺が最短経路で使われないなら知らない
            if(dis[u]+cost+dir[v]!=mindis) continue;
            if(2*dis[v]>mindis&&2*dis[u]<mindis){
                ans-=path[u]*patr[v]*patr[v]*path[u];
                // cout<<"edge "<<u<<' '<<v<<endl;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
