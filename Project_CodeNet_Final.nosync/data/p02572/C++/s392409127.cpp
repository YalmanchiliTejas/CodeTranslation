#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	
	int mod = 1000000007;
	for (int i = 1; i < n; i++) {
		a[i] += a[i - 1];
		a[i] %= mod;
	}

	long long ans = 0;
	for (int i = 1; i < n; i++) {
		ans += a[i - 1] * b[i];
		ans %= mod;
	}
	cout << ans << endl;

	return 0;
}