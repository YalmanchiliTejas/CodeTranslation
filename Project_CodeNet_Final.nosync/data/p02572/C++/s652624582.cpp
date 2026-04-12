#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

using namespace std;

long long int modinv(long long int a, long long int m) {
	long long int b = m, u = 1, v = 0;
	while (b) {
		long long int t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

int main()
{
	long long int N;
	cin >> N;

	vector<long long int> A(N);
	for (long long int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	long long int ans = 0;
	long long int tmp1 = 0;
	long long int tmp2 = 0;

	for (long long int i = 0; i < N; ++i)
	{
		tmp1 += A[i];
		tmp2 += (A[i] * A[i]) % 1000000007;
		tmp1 %= 1000000007;
		tmp2 %= 1000000007;
	}
	tmp1 *= tmp1;
	tmp1 %= 1000000007;

	long long int tmp3 = 0;
	if (tmp1 - tmp2 < 0) {
		tmp3 = tmp1 - tmp2 + 1000000007;
	}
	else tmp3 = tmp1 - tmp2;

	ans = tmp3 * modinv(2, 1000000007);
	ans %= 1000000007;

	cout << ans;

	return 0;
}