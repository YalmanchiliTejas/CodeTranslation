#include <iostream>
using namespace std;

const int N = 200005;
const long long MOD = 1000000007;
long long sum[N], a[N];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = n; i; --i)
		sum[i] = (sum[i + 1] + a[i]) % MOD;
	long long ans = 0;
	for (int i = n - 1; i; --i)
		ans = (ans + (a[i] * sum[i + 1])) % MOD;
	cout << ans;
	return 0;
}