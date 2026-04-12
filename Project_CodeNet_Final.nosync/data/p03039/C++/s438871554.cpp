#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<math.h>
#include<unordered_map>
#include<map>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using lst = list<int>;


const ll MAX = 200005;
const ll MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}


long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main()
{
	ll N, M, K;
	cin >> N >> M >> K;

	COMinit();
	ll ans = 0;
	
	ll C = COM(N*M - 2, K - 2);

	for (int x = 1; x <= N; ++x)for (int y = 1; y <= M; ++y)
	{
		ll tmp = (((-x)*((N - x) - (x - 1))*M) % MOD)*C % MOD;
		ans += tmp + MOD;
		ans %= MOD;
		tmp = (((-y)*((M - y) - (y - 1))*N) % MOD)*C % MOD;
		ans += tmp + MOD;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}