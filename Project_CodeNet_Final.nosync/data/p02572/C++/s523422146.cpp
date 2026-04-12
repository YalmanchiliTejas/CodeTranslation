#include <bits/stdc++.h>
using namespace std;
#define reps(i, a, n) for (int i = (a); i < (n); ++i)
#define rep(i, n) reps(i, 0, n)
#define deps(i, a, n) for (int i = (a); i >= (n); --i)
#define dep(i, n) deps(i, n, 0)
#define inf 2147483647
#define int long long
#define mod 1000000007

signed main(void)
{
	int n; cin >> n;
	int a[200005];
	rep (i, n) cin >> a[i];
	int ans = 0, sum = 0;
	rep (i, n - 1)
	{
		sum += a[i];
		sum %= mod;
		ans += (sum * a[i + 1]) % mod;
		ans %= mod;
	}
	cout << ans << endl;
}
