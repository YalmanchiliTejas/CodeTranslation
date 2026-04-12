#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	ll ans = 0;
	for (int b = m + 1; b <= n; b++) {
		int temp = (n + 1) / b;
		ans = ans + 1LL * temp * (b - m);
		if ((n + 1) % b <= m) continue;
		else ans = ans + 1LL * ((n+1) % b - m);
	}
	if (m == 0) ans = 1LL * n * n;
	cout << ans << endl;
	return 0;
}