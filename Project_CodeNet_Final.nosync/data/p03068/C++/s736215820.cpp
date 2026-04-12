//This template was last modified on 3/03/2020.
//Define many functions and words.
//The functions I have defined start with a capital letter.
#include <bits/stdc++.h>
using namespace std;
//#define MOD 998244353
#define MOD 1000000007
typedef long long ll;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<vl> matrix;//A(n, vl(m));
typedef vector<string> vs;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
typedef pair<double,double> pd;
typedef vector<pd> vpd;
typedef vector<bool> vb;
typedef map<ll,ll> mapl;
typedef queue<ll> quell;
typedef queue<pl> quepl;
typedef priority_queue<ll> pq_ll;
typedef priority_queue<pl> pq_pl;
#define nl "\n"s
#define rep(i,n) for(ll i=0LL; i<(n); i++)
#define INF 1001001001001001001
#define PI 3.14159265358979323846
#define SP << " "s <<
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define All(V) V.begin(),V.end()
#define Sortup(V) sort(All(V))
#define Sortdown(V) sort(V.rbegin(), V.rend())
#define L_b(V, key) lower_bound(All(V), key)
#define B_s(V, key) binary_search(All(V), key)
#define endYes do{cout << "Yes" << nl; return 0;}while(0)
#define endYES do{cout << "YES" << nl; return 0;}while(0)
#define endNo do{cout << "No" << nl; return 0;}while(0)
#define endNO do{cout << "NO" << nl; return 0;}while(0)
#define endS(str) do{cout << str << nl; return 0;}while(0)



//Mathmatical functions.

template<class T>bool Chmax(T &a, T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool Chmin(T &a, T b){if(a>b){a=b;return 1;}return 0;}
template<class T>double Dist(T x,T y,T X,T Y){return sqrt( (x-X)*(x-X)+(y-Y)*(y-Y) );}
ll Digit(ll N, ll base){ll res=0;while(N)res++, N/=base;return res;}
bool Bit(ll subset, ll Rsift){ return ((subset)>>(Rsift))&1; }
ll Gcd(ll a,ll b){ return b?Gcd(b,a%b):abs(a); }
ll Lcm(ll A,ll B){ return A/Gcd(A,B)*B; }
ll Pow(ll e,ll x){ll res=1LL;while(x){if(x&1)res*=e;e*=e;x/=2;}return res;}
ll Pow_mod(ll e,ll x){ll res=1LL;while(x){if(x&1)res=(1LL*res*e)%MOD;e=(1LL*e*e)%MOD;x/=2;}return res;}
void Mul(ll &a,ll b){ a=1LL*a*b%MOD; }
void Eratos_prime(vb &is_prime){//1-indexed
    ll N=is_prime.size()-1;
    rep(i, N) is_prime.at(i) = true;
    is_prime.at(0) = is_prime.at(1) = false;
    for(ll i=2; i*i<=N; i++) if(is_prime.at(i)) {
        for(ll j=i+i; j<=N; j+=i) is_prime.at(j) = false;
    }
}
void Primefact(ll N, mapl &elem){
    for(ll i=2; i*i<=N; i++) {
        while(N%i==0) {
            elem[i]++;
            N /= i;
        }
    }
    if(N>1) elem[N]++;
}
//any number of arguments.
template<class... T> ll Sum(T... args){
    ll res=0;
    for(ll i: initializer_list<ll>{args...}) res += i;
    return res;
}
//cumu is empty.
void Cumu_sum(vl &cumu, vl a){
    cumu.PB(0LL);
    rep(i, a.size()) cumu.PB( Sum(cumu[i], a[i]) );
}

// auto MOD int (@sunuke  pakutta)
struct mint {
    ll x;
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
    mint pow(ll t) const {//O(log(t))
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    //for prime MOD

    //O(log(MOD-2))
    mint inv() const { return pow(MOD-2); }
    mint& operator/=(const mint a) { return (*this) *= a.inv(); }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
};
//2**n % MOD, O(log(n))
mint f(int n) {
    if (n == 0) return 1;
    mint x = f(n/2);
    x *= x;
    if (n%2 == 1) x *= 2;
    return x;
}
//O(a + log(MOD-2)), Independent of n
mint choose(int n, int a) {
    mint x = 1, y = 1;
    rep(i,a) {
        x *= n-i;
        y *= i+1;
    }
    return x / y;
}
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division

struct UnionFind {
    vl d;
    UnionFind(ll n) : d(n, -1){};

    //return root number
    ll root(ll x){
        if( d[x]<0 ) return x;
        return d[x] = root(d[x]);//経路縮約
    }
    bool unite(ll x, ll y){
        x = root(x); y = root(y);
        if( x==y ) return false;
        if( -d[x]<-d[y] ) swap(x, y);//marge, 大きな方に結合
        d[x] += d[y];//negative num, size
        d[y] = x;//positive num, root
        return true;
    }
    bool issame(ll x, ll y){ return root(x)==root(y); }
    ll size(ll x){ return -d[root(x)]; }
};

/*
//Topological sort  O(|V|+|E|)
vl g[100100];
vb used(100100);
vl Sortedgraph;

void dfs_Tsort(ll u) {
  if(used[u]) return;
  used[u] = true;
  for(auto x: g[u]) dfs_Tsort(x);
  Sortedgraph.push_back(u);
}

//N:=|V|
void Topo_sort(ll N) {
  rep(i, N) dfs_Tsort(i);
  reverse(All(Sortedgraph));
}
*/

/*
//Warshall floyd  O(N**3)
#define MAX_V 100
matrix d(MAX_V, vl(MAX_V));

void warshall_floyd(ll V){
    rep(k, V) rep(i, V) rep(j, V){
        Chmin(d[i][j], d[i][k] + d[k][j]);
    }
}
*/

/*
//Combination in MOD  O(N)
//Constraints 1<=k<=n<10^6  and  MOD is prime  and MOD>n
const ll MAX=1001001;
vl fac(MAX), finv(MAX), inv(MAX);
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
//Combination
ll COM(ll n, ll k){
    if (n<k or n<0 or k<0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}*/



//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// solution comes here


int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll n, k;
    string s;
    cin >> n >> s >> k;
    k--;

    rep(i, n) {
        if( s[i]==s[k] ) cout << s[k];
        else cout << "*";
    }
    cout << nl;
}