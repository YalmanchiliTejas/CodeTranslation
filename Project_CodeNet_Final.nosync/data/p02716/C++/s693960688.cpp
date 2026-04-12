#include <cassert>
#include <algorithm>
#include <array>
#include <bitset>
#include <cctype>
#include <cstdint>
#include <cmath>
#include <complex>
#include <chrono>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <random>
#include <memory>
#include <utility>
#include <limits>
#include <list>

/* template start */
 
#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)
#define all(i) i.begin(), i.end()
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void debug_out(){std::cerr<<std::endl;}

template<typename Head,typename... Tail>
void debug_out(Head h,Tail... t){
  std::cerr<<" "<<h;
  if(sizeof...(t)>0)std::cout<<" :";
  debug_out(t...);
}
 
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2> pa) {
  return os << pa.first << " " << pa.second;
}
 
template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
  for (std::size_t i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}
 
template<typename T1,typename T2>
inline bool chmax(T1& a,T2 b){return a<b && (a=b,true);}
 
template<typename T1,typename T2>
inline bool chmin(T1& a,T2 b){return a>b && (a=b,true);}
 
long long pow_mod(long long a, long long b, long long mod=-1) {
  if(b==0)return 1;
  if ((a == 0)||(mod!=-1&&(a+mod)%mod==0))return 0;
  long long x = 1;
  while (b > 0) {
    if (b & 1)x = (mod!=-1)?(x * a) % mod:x*a;
    a = (mod!=-1)?(a * a) % mod:a*a;
    b >>= 1;
  }
  return x;
}

template <std::uint_fast64_t Modulus> class modint {
  using u64 = std::uint_fast64_t;

public:
  u64 a;

  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
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
    u64 exp = Modulus - 2;
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

/* template end */

using ll = long long;
using P=std::pair<long long,long long>;

constexpr ll MIN=-1e15;

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n;
  std::cin>>n;

  std::vector<ll> a(n);
  rep(i,0,n)std::cin>>a[i];

  ll m=n/2;

  if(n%2){
    std::vector<ll> left(m+1,0),mid(m+1,0),right(m+1,0);
    rep(i,0,m)left[i+1]=left[i]+a[2*i];
    for(ll i=m-1;i>=0;i--)mid[i]=mid[i+1]+a[2*i+1];
    for(ll i=m-1;i>=0;i--)right[i]=right[i+1]+a[2*i+2];
    std::vector<ll> left2(m+1,0);
    rep(i,0,m){
      left2[i+1]=std::max(left2[i]+mid[i]-mid[i+1],left[i+1]);
    }
    ll ans=std::numeric_limits<ll>::min();
    rep(i,0,m+1){
      chmax(ans,left2[i]+right[i]);
    }
    std::cout<<ans<<"\n";
  }else{
    std::vector<ll> left(m+1,0),right(m+1,0);
    rep(i,0,m)left[i+1]=left[i]+a[2*i];
    for(ll i=m-1;i>=0;i--)right[i]=right[i+1]+a[2*i+1];

    ll ans=std::numeric_limits<ll>::min();
    rep(i,0,m+1){
      chmax(ans,left[i]+right[i]);
    }
    std::cout<<ans<<"\n";
  }

  return 0;
}

