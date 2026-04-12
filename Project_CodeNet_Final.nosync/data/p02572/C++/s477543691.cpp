#include<bits/stdc++.h>

using namespace std;

int main(void){
  const long long MOD = 1000000007LL;
  long long N;
  cin >> N;
  vector<long long> A(N);
  for(int i = 0; i < N; i++) cin >> A[i];
  long long ans = 0;
  long long cumsum = 0;
  for(int i = N - 2; i >= 0; i--){
    cumsum += A[i + 1];
    cumsum %= MOD;
    ans += cumsum * A[i];
    ans %= MOD;
  }
  cout << ans << endl;
}
