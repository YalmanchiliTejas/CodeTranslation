#include <iostream>
#include <map>
#include <set>
using namespace std;

long long int INF = 110110110;
long long int _INFL = -INF * INF;

int N;
int A[200100];
long long int dp[200100][20];//i/2-j+10

int main(){
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  for (int i = 0; i < 200100; i++){
    for (int j = 0; j < 20; j++){
      dp[i][j] = _INFL;
    }
  }

  dp[0][10] = 0;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < 20; j++){
      if (i/2 - j + 10 < 0) continue;
      //dont choose
      int nj = (i+1) / 2 - i / 2 + j;
      if(nj < 20){
        dp[i+1][nj] = max(dp[i+1][nj], dp[i][j]);
      }
      //choose
      nj = (i+2) / 2 - i / 2 + j - 1;
      if(nj < 20){
        dp[i+2][nj] = max(dp[i+2][nj], dp[i][j] + A[i]);
      }
    }
  }
  long long int ans = _INFL;
  for (int i = 0; i <= N+1; i++){
    for (int j = 0; j < 20; j++){
      if (i / 2 - j + 10 == N / 2){
        ans = max(ans, dp[i][j]);
      }
    }
  }
  cout << ans << endl;
}
