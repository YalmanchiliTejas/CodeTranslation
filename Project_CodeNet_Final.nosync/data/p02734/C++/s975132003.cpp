#include <iostream>
using namespace std;

const long long mod = 998244353;
int n, s; long long d[3030], a;

int main()
{
	cin >> n >> s;

	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		if (x > s) continue;

		a = (a + d[s - x] * (n - i + 1)) % mod;
		if (x == s) a = (a + i * (n - i + 1)) % mod;

		for (int j = s - x; j > 0; j--) d[j + x] = (d[j + x] + d[j]) % mod;
		d[x] = (d[x] + i) % mod;
	}
	printf ("%lld\n", a);

	return 0;
}