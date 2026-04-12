#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define repi(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define repdi(i,a,b) for(ll i=(a)-1;i>=(b);--i)
#define repd(i,a) repdi(i,a,0)
#define itr(it,a) for( auto it = (a).begin(); it != (a).end(); ++it )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

using ll = long long;
using P = std::pair<ll, ll>;

constexpr ll INF = 1ll<<60;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class S, class T>
std::ostream& operator<< ( std::ostream& out, const std::pair<S,T>& a )
{ std::cout << '(' << a.first << ", " << a.second << ')'; return out; }

template<class T>
std::ostream &operator<< ( std::ostream& out, const std::vector<T>& a )
{ std::cout << '['; rep( i, a.size() ){ std::cout << a[i]; if( i != a.size()-1 ) std::cout << ", "; } std::cout << ']'; return out; }

struct mint {
  ll x; // typedef long long ll;
  ll mod;
  mint(ll x, ll mod):x((x%mod+mod)%mod),mod(mod){}
  mint operator-() const { return mint(-x,mod);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return mint(1,mod);
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

struct combination {
  std::vector<mint> fact, ifact;
  ll mod;
  combination(int n, ll mod):fact(n+1,mint(0,mod)),ifact(n+1,mint(0,mod)),mod(mod) {
    assert(n < mod);
    fact[0] = mint(1,mod);
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*mint(i,mod);
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*mint(i,mod);
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return mint(0,mod);
    return fact[n]*ifact[k]*ifact[n-k];
  }
};

ll N, mod;

int main()
{
  std::cin >> N >> mod;

  std::vector<std::vector<mint>> dp( 3010, std::vector<mint>( 3010, mint( 0, mod ) ) );
  std::vector<mint> two( 3010, mint( 0, mod ) ), ttwo( 3010, mint( 0, mod ) );

  combination comb( 30000, mod );

  dp[0][0] = mint( 1, mod );

  rep( i, N ) rep( j, i+2 )
    dp[i+1][j] = dp[i][j]*mint( j, mod )+dp[i][j-1]+dp[i][j];

  two[0] = mint( 1, mod );
  rep( i, N+4 )
    two[i+1] = two[i]*mint( 2, mod );

  ttwo[0] = mint( 2, mod );
  rep( i, N+4 )
    ttwo[i+1] = ttwo[i]*ttwo[i];

  mint ans = mint( 0, mod );

  rep( k, N+1 )
  {
    mint twoP = mint( 1, mod );

    mint sum = mint( 0, mod );

    rep( l, k+1 )
    {
      sum += ttwo[N-k]*twoP*dp[k][l];

      if( l != k )
        twoP *= two[N-k];
    }

    ans += comb( N, k )*sum*mint((k&1 ? -1 : 1),mod);
  }

  std::cout << ans.x << std::endl;

  return 0;
}