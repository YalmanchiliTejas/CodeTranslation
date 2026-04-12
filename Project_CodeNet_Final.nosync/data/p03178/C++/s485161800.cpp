#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // Educational DP - S Digit Sum
  // dp[i][j][k]:上位からi桁目まで各桁の総和をDで割った際の余りがkとなる数値の個数
  // Dの倍数とは、Dで割った際の余りが0のこと、和なのでmodを好きなタイミングでとれる
  // [(s%D + k) % D]　←　毎回mod Dをとってやる
  // [j || s < ｎ]:未満フラグが立つ条件　→　すでにj==1又はsがn未満のとき
  ll mod = 1e9 + 7; 
  string K;
  int D, N;
  cin >> K >> D;
  N = K.size();
  vector<vector<vector<ll> > > dp(N+1, vector<vector<ll> >(2, vector<ll>(D, 0)));
  dp[0][0][0] = 1;  // 初期値

  REP(i, N){
    int n = (int)(K.at(i) - '0');  // stringから数字を抜き出す
    REP(j, 2){
      REP(k, D){
        for(int s = 0; s <= (j ? 9 : n); s++){
          dp[i+1][j || s < n][(s%D + k) % D] += dp[i][j][k] % mod;
        }
      }
    }
  }

  cout << (dp[N][0][0] + dp[N][1][0] - 1) % mod << endl;  // 0を含んでいるので-1
}

