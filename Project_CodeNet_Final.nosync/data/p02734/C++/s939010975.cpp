#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <complex>

using ll = long long int;
using namespace std;

ll MOD = 998244353;

int main(){

  // read problem
  ll N, S, tmp;
  cin >> N >> S;
  vector<ll> A;
  for(ll i = 0; i < N; i++){
    cin >> tmp;
    A.push_back(tmp);
  }

  // solve problem
  vector<vector<ll> > dp(N+1, vector<ll>(S+1));

  // fill dp table
  dp[0][0] = 1;
  for(ll i = 1; i <= N; i++){
    for(ll s = 0; s <= S; s++){
      if(s < A[i-1]){
        dp[i][s] = dp[i-1][s];
      }
      else if(s == A[i-1]){
        dp[i][s] = dp[i-1][s] + i;
      }
      else{
        dp[i][s] = dp[i-1][s] + dp[i-1][s-A[i-1]];
      }
      dp[i][s] = (dp[i][s]+MOD)%MOD;
    }
  }

  // calculate answer
  ll ans = 0;
  for(ll i = 1; i <= N; i++){
    ans = (ans + dp[i][S] + MOD)%MOD;
  }

  cerr << "Answer:" << endl;
  cout << ans << endl;

  return 0;

  
}
