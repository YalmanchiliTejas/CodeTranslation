#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using pll = pair<ll,ll>;
using Graph = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i,l,r) for(ll i = (l); i <= (ll)(r); i++)
#define rep3(i,l,r) for(ll i = (l); i >= (ll)(r); i--)
#define dup(x,y) (((x)+(y)-1)/(y)) // x/yの除算の切り上げ
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int inf = 1001001001;
const ll INF = 1LL << 60;
const ll mod = 1000000007; //1000000007;
const ld pi = acos(-1);
 
//xor演算
//a^b=b^a
//a^(b^c)=(a^b)^c
//a^a=0
//a+b=a^b + 2(a&b)
//(4a)^(4a+1)^(4a+2)^(4a+3)=0
 
 
// map<string,int> aのvalueが最大のkeyがmaxv.firstで求められる
// auto maxv = *max_element(a.begin(), a.end(), [](auto lhs, auto rhs) { return lhs.second < rhs.second; });
 
// union by size + path having
// 最初にUnionFind a(n);で宣言
class UnionFind {
public:
    vector <ll> par; // 各元の親を表す配列
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)
 
    // Constructor
    UnionFind(ll sz_): par(sz_),siz(sz_, 1LL){
        for (ll i=0; i<sz_; i++) par[i]=i; // 初期では親は自分自身
    }
    void init(ll sz_){
        par.resize(sz_);
        siz.assign(sz_, 1LL);
        for (ll i=0; i<sz_; i++) par[i]=i; // 初期では親は自分自身
    }
 
    // Member Function
    // Find
    ll root(ll x){ // 根の検索
        while (par[x]!=x){
            x=par[x]=par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }
 
    // Union(Unite, Merge)
    bool unite(ll x, ll y){
        x=root(x);
        y=root(y);
        if (x==y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける)
        if (siz[x]<siz[y]) swap(x, y);
        siz[x]+=siz[y];
        par[y]=x;
        return true;
    }
 
    bool same(ll x, ll y){ // 連結判定
        return root(x)==root(y);
    }
 
    ll size(ll x){ // 素集合のサイズ
        return siz[root(x)];
    }
};
 
//セグメント木
//全て添字で扱うこと
// segment_tree seg;
// seg.build(配列名, 単位元)で宣言
// seg.build(a,0)
struct segment_tree{
    ll n; //vの要素数
    ll m; //葉の数
    vector<ll> v; //セグ木本体．ただの配列を使う
    ll id_e; //単位元 区間の和なら0、区間の積なら1、最大値なら-1とか、最小値ならINF、最大公約数なら0
 
    //二項演算
    ll binary_op(ll a,ll b){
        return a+b;//処理 区間の和ならa+b、区間の積ならa*b、最大値ならmax(a,b)、最初値ならmin(a,b)、最大公約数ならgcd(a,b)
    }
 
    //初期化関数．数列と単位元を受け取って初期化
    void build(vector<ll> a,ll b){
        id_e = b;
        m = 1;
        while(m<(ll)a.size()) m*=2; //aの項数以上の2べきのうち最小のものを求める
        n = 2*m-1;
        v.resize(n);
        for (ll i=0; i<(ll)a.size(); i++) v[m-1+i]=a[i]; //葉(1段目)の値
        for (ll i=a.size(); i<m; i++) v[m-1+i]=id_e; //葉(1段目)の右端の0埋め
        for (ll i=m-2; i>=0; i--){ //2段目以降を順番に埋めていく
        v[i]=binary_op(v[2*i+1],v[2*i+2]);
        }
    }
 
    //ある項の値をbに書き換え
    void update(ll a,ll b) {
        a+=(m-1);
        v[a]=b; //葉(1段目)を書き換え
        while((a-1)/2 != a){ //2段目以降を順番に書き換え
            a=(a-1)/2;
            v[a]=binary_op(v[2*a+1],v[2*a+2]);
        }
    }
 
    //区間和の補助関数
    //cur:今見ている頂点の，配列vでの添字
    //[l, r]:v[cur]がカバーする区間
    ll seg_sub(ll a,ll b,ll cur,ll l,ll r){
        if(a<=l && r<=b) return v[cur]; //今見ている頂点のカバーする区間が，[a,b]に完全に収まっている場合
        if(r<a || b<l) return id_e; //今見ている頂点のカバーする区間が，[a,b]と全く被っていない場合
        return binary_op( //今見ている頂点のカバーする区間が，[a,b]と一部被っている場合
            seg_sub(a,b,2*cur+1,l,(l+r)/2),
            seg_sub(a,b,2*cur+2,(l+r)/2+1,r)
        );
    }
 
    //区間[a, b]の和
    //最上段の頂点から子へ再帰していく
    ll partial_sum(ll a,ll b){return seg_sub(a,b,0,0,m-1);}
    };
 
// graph_d g(n);でn頂点のグラフを作成
// g.add_edge(a,b,cost);で頂点aから頂点bへのコストcostの辺が張られる
// g.dijkstra(s);で頂点sから各頂点への最短経路をダイクストラ法で探索できる
// ll dist=g.d[i];で探索結果を呼び出すことができる
struct edge{ll to, cost;};
struct graph_d{
    ll V;
    vector<vector<edge> > G;
    vector<ll> d;
 
    graph_d(ll n){
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
    priority_queue<pll,vector<pll>, greater<pll> > que;
    que.push(pll(0,s));
    while(!que.empty()){
        pll p = que.top(); que.pop();
        ll v = p.second;
        if(d[v]<p.first) continue;
        for(auto e : G[v]){
            if(d[e.to]>d[v]+e.cost){
                d[e.to] = d[v]+e.cost;
                que.push(pll(d[e.to],e.to));
            }
        }
    }
}
};
 
ll modpow(ll x,ll n){
    x=x%mod;
    if(n==0) return 1;
    else if(n%2==1){
        return (x*modpow(x,n-1))%mod;
    }
    else return modpow((x*x)%mod,n/2)%mod;
}
 
ll modcom(ll n,ll k){
    ll x=1;
    for(ll i=n-k+1; i<=n; i++){
        x=x*i%mod;
    }
    ll y=1;
    for(ll i=1; i<=k; i++){
        y=y*i%mod;
    }
    y=modpow(y,mod-2);
    return x*y%mod;
}
 
bool is_prime(ll n){
    switch(n){
        case 0:
        case 1: return false;
        case 2:
        case 3: return true;
    }
    if(n%2==0 || n%3==0) return false;
    for(ll i=5; i*i<=n; i+=6){
        if(n%i==0) return false;
        if(n%(i+2)==0) return false;
    }
    return true;
}
 
ll digsum(ll n){
    int res=0;
    while(n > 0){
       res+=n%10; //res++;だと桁数を求める関数,res+=n%10;なら格桁の和を求める関数
       n/=10;
    }
    return res;
}
 
vector<ll> divisor(ll n){
    vector<ll> ret;
    for(ll i=1; i*i<=n; i++){
        if(n%i==0){
            ret.push_back(i);
            if(i*i!=n) ret.push_back(n/i);
        }
    }
    sort(ret.begin(),ret.end());
    return ret;
}
 
vector<ll> divisor_cnt(ll n){
    vector<ll> cnt(n);
    for(ll i=1; i<=n; i++){
        for(ll j=i; j<=n; j+=i){
            cnt[j]++;
        }
    }
    return cnt;
}
 
map<ll,ll> prime_factor(ll n){
    map<ll,ll> res;
    res[1]=1;
    for(ll i=2; i*i<=n; i++){
        while(n%i==0){
            res[i]++;
            n/=i;
        }
    }
    if(n!=1) res[n]=1;
    return res;
}
 
// combination c(n+k);で二項係数テーブルをあらかじめ作成
// c(n,k)でnCkを呼び出す
// mint(25).pow(i)で25のi乗を呼び出す
struct mint {
    ll x; 
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
    };
    istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
    ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}
struct combination {
    vector<mint> fact, ifact;
    combination(int n):fact(n+1),ifact(n+1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
    }
    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n]*ifact[k]*ifact[n-k];
    }
};

template <std::int_fast64_t Modulus>
class ModInt {
    using i64 = std::int_fast64_t;
 
private:
    i64 m_value;
 
public:
    constexpr ModInt(const i64 x = 0) noexcept : m_value(x % Modulus) {
        if (m_value < 0) m_value += Modulus;
    }
 
    constexpr const i64& value() const noexcept { return m_value; }
 
    constexpr ModInt& operator+=(const ModInt rhs) noexcept {
        m_value += rhs.m_value;
        if (m_value >= Modulus) {
        m_value -= Modulus;
        }
        return *this;
    }
    constexpr ModInt& operator-=(const ModInt rhs) noexcept {
        if (m_value < rhs.m_value) {
            m_value += Modulus;
        }
        m_value -= rhs.m_value;
        return *this;
    }
    constexpr ModInt& operator*=(const ModInt rhs) noexcept {
        m_value = m_value * rhs.m_value % Modulus;
        return *this;
    }
    constexpr ModInt& operator/=(ModInt rhs) noexcept {
        *this *= rhs.inv();
        return *this;
    }
 
    constexpr ModInt& operator++() noexcept {
        *this += 1;
        return *this;
    }
    constexpr ModInt operator++(int) noexcept {
        ModInt res = *this;
        *this += 1;
        return res;
    }
    constexpr ModInt& operator--() noexcept {
        *this -= 1;
        return *this;
        }
    constexpr ModInt operator--(int) noexcept {
        ModInt res = *this;
        *this -= 1;
        return res;
    }
 
    constexpr ModInt inv() const noexcept {
        i64 q = m_value;
        i64 b = Modulus, u = 1, v = 0;
        while (b) {
            i64 t = q / b;
            q -= t * b;
            std::swap(q, b);
            u -= t * v;
            std::swap(u, v);
        }
        u %= Modulus;
        if (u < 0) u += Modulus;
        return u;
    }
 
    constexpr ModInt pow(i64 k) const noexcept {
        ModInt res = 1;
        ModInt tmp;
        if (k < 0) {
            tmp = (*this).inv();
            k = -k;
        }
        else {
            tmp = *this;
        }
        for (; k > 0; k >>= 1) {
            if (k & 1) res *= tmp;
            tmp *= tmp;
        }
        return res;
    }
 
    friend constexpr ModInt operator+(const ModInt& lhs, const ModInt& rhs) noexcept {
        return ModInt<Modulus>(lhs) += rhs;
    }
    friend constexpr ModInt operator-(const ModInt& lhs, const ModInt& rhs) noexcept {
        return ModInt<Modulus>(lhs) -= rhs;
    }
    friend constexpr ModInt operator*(const ModInt& lhs, const ModInt& rhs) noexcept {
        return ModInt<Modulus>(lhs) *= rhs;
    }
    friend constexpr ModInt operator/(const ModInt& lhs, const ModInt& rhs) noexcept {
        return ModInt<Modulus>(lhs) /= rhs;
    }
 
    friend constexpr bool operator<(const ModInt& lhs, const ModInt& rhs) noexcept {
        return lhs.m_value < rhs.m_value;
    }
    friend constexpr bool operator>(const ModInt& lhs, const ModInt& rhs) noexcept {
        return lhs.m_value > rhs.m_value;
    }
    friend constexpr bool operator<=(const ModInt& lhs, const ModInt& rhs) noexcept {
        return lhs.m_value <= rhs.m_value;
    }
    friend constexpr bool operator>=(const ModInt& lhs, const ModInt& rhs) noexcept {
        return lhs.m_value >= rhs.m_value;
    }
    friend constexpr bool operator==(const ModInt& lhs, const ModInt& rhs) noexcept {
        return lhs.m_value == rhs.m_value;
    }
    friend constexpr bool operator!=(const ModInt& lhs, const ModInt& rhs) noexcept {
        return lhs.m_value != rhs.m_value;
    }
 
    friend std::istream& operator>>(std::istream& is, ModInt& rhs) {
        i64 a;
        is >> a;
        rhs = a;
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const ModInt& rhs) {
        os << rhs.m_value;
        return os;
    }
};

 
int main(){
 
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ModInt<mod>> a(n);
    vector<ModInt<mod>> b(n);
    ModInt<mod> sum=0;
    ModInt<mod> sumb=0;
    rep(i,n){
        cin >> a[i];
        sum+=a[i];
        b[i] = (a[i]*a[i]);
        sumb+=b[i];
        
    }

    ModInt<mod> d=(sum)*(sum);
    ModInt<mod> e=(sumb);
    
    ModInt<mod> ans = ((d-e)/2);
    

    cout << ans << endl;
}