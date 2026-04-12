#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
#include <tuple>
#include<iomanip>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define MOD 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60

long long modpow(ll x, ll n) {
	if (n == 0) return 1LL;
	else if (n % 2 == 0) return modpow((x*x) % MOD, n / 2) % MOD;
	else return (modpow((x*x) % MOD, n / 2) * x) % MOD;
}

ll modComb(ll n, ll k) {
	ll res = 1;
	for (int i = 1; i <= n; i++) {
		res *= i;
		res %= MOD;
	}
	for (int i = 1; i <= k; i++) {
		res *= modpow(i, MOD - 2);
		res %= MOD;
	}
	for (int i = 1; i <= n - k; i++) {
		res *= modpow(i, MOD - 2);
		res %= MOD;
	}
	return res;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	/*
	ll n, m; cin >> n >> m;
	cout << "test" << endl;
	cout << "nCm = " << modComb(n, m) << endl;
	*/

	
	ll N, M, K; cin >> N >> M >> K;
	ll ans = 0;

	ll com;
	com= modComb(N * M - 2, K - 2);
	//cout << com << endl;
	
	ll res1 = N * N*(N - 1) / 2 - (N - 1)*N*(2 * N - 1) / 6;
	res1 %= MOD;
	res1 *= M * M; res1 %= MOD;
	ll res2 = M * M*(M - 1) / 2 - (M - 1)*M * (2 * M - 1) / 6;
	res2 %= MOD;
	res2 *= N * N; res2 %= MOD;

	cout << ((res1 + res2)*com) % MOD << endl;
	
	

	return 0;
}