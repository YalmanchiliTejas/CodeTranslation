#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int mod = 1000000007;
  cin >> N;
  int A[N] = {0};
  long long sum = 0;
  long long ans = 0;
  for (int i=0; i < N; i++){
    cin >> A[i];
    sum += A[i];
    sum %= mod;
  }
  for (int i=0; i < N; i++){
    sum -= A[i];
    if (sum < 0) sum += mod;
    ans += A[i] * sum;
    ans %= mod;
  }
  cout << ans << endl;
}