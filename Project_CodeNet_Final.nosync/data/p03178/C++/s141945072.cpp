#include <bits/stdc++.h>
using namespace std; void solve(); int main(){cin.tie(0); ios::sync_with_stdio(false); cout<<fixed<<setprecision(10); solve();}
using ll=int_fast64_t; using ld=long double; using pll=pair<ll,ll>; using pld=pair<ld,ld>;
#define fi first
#define se second
#define SELECTOR(_1,_2,_3,SELECT,...) SELECT
#define rep(...) SELECTOR(__VA_ARGS__,_rep1,_rep0)(__VA_ARGS__)
#define _rep0(i,n) for(ll i=0;i<n;++i)
#define _rep1(i,k,n) for(ll i=k;i<n;++i)
template<class T> void vecout(const T &v){for(auto it=v.begin();it!=v.end();++it,cout<<(it!=v.end()?" ":"\n"))cout<<*it;}
template<class T> vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<class... Ts> auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}

template <std::uint_fast64_t Modulus> class modint {
public:
  ll a;
  constexpr modint(const ll x = 0) noexcept : a(x % Modulus) {}
  constexpr ll &value() noexcept { return a; }
  constexpr const ll &value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    ll exp = Modulus - 2;
    while (exp) {
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
};

void solve(){
  const ll MOD=1'000'000'007;
  string k; cin>>k;
  ll d; cin>>d;
  ll n=k.size();
  auto dp=make_v(n+1,d,2,modint<MOD>(0));
  dp[0][0][0]=modint<MOD>(1);
  rep(i,n){
    ll a=k[i]-'0';
    rep(j,d)rep(o,10){
      dp[i+1][(j+o)%d][1]+=dp[i][j][1];
      if(o<a) dp[i+1][(j+o)%d][1]+=dp[i][j][0];
      else if(o==a) dp[i+1][(j+o)%d][0]+=dp[i][j][0];
    }
  }
  cout<<(dp[n][0][0]+dp[n][0][1]-1).a<<"\n";
}