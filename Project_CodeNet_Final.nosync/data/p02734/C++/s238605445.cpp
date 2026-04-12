#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
using namespace std;
const long long MOD = 998244353;
long long A[3000];
long long dp_left[3000][3001];
long long dp_right[3000][3001];
int main(){
  int N;
  int S;
  cin >> N >> S;
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }

  dp_left[0][0] = 1;
  dp_left[0][A[0]] = 1;
  for(int i = 1; i < N; i++){
    for(int j = 0; j <= S; j++){
      dp_left[i][j] = (dp_left[i][j] + dp_left[i - 1][j]) % MOD;
      if(j >= A[i]){
        if(j - A[i] == 0){
          dp_left[i][j] = (dp_left[i][j] + (i + 1)) % MOD;
        } else {
          dp_left[i][j] = (dp_left[i][j] + dp_left[i - 1][j - A[i]]) % MOD;
        }
      }
    }
  }

  /*
  dp_right[N - 1][0] = 1;
  dp_right[N - 1][A[0]] = 1;
  for(int i = N - 1; i >= 0; i--){
    for(int j = 0; j <= S; j++){
      dp_right[i][j] = (dp_right[i][j] + dp_right[i + 1][j]) % MOD;
      if(j >= A[i]){
        dp_right[i][j] = (dp_right[i][j] + dp_right[i + 1][j - A[i]]) % MOD;
      }
    }
  }
  */

  

  long long ans = 0;
  for(int i = 0; i < N; i++){
    long long cur_cases;
    if(i == 0){
      cur_cases = dp_left[i][S];
    } else {
      cur_cases = (dp_left[i][S] -  dp_left[i - 1][S] + MOD) % MOD;
    }
    ans = (ans + (cur_cases * (N - i) % MOD)) % MOD;
  }
  cout << ans << endl;


  return 0;
}
