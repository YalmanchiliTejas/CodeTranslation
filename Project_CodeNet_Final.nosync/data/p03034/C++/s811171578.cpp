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
 
#define rep(i, a, b) for (long long i = (a); (i) < (b); (i)++)
#define all(i) i.begin(), i.end()
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void debug_out(){std::cerr<<std::endl;}

template<typename Head,typename... Tail>
void debug_out(Head h,Tail... t){
  std::cerr<<" "<<h;
  debug_out(t...);
}
 
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2> pa) {
  return os << pa.first << " " << pa.second;
}
 
template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
  for (int i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
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

const long long MOD = 998244353;
// const long long MOD = 1e9 + 7;

using ll = long long;
using P=std::pair<long long,long long>;

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll n;
  std::cin>>n;

  std::vector<ll> s(n);
  rep(i,0,n)std::cin>>s[i];

  ll ans=std::numeric_limits<ll>::min();

  rep(i,1,n){
    ll val=0;
    for(ll k=0;k*i<=n-1;k++){
      ll a=n-1-k*i;
      if(i>=a)continue;
      if(a%i==0&&a/i<=k)continue;
      val+=s[k*i]+s[a];
      chmax(ans,val);
    }
  }

  std::cout<<ans<<"\n";

  return 0;
}
