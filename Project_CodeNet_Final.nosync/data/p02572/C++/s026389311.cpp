#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>
#include <map>
#include <deque>
#include <queue>
#include <tuple>
using namespace std;

#define prec(i) cout << fixed << setprecision(i)

void output_yn(bool isYes) {
	if (isYes)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

const long long MOD = 1000000007;

long long fact(long long k) {
	long long sum = 1;
	for (long long i = 2; i <= k; i++)
		sum *= i;

	return sum;
}

long long fact_mod(long long k) {
	long long sum = 1;
	for (long long i = 2; i <= k; i++)
		sum = (sum * i) % MOD;

	return sum;
}

int ctoi(char c) {
	if (c >= '0' && c <= '9')
		return c - '0';
	else
		return -1;
}

long long pow_mod(int a, int b) {
	long long ans = 1;
	for (int i = 0; i < b; i++)
		ans = (ans * a) % MOD;

	return ans;
}

long long powll(long long a, long long  b) {
	long long ans = 1;
	for (long long i = 0; i < b; i++)
		ans = ans * a;

	return ans;
}

long long modinv(long long a) {

	long long b = MOD, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= MOD;
	if (u < 0) u += MOD;

	return u;
}

long long _gcd(long long a, long long b)
{
	if (a < b)
		swap(a, b);

	if (a % b == 0)
		return b;
	else
		return _gcd(b, a % b);
}

long long _lcm(long long a, long long b)
{
	return (((a * b) % MOD) * modinv(_gcd(a, b))) % MOD;
}

long long ncr(long long n, long long r) {
	long long sum = 1;
	for (long long i = r + 1; i <= n; i++)
		sum *= i;

	return sum;
}


int main()
{
	int n, ans = 0;
	cin >> n;

	vector<long long> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	long long sum = 0;
	for (int i = 0; i < n; i++)
		sum = (sum + a[i]) % MOD;

	for (int i = 0; i < n; i++) {
		sum -= a[i];
		if (sum < 0)
			sum += MOD;
		ans += (sum * a[i]) % MOD;
		ans %= MOD;
	}

	cout << ans << endl;

	return 0;
}