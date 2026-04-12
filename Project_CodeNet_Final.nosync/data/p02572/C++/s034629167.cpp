#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N;
  cin >> N;

  long long A[N];

  for (long long i = 0; i < N; i++) {
      cin >> A[i]; 
  }
  
  long long count_sum = 0;
  long long count = 0;
  long long count_pre = 0;
  long long mod = pow(10,9) + 7;

  for (long long i = 0; i < N; i++){
       count_sum += A[i];
  }

  for (long long i = 0; i < N; i++) {
      count_sum -= A[i]; 
      count_pre = count_sum % mod;
      count += (count_pre * A[i]) % mod;
      count_pre = 0;     
  }
      cout << count % mod <<endl;
}