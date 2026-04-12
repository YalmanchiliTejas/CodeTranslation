#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vi2 = vector<vector<int>>;
using vl = vector<ll>;
using vl2 = vector<vector<ll>>;
using vb = vector<bool>;
using vb2 = vector<vector<bool>>;
using vc = vector<char>;
using vc2 = vector<vector<char>>;
using vs = vector<string>;
using si = set<int>;
using vs2 = vector<vector<string>>;
using pii = pair<int, int>;
using mii = map<int, int>;
const int INF = 1e9+1;
const ll LINF = 1e18+1;
const long double LPI = acos(-1.0);
const  double PI = acos(-1.0);
const int mod = 1000000007;

#define MP(a,b) make_pair((a),(b))
#define MT(...) make_tuple(__VA_ARGS__)
#define sz(x) (int)(x).size()
 
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,x) for(ll i=0;i<(int)(x);i++)
#define REPS(i,x) for(ll i=1;i<=(int)(x);i++)
#define RREP(i,x) for(ll i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(ll i=((int)(x));i>0;i--)
 
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define SORT(v) sort(ALL(v));
#define RSORT(v) sort(RALL(v));
#define IN(type,a) type a;cin >> a;
#define VIN(type,a,n) vector<type> a(n);cin >> a;
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl;
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl;
#define COUT(x) cout << (x) << endl;
#define DCOUT(x,n) cout << fixed << setprecision(n) << (x) << endl;
#define ENDL cout << endl;
#define DB(s,x) cout << (s) << " : " << x << endl;
 
#define HOGE COUT("HOGE")
 
template<typename T>inline istream& operator>>(istream&i,vector<T>&v)
{REP(j,sz(v))i>>v[j];return i;}
 
template<typename T> bool chmax(T& a, const T& b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T& a, const T& b){if(a>b){a=b;return true;}return false;}
template<typename T> T gcd(T a,T b){if(b==0){return a;}else{return gcd(b, a%b);}}
template<typename T> T lcm(T a,T b){return a*b/gcd(a, b);}
template<typename T> bool isPrime(T a){if(a<=1){return false;}
    for(T i=2;i*i<=a;i++){if (a%i==0) {return false;}}return true;}
template<typename T> T ord(T p,T n){T ans=0;while(true){if(n%p==0){n/=p;ans++;}else{break;}}return ans;}

struct mint {
  ll x; // typedef long long ll;
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

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

int main() {
    IN(int, n);
    VIN(ll, a, n);
    vector<ll> s(n+1);
    s[0] = 0;
    REP(i, n){
        s[i+1] = s[i]+a[i];
    }
    ll ans = 0;
    REP(i, n-1){
        ans += a[i]*((s[n]-s[i+1])%mod)%mod;
        ans %= mod;
    }
    COUT(ans);
}

