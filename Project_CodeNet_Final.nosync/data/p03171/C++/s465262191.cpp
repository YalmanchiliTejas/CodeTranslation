#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;

int main(){
  int N;
  cin >> N;
  int a[3010];
  for(int i=0; i<N; i++) cin >> a[i];
  LL dp[3010][3010];
  for(int i=1; i<=N; i++){
    for(int j=0; j<=N-i; j++){
      dp[i][j]=max(a[j+i-1]-dp[i-1][j],a[j]-dp[i-1][j+1]);
    }
  }
  cout << dp[N][0] << endl;
  
  return 0;
}