#include<bits/stdc++.h>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// 定数たち
const ll INF = 1e18;
const double PI = 3.14159265358979323846264338327950;

//最大公約数
ll gcd(ll x, ll y) {
    ll tmp = 0;
    if (x < y){
        tmp=x;
        x=y;
        y=tmp;
    }
    while (y > 0) {
        ll r = x % y;
        x = y;
        y = r;
        }
    return x;
}

//最大公倍数
ll lcm(ll x,ll y){
    return x/gcd(x,y)*y;
}

const int MAX = 1e6+1;
const ll MOD = 1e9+7;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

struct mint {
  ll x; // typedef long long ll;
    mint(ll x=0):x((x%MOD+MOD)%MOD){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
    }
    mint& operator-=(const mint a) {
    if ((x += MOD-a.x) >= MOD) x -= MOD;
    return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime MOD
    mint inv() const {
        return pow(MOD-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
};

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


//階乗
ll kaijo(ll k){
    ll sum = 1;
    for (ll i = 1; i <= k; ++i)
    {
        sum *= i;
        sum%=1000000000+7;
    }
    return sum;
}

long long modpow(long long a, long long n, long long MOD) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

struct UnionFind {
    vector<int> par;
    UnionFind(int n) : par(n, -1) { }
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    ll size(int x) {
        return -par[root(x)];
    }
};

// 二項係数（大きい値用）
ll count(int n, int a){
    ll bunshi = 1;
    for(int i = 0; i < a; i++){
        bunshi*=(n-i);
        bunshi%=MOD;
    }
    ll bunbo = 1;
    for(int i = 1; i < a+1; i++){
        bunbo*=i;
        bunbo%=MOD;
    }
    bunbo = modpow(bunbo,MOD-2,MOD);
    return (bunshi*bunbo)%MOD;
}

// 約数列挙。約数をvector<ll>で返す。計算量はsqrt(n)。
vector<ll> divisor(ll n) {
    vector<ll> ret;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
        ret.push_back(i);
        if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}


// グラフ
struct edge{ll to, cost;};
// typedef pair<ll,ll> P;
struct graph{
    ll V;
    vector<vector<edge> > G;
    vector<ll> d;

    graph(ll n){
        init(n);
    }

    void init(ll n){
        V = n;
        G.resize(V);
        d.resize(V);
        rep(i,V){
        d[i] = INF;
        }
    }

    void add_edge(ll s, ll t, ll cost){
        edge e;
        e.to = t, e.cost = cost;
        G[s].push_back(e);
    }

    void dijkstra(ll s){
        rep(i,V){
            d[i] = INF;
        }
        d[s] = 0;
        priority_queue<P,vector<P>, greater<P> > que;
        que.push(P(0,s));
        while(!que.empty()){
            P p = que.top(); que.pop();
            ll v = p.second;
            if(d[v]<p.first) continue;
            for(auto e : G[v]){
                if(d[e.to]>d[v]+e.cost){
                d[e.to] = d[v]+e.cost;
                que.push(P(d[e.to],e.to));
                }
            }
        }
    }
};



// ここから開始
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main(){
    int N;
    cin>>N;
    vector<ll> a(N);
    rep(i,N) cin>>a[i];

    vector<ll> sm(N+1,0);
    rep(i,N) {
        sm[i+1] = a[i]+sm[i];
        sm[i+1]%=MOD;
    }
    ll ans = 0;
    for(int i = 1; i < N; i++){
       ans+=(sm[i]*a[i])%MOD;
       ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}