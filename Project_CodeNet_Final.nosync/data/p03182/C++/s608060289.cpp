#pragma region Modefs
#define retword "-1"
#define MAXCOMB 202020
#define MOD 1000000007
#define EPS 1e-9;
#pragma endregion
//--MACROS---------------------------------
#pragma region Macros
#include <bits/stdc++.h>
#define SORT(x) sort((x).begin(), (x).end())
#define RSORT(x) sort((x).rbegin(), (x).rend())
#define ALL(x) (x).begin(), (x).end()
#define REV(x) reverse(ALL(x))
#define rep(i, n) for (ll i = 0; i < n; i++)
#define reps(i, m, n) for (ll i = m; i < n; i++)
#define repr(i, m, n) for (ll i = m; i >= n; i--)
#define SP << " " <<
#define INF2 1000000000000000037LL
#define INF  1000000007
#define lwb(x,n) distance(x.begin(),lower_bound(ALL(x),(n)))
#define upb(x,n) distance(x.begin(),upper_bound(ALL(x),(n)))
#define fora(i, ...) if(ll i = -1) for(__VA_ARGS__) if(i++, true)
#ifdef _MY_DEBUG
#define isdebug true
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0,a1,a2,a3,x,...) x
#define debug_1(x1) cout<<#x1<<": "<<x1<<endl
#define debug_2(x1,x2) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<endl
#define debug_3(x1,x2,x3) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<endl
#define debug_4(x1,x2,x3,x4) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<endl
#define de(...) CHOOSE((__VA_ARGS__,debug_4,debug_3,debug_2,debug_1,~))(__VA_ARGS__)
#else
#define isdebug false
#define de(...)
#endif
using namespace std;
using ll = long long;
using ld = long double;
const ld PI = 3.141592653589793238462643;
using P  = pair<ll,ll>;
using TP  = tuple<ll,ll,ll>;
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
template<class T = ll> using v = vector<T>;
template<class T = ll> using vv = vector<vector<T>>;
template<class T = ll> using vvv = vector<vector<vector<T>>>;
template<class T> bool maxi(T &a, const T &b){ if(a<b){a=b;return 1;}return 0;}
template<class T> bool mini(T &a, const T &b){ if(b<a){a=b;return 1;}return 0;}
template<class T> ll sumer(const T& a){ return accumulate(ALL(a),0LL); }
template<class T> ll miner(const T& a){ return *min_element(ALL(a)); }
template<class T> ll maxer(const T& a){ return *max_element(ALL(a)); }
template<class T> ll bs(ll ok, ll ng, T checker){
    while( abs(ok-ng)>1 ){ ll mid = (ok+ng)/2; (checker(mid)?ok:ng) = mid; }
    return ok;
}
template<class T> ld bs2(ld ok, ld ng, T checker){
    rep(i,300){ ld mid = (ok+ng)/2; (checker(mid)?ok:ng) = mid; }
    return ok;
}
template<class T> void UNIQUE(vector<T> &a){ SORT(a);a.erase(unique(ALL(a)),a.end());}
template<class T, class U> ostream &operator<<(ostream &os, const pair<T,U> &pe) { os << pe.first << " " << pe.second; return os;}
template<class T> ostream &operator<<(ostream &os, const v<T> &ve) { rep(i,ve.size()) os<< (i?" ":"")<<ve[i]; return os;}
ll topbit(ll a) { return a==0?-1:63-__builtin_clzll(a);}
ll botbit(ll a) { return a==0?64:__builtin_ctzll(a);}
ll popcount(ll a) { return __builtin_popcountll(a);}
#define dame do {cout<< retword <<"\n"; return;} while(false)
template< int mod >
struct ModInt {
    ll x;
    ModInt() : x(0) {}
    ModInt(ll y) : x(y >= 0 ? ( y<mod ? y : y%mod ) : (mod - (-y) % mod) % mod) {}
    ModInt &operator+=(const ModInt &p) {
        if((x += p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator-=(const ModInt &p) {
        if((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator*=(const ModInt &p) {
        x = (int) (1LL * x * p.x % mod);
        return *this;
    }
    ModInt &operator/=(const ModInt &p) {
        *this *= p.inv();
        return *this;
    }
    ModInt operator-() const { return ModInt(-x); }
    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
    bool operator==(const ModInt &p) const { return x == p.x; }
    bool operator!=(const ModInt &p) const { return x != p.x; }
    bool operator<(const ModInt &p) const {return x < p.x; }

    ModInt operator+(const ll &q) const {return ModInt(*this) += (ModInt)q; }
    ModInt operator-(const ll &q) const {return ModInt(*this) -= (ModInt)q; }
    ModInt operator*(const ll &q) const {return ModInt(*this) *= (ModInt)q; }
    ModInt operator/(const ll &q) const {return ModInt(*this) /= (ModInt)q; }
    bool operator==(const ll &q) const {return x == q; }
    bool operator!=(const ll &q) const {return x != q; }

    ModInt operator++(){ if(++x == mod) x = 0; return *this; }
    ModInt operator--(){ x = (x == 0 ? mod-1 : x-1); return *this; }
    ModInt operator++(int){ const ModInt res(*this); ++*this; return res; }
    ModInt operator--(int){ const ModInt res(*this); --*this; return res; }

    ModInt inv() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while(b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(ll n, bool inv=false) const {
        ModInt ret(1), mul(x);
        while(n > 0) {
        if(n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        if(inv) ret=ret.inv();
        return ret;
    }

    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }
    friend istream &operator>>(istream &is, ModInt &a) {
        ll t;
        is >> t;
        a = ModInt< mod >(t);
        return (is);
    }
};
using mint = ModInt< MOD >;
mint mpow(ll x, ll n, bool inv=false) {
    mint ret(1), mul(x);
    while(n > 0) {
    if(n & 1) ret *= mul;
        mul *= mul;
        n >>= 1;
    }
    if(inv) ret=ret.inv();
    return ret;
}
mint fac[MAXCOMB], finv[MAXCOMB], inv[MAXCOMB];
void cinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    reps(i, 2, MAXCOMB){
        fac[i] = fac[i - 1] * i;
        inv[i] = inv[MOD%i] * -(MOD/i);
        finv[i] = finv[i - 1] * inv[i];
    }
}
mint com(int n, int k){ // 二項係数計算
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * finv[k] * finv[n-k];
}
#pragma endregion
//--GLOBAL---------------------------------
template <class Mono = ll, class Lazy = ll>
struct SegTree{
    using FuncMM = function<Mono(Mono,Mono)>;
    using FuncML = function<void(Mono&,Lazy)>;
    using FuncLL = function<void(Lazy&,Lazy)>;
    using FuncLW = function<Lazy(Lazy,int)>;
    FuncMM FMM;
    FuncML FML;
    FuncLL FLL;
    FuncLW FLW;
    int N;
    vector<Mono> dat;
    vector<Lazy> lazy;
    Mono unitMono; //初期値であり単位元
    Lazy unitLazy; //初期値であり単位元

    SegTree(int n, Mono unitm, Lazy unitl, FuncMM fmm, FuncML fml, FuncLL fll, FuncLW flw) : unitMono(unitm), unitLazy(unitl), FMM(fmm), FML(fml), FLL(fll), FLW(flw) {
        N = 1;
        while(N < n) N <<= 1;
        dat.resize(2*N-1, unitMono); //和なら0
        lazy.resize(2*N-1, unitLazy); //和なら0
    }

    void set(int i, const Mono &val) { dat[i+N-1] = val; }
    void build() {
        repr(k,N-2,0) dat[k] = FMM(dat[k*2+1], dat[k*2+2]);
    }

    void eval(int k, int w){
        if(lazy[k]==unitLazy) return;
        if(k<N-1) FLL(lazy[k*2+1], lazy[k]), FLL(lazy[k*2+2], lazy[k]);
        FML(dat[k], FLW(lazy[k], w));
        lazy[k] = unitLazy;
    }

    void _update(int a, int b, const Lazy &val, int k, int l, int r) {
        eval(k, r-l);
        if(a <= l and r <= b) {FLL(lazy[k], val), eval(k, r-l); return;} // 被覆
        else if(r <= a or b <= l) return; // 範囲外
        else{ // a<r and l<b : 掘る
            _update(a,b,val,k*2+1,l,(l+r)>>1);
            _update(a,b,val,k*2+2,(l+r)>>1,r);
            dat[k]=FMM(dat[k*2+1],dat[k*2+2]);
        }
    }

    void update(int a, int b, const Lazy &val) { _update(a,b,val,0,0,N); } // 0-indexed [a,b)

    Mono _query(int a, int b, int k, int l, int r) {
        eval(k, r-l);
        if(a <= l and r <= b) return dat[k]; // 被覆
        if(r <= a or b <= l) return unitMono; // 範囲外
        return FMM( _query(a,b,k*2+1,l,(l+r)>>1), _query(a,b,k*2+2,(l+r)>>1,r) );
    }

    Mono query(int a, int b){ //[a,b)
        return _query(a,b,0,0,N);
    }

    inline Mono operator[](int i) { return query(i,i+1); }

};
// 区間add, RMQ
    // using Mono=ll; using Lazy=ll;
    // auto fmm = [](Mono a, Mono b){ return min(a,b); };
    // auto fml = [](Mono &a, Lazy b){ a+=b; };
    // auto fll = [](Lazy &a, Lazy b){ a+=b; };
    // auto flw = [](Lazy a, int w){ return a; };
    // Mono unitMono=INF2; Lazy unitLazy=0;
    // SegTree<Mono,Lazy> seg(N,unitMono,unitLazy,fmm,fml,fll,flw);

// 区間add, 区間sum
    // using Mono=ll; using Lazy=ll;
    // auto fmm = [](Mono a, Mono b){ return a+b; };
    // auto fml = [](Mono &a, Lazy b){ a+=b; };
    // auto fll = [](Lazy &a, Lazy b){ a+=b; };
    // auto flw = [](Lazy a, int w){ return a*w; };
    // Mono unitMono=0; Lazy unitLazy=0;
    // SegTree<Mono,Lazy> seg(N,unitMono,unitLazy,fmm,fml,fll,flw);

// 小さくする区間set, RMQ
    // using Mono=ll; using Lazy=ll;
    // auto fmm = [](Mono a, Mono b){ return min(a,b); };
    // auto fml = [](Mono &a, Lazy b){ a=min(a,b); };
    // auto fll = [](Lazy &a, Lazy b){ a=min(a,b); };
    // auto flw = [](Lazy a, int w){ return a; };
    // Mono unitMono=INF2; Lazy unitLazy=INF2;
    // SegTree<Mono,Lazy> seg(N,unitMono,unitLazy,fmm,fml,fll,flw);

// 区間chmin, RMQ/RSQ -> SegTreebeats O(NlogN+Mlog^2 N)

//--MAIN-----------------------------------
void Main() {
    ll N,M;
    cin>>N>>M;

    // 区間add, RMQ
    using Mono=ll; using Lazy=ll;
    auto fmm = [](Mono a, Mono b){ return max(a,b); };
    auto fml = [](Mono &a, Lazy b){ a+=b; };
    auto fll = [](Lazy &a, Lazy b){ a+=b; };
    auto flw = [](Lazy a, int w){ return a; };
    Mono unitMono=0; Lazy unitLazy=0;
    SegTree<Mono,Lazy> seg(N+1,unitMono,unitLazy,fmm,fml,fll,flw);

    v<P> q[N+1];
    rep(i,M){
        ll l,r,a; cin>>l>>r>>a;
        q[r].emplace_back(l,a);
    }
    
    rep(i,N){
        ll x=seg.query(0,i+1);
        seg.update(i+1,i+2,x);
        for(auto& pe: q[i+1]){
            ll l=pe.first, a=pe.second;
            seg.update(l,i+2,a);
        } 
    }

    cout<< seg.query(0,N+1) <<"\n";

}
//--START----------------------------------
int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    // if(isdebug) {ifstream in("input.txt"); cin.rdbuf(in.rdbuf());}
    // if(isdebug) {ofstream out("output.txt"); cout.rdbuf(out.rdbuf());}
    cout << fixed << setprecision(15);
    // ll Qkai; cin>>Qkai; rep(QQ,Qkai) Main();
    Main();
}
//-----------------------------------------