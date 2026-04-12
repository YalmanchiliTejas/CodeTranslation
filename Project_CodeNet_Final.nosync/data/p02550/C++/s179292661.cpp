#line 1 "main_e.cpp"
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cstdint>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <chrono>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <random>
#include <utility>
#include <limits>
#include <list>
#include <type_traits>

/* template start */

using i64=std::int_fast64_t;
using u64=std::uint_fast64_t;
 
#define rep(i, a, b) for (i64 i = (a); (i) < (b); (i)++)
#define all(i) i.begin(), i.end()

#ifdef LOCAL
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

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

template<typename Num>
constexpr Num mypow(Num a, u64 b,Num id=1) {
  if(b==0)return id;
  Num x = id;
  while (b > 0) {
    if(b & 1)x*=a;
    a*=a;
    b >>= 1;
  }
  return x;
}

/* template end */

int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  i64 n,x,m;
  std::cin>>n>>x>>m;

  if(n<=m){
    i64 ans=0;
    i64 a=x;
    rep(i,0,n){
      ans+=a;
      a=(a*a)%m;
    }
    std::cout<<ans<<"\n";
    return 0;
  }

  std::vector<i64> itr(m,-1);

  i64 prev=x;

  i64 start,end;

  rep(i,0,n){
    if(itr[prev]!=-1){
      start=itr[prev];
      end=i;
      break;
    }
    itr[prev]=i;
    prev=(prev*prev)%m;
  }

  i64 ans=0;
  i64 a=x;
  rep(i,0,start){
    ans+=a;
    a=(a*a)%m;
  }

  i64 sum=0;
  rep(i,start,end){
    sum+=a;
    a=(a*a)%m;
  }
  
  ans+=sum*((n-start)/(end-start));
  i64 mod=(n-start)%(end-start);
  rep(i,start,start+mod){
    ans+=a;
    a=(a*a)%m;
  }

  std::cout<<ans<<"\n";
  
  return 0;
}
