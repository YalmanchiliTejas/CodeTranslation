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
#include "ctime"

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-9;

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

	cin >> N >> M;
	long long int ans = power(2, power(2, N, M - 1), M);
	vector<long long int>by(N + 1, 1);
	vector<long long int>rev(N + 1, 1);
	for (int i = 1; i <= N; i++) {
		by[i] = by[i - 1] * i%M;
		rev[i] = power(by[i], M - 2, M);
	}
	vector<long long int>two(N + 1, 1);
	vector<long long int>twoM1(N + 1, 1);
	for (int i = 1; i <= N; i++) {
		two[i] = two[i - 1] * 2 % M;
		twoM1[i] = twoM1[i - 1] * 2 % (M - 1);
	}
	vector<long long int>num(N + 1);
	num[0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j >= 0; j--) {
			if(j)num[j] = num[j] * (j+1)%M + num[j - 1];
			num[j] %= M;
		}
	//	for (int j = 0; j <= i; j++) {
	//		cout << i << " " << j << " " << num[j] << endl;
	//	}
		long long int ncr = by[N] * rev[i] % M*rev[N - i] % M;
		long long int add = 0;
		long long int numb = two[N - i];
	//	vector<long long int>dp(i + 1);
	//	dp[i] = power(2, twoM1[N - i], M);
	//	for (int j = 1; j <= i; j++) {
	//		for (int k = 0; k <= i; k++) {
	//			for (int l = k + j; l <= i; l += j) {
	//				long long int a = by[l - k] * power(rev[j], (l - k) / j, M) % M*rev[(l - k) / j] % M*by[l] % M*rev[k] % M*rev[l - k] % M;
	//				dp[k] += dp[l] * a%M*power(num, (l - k) / j, M) % M;
	//				dp[k] %= M;
	//			}
	//		}
	//	}

		//add = accumulate(dp.begin(), dp.end(), 0LL) % M*ncr%M;
		for (int j = 0; j <= i; j++) {
			add += num[j] * power(numb, j, M) % M*ncr%M;
			add %= M;
		}
		add *= power(2, twoM1[N - i], M);
		add %= M;
		if (i & 1) {
			ans += M - add;
			ans %= M;
		}
		else {
			ans += add;
			ans %= M;
		}
//		cout << ans << endl;
	}
	cout << ans << endl;
}