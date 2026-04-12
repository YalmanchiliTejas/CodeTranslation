#include<bits/stdc++.h>
using namespace std;
int N, M;
int A[10];
int dp[100001];

bool Check(int k)
{
  fill_n(dp, 100001, -1);
  dp[0] = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j <= M; j++) {
      if(dp[j] >= 0) {
        dp[j] = k;
      } else if(j < A[i] || dp[j - A[i]] <= 0) {
        dp[j] = -1;
      } else {
        dp[j] = dp[j - A[i]] - 1;
      }
    }
  }
  return(dp[M] >= 0);
}


int main()
{
  while(cin >> N >> M, N) {
    for(int i = 0; i < N; i++) {
      cin >> A[i];
    }
    int low = 0, high = M / *min_element(A, A + N);
    while(high - low > 0) {
      int mid = (low + high) >> 1;
      if(Check(mid)) high = mid;
      else low = mid + 1;
    }
    cout << low << endl;
  }
}