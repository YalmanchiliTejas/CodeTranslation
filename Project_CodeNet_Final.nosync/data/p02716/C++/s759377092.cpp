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
    vector<i64> A(N); cin >> A;

    if(N % 2 == 0){
      vector<i64> se, so;

      so.push_back(0);

      REP(i,N){
        if(i % 2 == 0){
          so.push_back(A[i]);
        }else{
          se.push_back(A[i]);
        }
      }

      REP(i,N/2){
        so[i+1] += so[i];
      }

      se.push_back(0);
      reverse(ALL(se));

      REP(i,N/2){
        se[i+1] += se[i];
      }

      reverse(ALL(se));

      dump(so, se);

      i64 ans = LLONG_MIN;

      REPE(i,N/2){
        chmax(ans, so[i] + se[i]);
      }
      
      pout(ans);
    }else{
      i64 ans = LLONG_MIN;

      {
        i64 t = 0;

        REP(i,N) if(i % 2 == 1) t += A[i];

        chmax(ans, t);
      }

      {
        auto dp = make_vector<i64>(N+10, 3, LLONG_MIN);

        dp[0][0] = 0;
        
        REP(i,N){
          if(dp[i][0] != LLONG_MIN and i % 2 == 0){
            chmax(dp[i+2][0], dp[i][0] + A[i]);
            chmax(dp[i+3][1], dp[i][0] + A[i]);
          }
          if(dp[i][1] != LLONG_MIN and i % 2 == 1){
            chmax(dp[i+2][1], dp[i][1] + A[i]);
            chmax(dp[i+3][2], dp[i][1] + A[i]);
          }
          if(dp[i][2] != LLONG_MIN and i % 2 == 0){
            chmax(dp[i+2][2], dp[i][2] + A[i]);
          }
        }

        chmax(ans, dp[N-1][0]);
        chmax(ans, dp[N][1]);
        chmax(ans, dp[N+1][2]);
      }

      reverse(ALL(A));
      
      {
        auto dp = make_vector<i64>(N+10, 3, LLONG_MIN);

        dp[0][0] = 0;
        
        REP(i,N){
          if(dp[i][0] != LLONG_MIN and i % 2 == 0){
            chmax(dp[i+2][0], dp[i][0] + A[i]);
            chmax(dp[i+3][1], dp[i][0] + A[i]);
          }
          if(dp[i][1] != LLONG_MIN and i % 2 == 1){
            chmax(dp[i+2][1], dp[i][1] + A[i]);
            chmax(dp[i+3][2], dp[i][1] + A[i]);
          }
          if(dp[i][2] != LLONG_MIN and i % 2 == 0){
            chmax(dp[i+2][2], dp[i][2] + A[i]);
          }
        }

        chmax(ans, dp[N-1][0]);
        chmax(ans, dp[N][1]);
        chmax(ans, dp[N+1][2]);
      }

      

      pout(ans);
    }
  }

  return 0;
}
