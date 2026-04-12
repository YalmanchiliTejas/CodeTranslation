// https://atcoder.jp/contests/abc154/tasks/abc154_e
// AtCoder Beginner Contest 154
// E - Almost Everywhere Zero

/*
Problem.
n以下で、0でない桁の数がちょうどk個の自然数(>0)の数？

Point.
みるからに桁DP。
dp[桁数(上位から)][0以外の桁数][0]:現在値がn未満であることが確定でない。
dp[桁数(上位から)][0以外の桁数][1]:        ,,           確定である。
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main(){
  string n;
  cin >> n;
  int k;
  cin >> k;
  int dp[101][4][2] = {};
  dp[0][0][0] = 1;

  for(int i = 0; i < n.length(); i++){
    int num = n[i] - '0';
    for(int j = 0; j < k+1; j++){
      for(int l = 0; l < 2; l++){
        for(int d = 0; d < 10; d++){
          int n_zero = (d) ? j + 1 : j;     //0以外を使用したためn_zeroが増加
          if(n_zero > k) continue;          //すでに0でない数がkを超えている。
          if(l == 0 && d > num) continue;   //d > num -> nを超えている
          if(l == 0 && d == num)            //nより小さいことが確定していない
            dp[i+1][n_zero][0] += dp[i][j][l];
          else                              //nより小さいことが確定した。
            dp[i+1][n_zero][1] += dp[i][j][l];
        }
      }
    }
  }
  cout << dp[n.length()][k][0] + dp[n.length()][k][1] << endl;
}
