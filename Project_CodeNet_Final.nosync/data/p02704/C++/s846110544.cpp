#include <algorithm>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define FOR(i,k,n) for(int(i)=(k);(i)<(n);++(i))
#define rep(i,n) FOR(i,0,n)
#define all(v) begin(v),end(v)
#define debug(x) std::cerr<<#x<<": "<<x<<"\n"
#define debug2(x,y) std::cerr<<#x<<": "<<x<<", "<<#y<<": "<<y<<"\n"
#define debug3(x,y,z) std::cerr<<#x<<": "<<x<<", "<<#y<<": "<<y<<", "<<#z<<": "<<z<<"\n"

using ll=long long;
using vi=std::vector<int>;
using vvi=std::vector<vi>;
using vll=std::vector<ll>;
using vvll=std::vector<vll>;
template<typename T> using vvec=std::vector<std::vector<T>>;
template<typename T>
auto make_v(size_t sz){return std::vector<T>(sz);}
template<typename T,typename... Ts>
auto make_v(size_t sz,Ts...ts){return std::vector<decltype(make_v<T>(ts...))>(sz,make_v<T>(ts...));}
template<typename T>
void fill_v(T&var,const T&x){var=x;}
template<typename V,typename T>
void fill_v(V&v,const T&x){for(auto&& w:v){fill_v(w,x);}}

template<typename T> std::ostream& operator<<(std::ostream&s,const std::vector<T>&v){
  int sz=v.size();s<<"\n";rep(i,sz){s<<v[i];if(i<sz-1){s<<"\t";}}s<<"\n";return s;}
template<typename T> std::ostream& operator<<(std::ostream&s,const std::vector<std::vector<T>>&v){
  for(auto&& w:v){s<<w;}return s;}
template<typename T> std::ostream& operator<<(std::ostream&s,const std::deque<T>&v){
  int sz=v.size();s<<"\n";rep(i,sz){s<<v[i];if(i<sz-1){s<<"\t";}}s<<"\n";return s;}
template<typename T> std::ostream& operator<<(std::ostream&s,const std::deque<std::deque<T>>&v){
  for(auto&& w:v){s<<w;}return s;}
template<typename T> std::ostream& operator<<(std::ostream&s, const std::set<T>&v){
  s<<"\n";for(auto&& elm:v){s<<elm<<"\t";}s<<"\n";return s;}

inline void scan(int&a){scanf("%d",&a);}
inline void scan(ll&a){scanf("%lld",&a);}

using ull = unsigned long long;
inline void scan(ull&a){scanf("%llu",&a);}

inline void scan(char&a){scanf(" %c",&a);}
inline void scan(double&a){scanf("%lf",&a);}
template<typename T>
inline void scan(std::vector<T>&v){for(auto&& sv:v){scan(sv);}}
template<typename First,typename...Args>
inline void scan(First&f,Args&...args){scan(f);scan(args...);}
inline void scan(std::string&s){char BUF[3000000];scanf(" %s",BUF);s=std::string(BUF);}
inline void print(int a){printf("%d\n",a);}
inline void print(ll a){printf("%lld\n",a);}
inline void print(double a){printf("%.12f\n",a);}
inline void print(std::string s){std::cout<<s<<"\n";}

using namespace std;

// return k-th bit of x
int get_bit(ull x, int k) {
  return (x >> k) & 1;
}

int n;
int b = 64;
void print_(vector<vector<vi> > & bits) {
  rep (i, n) {
    rep (j, n) {
      ull num = 0;
      rep (k, b) {
        num |= ((ull)bits[i][j][k] << k);
      }
      printf("%llu%c", num, " \n"[j == n-1]);
    }
  }
}

void solve() {
  scan(n);
  vi s(n), t(n);
  scan(s);
  scan(t);
  vector<ull> u(n), v(n);
  scan(u);
  scan(v);

  vector<vector<vi> > bits(n, vvi(n, vi(b, -1)));
  // sum:0 or product:1
  rep (i, n) {
    rep (j, n) {
      rep (k, b) {
        if (s[i] == 0) {
          if (get_bit(u[i], k) == 1) {
            if (bits[i][j][k] == 0) {
              print(-1);
              return;
            }
            bits[i][j][k] = 1;
          }
        } else {
          if (get_bit(u[i], k) == 0) {
            if (bits[i][j][k] == 1) {
              print(-1);
              return;
            }
            bits[i][j][k] = 0;
          }
        }
        if (t[j] == 0) {
          if (get_bit(v[j], k) == 1) {
            if (bits[i][j][k] == 0) {
              print(-1);
              return;
            }
            bits[i][j][k] = 1;
          }
        } else {
          if (get_bit(v[j], k) == 0) {
            if (bits[i][j][k] == 1) {
              print(-1);
              return;
            }
            bits[i][j][k] = 0;
          }
        }
      }
    }
  }
  rep (i, n) {
    rep (j, n) {
      rep (k, b) {
        int bit_u = get_bit(u[i], k);
        int bit_v = get_bit(v[j], k);
        bits[i][j][k] = max(bits[i][j][k], 0);
        if (bit_u == 1 and bit_v == 1) {
          bits[i][j][k] = 1;
        }
        if ((s[i] == 0 and bit_u == 1) or (t[j] == 0 and bit_v == 1)) {
          if (bits[i][j][k] == 0) {
            print(-1);
            return;
          }
        }
        if ((s[i] == 1 and bit_u == 0) or (t[j] == 1 and bit_v == 0)) {
          if (bits[i][j][k] == 1) {
            print(-1);
            return;
          }
        }
      }
    }
  }
  rep (k, b) {
    rep (i, n) {
      if (not (s[i] == 0 and u[i] == 0)) { continue; }
      int bwand = bits[i][0][k];
      rep (j, n) {
        bwand &= bits[i][j][k];
      }
      if (bwand == 1) {
        print(-1);
        return;
      }
    }
    rep (j, n) {
      if (not (t[j] == 0 and v[j] == 0)) { continue; }
      int bwand = bits[0][j][k];
      rep (i, n) {
        bwand &= bits[i][j][k];
      }
      if (bwand == 1) {
        print(-1);
        return;
      }
    }
  }
  //debug(bits);
  // sum:1 or product:0
  // one or more 1, one or more 0
  rep (k, b) {
    //debug(k);
    rep (i, n) {
      //debug(i);
      if (not (s[i] == 1 and get_bit(u[i], k) == 1)) { continue; }
      bool ok = false;
      rep (j, n) {
        if (bits[i][j][k] == 1) {
          ok = true;
        }
      }
      if (ok) { continue; }
      rep (j, n) {
        if (not (t[j] == 0 and get_bit(v[j], k) == 0)) { continue; }
        int cnt = 0;
        rep (i2, n) {
          cnt += 1 ? (bits[i2][j][k] == 0) : 0;
          if (cnt == 2) {
            assert (bits[i][j][k] == 0);
            bits[i][j][k] = 1;
            ok = true;
            break;
          }
        }
        if (ok) { break; }
      }
      if (not ok) {
        print(-1);
        return;
      }
    }
    rep (j, n) {
      //debug(j);
      if (not (t[j] == 1 and get_bit(v[j], k) == 1)) { continue; }
      bool ok = false;
      rep (i, n) {
        if (bits[i][j][k] == 1) {
          ok = true;
        }
      }
      if (ok) { continue; }
      rep (i, n) {
        if (not (s[i] == 0 and get_bit(u[i], k) == 0)) { continue; }
        int cnt = 0;
        rep (j2, n) {
          cnt += 1 ? (bits[i][j2][k] == 0) : 0;
          if (cnt == 2) {
            assert (bits[i][j][k] == 0);
            bits[i][j][k] = 1;
            ok = true;
            break;
          }
        }
        if (ok) { break; }
      }
      if (not ok) {
        print(-1);
        return;
      }
    }
  }
  print_(bits);
}

int main() {
  solve();
  return 0;
}
