#include <iostream>
 
constexpr int MOD = 1000000007;
 
int arr[200005];
long long pre_sum[200005];
 
int main()
{
	using std::cin;
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n >> arr[0];
	pre_sum[0] = arr[0];
	long long ans = 0;
	for (int i = 1; i < n; i++)
	{
		cin >> arr[i];
		pre_sum[i] = pre_sum[i - 1] + arr[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		const long long sum_j = pre_sum[n - 1] - pre_sum[i];
		ans += arr[i] * (sum_j % MOD) % MOD;
		ans %= MOD;
	}
	std::cout << ans << std::endl;
	return 0;
}