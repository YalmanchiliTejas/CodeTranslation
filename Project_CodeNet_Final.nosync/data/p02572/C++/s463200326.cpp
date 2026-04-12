#include <bits/stdc++.h>
#include <cmath>

using namespace std;
int main(void) {
  int N;
  cin >> N;
  
  int d = 1000000007;
  vector<int64_t> B(N+1,0);
  vector<int> A(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
    B[i+1] = B[i] + A[i];
  }
  
  int64_t ans = 0;
  for(int i=0; i<N; i++){
    int64_t sum = (B[N]-B[i+1])%d;
    ans += sum*A[i];
    ans %= d;
  }
  
  cout << ans << endl;
  
}