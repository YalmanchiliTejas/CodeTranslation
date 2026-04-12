#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPR(i, n) for(int i=n-1; i>=0; i--)
#define FOR(i, m, n) for(int i=m; i<n; i++)
#define ALL(v) v.begin(), v.end()
#define SIZE(x) ll(x.size()) 
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 2e9;
const ll LINF = (1LL<<60);

const int mod = 1000000007;
//const int mod = 998244353;
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

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n){ 
    cin >> a[i];
  }

  mint ans = 0;
  mint tmp = a.back();
  REPR(i,n-1){
    ans += tmp * mint(a[i]);
    tmp += mint(a[i]); 
  }
  cout << ans << '\n';

  return 0;
}
