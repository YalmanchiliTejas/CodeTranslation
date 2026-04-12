#include <iostream>
using namespace std;

long long md = 1000000007;

long long fp(long long n, int k)
{
	long long s = 1;
	while (k) {
		if (k % 2) s = (s * n) % md;
		k /= 2; n = (n * n) % md;
	}
	return s;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k; cin >> n >> m >> k;
	long long ans = 0, s = 0;
	for (int i = 1; i < n; i++) 
		s = (s + 1LL * i * (n - i)) % md;
	ans = (ans + ((s * m) % md) * m) % md;
	s = 0;
	for (int i = 1; i < m; i++)
		s = (s + 1LL * i * (m - i)) % md;
	ans = (ans + ((s * n) % md) * n) % md;
	long long r = 1LL * n * m - 2, t = 1;
	for (int i = 2; i < k; i++) {
		ans = (ans * r) % md;
		r = (r - 1 + md) % md;
		t = (t * (i - 1)) % md;
	}
	cout << (ans * fp(t, md - 2)) % md << '\n';
	return 0;
}	