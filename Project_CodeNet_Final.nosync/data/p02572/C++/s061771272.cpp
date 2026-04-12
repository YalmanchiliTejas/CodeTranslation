#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long modpow(long long a, long long b){
	long long ans = 1;
	while (b > 0){
		if (b % 2 == 1){
			ans *= a;
			ans %= MOD;
		}
		a *= a;
		a %= MOD;
		b /= 2;
	}
	return ans;
}
long long modinv(long long a){
	return modpow(a, MOD - 2);
}
int main(){
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  long long sum = 0;
  long long sqsum = 0;
  for (int i = 0; i < N; i++){
    sum += A[i];
    sum %= MOD;
    sqsum += A[i] * A[i];
    sqsum %= MOD;
  }
  long long ans = (sum * sum - sqsum + MOD) % MOD;
  ans *= modinv(2);
  ans %= MOD;
  cout << ans << endl;
}