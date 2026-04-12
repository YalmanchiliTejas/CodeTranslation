#include <bits/stdc++.h>
using namespace std;using ll=int_fast64_t;using ld=long double;using pll=pair<ll,ll>;using pld=pair<ld,ld>;
const ll INF=1LL<<60;void solve();int main(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(10);solve();}
#define fi first
#define se second
#define SELECTOR(_1,_2,_3,_4,SELECT,...) SELECT
#define rep(...) SELECTOR(__VA_ARGS__,_rep2,_rep1,_rep0)(__VA_ARGS__)
#define _rep0(i,n) for(ll i=0;i<n;++i)
#define _rep1(i,k,n) for(ll i=k;i<n;++i)
#define _rep2(i,k,n,d) for(ll i=k;d!=0&&d>0?i<n:i>n;i+=d)
template<class T> vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<class... Ts> auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<class T> inline bool chmax(T &a,const T &b){if(a<b){a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a,const T &b){if(a>b){a=b; return 1;} return 0;}
template<class T> void contout(const T &v){for(auto it=v.begin();it!=v.end();++it,cout<<(it!=v.end()?" ":"\n"))cout<<*it;}

template <std::uint_fast64_t Modulus> class mint {
public:
  ll a;
  constexpr mint(const ll x = 0) noexcept : a(x % Modulus) {}
  constexpr ll &value() noexcept { return a; }
  constexpr const ll &value() const noexcept { return a; }
  constexpr mint operator+(const mint rhs) const noexcept {
    return mint(*this) += rhs;
  }
  constexpr mint operator-(const mint rhs) const noexcept {
    return mint(*this) -= rhs;
  }
  constexpr mint operator*(const mint rhs) const noexcept {
    return mint(*this) *= rhs;
  }
  constexpr mint operator/(const mint rhs) const noexcept {
    return mint(*this) /= rhs;
  }
  constexpr mint &operator+=(const mint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr mint &operator-=(const mint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr mint &operator*=(const mint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr mint &operator/=(mint rhs) noexcept {
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

const ll MOD=1000000007;
void solve(){
  string k; cin>>k;
  ll D; cin>>D;
  auto dp=make_v(D,2,mint<MOD>(0)); // dp[r][lt]
  dp[0][0]=1;
  rep(i,k.size()){
    ll a=k[i]-'0';
    auto newdp=make_v(D,2,mint<MOD>(0));
    rep(r,D)rep(lt,2)rep(d,10){
      ll nr=(r+d)%D,nlt=lt;
      if((!lt)&&d>a) continue;
      if(d<a) nlt=1;
      newdp[nr][nlt]+=dp[r][lt];
    }
    dp=newdp;
  }
  cout<<(dp[0][0]+dp[0][1]-1).a<<"\n";
}