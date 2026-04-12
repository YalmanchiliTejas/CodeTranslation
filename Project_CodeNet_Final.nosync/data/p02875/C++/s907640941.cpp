#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<numeric>
#include<functional>
#include<algorithm>
#include<bitset>
#include<tuple>
#include<unordered_set>
#include<unordered_map>
#include<random>
#include<array>
#include<cassert>
using namespace std;
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define uniq(v) v.erase(unique(all(v)),v.end())

#define MOD 998244353


//逆元で二項係数を計算(MODは素数)　前処理O(n),本計算O(1)
#define MAXN 10000000
long long inv[MAXN + 1];//MODを法とする乗法の逆元
long long fact[MAXN + 1];//階乗
long long ifact[MAXN + 1];//階乗の逆元
void init(int n) {
	inv[1] = 1;
	for (int i = 2; i <= n; i++) inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
	fact[0] = ifact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = i * fact[i - 1] % MOD;
		ifact[i] = ifact[i - 1] * inv[i] % MOD;
	}
}
long long C(int n, int r) {
	if (n < 0 || r < 0 || r > n)return 0;
	if (r > n / 2)r = n - r;
	return fact[n] * ifact[n - r] % MOD * ifact[r] % MOD;
}
//x^y%MOD
long long pow_mod(long long x, long long y) {
	int res = 1;
	while (y) {
		if (y & 1)res = (res * x) % MOD;
		y >>= 1;
		x = (x * x) % MOD;
	}
	return res;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	

	int n;
	cin >> n;
	init(n);
	long long ans = pow_mod(3, n);

	for (int i = n / 2 + 1; i <= n; i++) {
		long long c = C(n, i) * 2;
		c *= pow_mod(2, n - i);
		ans -= c % MOD;
	}
	ans %= MOD;
	ans += MOD;
	ans %= MOD;

	cout << ans << endl;




	return 0;
}