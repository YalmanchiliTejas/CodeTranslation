#include<stdio.h>
#include<iostream>
#include<algorithm> // sort(ALL())
#include<string>
#include<string> // to_string()
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue> // push(), front(), pop() 先入れ先出し
#include<map> // 連想配列 map<string, int>
#include<iomanip>
#include<set>
#include<utility>
using namespace std;
#define FOR(i, a, b) for(int i=(a); i<(b);  i++)
#define REP(i, n)    for(int i=0;   i<(n);  i++)
#define REP1(i, n)   for(int i=1;   i<=(n); i++)
#define scan(argument) cin>>argument

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string n;
  int k;
  scan(n); scan(k);
  int di = n.length();

  int dp0[di+1][k+1];
  int dp1[di+1][k+1];

  REP1(i, di){
    dp0[i][0] = 1; // 0, 00, 000, ...
    dp1[i][0] = 0;
  }

  dp0[1][1] = (int)(n[0]-'0')-1; // 1 ~ n[0]-1
  dp1[1][1] = 1; // n[0]
  FOR(j, 2, k+1){
    dp0[1][j] = 0;
    dp1[1][j] = 0;
  }

  REP1(i ,di-1){ // 上からi桁目まで決めて
    REP(j, k){ // 0でない桁がj個ある
      int ni = (int)(n[i]-'0'); // 上からi+1番目
      if(ni == 0){
        dp0[i+1][j+1] = dp0[i][j]*9 + dp0[i][j+1]; // 1~9, 0
        dp1[i+1][j+1] = dp1[i][j+1]; // 0
      }
      else{
        dp0[i+1][j+1] = dp0[i][j]*9 + dp0[i][j+1]  // 1~9, 0
                      + dp1[i][j]*(ni-1) + dp1[i][j+1]; // 1~ni-1, 0
        dp1[i+1][j+1] = dp1[i][j];
      }
    }
  }

  cout << dp0[di][k] + dp1[di][k] << "\n";

  return 0;
}
