#include <bits/stdc++.h>
#define SORT(x) sort((x).begin(), (x).end())
#define RSORT(x) sort((x).rbegin(), (x).rend())
#define ALL(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define reps(i, m, n) for (ll i = m; i < n; i++)
#define repr(i, m, n) for (ll i = m; i >= n; i--)
#define de(x) cout << #x << "=" << x << endl;
#define SP << " " <<
template <class T> bool maxi(T &a, const T &b) {
    if (a < b) { a = b; return 1;} return 0;}
template <class T> bool mini(T &a, const T &b) {
    if (b < a) { a = b; return 1;} return 0;}
#define dame {cout<< "-1" <<"\n"; return;}
#define INF2 1000000000000000037
#define INF  1000000007
#define MOD  998244353
using namespace std;
using ll = long long;
using ld = long double;
using P  = pair<ll,ll>;
//--GLOBAL---------------------------------
template< int mod >
struct ModInt {
    int x;

    ModInt() : x(0) {}
    ModInt(ll y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

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
vector<mint> powpool;
void makepow(ll num, ll pool, bool inv=false){
    mint now=1;
    if(inv) makepow((now/num).x ,pool);
    rep(i,pool+1){
        powpool.emplace_back(now);
        now*=num;
    }
}
mint poolpow(ll n){
    if(n>=powpool.size()) return powpool[1].pow(n);
    return powpool[n];
}
mint dp[3010][3010];
//--MAIN-----------------------------------
void Main() {
    ll N,S;
    cin>>N>>S;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    mint ans=0;

    rep(i,N){
        dp[i][0]=i+1;
        rep(j,S+1){
            dp[i+1][j]+=dp[i][j];
            if((j+A[i])>S) continue;
            dp[i+1][j+A[i]]+=dp[i][j];
        }
        ans+=dp[i+1][S]*(N-i);
        dp[i+1][S]=0;
    }

    cout<< ans <<"\n";
}

//--START----------------------------------
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
//-----------------------------------------
