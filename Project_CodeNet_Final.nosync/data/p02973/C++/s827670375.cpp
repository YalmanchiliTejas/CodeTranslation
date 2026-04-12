#include<bits/stdc++.h>

using namespace std;

#define INF 1145141919

int main(void){
  int N,i,ans=0;
  cin >> N;
  int A[N],dp[N];
  for(i=N-1;i>=0;i--){
    cin >> A[i];
  }
  fill(dp,dp+N,INF);
  for(i=0;i<N;i++){
    *upper_bound(dp,dp+N,A[i])=A[i];
  }
  ans=lower_bound(dp,dp+N,INF)-dp;
  cout << ans << endl;
}