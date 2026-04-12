#include <bits/stdc++.h>
#define FOR(i, k, n) for(int i = (k); i < (n); i++)
#define FORe(i, k, n) for(int i = (k); i <= (n); i++)
#define FORr(i, k, n) for(int i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(int i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
using ll = long long;

const int INF = 1001001001;
const int mod = 1000000007;

class mint{
  public:
  ll x;
  mint(ll x = 0):x((x % mod + mod) % mod){};
  mint pow(ll y) const {
    mint res(1);
    mint a(x);
    while(y>0){
      if(y&1) res *= a;
      a *= a;
      y >>= 1;
    }
    return res;
  }
  mint inv() const{ return pow(mod-2); }
  mint& operator+= (const mint a) noexcept {
    if((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-= (const mint a) noexcept {
    if((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*= (const mint a) noexcept {
    (x *= a.x) %= mod;
    return *this;
  }
  mint& operator/= (const mint a) noexcept {
    return (*this) *= a.inv();
  }
  mint operator+ (const mint a) const noexcept {
    mint res(*this);
    return res += a;
  }
  mint operator- (const mint a) const noexcept {
    mint res(*this);
    return res -= a;
  }
  mint operator* (const mint a) const noexcept {
    mint res(*this);
    return res *= a;
  }
  mint operator/ (const mint a) const noexcept{
    mint res(*this);
    return res /= a;
  }
};

class comb{
  public:
  vector<mint> fact, ifact;
  comb(int n): fact(n+1), ifact(n+1){
    fact[0] = 1;
    for(int i = 1; i <= n; i++) fact[i] = fact[i-1] * i;
    ifact[n] = fact[n].inv();
    for(int i = n; i >= 1; i--) ifact[i-1] = ifact[i] * i;
  }
  mint operator()(int n, int k) const noexcept{
    if(k < 0 || n < k) return 0;
    return fact[n] * ifact[k] * ifact[n-k];
  }
};

int main(void){
  ll n, m, k;
  cin >> n >> m >> k;

  comb c(n*m);
  mint sum = 0;
  REP(d, n) sum += d*(n-d)*m*m;
  REP(d, m) sum += d*(m-d)*n*n;
  sum *= c(n*m-2, k-2);
  cout << sum.x << endl;
  return 0;
}