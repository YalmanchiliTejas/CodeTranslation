#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int64_t MOD = 1000000007;
  
  int N; cin >> N; int64_t sum = 0, ans = 0;
  
  vector<int64_t> vec(N);
  
  for (int i = 0; i < N; i++) {
    
    int64_t A; cin >> A;
    
    vec[i] = A; sum += A;
    
  }
  
  for (int i = 0; i < N; i++) {
    
    sum -= vec[i];
    
    ans += sum % MOD * vec[i] % MOD;
    
    ans %= MOD;
    
  }
  
  cout << ans << endl;
  
}