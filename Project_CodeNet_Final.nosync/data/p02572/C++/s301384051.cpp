#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

int main(){
  long long N;
  cin >> N;
  vector<long long> A(N);
  for(int i=0;i<N;i++) cin >> A[i];
  
  long long sum = 0;
  for(int i=0;i<N;i++){
    sum += A[i];
    sum %= mod;
  }
  
  long long ans = 0;
  for(int i=0;i<N;i++){
    sum += mod;
    sum -= A[i];
    sum %= mod;
    long long x = sum * A[i];
    x %= mod;
    ans += x;
    ans %= mod;
  }
  
  cout << ans << endl;
  return 0;
}
