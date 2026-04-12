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
constexpr long long mod = 998244353;

// [l,r]
int dp_rec(string& s, int l, int r, vector<vector<int>>& dp){
  if(l>r) return 0;
  if(dp[l][r] != -1) return dp[l][r];
  if(l==r) return dp[l][r] = 0;
  if(l+1==r){
    return dp[l][r] = s[l] == s[r] || s[l] == 'C' || s[r] == 'C';
  }

  if(s[l] == s[r] || s[l] == 'C' || s[r] == 'C'){
    if(dp_rec(s, l+1, r-1, dp)){
      return dp[l][r] = 1;
    }
  }

  for(int c=0; c<r; c++){
    if(dp_rec(s, l, c, dp) && dp_rec(s, c+1, r, dp)){
      return dp[l][r] = 1;
    }
  }

  return dp[l][r] = 0;
}

bool check(string s){
  vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
  bool ok = dp_rec(s, 0, s.size()-1, dp);
  // eprintln(ok);

  // eprintln(s);
  // for(int l=0; l<s.size(); l++){
  //   string tmp_ok(s.size(), '_');
  //   for(int r=l; r<s.size(); r++){
  //     tmp_ok[r] = s[r];
  //     if(dp[l][r] == 1){
  //       eprintln(tmp_ok);
  //     }
  //   }
  // }
  return ok;
}

int rec(string& s, int n, int k){
  if(k == n){
    if(check(s)){
      // eprintln(s);
      return 1;
    }else{
      eprintln(s);
      return 0;
    }
  }

  int res = 0;
  s[k] = 'A';
  res += rec(s, n, k+1);
  s[k] = 'B';
  res += rec(s, n, k+1);
  // s[k] = 'C';
  // res += rec(s, n, k+1);
  return res;
}


// precomputation O(size)
class combination_mod{
  const long long mod;
  const long long size;
  
  vector<long long> fact; //n!
  vector<long long> fact_inv; // (n!)^-1

  void make_fact(){
    fact[0] = 1;
    for(long long i=1; i<size; i++){
      fact[i] = fact[i-1]*i % mod;
    }
  }

  void make_fact_inv(){
    fact_inv[0] = fact_inv[1] = 1;
    for(long long i=2; i<size; i++){
      fact_inv[i] = fact_inv[mod%i] * (mod - mod/i) % mod;  // x ^ -1
    }
    for(int i=2; i<size; i++){
      fact_inv[i] = fact_inv[i-1] * fact_inv[i] % mod;  // x! ^ -1
    }
  }

public:
  combination_mod(long long mod_, long long size_ = 2000000) : mod(mod_), size(size_+1){
    fact.resize(size);
    fact_inv.resize(size);
    make_fact();
    make_fact_inv();
  }

  //nCk mod p O(1)
  long long operator()(long long n, long long k){
    if(n<0 || k<0) return 0;
    if(k==0 || n==k) return 1;
    long long ret = fact[n] * fact_inv[k] % mod * fact_inv[n-k] % mod;
    return ret;
  }
};


int main(){
  // string s;
  // cin >> s;
  // check(s);
  // int len;
  // cin >> len;
  // string s(len, '.');
  // int ans = rec(s, len, 0);
  // eprintln(ans);

  int n;
  cin >> n;
  combination_mod c(mod, n+1);

  long long s = 0;
  for(int k=n/2+1; k<=n; k++){
    int r = n-k;
    s += c(n, k) * my_pow_mod(2, r, mod) % mod;
    if(s >= mod) s -= mod;
  }

  s += s;
  if(s >= mod) s %= mod;

  long long ans = my_pow_mod(3, n, mod);
  ans = (ans - s + mod) % mod;
  println(ans);
  return 0;
}
