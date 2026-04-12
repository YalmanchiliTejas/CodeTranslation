#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  
  cin >> N;
  
  long long sum = 0;
  vector<long long> A, A_sum_excepted;
  
  for (int i = 0; i < N; i++) {
    long long inA;
    
    cin >> inA;
    
    sum += inA;
    A.push_back(inA);
  }
  
  for (int i = 0; i < N - 1; i++) {
    sum -= A[i];
    A_sum_excepted.push_back((sum % 1000000007));
  }
  
  long long ans = 0;
  for (int i = 0; i < N - 1; i++) {
    ans += A_sum_excepted[i] * A[i];
    ans %= 1000000007;
  }
  
  cout << ans << endl;
  
  return 0;
}