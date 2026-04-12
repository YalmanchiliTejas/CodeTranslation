#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
//#define ll long long
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define rep(i, n) REP(i, 0, n)
#define rep_rev(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define all(x) (x).begin(),(x).end()
ll t1,t2,t3;
const ll mod = 1000000007;
const int INF = 1e9;
const ll INFLONG = 1e18;




int main(){
  ll n;
  cin >> n;
  vector<ll> vec(n);
  rep(i,n){
    cin >> vec[i];
  }
  ll ans = -INFLONG;
  vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(2,vector<ll>(3,-INFLONG)));
  dp[0][1][1] = 0;
  rep(i,n){
    if(i % 2 == 0){
      rep(j,3){
        chmax(dp[i+1][1][j],dp[i][1][j]);
        chmax(dp[i+1][0][j],dp[i][0][j]);
      }
      chmax(dp[i+1][1][0],dp[i][0][0]);

      chmax(dp[i+1][0][1],dp[i][1][0] + vec[i]);
      chmax(dp[i+1][1][1],dp[i][0][1]);

      chmax(dp[i+1][0][2],dp[i][1][1] + vec[i]);
      chmax(dp[i+1][1][2],dp[i][0][2]);
    }else{
      rep(j,2){
        chmax(dp[i+1][1][j],dp[i][1][j+1]);
        chmax(dp[i+1][0][j],dp[i][0][j+1]);
      }
      chmax(dp[i+1][0][0],dp[i][1][0] + vec[i]);
      chmax(dp[i+1][1][0],dp[i][0][1]);

      chmax(dp[i+1][0][1],dp[i][1][1] + vec[i]);
      chmax(dp[i+1][1][1],dp[i][0][2]);
    }
  }
//    rep(i,n+1){
//      rep(j,2){
//        rep(k,3){
//          cout << dp[i][j][k];
//        }
//        cout << " ";
//      }
//      cout << endl;
//    }
  ans = max(dp[n][0][1],dp[n][1][1]);
  cout << ans << endl;
}