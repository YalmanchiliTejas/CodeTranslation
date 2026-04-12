#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

//container util
#define all(x) (x).begin(),(x).end()

//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

//const value
//const ll MOD = 1e9 + 7;
//const int dx[] = {0,1,0,-1};//{0,0,1,1,1,-1,-1,-1};
//const int dy[] = {1,0,-1,0};//{1,-1,0,1,-1,0,1,-1};

//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

template <typename T1, typename T2> 
inline bool chmax(T1 &a, T2 b) {
  return a < b && (a = b, true);
}

template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
  return a > b && (a = b, true);
}


ll dp[101010][2][2][4] ;// pos, less , start, notK
int main(){
  string A;
  cin >> A;
  ll n = A.length();
  ll K;
  cin >> K;
  dp[0][0][0][0] = 1;
  rep(i,n) rep(j,2) rep(k,2) rep(notK,4) {
    int lim;
    if(j) lim = 9;
    else  lim = A[i] - '0';

    rep(d, lim + 1){
      if(k == 0){
        if(d==0) dp[i+1][j || d < lim][0][notK] += dp[i][j][k][notK];
        else     dp[i+1][j || d < lim][1][notK+1] += dp[i][j][k][notK];
      }else{
        if(d!=0){
          if(notK + 1 < 4)dp[i+1][j || d < lim][k][notK+1] += dp[i][j][k][notK];
        }else{
          dp[i+1][j || d < lim][k][notK] += dp[i][j][k][notK];
        }
      }
    }
  }
  int ans = 0;
  rep(j,2) ans += dp[n][j][1][K];
  cout << ans << endl;
  return 0;
}

