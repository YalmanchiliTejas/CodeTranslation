#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>

#define rep(i,n) for(int i=0;i<n;i++)
#define dup(x,y) (((x)+(y)-1)/(y)) // dup * y >= x なる最小のdup.
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;

int main() {
  /* 桁DP */
  string N_str; int K;
  cin >> N_str >> K;

  int dp1[101][3]; // dp[i][j] ... 左からi+1桁目までで、0でない桁がj+1個で、Nより小さいことが確定している
  int dp2[101][3]; // dp[i][j] ... 左からi+1桁目までで、0でない桁がj+1個で、Nより小さいことが確定していない。

  dp1[0][0] = N_str[0] - '0' -1;
  dp1[0][1] = 0;
  dp1[0][2] = 0;

  dp2[0][0] = 1;
  dp2[0][1] = 0; 
  dp2[0][2] = 0;
  
  for(int i=1; i<N_str.size(); i++) {


    if(N_str[i]-'0'>0) {
      dp1[i][0] = 9               + dp1[i-1][0] * 1 + dp2[i-1][0] * 1; // 00.'*'..., *00..'0'.., 3'0'...
      dp1[i][1] = dp1[i-1][0] * 9 + dp1[i-1][1] * 1 + dp2[i-1][1] * 1 + dp2[i-1][0] * (N_str[i]-'0'-1); // *...'*'..., **...'0'..., 31'4'...
      dp1[i][2] = dp1[i-1][1] * 9 + dp1[i-1][2] * 1 + dp2[i-1][2] * 1 + dp2[i-1][1] * (N_str[i]-'0'-1); // **..'*'..., ***..'0'..., 314'0'...
      
      dp2[i][0] = 0; // 30...
      dp2[i][1] = dp2[i-1][0]; // 31....
      dp2[i][2] = dp2[i-1][1]; // 314...
    } else {
      dp1[i][0] = 9               + dp1[i-1][0] * 1; // 00.'*'..., *00..'0'..
      dp1[i][1] = dp1[i-1][0] * 9 + dp1[i-1][1] * 1; // *...'*'..., **...'0'...
      dp1[i][2] = dp1[i-1][1] * 9 + dp1[i-1][2] * 1; // **..'*'..., ***..'0'...

      dp2[i][0] = dp2[i-1][0]; // 30...
      dp2[i][1] = dp2[i-1][1]; // 310...
      dp2[i][2] = dp2[i-1][2]; // 3140...
    }
  }

  // rep(i, N_str.size()) cout << dp1[i][0] << ' ';
  // cout << endl;
  // rep(i, N_str.size()) cout << dp1[i][1] << ' ';
  // cout << endl;
  // rep(i, N_str.size()) cout << dp1[i][2] << ' ';
  // cout << endl;


  cout << dp1[N_str.size()-1][K-1] + dp2[N_str.size()-1][K-1] << endl;

  return 0;
}