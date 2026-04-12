#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1000000007;
const ll INF = 9999999999;
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
  T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }

ll solve(string s, int k){
  // 0以上N以下の整数であって、条件を満たすものの個数を求めよ
  // 条件：10進法で表した時、0でない数字が丁度K個ある
  const int L = s.size();
  
  vector<vector<vector<ll>>> dp(L+1, vector<vector<ll>>(2, vector<ll>(5, 0)));
  // dp[i][j][k]...i桁決定、jはN未満フラグ、kは0でない数字の個数(0,1,2,3,4。4はバッファ)

  dp.at(0).at(0).at(0) = 1;

  for (int i=0; i<L; i++){
    int D = s.at(i) - '0';
    for (int j=0; j<2; j++){
      for (int k=0; k<4; k++){
        for (int d=0; d<=(j ? 9 : D); d++){
          /* 添え字の遷移について
          i...次へ行くので必ずi+1
          j...元々1なら1。0なら、dがD未満なら1, そうでなければ0
          k...d==0ならそのまま。d!=0ならプラス1。
          */
          dp.at(i+1).at(j || (d < D)).at(k + (d != 0)) += dp.at(i).at(j).at(k);
          // dp.at(i+1).at(j || (d < D)).at(k || d == 4 || d == 9) += dp.at(i).at(j).at(k);
        }
      }
    }
  }
  return dp.at(L).at(0).at(k) + dp.at(L).at(1).at(k);
}

int main() {
  string s; cin >>s;
  int k; cin >>k;

  cout <<solve(s, k) <<endl;
}