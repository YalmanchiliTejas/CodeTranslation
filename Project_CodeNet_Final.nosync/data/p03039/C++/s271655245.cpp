#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rrep(i,n) for (int i = n-1; i >= 0; i--)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define tmax(a,b,c) max(a,max(b,c))
#define tmin(a,b,c) min(a,min(b,c))
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
#define vp vector<P>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using LP = pair<ll,ll>;
template<class T> istream& operator>>(istream& is,vector<T>& v) { for(T& t:v){is>>t;} return is; }
template<class T> ostream& operator<<(ostream& os,const vector<T>& v) { for(T t:v){os<<t<<" ";} os<<"\n"; return os; }
void Yes(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YES(bool b) { cout << (b ? "YES" : "NO") << endl; }
template<class T> inline bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001;

const int mod = 1000000007;
struct mint {
  ll x;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) { if ((x += a.x) >= mod) x -= mod; return *this;}
  mint& operator++() { x += 1; return *this;}
  mint& operator-=(const mint a) { if ((x += mod-a.x) >= mod) x -= mod; return *this; }
  mint& operator--() { x -= 1; return *this;}
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
  mint operator+(const mint a) const { mint res(*this); return res+=a; }
  mint operator-(const mint a) const { mint res(*this); return res-=a; }
  mint operator*(const mint a) const { mint res(*this); return res*=a; }
  bool operator==(const int n) const { mint a(n); return this->x == a.x; }
  bool operator==(const ll n) const { mint a(n); return this->x == a.x; }
  bool operator!=(const int n) const { mint a(n); return this->x != a.x; }
  bool operator!=(const ll n) const { mint a(n); return this->x != a.x; }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
  // for prime mod
  mint inv() const { return pow(mod-2); }
  mint& operator/=(const mint a) { return (*this) *= a.inv(); }
  mint operator/(const mint a) const { mint res(*this); return res/=a; }
};
istream& operator>>(istream& is,const mint& m) { return is >> m.x; }
ostream& operator<<(ostream& os,const mint& m) { return os << m.x; }

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
}comb(200000);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n,m,k;
    cin >> n >> m >> k;
    mint c = comb(n*m-2,k-2);
    mint ans = 0;
    rep2(i,1,n) {
        mint now = n-i;
        now *= mint(m);
        now *= mint(m);
        now *= c;
        now *= i;
        ans += now;
    }
    rep2(i,1,m) {
        mint now = m-i;
        now *= mint(n);
        now *= mint(n);
        now *= c;
        now *= i;
        ans += now;
    }
    cout << ans << endl;
}