#include <iostream>
#include <vector>

using namespace std;

int main()
{
	constexpr long long MOD = 1000000007;
	constexpr long long inv_2_MOD = 500000004;

	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	long long sum = 0;
	long long sum_sqr = 0;
	for (long long val : a)
	{
		sum += val;
		sum_sqr += (val * val) % MOD;
	}
	sum %= MOD;
	sum_sqr %= MOD;
	cout << (((sum * sum - sum_sqr) % MOD) * inv_2_MOD) % MOD << endl;
}