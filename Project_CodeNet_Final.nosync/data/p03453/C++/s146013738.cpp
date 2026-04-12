#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <functional>
#include <set>
#include <ctime>
#include <random>
#include <chrono>
#include <cassert>
#include <tuple>
#include <utility>
using namespace std;

namespace {
  using Integer = long long; //__int128;
  template<class T, class S> istream& operator >> (istream& is, pair<T,S>& p){return is >> p.first >> p.second;}
  template<class T> istream& operator >> (istream& is, vector<T>& vec){for(T& val: vec) is >> val; return is;}
  template<class T> istream& operator ,  (istream& is, T& val){ return is >> val;}
  template<class T, class S> ostream& operator << (ostream& os, const pair<T,S>& p){return os << p.first << " " << p.second;}
  template<class T> ostream& operator << (ostream& os, const vector<T>& vec){for(size_t i=0; i<vec.size(); i++) os << vec[i] << (i==vec.size()-1?"":" "); return os;}
  template<class T> ostream& operator ,  (ostream& os, const T& val){ return os << " " << val;}

  template<class H> void print(const H& head){ cout << head; }
  template<class H, class ... T> void print(const H& head, const T& ... tail){ cout << head << " "; print(tail...); }
  template<class ... T> void println(const T& ... values){ print(values...); cout << endl; }

  template<class H> void eprint(const H& head){ cerr << head; }
  template<class H, class ... T> void eprint(const H& head, const T& ... tail){ cerr << head << " "; eprint(tail...); }
  template<class ... T> void eprintln(const T& ... values){ eprint(values...); cerr << endl; }

  class range{ Integer start_, end_, step_; public: struct range_iterator{ Integer val, step_; range_iterator(Integer v, Integer step) : val(v), step_(step) {} Integer operator * (){return val;} void operator ++ (){val += step_;} bool operator != (range_iterator& x){return step_ > 0 ? val < x.val : val > x.val;} }; range(Integer len) : start_(0), end_(len), step_(1) {} range(Integer start, Integer end) : start_(start), end_(end), step_(1) {} range(Integer start, Integer end, Integer step) : start_(start), end_(end), step_(step) {} range_iterator begin(){ return range_iterator(start_, step_); } range_iterator   end(){ return range_iterator(  end_, step_); } };

  inline string operator "" _s (const char* str, size_t size){ return move(string(str)); }
  constexpr Integer my_pow(Integer x, Integer k, Integer z=1){return k==0 ? z : k==1 ? z*x : (k&1) ? my_pow(x*x,k>>1,z*x) : my_pow(x*x,k>>1,z);}
  constexpr Integer my_pow_mod(Integer x, Integer k, Integer M, Integer z=1){return k==0 ? z%M : k==1 ? z*x%M : (k&1) ? my_pow_mod(x*x%M,k>>1,M,z*x%M) : my_pow_mod(x*x%M,k>>1,M,z);}
  constexpr unsigned long long operator "" _ten (unsigned long long value){ return my_pow(10,value); }

  inline int k_bit(Integer x, int k){return (x>>k)&1;} //0-indexed

  mt19937 mt(chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count());

  template<class T> string join(const vector<T>& v, const string& sep){ stringstream ss; for(size_t i=0; i<v.size(); i++){ if(i>0) ss << sep; ss << v[i]; } return ss.str(); }

  inline string operator * (string s, int k){ string ret; while(k){ if(k&1) ret += s; s += s; k >>= 1; } return ret; }
}
constexpr long long mod = 9_ten + 7;

int main(){
  long long n,m;
  cin >> n,m;

  long long s,t;
  cin >> s,t;
  s--; t--;

  vector<vector<pair<long long,long long>>> g(n);
  vector<tuple<long long,long long, long long>> e(m);
  for(long long i=0; i<m; i++){
    long long u,v; long long d;
    cin >> u,v,d;
    u--; v--;
    g[u].emplace_back(v, d);
    g[v].emplace_back(u, d);
    e[i] = make_tuple(u,v,d);
  }

  vector<long long> dist_s(n, 1ll<<55);
  vector<long long> dp_s(n, 0);

  vector<long long> dist_t(n, 1ll<<55);
  vector<long long> dp_t(n, 0);

  auto dijkstra = [&g](long long start, long long goal, vector<long long>& dist, vector<long long>& dp)
  {
    dist[start] = 0;
    dp[start] = 1;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push( {dist[start], start} );
    while(pq.size()){
      auto p = pq.top(); pq.pop();
      long long pos = p.second;
      if( pos == goal ) break;
      if( dist[pos] < p.first ) continue;

      for(auto f : g[pos]){
        long long nx = f.first;
        long long dd = dist[pos] + f.second;
        if( dd < dist[nx] ){
          dist[nx] = dd;
          dp[nx] = dp[pos];
          pq.push( {dist[nx], nx} );
        }else if( dd == dist[nx] ){
          dp[nx] += dp[pos];
          if( dp[nx] >= mod ) dp[nx] -= mod;
        }
      }
    }
  };

  dijkstra(s,t, dist_s, dp_s);
  dijkstra(t,s, dist_t, dp_t);

  long long ans = dp_s[t] * dp_t[s] % mod;

  long long ddd = dist_s[t];

  for(long long v=0; v<n; v++){
    if( dist_s[v] + dist_t[v] != ddd ) continue;
    if( dist_s[v] == dist_t[v] ){
      long long tmp = dp_s[v] * dp_t[v] % mod;
      ans = (ans - tmp*tmp%mod + mod) % mod;
      // ans = (ans + tmp*tmp%mod + mod) % mod;
    }
  }

  for(long long i=0; i<m; i++){
    long long u,v; long long d;
    tie(u,v,d) = e[i];

    if( dist_s[u] > dist_s[v] ) swap(u,v);

    if( abs( dist_s[u] - dist_s[v] ) != d ) continue;
    if( abs( dist_t[u] - dist_t[v] ) != d ) continue;

    if( dist_s[u] + dist_t[v] + d != ddd ) continue;

    if(
      ( dist_s[u] <= dist_t[v] && dist_t[v] < dist_s[v] ) ||
      ( dist_t[v] <= dist_s[u] && dist_s[u] < dist_t[u] ) 
    ){
      long long x = dp_s[u] * dp_t[v] % mod;
      long long y = dp_t[v] * dp_s[u] % mod;
      ans = (ans - x*y%mod + mod) % mod;
    }
  }

  assert( ans >= 0 );

  println( ans%mod );

  return 0;
}
