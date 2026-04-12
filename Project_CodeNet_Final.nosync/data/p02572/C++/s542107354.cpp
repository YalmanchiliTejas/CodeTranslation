#include<bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main() {
	long long n; cin >> n;
	long long a[n], sum[n] = {};
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(i == 0) sum[i] = a[i];
		else sum[i] += sum[i-1] + a[i];
	}

	long long ans = 0;
	for (int i = 0; i < n-1; i++)
	{
		long long tmp = a[i] * ((sum[n-1] - sum[i]) % mod) % mod;
		ans = (ans + tmp) % mod;
	}
	cout << ans << endl;
	return 0;
}
