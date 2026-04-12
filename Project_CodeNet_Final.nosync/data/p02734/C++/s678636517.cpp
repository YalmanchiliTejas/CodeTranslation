#include<bits/stdc++.h>
using namespace std;

const int MAX = 3010;
const int64_t MOD = 998244353;
int64_t dp[MAX][MAX];

int main(){
  int N, S;
  cin >> N >> S;
  vector<int> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
  }
  int64_t ans = 0;
  for(int i=0; i<N; i++){
    dp[i+1][vec[i]] += i+1;
    if(vec[i] == S){
      ans += (i+1)*(N-i);
      ans %= MOD;
    }
    for(int j=0; j<MAX; j++){
      dp[i+1][j] += dp[i][j];
      dp[i+1][j] %= MOD;
      if(dp[i][j] != 0 && j + vec[i] < MAX){
        dp[i+1][j+vec[i]] += dp[i][j];
        dp[i+1][j] %= MOD;
        if(j + vec[i] == S){
          ans += dp[i][j]*(N-i);
          ans %= MOD;
        }
      }
    }
  }
  cout << ans << endl;
}
        