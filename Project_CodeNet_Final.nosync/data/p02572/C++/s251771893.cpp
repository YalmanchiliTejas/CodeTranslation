#include<bits/stdc++.h>

const int MOD = 1e9 + 7;

using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<long long> A(N);
  long long sum_A = 0;
  long long prod = 0;
  for(int i = 0; i < N; i++){
    cin >> A[i];
    
    sum_A += A[i];
    sum_A %= MOD;
    
    prod -= A[i] * A[i] % MOD;
    prod %= MOD;
  }
  
  prod += ((sum_A * sum_A % MOD - prod) * 500000004) % MOD;
  
  cout << (prod + MOD) % MOD << endl;
  
  return 0;
}