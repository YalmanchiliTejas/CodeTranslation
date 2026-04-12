#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

using ipair = pair<ll,ll>;

ll INF = 1e16+7;

bool operator>(const ipair a,const ipair b){return a.first > b.first;}

int dp[101][4][2];

int main(){

  string S;
  cin >> S;
  int N = S.size();
  int K;
  cin >> K;

  dp[0][0][0] = 1;

  rep(i, N) rep(j, 4) rep(k, 2){
    int nd = S[i] - '0';
    rep(d, 10){
      // 次の状態
      int ni = i+1, nj = j, nk = k;
      // 次の状態の条件
      if(d != 0) nj++;
      if(K < nj) continue;
      if(k==0){
        if(nd < d) continue;
        if(nd > d) nk = 1;
      }
      // 遷移
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }

  int ans = dp[N][K][0] + dp[N][K][1];
  cout << ans << endl;

  return 0;
}
