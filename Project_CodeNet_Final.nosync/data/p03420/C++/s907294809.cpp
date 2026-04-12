#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e3 + 5;
const double eps = 1e9;
typedef long long LL;
#define ls o<<1
#define rs o<<1|1
#define m(o) (q[o].l+((q[o].r-q[o].l)>>1))

int main() {
	LL n, k;
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	if (k == 0) {
		cout << n*n << endl;
	}
	else {
		LL ans = 0;
		for (int i = k + 1; i <= n; i++) {
			ans += (n / i) * (i - k) + max(0LL, n % i - k + 1);
		}
		cout << ans << endl;
	}
	return 0;
}