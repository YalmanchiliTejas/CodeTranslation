#include "bits/stdc++.h"
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, mod = 1e9 + 7;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	vector<long long> b(n);
	b[n - 1] = a[n - 1];
	for (int j = n - 2; j >= 0; j--) b[j] = (b[j + 1] + a[j])%mod;
	long long ans{};
	for (int i = 0; i < n - 1; i++) ans = (ans + a[i]*b[i + 1])%mod;
	cout << ans;
}
