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
	const long long int mod = 1000000007;
	map<long long int, long long int>mp;
	//cout << fixed << setprecision(10);
	long long int n, m, k,a[200005],L[200001], R[200001],res=0,now=0;
	long long int sum=0;
	cin >> n >> m>>k;
	kai(1, 200002, mod);
	for (long long int i = 1; i <= m; i++) {
		long long int tmp = n;
		tmp *= ((m - i) * (m - i + 1) / 2 + (i - 1) * i / 2)%mod;
		tmp %= mod;
		tmp *= comb(n * m - 1, k - 1, mod);
		tmp %= mod;
		tmp *= n;
		tmp %= mod;
		tmp *= rui(n * m - 1, mod - 2, mod);
		tmp %= mod;
		res += tmp;
		res %= mod;
	}
	for (long long int i = 1; i <= n; i++) {
		long long int tmp = m;
		tmp *= ((n- i) * (n - i + 1) / 2 + (i - 1) * i / 2)%mod;
		tmp %= mod;
		tmp *= comb(n * m - 1, k - 1, mod);
		tmp %= mod;
		tmp *= m;
		tmp %= mod;
		tmp *= rui(n * m - 1, mod - 2, mod);
		tmp %= mod;
		res += tmp;
		res %= mod;

	}
	res *= rui(2, mod - 2, mod);
	res %= mod;
	res *= k - 1;
	
	cout << res%mod;
}
