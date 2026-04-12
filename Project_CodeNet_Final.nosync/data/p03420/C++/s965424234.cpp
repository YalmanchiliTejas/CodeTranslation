#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long n, k;
	cin >> n >> k;

	long long ans = 0;
	for (int i = k + 1; i <= n; i++) {
		ans += n / i * max(0LL, i - k);
		ans += max(0LL, n % i + 1 - k);
	}
	ans -= k == 0 ? n : 0;
	cout << ans << endl;

	return 0;
}