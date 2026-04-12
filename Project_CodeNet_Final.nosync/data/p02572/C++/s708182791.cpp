#include <iostream>
#define MOD 1000000007
#define M_OD2 2000000014
using namespace std;

int main() {
  long long N; cin >> N;
  long long A[N]; for (int i = 0; i < N; i++) cin >> A[i];
  
  long long sum = 0;
  for (int i = 0; i < N; i++){
    sum = (sum + A[i]) % M_OD2;
  }
  long long sum_ = 0;
  for (int i = 0; i < N; i++){
    sum_ = (A[i] * A[i] + sum_) % M_OD2;
  }
  long long ans;
  ans = ((sum * sum - sum_) % M_OD2 + M_OD2) % M_OD2;
  if (ans % 2 == 0) cout << ans / 2 << endl;
  if (ans % 2 == 1) cout << (ans + MOD) / 2 << endl;
}