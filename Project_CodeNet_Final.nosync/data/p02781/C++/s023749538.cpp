#include <bits/stdc++.h>
#define FOR(i, k, n) for(int i = (k); i < (n); i++)
#define FORr(i, k, n) for(int i = (k); i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORr(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
using ll = long long;

int dp[105][4][2];


int nck(int n, int k){
  int ret = 1;
  REP(i, k){
    ret *= n;
    n--;
  }
  FORr(i, k, 1){
    ret /= i;
  }
  return ret;
}

int main(void){
  string s;
  int K;
  cin >> s >> K;

  int n = s.size();
  
  dp[0][0][0] = 1;
  REP(i, n){
    REP(j, 4){
      REP(k, 2){
        //nd:i桁目の数字
        int nd = s[i] - '0';
        
        //0~9まで数字を試す
        REP(d, 10){
          //ni:次の桁
          //nj:使った非0の数
          //nk:i桁目の数字と一致してるか=0,それ以下か=1
          int ni = i+1, nj = j, nk = k;
          //非0ならjを増やす
          if(d != 0) nj++;
          //njがkより大きい->k個非0を使ってたら飛ばす
          if(nj > K) continue;
          //dがndと一致してるか確かめる
          if(k == 0){
            if(d > nd) continue;
            if(d < nd) nk = 1;
          }
          dp[ni][nj][nk] += dp[i][j][k];
        }
      }
    }
  }
  int ans = dp[n][K][0] + dp[n][K][1];
  cout << ans << endl;
  return 0;
}