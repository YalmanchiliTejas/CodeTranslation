#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10, mod = 1e9 + 7;
ll n, a[N], sum, ans;
int main()
{
    std::ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], sum += a[i], sum %= mod;
	for(int i = 1; i <= n; i++)
	{
		sum = (sum + mod - a[i]) % mod;
		ans = (ans + sum * a[i] % mod) % mod;
	}
	cout << ans << endl;
	return 0;
}
