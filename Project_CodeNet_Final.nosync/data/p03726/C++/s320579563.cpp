#include <cassert>
#include "limits.h"
#include <limits>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
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
 
#define rep(i, a, b) for (long long (i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << "debug " <<"LINE:"<<__LINE__<<"  "<< #i <<":"<< i << std::endl

 
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
  if ((a == 0)||(mod!=-1&&a%mod==0)) {
    return 0;
  }
 
  long long x = 1;
 
  while (b > 0) {
    if (b & 1) {
      x = (mod!=-1)?(x * a) % mod:x*a;
    }
    a = (mod!=-1)?(a * a) % mod:a*a;
    b >>= 1;
  }
  return x;
}
 
// const long long MOD = 998244353;
const long long MOD = 1e9 + 7;

using ll = long long;
using P = std::pair<long long,long long>;

//非再帰トポロジカルソート 隣接リストを渡す 返り値のサイズがnじゃないならnot DAG
std::vector<ll> topo_sort(std::vector<std::vector<ll>>& graph) {
  ll n = graph.size();
  std::vector<ll> ret, num(n, 0);
  std::queue<ll> que;
  for(ll i=0;i<n;i++){
    for (ll j : graph[i]) num[j]++;
  }
  for (ll i = 0; i < n; i++) {
    if (num[i] == 0) que.push(i);
  }
  while (!que.empty()) {
    ll u = que.front();
    que.pop();
    ret.push_back(u);
    for (ll i : graph[u]) {
      num[i]--;
      if (num[i] == 0) que.push(i);
    }
  }

  return ret;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  ll n;
  std::cin>>n;

  std::vector<std::vector<ll>> graph(n),directed(n);

  rep(i,0,n-1){
    ll a,b;
    std::cin>>a>>b;
    a--;b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  std::vector<bool> matching(n,false);

  auto f=[&](auto f,ll now,ll par)->void{
    for(ll e:graph[now]){
      if(e==par)continue;
      directed[now].push_back(e);
      f(f,e,now);
    }
  };

  f(f,0,-1);

  std::vector<ll> topo=topo_sort(directed);

  for(ll i=n-1;i>=0;i--){
    ll now=topo[i];
    for(ll next:directed[now]){
      if(!matching[next]){
        matching[now]=true;
        matching[next]=true;
        break;
      }
    }
  }

  bool ans=true;
  rep(i,0,n)ans=(ans&matching[i]);

  if(ans)std::cout<<"Second\n";
  else std::cout<<"First\n";

  return 0;
}