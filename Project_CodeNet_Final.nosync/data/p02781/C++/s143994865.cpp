#include <bits/stdc++.h>
#define LLI long long int
#define FOR(v, a, b) for(LLI v = (a); v < (b); ++v)
#define FORE(v, a, b) for(LLI v = (a); v <= (b); ++v)
#define REP(v, n) FOR(v, 0, n)
#define REPE(v, n) FORE(v, 0, n)
#define REV(v, a, b) for(LLI v = (a); v >= (b); --v)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define ITR(it, c) for(auto it = (c).begin(); it != (c).end(); ++it)
#define RITR(it, c) for(auto it = (c).rbegin(); it != (c).rend(); ++it)
#define EXIST(c,x) ((c).find(x) != (c).end())
#define fst first
#define snd second
#define popcount __builtin_popcount
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
template <typename T> void puts_all(const T &value){std::cout << value << "\n";}
template <typename T, typename ...Args> void puts_all(const T &value, const Args&... args){std::cout << value << " ";puts_all(args...);}

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

LLI dp[200][4][2];


int main(){
  string N;
  int K;

  while(cin >> N >> K){

    fill_array(dp, 0);

    dp[0][0][0] = 1;

    int s = N.size();

    REP(i,s){
      REPE(j,K){
        REP(k,2){

          FORE(d,0,9){
            
            int nj = j + (d == 0 ? 0 : 1);
            if(nj <= 3){
              
              /*              bool nk;

              if(k){
                nk = true;
              }else{
                if(N[i]-'0' == d){
                  nk = false;
                }else if(N[i]-'0' > d){
                  nk = true;
                }else{
                  continue;
                }
                }*/


              if(k or N[i] - '0' >= d){
                dp[i+1][nj][k or N[i]-'0' > d] += dp[i][j][k];
              }

              //dp[i+1][nj][nk] += dp[i][j][k];
            }
            
            /*            
            if(d == 0){
              if(N[i] == '0'){
                dp[i+1][j][k] += dp[i][j][k];
              }else{
                dp[i+1][j][true] += dp[i][j][k];
              }
            }else{
              if(j+1 <= 3){
                if(N[i] == (char)('0'+d)){
                  dp[i+1][j+1][k] += dp[i][j][k];
                }else if(N[i] > (char)('0'+d)){
                  dp[i+1][j+1][true] += dp[i][j][k];
                }
              }
              }*/


            
          }
        }
      }
    }


    LLI ans = 0;
    ans = dp[s][K][0] + dp[s][K][1];

    puts_all(ans);
  }


  return 0;
}
