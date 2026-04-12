#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> A(N);
  for(int i = 0; i < N; ++i){
    cin >> A[i];
  }
  int m = 2+N%2;
  const long long INF = 1e18;
  vector<long long> dp(m,-INF);
  dp[0] = 0;
  for(int i = 0; i < N; ++i){
    vector<long long> dp_(m,-INF);
    for(int j = 0; j < m; ++j){
      if(dp[j] == -INF) continue;
      dp_[j] = max(dp_[j],dp[j]+((i+j)%2 ? 0 : A[i]));
      if(j+1 < m)
        dp_[j+1] = max(dp_[j+1],dp[j]);
    }
    swap(dp,dp_);
  }
  cout << dp.back() << endl;
}
