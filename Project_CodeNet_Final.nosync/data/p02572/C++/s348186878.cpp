#include <bits/stdc++.h>
using namespace std;

int main() {
    int mod = 1000000007;
  int N;
  cin >> N;
  long long A[N];
  long long sum = 0;
  for(int i = 0; i < N; i++){
      cin >> A[i];
      sum += A[i];
      sum %= mod;
  }
  long ans = 0;

  for(int i = 0; i < N; i++){
      sum -= A[i];
      if(sum < 0) sum += mod;
      ans += A[i]*sum;
      ans %= mod;

  }
  cout << ans << endl;
}