#include <bits/stdc++.h>
using namespace std;

#define REP(i,m,n) for(int i=(m); i<(int)(n); i++)
#define RREP(i,m,n) for(int i=(int)(n-1); i>=m; i--)
#define rep(i,n) REP(i,0,n)
#define rrep(i,n) RREP(i,0,n)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define fi first
#define se second
#define debug(...) {cerr<<"[L"<<__LINE__<<"] "; _debug(__VA_ARGS__);}

template<typename T>
string join(const vector<T>&v, string del=", "){ stringstream s;
    for(auto x : v) s << del << x; return s.str().substr(del.size());
}
template<typename T>
ostream& operator<<(ostream& o, const vector<T>&v){
    if(v.size()) o << "[" << join(v) << "]"; return o;
}
template<typename T>
ostream& operator<<(ostream& o, const vector<vector<T> >&vv){
    int l = vv.size();
    if(l){ o<<endl; rep(i,l) o << (i==0 ? "[ " : ",\n  " ) << vv[i] << (i==l-1 ? " ]" : ""); }
    return o;
}
inline void _debug(){cerr<<endl;}
template<class First, class... Rest>
void _debug(const First& first, const Rest&... rest){cerr<<first<<" ";_debug(rest...);}

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

const double PI = (1*acos(0.0));
const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll mod = 1e9 + 7;

inline void finput(string filename) {
    freopen(filename.c_str(), "r", stdin);
}

struct mint {
    long long x;
    mint(long long x=0) : x((x%mod+mod)%mod) {}
    mint operator-() const {
      return mint(-x);
    }
    mint& operator+=(const mint& a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint& a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const  mint& a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint& a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint& a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint& a) const {
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
    mint inv() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint& a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint& a) const {
        mint res(*this);
        return res/=a;
    }
    friend ostream& operator<<(ostream& os, const mint& m){
        os << m.x; return os;
    }
};

struct Factorial{
    vector<mint> fact;
    vector<mint> factinv;
    Factorial(ll n){
        fact = vector<mint>(n+1);
        factinv = vector<mint>(n+1);
        fact[0] = 1;
        REP(i,1,n+1) fact[i] = fact[i-1] * i;
        factinv[n] = fact[n].inv();
        RREP(i,1,n+1) factinv[i-1] = factinv[i] * i;
    }
    mint C(ll n, ll k){
        if(k<0 || k>n) return 0;
        return fact[n] * factinv[n-k] * factinv[k];
    }
    mint P(ll n, ll k){
        if(k<0 || k>n) return 0;
        return fact[n] * factinv[n-k];
    }
    mint H(ll n, ll k){
        if(n==0 && k==0) return 1;
        return C(n+k-1, k);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    // finput("./input");
    ll n,m,k; cin >> n >> m >> k;
    auto fa = Factorial(n*m);
    mint xc = 0;
    REP(d,1,m) xc += mint(d) * mint(m-d) * mint(n*n) * fa.C(n*m-2, k-2);
    mint yc = 0;
    REP(d,1,n) yc += mint(d) * mint(n-d) * mint(m*m) * fa.C(n*m-2, k-2);
    cout << xc + yc << endl;
    return 0;
}