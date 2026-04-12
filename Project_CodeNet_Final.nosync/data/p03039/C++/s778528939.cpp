#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define sz(x) (int)(x).size()
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define EPS (1e-10)
#define equals(a, b) (fabs((a)-(b)) < EPS)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef set<int> S;
typedef queue<int> Q;
typedef queue<P> QP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MOD = 1000000007;

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
  mint& operator*=(const mint a) { (x *= a.x) %= MOD; return *this;}
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
   mint inv() const { return pow(MOD-2);}
   mint& operator/=(const mint a) { return *this *= a.inv();}
   mint operator/(const mint a) const { return mint(*this) /= a;}
};
typedef vector<mint> vm;
typedef vector<vm> vvm;

class Combi {
private:
  v(ll) fac, inv, finv;
  void init(int N) {
    fac[0] = fac[1] = 1; inv[1] = 1; finv[0] = finv[1] = 1;
    for (int i = 2; i < N; i++) {
      fac[i] = fac[i - 1] * i % MOD;
      inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
      finv[i] = finv[i - 1] * inv[i] % MOD;
    }
  }
public:
  Combi(int N) : fac(N + 1), inv(N + 1), finv(N + 1) { init(N + 1); }
  ll Cmod(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
  }
  ll Pmod(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * finv[n - k] % MOD;
  }
};
  
int main() {
  int n,m,k;
  cin >> n >> m >> k;
  Combi comb(n*m);
  mint ans = 0;
  srep(i,1,n) {
    ans += (ll(n-i)*m*m)*i;
  }
  srep(i,1,m) {
    ans += (ll(m-i)*n*n)*i;
  }
  ans *= comb.Cmod(n*m-2,k-2);
  cout << ans.x << endl;
  return 0;
}