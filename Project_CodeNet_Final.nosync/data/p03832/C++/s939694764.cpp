#include <iostream>
using namespace std;

const int MAX = 210000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];
void COMinit(){
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++){
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}
long long COM(int n, int k){
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

inline long long mod(long long a, long long m) {
	return (a % m + m) % m;
}

long long pow(long long a, long long n, long long m) {
	if (n == 0) return 1 % m;
	long long t = pow(a, n / 2, m);
	t = mod(t * t, m);
	if (n & 1) t = mod(t * a, m);
	return t;
}


long long dp[1100][1100]; // i 人を j+A 人未満のグループで分ける方法

int main() {
	long long N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;

	COMinit();
	for (int i = 0; i < 1100; ++i) for (int j = 0; j < 1100; ++j) dp[i][j] = 0;
	dp[0][0] = 1;
	for (int i = 0; i <= N; ++i) for (int j = 0; j <= B - A + 1; ++j) {
		int num = A + j;

		//cout << i << ", " << num - 1 << ": " << dp[i][j] << endl;

		// num 人グループが 0 個
		dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;

		// num 人グループが C 以上 D 以下
		for (int k = C; k <= D; ++k) {
			int all = i + num*k;
			if (all > N) break;
			long long choose = COM(N - i, num * k);
			long long divide = fac[num*k] * pow(finv[num], k, MOD) % MOD;
			long long nonkubetsu = finv[k];
			long long mul = choose * divide % MOD * nonkubetsu % MOD;

			//cout << N - i << ", " << num << ", " << k << ": " << choose << ", " << divide << "; " << mul << endl;

			dp[all][j + 1] = (dp[all][j + 1] + dp[i][j] * mul % MOD) % MOD;
		}
	}

	cout << dp[N][B - A + 1] << endl;
}