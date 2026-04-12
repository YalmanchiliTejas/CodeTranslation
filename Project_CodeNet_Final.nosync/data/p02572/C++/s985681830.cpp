#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
	int mod = 1e9 + 7;
	int n; cin >> n;
	ll ans = 0, sum = 0;
	for (int i = 0; i < n; ++i)
	{
		ll A; cin >> A;
		ans = (ans + sum * A) % mod;
		sum = (sum + A) % mod;
	}
	cout << ans << endl;
}
