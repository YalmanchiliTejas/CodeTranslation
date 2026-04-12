#include <iostream>
#include <vector>
using namespace std;
long long MOD = 1000000007;
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
vector<long long> mf = {1};
vector<long long> mfi = {1};
long long modfact(int n){
	if (mf.size() > n){
		return mf[n];
	} else {
		for (int i = mf.size(); i <= n; i++){
			long long next = mf.back() * i % MOD;
			mf.push_back(next);
			mfi.push_back(modinv(next));
		}
		return mf[n];
	}
}
long long modfactinv(int n){
	if (mf.size() > n){
		return mfi[n];
	} else {
		return modinv(modfact(n));
	}
}
int main(){
	int N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	vector<vector<long long>> binom(N + 1, vector<long long>(N + 1, 0));
	for (int i = 0; i <= N; i++){
		binom[i][0] = 1;
		binom[i][i] = 1;
	}
	for (int i = 2; i <= N; i++){
		for (int j = 1; j < i; j++){
			binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
		}
	}
	vector<long long> dp(N + 1, 0);
	dp[0] = 1;
	for (int i = A; i <= B; i++){
		for (int j = N; j >= 0; j--){
			long long tmp = dp[j];
			for (int k = 0; k <= D; k++){
				if (j + i * k > N){
					break;
				}
				if (k >= C){
					dp[j + i * k] += tmp * modfactinv(k) % MOD;
					dp[j + i * k] %= MOD;
				}
				tmp *= binom[N - j - i * k][i];
				tmp %= MOD;
			}
		}
	}
	cout << dp[N] << endl;
}