#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define int long long
#define N 200010
#define M 1010

using namespace std;
const int mod = 1e9 + 7;
int sum[N], a[N], n;

int read() {
	int s = 0, f = 0; char ch = getchar();
	while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return f ? -s : s;
}

signed main() {
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read(), sum[i] = (sum[i - 1] + a[i]) % mod;
	int ans = 0;
	for (int i = 1; i <= n - 1; i++) {
		int xx = (sum[n] - sum[i] + mod) % mod;
		ans = (ans + (a[i] * xx) % mod) % mod;
	}
	cout << ans << "\n";
}