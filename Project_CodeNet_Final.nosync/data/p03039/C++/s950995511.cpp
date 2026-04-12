#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 1000000007;
//const int MOD = 998244353;
//const long long int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;

long long int power(long long int x, long long int n, long long int M) {
	long long int ret = 1;
	long long int by = x;
	while (n) {
		if (n & 1) {
			ret *= by;
			ret %= M;
		}
		by *= by;
		by %= M;
		n >>= 1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	vector<long long int>by(N*M + 1, 1);
	vector<long long int>rev(N*M + 1, 1);
	long long int ans = 0;
	for (int i = 1; i <= N * M; i++) {
		by[i] = by[i - 1] * i;
		by[i] %= MOD;
		rev[i] = power(by[i], MOD - 2, MOD);
	}
	for (int i = 0; i < N; i++) {
		long long int box = 1LL * i * (i + 1) / 2;
		box *= M;
		box %= MOD;
		box *= M;
		box %= MOD;
		box *= by[N*M - 2];
		box %= MOD;
		box *= rev[K - 2];
		box %= MOD;
		box *= rev[N*M - K];
		box %= MOD;
		ans += box;
		ans %= MOD;
	}
	for (int i = 0; i < M; i++) {
		long long int box = 1LL * i * (i + 1) / 2;
		box *= N;
		box %= MOD;
		box *= N;
		box %= MOD;
		box *= by[N*M - 2];
		box %= MOD;
		box *= rev[K - 2];
		box %= MOD;
		box *= rev[N*M - K];
		box %= MOD;
		ans += box;
		ans %= MOD;
	}
	ans %= MOD;
	cout << ans << endl;
}