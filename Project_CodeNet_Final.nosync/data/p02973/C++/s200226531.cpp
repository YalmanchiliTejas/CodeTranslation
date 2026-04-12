#include <bits/stdc++.h>
using namespace std;
 
//long long
using ll = long long;
 
// pair<int, int>
using PII = pair<int, int>;
 
 
//最大値、mod
const int MOD = 1000000007;
const int mod = 1000000007;
const int INF = 1000000000;
const long long LINF = 1e18;
const int MAX = 510000;
 
//出力系
#define print(x) cout << x << endl
#define prints(x) cout << fixed << setprecision(20) << x << endl
#define printc(x) cout << setw(2) << setfill('0') << x << endl;
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
 
//配列入力
vector<long long>vecin(ll n){
    vector<long long>res(n);
    for(int i = 0; i < n; i++) cin >> res[i];
    return res;
}

// begin() end()
#define all(x) (x).begin(),(x).end()
 
//for
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define rep(i,a,b) for(int i=(a);i<(b);i++)
 
//最大公約数 
 ll gcd(ll x, ll y) { return y ? gcd(y,x%y) : x;}

// 最小公倍数
unsigned lcm(unsigned a, unsigned b){
    return a / gcd(a, b) * b; 
}
 
// a = max(a, b), a = min(a, b)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
// num ^ pow(mod取る)
ll pow_mod(ll num, ll pow, ll mod) {
    ll prod = 1;
    num %= mod;
    while (pow > 0) {
        if (pow & 1) prod = prod * num % mod;
        num = num * num % mod;
        pow >>= 1;
    }
    return prod;
}
 
 
 
// 二項係数(MODとる、1 ≦ k ≦ n ≦ 10^7 程度)
// COMinit()
// COM(x, y)
// とコンビで使う
 
// テーブルを作る前処理
long long fac[MAX], finv[MAX], inv[MAX];
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
 
// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
 

 
 
// UnionFind
struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<ll> Size;
    UnionFind(int n = 1) {
        init(n);
    }
 
    void init(int n = 1) {
        par.resize(n + 1); rank.resize(n + 1); Size.resize(n + 1);
        for (int i = 0; i <= n; ++i) par[i] = i, rank[i] = 0, Size[i] = 1;
    }
 
    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            return par[x] = r;
        }
    }
 
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
 
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        Size[x] += Size[y];
        return true;
    }
 
    ll size(int x){
        return Size[root(x)];
    }
};

 
//modint構造体 
struct Mint {
    int val;
    Mint inv() const{
        int tmp,a=val,b=mod,x=1,y=0;
        while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);
        return Mint(x);
    }
public:
    Mint():val(0){}
    Mint(ll x){if((val=x%mod)<0)val+=mod;}
    Mint pow(ll t){Mint res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;}return res;}
    Mint& operator+=(const Mint& x){if((val+=x.val)>=mod)val-=mod;return *this;}
    Mint& operator-=(const Mint& x){if((val+=mod-x.val)>=mod)val-=mod; return *this;}
    Mint& operator*=(const Mint& x){val=(ll)val*x.val%mod; return *this;}
    Mint& operator/=(const Mint& x){return *this*=x.inv();}
    bool operator==(const Mint& x) const{return val==x.val;}
    bool operator!=(const Mint& x) const{return val!=x.val;}
    bool operator<(const Mint& x) const{return val<x.val;}
    bool operator<=(const Mint& x) const{return val<=x.val;}
    bool operator>(const Mint& x) const{return val>x.val;}
    bool operator>=(const Mint& x) const{return val>=x.val;}
    Mint operator+(const Mint& x) const{return Mint(*this)+=x;}
    Mint operator-(const Mint& x) const{return Mint(*this)-=x;}
    Mint operator*(const Mint& x) const{return Mint(*this)*=x;}
    Mint operator/(const Mint& x) const{return Mint(*this)/=x;}
};
struct factorial {
    vector<Mint> Fact, Finv;
public:
   //factorial fact(10000010);
   //fact.nCr(a, b)
  //「fact」の部分は自由に名前変更可能
    factorial(int maxx){
        Fact.resize(maxx+1),Finv.resize(maxx+1); Fact[0]=Mint(1); rep(i,0,maxx)Fact[i+1]=Fact[i]*(i+1);
        Finv[maxx]=Mint(1)/Fact[maxx]; rrep(i,maxx,0)Finv[i-1]=Finv[i]*i;
    }
    Mint fact(int n,bool inv=0){if(inv)return Finv[n];else return Fact[n];}
    Mint nPr(int n,int r){if(n<0||n<r||r<0)return Mint(0);else return Fact[n]*Finv[n-r];}
    Mint nCr(int n,int r){if(n<0||n<r||r<0)return Mint(0);else return Fact[n]*Finv[r]*Finv[n-r];}
};


// 1 * 2 * 3 .... * n (mod)
ll modfact(ll n) { 
    if (n <= 1) return 1;
    return (n * modfact(n - 1)) % MOD;
}


// kが角度だった場合:cos(k * (PI / 180));
//const double PI = acos(-1);のまま使うと円周率(M_PIもあるよ)
const double PI = acos(-1);


// 多次元 vector 生成   例: auto dp = make_vec<long long>(N+1, 5, 5, 5); 
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

//素因数分解
vector<pair<long long, int>>factorize(long long n){
  vector<pair<long long, int>> res;
  for(long long i = 2; i * i <= n; ++i){
    if(n % i) continue;
    res.emplace_back(i, 0);
    while(n % i == 0){
      n /= i;
      res.back().second++;
    }
  }
if(n != 1) res.emplace_back(n, 1);
return res;
}

// 素数判定
bool primejudge(long long a){
    if(a <= 1) return false;
    for(long long i = 2; i * i <= a; i++){
        if(a % i == 0) return false;
    }
    return true;
}

//　累積和
// vector<long long>sums(vector<int>n){
//     vector<long long>res(n.size() + 1, 0);
//     for(int i = 0; i < n.size(); i++) res[i + 1] = n[i] + res[i];
//     return res;
// }

int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};

int main() {

    ll n;
    cin >> n;
    vector<ll> a(n);

    REP(i, n) cin >> a[i];
    vector<ll> d;

    REP(i, n) {
        auto itr = lower_bound(d.rbegin(), d.rend(), a[i]);
        if (itr == d.rbegin()) {
            d.emplace_back(a[i]);
        } else {
            itr--;
            *itr = a[i];
        }
    }
    cout << d.size() << endl;
    return 0;
}