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
#include "functional"

using namespace std;

//constexpr long long int MOD = 1000000007;
//const int MOD = 1000000007;
constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;

constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

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

	cin >> N;
	vector<long long int>a(N / 2 + 1);
	vector<long long int>by(N + 1, 1);
	vector<long long int>rev(N + 1, 1);
	for (int i = 1; i <= N; i++) {
		by[i] = by[i - 1] * i;
		by[i] %= MOD;
		rev[i] = power(by[i], MOD - 2, MOD);
	}
	for (int i = 0; i <= N / 2; i++) {
		a[i] = by[N / 2] * rev[N / 2 - i];
		a[i] %= MOD;
		a[i] *= rev[i];
		a[i] %= MOD;
		a[i] *= power(2, N / 2 - i, MOD);
		a[i] %= MOD;
		//cout << i << " " << a[i] << endl;
	}
	auto asum = a;
	for (int i = 1; i <= N / 2; i++) {
		asum[i] += asum[i - 1];
		asum[i] %= MOD;
		//cout << i << " " << asum[i] << endl;
	}
	long long int ans = power(3, N, MOD);
	long long int minus = 0;
	for (int i = 1; i <= N / 2; i++) {
		long long int box = asum[N / 2] - asum[N / 2 - i];
	//	cout << box << endl;
		box += MOD;
		box %= MOD;
		box *= a[i];
		box *= 2;
		box %= MOD;
		minus += box;
		minus %= MOD;
		//cout << i << " " << minus << endl;
	}
	ans -= minus;
	ans += MOD;
	ans %= MOD;
	cout << ans << endl;
}