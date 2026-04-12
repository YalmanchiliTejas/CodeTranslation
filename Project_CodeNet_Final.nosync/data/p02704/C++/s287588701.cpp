#include <bits/stdc++.h>

using i32 = int_fast32_t;
using i64 = int_fast64_t;
using u32 = uint_fast32_t;
using u64 = uint_fast64_t;
using f64 = double;
using f80 = long double;

#define FOR(v, a, b) for(i64 v = (a); v < (b); ++v)
#define FORE(v, a, b) for(i64 v = (a); v <= (b); ++v)
#define REP(v, n) FOR(v, 0, n)
#define REPE(v, n) FORE(v, 0, n)
#define REV(v, a, b) for(i64 v = (a); v >= (b); --v)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define ITR(it, c) for(auto it = (c).begin(); it != (c).end(); ++it)
#define RITR(it, c) for(auto it = (c).rbegin(); it != (c).rend(); ++it)
#define EXIST(c,x) ((c).find(x) != (c).end())
#define fst first
#define snd second
#define UNIQ(v) (v).erase(unique(ALL(v)), (v).end())
#define bit(i) (1LL<<(i))

#ifdef DEBUG
#include <Mylib/Debug/debug.cpp>
#else
#define dump(...) ((void)0)
#endif

using namespace std;

template <typename I> void join(ostream &ost, I s, I t, string d=" "){for(auto i=s; i!=t; ++i){if(i!=s)ost<<d; ost<<*i;}ost<<endl;}
template <typename T> istream& operator>>(istream &is, vector<T> &v){for(auto &a : v) is >> a; return is;}
template <typename T> void pout(const T &value){std::cout << value << "\n";}
template <typename T, typename ...Args> void pout(const T &value, const Args&... args){std::cout << value << " ";pout(args...);}

template <typename T, typename U> bool chmin(T &a, const U &b){return (a>b ? a=b, true : false);}
template <typename T, typename U> bool chmax(T &a, const U &b){return (a<b ? a=b, true : false);}
template <typename T, size_t N, typename U> void fill_array(T (&a)[N], const U &v){fill((U*)a, (U*)(a+N), v);}
template <typename T> auto make_vector(int n, int m, const T &value){return vector<vector<T>>(n, vector<T>(m, value));}


struct Init{
  Init(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(12);
  }
}init;




int main(){
  int N;

  while(cin >> N){
    vector<u64> S(N), T(N), U(N), V(N); cin >> S >> T >> U >> V;

    auto ans = make_vector<u64>(N, N, 0);
    bool ok = true;

    REP(k,64){
      const u64 mask = 1LL << k;

      auto a = make_vector<optional<u64>>(N, N, nullopt);

      auto check_r =
        [&](int r){
          if(S[r] == 0){
            u64 t = mask;
            REP(j,N) t &= *a[r][j];
            if(t != (U[r] & mask)) return false;
          }else{
            u64 t = 0;
            REP(j,N) t |= *a[r][j];
            if(t != (U[r] & mask)) return false;
          }

          return true;
        };

      auto check_c =
        [&](int c){
          if(T[c] == 0){
            u64 t = mask;
            REP(i,N) t &= *a[i][c];
            if(t != (V[c] & mask)) return false;
          }else{
            u64 t = 0;
            REP(i,N) t |= *a[i][c];
            if(t != (V[c] & mask)) return false;
          }

          return true;
        };

      vector<int> rs, cs;

      REP(i,N){
        if(S[i] == 0 and U[i] & mask){
          REP(j,N) a[i][j] = mask;
        }else if(S[i] == 1 and !(U[i] & mask)){
          REP(j,N) a[i][j] = 0;
        }else{
          rs.push_back(i);
        }
      }

      REP(j,N){
        if(T[j] == 0 and V[j] & mask){
          REP(i,N) a[i][j] = mask;
        }else if(T[j] == 1 and !(V[j] & mask)){
          REP(i,N) a[i][j] = 0;
        }else{
          cs.push_back(j);
        }
      }


      if(rs.size() >= 2 and cs.size() >= 2){
        for(auto r : rs){
          for(auto c : cs){
            a[r][c] = 0;
          }
        }
        
        if(rs.size() > cs.size()){
          REP(i,rs.size()){
            a[rs[i]][cs[i % cs.size()]] = mask;
          }
        }else{
          REP(j,cs.size()){
            a[rs[j % rs.size()]][cs[j]] = mask;
          }
        }
      }else if(rs.size() == 1){
        int r = rs[0];

        if(S[r] == 0){
          REP(j,N){
            if(!a[r][j]){
              a[r][j] = 0;
              if(not check_c(j)) a[r][j] = mask;
            }
          }
        }else{
          REP(j,N){
            if(!a[r][j]){
              a[r][j] = mask;
              if(not check_c(j)) a[r][j] = 0;
            }
          }
        }
      }else if(cs.size() == 1){
        int c = cs[0];

        if(T[c] == 0){
          REP(i,N){
            if(!a[i][c]){
              a[i][c] = 0;
              if(not check_r(i)) a[i][c] = mask;
            }
          }
        }else{
          REP(i,N){
            if(!a[i][c]){
              a[i][c] = mask;
              if(not check_r(i)) a[i][c] = 0;
            }
          }
        }
      }

      dump(a);


      REP(i,N){
        REP(j,N){
          if(!a[i][j]) ok = false;
        }
      }


      if(not ok) break;

      
      REP(i,N){
        if(not check_r(i)) ok = false;
      }

      REP(j,N){
        if(not check_c(j)) ok = false;
      }

      if(not ok) break;

      REP(i,N){
        REP(j,N){
          ans[i][j] += *a[i][j];
        }
      }
    }

    if(ok){
      REP(i,N){
        join(cout, ALL(ans[i]));
      }
    }else{
      pout(-1);
    }
  }

  return 0;
}
