#include <bits/stdc++.h>
using namespace std;

#define REP(i,m,n) for(int i=(m); i<(int)(n); i++)
#define RREP(i,m,n) for(int i=(int)(n-1); i>=m; i--)
#define rep(i,n) REP(i,0,n)
#define rrep(i,n) RREP(i,0,n)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define aut(r,v) __typeof(v) r = (v)
#define each(it,o) for(aut(it,(o).begin()); it!=(o).end(); ++it)
#define reach(it,o) for(aut(it,(o).rbegin()); it!=(o).rend(); ++it)
#define fi first
#define se second
#define debug(...) {cerr<<"[L"<<__LINE__<<"] "; _debug(__VA_ARGS__);}

template<typename T1, typename T2> ostream& operator<<(ostream& o, const pair<T1, T2>& p)
{return o<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>string join(const vector<T>&v, string del=", ")
{stringstream s;rep(i,v.size())s<<del<<v[i];return s.str().substr(del.size());}
template<typename T>ostream& operator<<(ostream& o, const vector<T>&v)
{if(v.size())o<<"["<<join(v)<<"]";return o;}
template<typename T>ostream& operator<<(ostream& o, const vector<vector<T> >&vv)
{int l=vv.size();if(l){o<<endl;rep(i,l){o<<(i==0?"[ ":",\n  ")<<vv[i]<<(i==l-1?" ]":"");}}return o;}
template<typename T>ostream& operator<<(ostream& o, const set<T>& st)
{vector<T> v(st.begin(),st.end());o<<"{ "<<join(v)<<" }";return o;}
template<typename T1, typename T2>ostream& operator<<(ostream& o, const map<T1, T2>& m)
{each(p,m){o<<(p==m.begin()?"{ ":",\n  ")<<*p<<(p==--m.end()?" }":"");}return o;}
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
const ll INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll mod = 998244353;

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

int main(){
    ios_base::sync_with_stdio(0);
    // finput("./input");
    int n, s;
    cin >> n >> s;
    vl a(n);
    rep(i,n) cin >> a[i];

    mint ans = 0;
    vector<vector<mint>> dp(n+1, vector<mint>(s+1));
    dp[0][0] = 1;
    rep(i,n){
        rep(j,s+1) dp[i+1][j] = dp[i][j];
        if(a[i] <= s) dp[i+1][a[i]] += i+1;
        REP(j,1,s+1) if(j+a[i] <= s) dp[i+1][j+a[i]] += dp[i][j];
        if(a[i] == s) ans += (i+1) * (n-i);
        REP(j,1,s+1) if(j+a[i] == s) ans += dp[i][j] * (n-i);
    }
    cout << ans << endl;
    return 0;
}