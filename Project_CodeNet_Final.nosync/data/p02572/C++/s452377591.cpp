#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {

  int N;
  cin >> N;

  vector<long long>A(N);
  long long sum = 0,ans = 0;
  for(int i = 0;i < N;i++) {
    cin >> A[i];
    sum += A[i];
  }

  for(int i = 0;i < N-1;i++) {
    sum -= A[i];
    ans += A[i]*(sum % MOD);
    ans %= MOD;
  }

  cout << ans << endl;



}
