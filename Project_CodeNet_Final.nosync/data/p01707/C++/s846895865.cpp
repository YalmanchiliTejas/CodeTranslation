#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
 
constexpr int mod = 1000000007;
 
inline long long mod_pow(long long n, long long k) {
	long long res = 1;
	while(k > 0) {
		if(k & 1) res = res * n % mod;
		n = n * n % mod;
		k >>= 1;
	}
	return res;
}
 
inline long long mod_inverse(long long n) {
	return mod_pow(n, mod - 2);
}
 
inline long long mod_combination(long long n, long long k) {
	long long res = 1;
	if(k * 2 > n) k = n - k;
 
	for(int i = 0; i < k; ++i) {
		res = res * ((n - i) % mod) % mod;
	}
 
	long long tmp = 1;
	for(int i = 1; i <= k; ++i) {
		tmp = tmp * i % mod;
	}
 
	res = res * mod_inverse(tmp) % mod;
 
	return res;
}
 
constexpr int MAX = 2000;
int dp[MAX + 1][MAX + 1];
 
int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, x;
	long long d;

	while(cin >> n >> d >> x && n) {
		const int eat = min<long long>(n, d);
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
 
		for(int i = 0; i < eat; ++i) {
			int sum = dp[i][0];

			for(int k = 1; k <= n; ++k) {
				if(k >= x) sum = (sum + mod - dp[i][k - x]) % mod;
				dp[i + 1][k] = (dp[i + 1][k] + sum) % mod;
				sum = (sum + dp[i][k]) % mod;
			}
		}

		long long ans = 0;
		for(int day = 1; day <= eat; ++day) {
			ans = (ans + dp[day][n] * mod_combination(d, day)) % mod;
		}
		cout << ans << endl;
	}
 
	return EXIT_SUCCESS;
}