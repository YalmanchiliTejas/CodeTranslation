#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
using namespace std;

//階乗先に計算
long long int kaizyou[200005] = { 1 };
long long int kai(long long int a, long long int b, long long int mod) {
	long long int tmp = 1;
	for (long long int i = a; i <= b; i++) {
		tmp *= i;
		tmp %= mod;

		kaizyou[i] = tmp;
	}
	return tmp;
}


//累乗(繰り返し2乗法)　aのb乗(mod)を求める。
long long int rui(long long int a, long long int b, long long mod) {
	int memo[65] = {};
	long long int A[65] = {};
	long long int tmp = 1;
	for (int i = 0; i < 65; i++) {
		memo[i] = b % 2;
		b /= 2;
	}

	A[0] = a;
	A[0] %= mod;

	for (int i = 1; i < 65; i++) {
		A[i] = A[i - 1] * A[i - 1];
		A[i] %= mod;
	}
	for (int i = 0; i < 65; i++) {
		if (memo[i] == 1) {
			tmp *= A[i];
			tmp %= mod;
		}
	}
	tmp %= mod;
	return tmp;
}

//コンビネーション計算
long long int comb(long long int n, long long int r, long long int mod) {
	long long int tmp;

	tmp = (kaizyou[n] * rui(kaizyou[r], mod - 2, mod)) % mod;
	tmp *= rui(kaizyou[n - r], mod - 2, mod);
	tmp %= mod;
	if (tmp < 0) { tmp = (mod - tmp) % mod; }
	return tmp;
}


int main() {
	complex<long double>cmpmp;
	const long long int mod = 1000000007;
	map<long long int, long long int>mp;
	//cout << fixed << setprecision(10);
	long long int n, a, b, c, d, dp[1005][1005] = {}, RUI[1005][1005];
	cin >> n >> a >> b >> c >> d;
	kai(1, 1400,mod);

	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			RUI[i][j] = rui(kaizyou[i], mod - j - 1, mod);
		}
	}

	dp[a - 1][n] = 1;
	for (int i = a; i <= b; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] += dp[i - 1][j];
			for (int k = c; k * i <= j && k <= d; k++) {
				long long int tmp = kaizyou[j] * RUI[i][k];
				tmp %= mod;
				tmp *= RUI[j - i * k][1];
				tmp %= mod;
				tmp *= RUI[k][1];
				tmp %= mod;
				dp[i][j - i * k] += dp[i - 1][j] * tmp;
				dp[i][j - i * k] %= mod;
			}
		}
	}
	cout << dp[b][0] << endl;

}
