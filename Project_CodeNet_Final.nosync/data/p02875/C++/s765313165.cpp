//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define F first
#define S second
#define _sz(x) (int)x.size()
#define pb push_back

#define error(x) cout << #x << " = " << x << endl

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 1e7 + 20, mod = 998244353;
int n, fac[N], inv[N], ans;

inline int pw (int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}

	return res;
}

inline int C (int n, int k)
{
	return 1ll * fac[n] * inv[k] % mod * inv[n - k] %mod;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	fac[0] = inv[0] = 1;
	for (int i = 1; i < N; i++)
	{
		fac[i] = 1ll * fac[i - 1] * i % mod;
		inv[i] = pw(fac[i], mod - 2);
	}

	cin >> n;

	n /= 2;

	ans = pw(3, 2 * n);

	for (int i = n + 1; i <= 2 * n; i++)
	{
		int res = C(2 * n, i);
		res = 2 * res % mod;

		res = 1ll * res * pw(2, 2 * n - i) % mod;

		ans = (ans + mod - res) % mod;

	}
	
	cout << ans << '\n';
}
