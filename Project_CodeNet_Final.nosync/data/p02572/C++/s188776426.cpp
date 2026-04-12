#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
	int mod = 1e9 + 7;
	int n; cin >> n;
	vector<int> A(n);
	vector<ll> B(n+1, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
		B[i+1] = B[i] + A[i];
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ll sum = (B[n] - B[i+1]) % mod;
		ans += A[i] * sum;
		ans %= mod;
	}
	cout << ans << endl;
}
